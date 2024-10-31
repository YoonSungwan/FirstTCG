// Fill out your copyright notice in the Description page of Project Settings.


#include "TCG/Public/Card.h"
#include "TCG/Public/CardData.h"
#include "TCG/Public/MinionCardData.h"

ACard::ACard()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
}

void ACard::InitializeCard(UCardData* InCardData)
{
	CardData = InCardData;
	//필요할 경우 초기화 시, CardData에서 속성을 복사
}

void ACard::PrintCardInfo() const
{
	if(const UMinionCardData* MinionCard = Cast<UMinionCardData>(CardData))
	{
		UE_LOG(LogTemp, Log, TEXT("MinionCardData: %s"), *MinionCard->CardName);
	}
	
	/*if (CardData)
	{
		UE_LOG(LogTemp, Log, TEXT("Card Name: %s, Mana Cost: %d, Attack Power: %d, Health: %d"),
			*CardData->CardName, CardData->ManaCost, CardData->AttackPower, CardData->Health);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Card Data is not initialized."));
	}*/
}

void ACard::LoadAndInitializeCardData(const FString& AssetPath)
{
	//FString을 FSoftObjectPath로 변환
	FSoftObjectPath SoftObjectPath(AssetPath);
	TSoftObjectPtr<UCardData> CardDataAsset(SoftObjectPath);

	//유효하거나, 동기적으로 호출이 됐으면
	if(CardDataAsset.IsValid() || CardDataAsset.LoadSynchronous())
	{
		UCardData* LoadedCardData = CardDataAsset.Get();
		InitializeCard(LoadedCardData);

		UE_LOG(LogTemp, Log, TEXT("Card Initialized with data Asset : %s"), *LoadedCardData->CardName);
	}
}
