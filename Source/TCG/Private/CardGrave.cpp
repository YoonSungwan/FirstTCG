// Fill out your copyright notice in the Description page of Project Settings.


#include "CardGrave.h"

#include "Card.h"


// Sets default values
ACardGrave::ACardGrave()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

bool ACardGrave::SendCardToGrave(ACard* Card)
{
	if(Card)
	{
		CardsInGrave.Add(Card);
		return true;
	}

	UE_LOG(LogTemp, Warning, TEXT("Send Card to Grave is Failed..."));
	return false;
}

ACard* ACardGrave::ReturnCardToHand(const FString& CardName)
{
	if(CardsInGrave.Num() > 0)
	{
		for(ACard* card : CardsInGrave)
		{
			if(card->GetName() == CardName)
			{
				return card;
			}
		}
	}
	UE_LOG(LogTemp, Error, TEXT("Find Card in grave Action is Failed..."));
	return nullptr;
}

