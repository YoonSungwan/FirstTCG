// Fill out your copyright notice in the Description page of Project Settings.


#include "DeckEditor.h"
#include "Card.h"
#include "Deck.h"
#include "HairStrandsInterface.h"
#include "TCGPlayer.h"

// Sets default values
ADeckEditor::ADeckEditor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADeckEditor::BeginPlay()
{
	Super::BeginPlay();

	CardType.Add(TEXT("Minion"));
	CardType.Add(TEXT("Spell"));
	CardType.Add(TEXT("Secret"));

	InitializeDeck();
}

// Called every frame
void ADeckEditor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADeckEditor::InitializeDeck()
{
	if(!SubClassDeck)
	{
		UE_LOG(LogTemp, Error, TEXT("Is not Setting deck"));
		return;
	}
	
	ADeck* Deck = GetWorld()->SpawnActor<ADeck>(SubClassDeck);

	if(!Deck)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find deck"));
		return;
	}
	for(FString Type : CardType)
	{
		for(int i=1; i<4; i++)
		{
			ACard* Card = NewObject<ACard>();
			//Type
			FString DataAssetName = FString("DA_").Append(Type).Append(FString::FromInt(i));
			FString AssetPath = FString("/Game/DataAsset/").Append(Type).Append("/").Append(DataAssetName).Append(".").Append(DataAssetName);
			UE_LOG(LogTemp, Warning, TEXT("AssetPath is %s"), *AssetPath);
			
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

	/*if(GetWorld()->GetFirstPlayerController())
	{
		UE_LOG(LogTemp, Warning, TEXT("Find Player"));
		ATCGPlayer* Player = Cast<ATCGPlayer>(GetWorld()->GetFirstPlayerController());
		if(Player)
		{
			Player->Deck = Deck;
			UE_LOG(LogTemp, Warning, TEXT("Player's Deck Setting over"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Player's Deck Setting failed..."));
		}
	}*/
	
}

