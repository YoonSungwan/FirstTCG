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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Deck")
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Deck")
	class UStaticMeshComponent* DeckMesh;

	int32 MaxDeckNum;

	UFUNCTION()
	void ShuffleDeck();

	void AddCardToDeck(ACard* Card);
	bool IsFullDeck();

	ACard* DrawCard(class UHand* PlayerHand);

	ACard* FindCardByName(const FString& Name) const;
	
	TArray<ACard*> GetDeck();
	
	void PrintDeckInfo() const;

private:
	TArray<ACard*> Cards;

};
