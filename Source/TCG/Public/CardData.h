// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CardData.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCardTriggered, AActor*, Actor);
class UCardEffectManager;
class ACard;
UCLASS()
class TCG_API UCardData : public UDataAsset
{
	GENERATED_BODY()

public:
	//Delegate 변수
	FOnCardTriggered OnCardTriggered;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Card")
	FString CardName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Card")
	int32 ManaCost;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Card")
	int32 AttackPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Card")
	int32 Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Card")
	ECardType CardType;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Card")
	UTexture2D* CardTexture;

	UPROPERTY()
	UCardEffectManager* CardEffectManager;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Effect")
	void ApplyEffect(ACard* Target);

	virtual void ApplyEffect_Implementation(ACard* Target);
};
