// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Hand.generated.h"

class ACard;
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TCG_API UHand : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHand();

	// Sets default values for this actor's properties
	TArray<ACard*> CardsInHand;

	int32 MaxHandSize;
	
	bool AddCardToHand(ACard* Newcard);

	bool RemoveCardFromHand(ACard* CardToRemove);

	bool IsHandFull() const;

	void ArrangeCardInHand();

	void PrintHandInfo() const;
};
