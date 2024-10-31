// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CardData.generated.h"

/**
 * 
 */
UCLASS()
class TCG_API UCardData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Card")
	FString CardName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Card")
	int32 ManaCost;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Card")
	int32 AttackPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Card")
	int32 Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Card")
	ECardType CardType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Card")
	UTexture2D* CardTexture;*/

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Effect")
	void ApplyEffect(AActor* Target);

	virtual void ApplyEffect_Implementation(AActor* Target);
};
