// Fill out your copyright notice in the Description page of Project Settings.


#include "GameField.h"
#include "Card.h"
#include "CardData.h"
#include "Hand.h"
#include "Deck.h"
#include "TCGGameMode.h"
#include "TCGPlayer.h"
#include "DeckEditorWidget.h"
#include "CardWidget.h"
#include "Components/CapsuleComponent.h"


// Sets default values
AGameField::AGameField()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleFieldComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Field Capsule Component"));
	SetRootComponent(CapsuleFieldComp);

	StaticFieldComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Field Static Component"));
	StaticFieldComp->SetupAttachment(CapsuleFieldComp);

	CardSlot = 3;
}

// Called when the game starts or when spawned
void AGameField::BeginPlay()
{
	Super::BeginPlay();

	if(GameMode)
	{
		GameMode->SetCurrentPhase(EGamePhase::GameStart);
	}

	if(EditorWidgetClass)
	{
		EditorWidget = CreateWidget<UDeckEditorWidget>(GetWorld(), EditorWidgetClass);
		
		if(EditorWidget)
		{
			EditorWidget->OpenDeckEditor();
		}
	}

	InitializeDeck();
}

// Called every frame
void AGameField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


bool AGameField::IsSlotFull() const
{
	if(CardOnField.Num() >= CardSlot)
	{
		return true;
	}

	return false;
}

void AGameField::ActivateCard(ATCGPlayer* TargetPlayer, ACard* Card)
{
	if(!TargetPlayer || !Card)
	{
		UE_LOG(LogTemp, Error, TEXT("Player or Card is not valid"));
		return;
	}
	
	UE_LOG(LogTemp, Display, TEXT("%s is Active To %s "), *Card->GetName(), *TargetPlayer->GetName());

	OnTargetPlayer.Broadcast(TargetPlayer, Card);
}

void AGameField::SalvageCard(ACard* Card)
{
	if(Card)
	{
		if(GamePlayer && GamePlayer->Hand)
		{
			GamePlayer->Hand->AddCardToHand(Card);
		}
	}
}

void AGameField::InitializeDeck()
{
	if(!SubClassDeck)
	{
		UE_LOG(LogTemp, Error, TEXT("Is not Setting deck"));
		return;
	}
	
	Deck = GetWorld()->SpawnActor<ADeck>(SubClassDeck);

	if(!Deck)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find deck"));
		return;
	}

	//덱 Spawn하고 카드 채우기
	//TODO : 데이터에셋(카드) 이름 수정하기, 에디터에서 덱 수정하도록 변경 필수
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	for(int32 i=0; i< StaticEnum<ECardType>()->NumEnums() -1; ++i)
	{
		FString Type = StaticEnum<ECardType>()->GetNameStringByIndex(i);

		FString DA_FolderPath = FString("/Game/DataAsset/").Append(Type);

		//폴더 안의 데이터 에셋 개수
		int32 AssetCount = GetDAFileNum(AssetRegistryModule, DA_FolderPath);

		for(int32 j=0; j < AssetCount; ++j)
		{
			ACard* Card = NewObject<ACard>();

			//데이터에셋 파일은 이름 규칙은 1부터 시작
			FString DataAssetName = FString("DA_").Append(Type).Append(FString::FromInt(j+1));
			FString AssetPath = FString("/Game/DataAsset/").Append(Type).Append("/").Append(DataAssetName).Append(".").Append(DataAssetName);
			
			Card->LoadAndInitializeCardData(AssetPath);
			
			if(Card && Card->CardData)
			{
				Deck->AddCardToDeck(Card);
				if(Deck->IsFullDeck())
				{
					return;
				}
			}
		}
	}

	//TODO : 별도의 이벤트로 분리 & 델리게이트 처리
	if(EditorWidget && EditorWidget->bIsEditorOpen)
	{
		if(SubClassCard)
		{
			EditorWidget->DisplayCardFromDeck(Deck, SubClassCard);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("GameField : SubClassCard not setting"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("GameField : EditorWidget not setting"));
	}
}

//데이터에셋 파일 개수 리턴
int32 AGameField::GetDAFileNum(FAssetRegistryModule& AssetRegistryModule, FString DA_FolderPath) const
{
	int FolderNum = -1;
	if(DA_FolderPath != "")
	{
		FARFilter Filter;
		Filter.PackagePaths.Add(*DA_FolderPath); // 폴더 경로
		//Filter.bRecursivePaths = false; // 하위 폴더 포함 여부 (필요 시 true로 설정)

		TArray<FAssetData> AssetList;
		AssetRegistryModule.Get().GetAssets(Filter, AssetList);

		// 에셋 개수 출력
		FolderNum = AssetList.Num();
	}

	return FolderNum;
}
