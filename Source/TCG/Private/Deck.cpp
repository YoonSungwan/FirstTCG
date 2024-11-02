// Fill out your copyright notice in the Description page of Project Settings.


#include "TCG/Public/Deck.h"

#include "Components/CapsuleComponent.h"
#include "TCG/Public/Card.h"
#include "TCG/Public/CardData.h"
#include "TCG/Public/Hand.h"

// Sets default values
ADeck::ADeck()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MaxDeckNum = 20;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>("Capsule Component");
	RootComponent = CapsuleComp;

	DeckMesh = CreateDefaultSubobject<UStaticMeshComponent>("Deck Mesh");
	DeckMesh->SetupAttachment(RootComponent);
}



//셔플 알고리즘 - 제일 쉬운 방법
void ADeck::ShuffleDeck()
{
	const int32 NumCard = Cards.Num();
	UE_LOG(LogTemp, Log, TEXT("Start Shuffle Deck"));
	for(int i=NumCard-1; i > 0; i--)
	{
		int j = FMath::RandRange(0, i);

		if(Cards.IsValidIndex(i) && Cards.IsValidIndex(j))
		{
			Cards.Swap(i, j);
		}
	}

	//멀리건
	/*TArray<ACard*> FrontDeck;
	TArray<ACard*> EndDeck;
	
	for(int i=0; i < NumCard; i++)
	{
		if(i <= ((NumCard)/2))
		{
			FrontDeck.Add(Cards[i]);
		}
		else
		{
			EndDeck.Add(Cards[i]);
		}
	}*/
}

void ADeck::AddCardToDeck(ACard* Card)
{
	if(!IsFullDeck())
	{
		Cards.Add(Card);	
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Deck Count's already Max"));
	}
}

bool ADeck::IsFullDeck()
{
	return Cards.Num() >= MaxDeckNum;
}

ACard* ADeck::DrawCard(class UHand* PlayerHand)
{
	if(Cards.Num() > 0)
	{
		ACard* DrawnCard = Cards[0];
		Cards.RemoveAt(0);
		if(PlayerHand && PlayerHand->AddCardToHand(DrawnCard))
		{
			return DrawnCard;
		}
		
		//드로우 실패 시 처리 추가 가능
		UE_LOG(LogTemp, Warning, TEXT("Draw Card Fail"));
	}
	return nullptr;
}

ACard* ADeck::FindCardByName(const FString& Name) const
{
	for(ACard* Card : Cards)
	{
		if(Card &&Card->CardData && Card->CardData->CardName == Name)
		{
			return Card;
		}
	}
	return nullptr;
}

TArray<ACard*> ADeck::GetDeck()
{
	return Cards;
}

void ADeck::PrintDeckInfo() const
{
	UE_LOG(LogTemp, Log, TEXT("Deck contains cards: %d"), Cards.Num());

	for(const ACard* Card : Cards)
	{
		if(Card && Card->CardData)
		{
			UE_LOG(LogTemp, Log, TEXT(" - %s (ManaCost: %d)"), *Card->CardData->CardName, Card->CardData->ManaCost);
		}
	}
}
