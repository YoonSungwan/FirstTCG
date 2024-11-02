// Fill out your copyright notice in the Description page of Project Settings.


#include "TCG/Public/Hand.h"
#include "TCG/Public/Card.h"
#include "TCG/Public/CardData.h"

// Sets default values
UHand::UHand()
{
	// 손 패는 업데이트 될 경우가 많으니까 Tick true
	PrimaryComponentTick.bCanEverTick = true;
	MaxHandSize = 10;

	/*ATCGGameMode* GameMode = Cast<ATCGGameMode>(GetWorld()->GetAuthGameMode());
	if(GameMode)
	{
		GameMode->TurnStateDelegate.AddDynamic(this, &UHand::ArrangeCardInHand);
	}*/
}

//이벤트(함수)가 제대로 동작했는지 확인하기 위해 return을 bool 타입으로
bool UHand::AddCardToHand(ACard* NewCard)
{
	if(NewCard && !IsHandFull())
	{
		CardsInHand.Add(NewCard);
		ArrangeCardInHand();
		return true;
	}
	
	return false;
}

bool UHand::RemoveCardFromHand(ACard* CardToRemove)
{
	if(CardToRemove && CardsInHand.Contains(CardToRemove))
	{
		CardsInHand.Remove(CardToRemove);;
		ArrangeCardInHand();
		return true;
	}
	return false;
}

bool UHand::IsHandFull() const
{
	return (CardsInHand.Num() >= MaxHandSize);
}

void UHand::ArrangeCardInHand()
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

void UHand::PrintHandInfo() const
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
