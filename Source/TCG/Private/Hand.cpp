// Fill out your copyright notice in the Description page of Project Settings.


#include "TCG/Public/Hand.h"

#include "TCGGameMode.h"
#include "TCG/Public/Card.h"
#include "TCG/Public/CardData.h"

// Sets default values
AHand::AHand()
{
 	// 손 패는 업데이트 될 경우가 많으니까 Tick true
	PrimaryActorTick.bCanEverTick = true;
	MaxHandSize = 10;

	/*ATCGGameMode* GameMode = Cast<ATCGGameMode>(GetWorld()->GetAuthGameMode());
	if(GameMode)
	{
		GameMode->TurnStateDelegate.AddDynamic(this, &AHand::ArrangeCardInHand);
	}*/
}

//이벤트(함수)가 제대로 동작했는지 확인하기 위해 return을 bool 타입으로
bool AHand::AddCardToHand(ACard* NewCard)
{
	if(NewCard && !IsHandFull())
	{
		CardsInHand.Add(NewCard);
		ArrangeCardInHand();
		return true;
	}
	
	return false;
}

bool AHand::RemoveCardFromHand(ACard* CardToRemove)
{
	if(CardToRemove && CardsInHand.Contains(CardToRemove))
	{
		CardsInHand.Remove(CardToRemove);;
		ArrangeCardInHand();
		return true;
	}
	return false;
}

bool AHand::IsHandFull() const
{
	return (CardsInHand.Num() >= MaxHandSize);
}

void AHand::ArrangeCardInHand()
{
	//손 패에 카드를 배치
	const float CardSpacing = 10.f;
	const FVector StartPosition = FVector(-(CardSpacing * CardsInHand.Num() / 2), 0, 0);

	for(int32 i=0; i<CardsInHand.Num(); i++)
	{
		if(CardsInHand[i])
		{
			FVector NewPosition = StartPosition + FVector(i * CardSpacing, 0, 0);
			CardsInHand[i]->SetActorLocation(NewPosition);
		}
	}
}

void AHand::PrintHandInfo() const
{
	UE_LOG(LogTemp, Log, TEXT("Hand contains cards Num: %d"), CardsInHand.Num());
	for(const ACard* Card : CardsInHand)
	{
		if(Card && Card->CardData)
		{
			UE_LOG(LogTemp, Log, TEXT(" - %s (ManaCost: %d) <- HandClass"), *Card->CardData->CardName, Card->CardData->ManaCost);	
		}
	}
}
