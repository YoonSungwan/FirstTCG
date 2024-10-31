// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Hand.generated.h"

class ACard;
UCLASS()
class TCG_API AHand : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHand();

	TArray<ACard*> CardsInHand;

	int32 MaxHandSize;
	
	bool AddCardToHand(ACard* Newcard);

	bool RemoveCardFromHand(ACard* CardToRemove);

	bool IsHandFull() const;

	void ArrangeCardInHand();

	void PrintHandInfo() const;
};
