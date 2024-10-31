// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DeckEditor.generated.h"

class ACard;
class ADeck;
UCLASS()
class TCG_API ADeckEditor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADeckEditor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TArray<ACard*> Cards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Deck")
	ADeck* Deck;

	void InitializeDeck();
};
