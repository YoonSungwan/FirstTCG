// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Deck.generated.h"

class ACard;
UCLASS()
class TCG_API ADeck : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeck();

	int32 MaxDeckNum;

	TArray<ACard*> Cards;

	UFUNCTION()
	void ShuffleDeck();

	void AddCardToDeck(ACard* Card);

	ACard* DrawCard(class AHand* PlayerHand);

	ACard* FindCardByName(const FString& Name) const;

	void PrintDeckInfo() const;

};
