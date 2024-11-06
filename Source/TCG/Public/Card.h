// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Card.generated.h"

class UCardData;
UCLASS()
class TCG_API ACard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACard();

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CardActor")
	//class UCapsuleComponent* CapsuleCardComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CardActor")
	class UStaticMeshComponent* StaticCardComp;
	
	UPROPERTY()
	UCardData* CardData;

	void InitializeCard(UCardData* InCardData);
	
	void PrintCardInfo() const;
	
	void LoadAndInitializeCardData(const FString& AssetPath);
};