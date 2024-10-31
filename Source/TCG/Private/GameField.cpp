// Fill out your copyright notice in the Description page of Project Settings.


#include "GameField.h"
#include "Card.h"
#include "CardData.h"
#include "Hand.h"
#include "TCGGameMode.h"
#include "TCGPlayer.h"


// Sets default values
AGameField::AGameField()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
