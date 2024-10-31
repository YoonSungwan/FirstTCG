// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CardGrave.generated.h"

class ACard;
UCLASS()
class TCG_API ACardGrave : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACardGrave();
	
	bool SendCardToGrave(ACard* Card);
	ACard* ReturnCardToHand(const FString& CardName);

private:
	TArray<ACard*> CardsInGrave;
};
