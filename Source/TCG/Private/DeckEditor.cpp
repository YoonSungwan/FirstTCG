// Fill out your copyright notice in the Description page of Project Settings.


#include "DeckEditor.h"
#include "Card.h"
#include "Deck.h"

// Sets default values
ADeckEditor::ADeckEditor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADeckEditor::BeginPlay()
{
	Super::BeginPlay();

	FString Type = "Spell";

	InitializeDeck();
}

// Called every frame
void ADeckEditor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADeckEditor::InitializeDeck()
{
	ACard* Card = NewObject<ACard>();
	
	FString DataAssetName = FString("Minion").Append(FString::FromInt(2));
	FString AssetPath = FString("/Game/DA_").Append(DataAssetName).Append(FString(".DA_")).Append(DataAssetName);
	UE_LOG(LogTemp, Warning, TEXT("AssetPath is %s"), *AssetPath);
	Card->LoadAndInitializeCardData(AssetPath);
}

