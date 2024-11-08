// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Card.h"
#include "UObject/Object.h"
#include "CardEffectManager.generated.h"

class UCardData;
/**
 * 
 */
UCLASS()
class TCG_API UCardEffectManager : public UObject
{
	GENERATED_BODY()

public:
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CardEffectManager")
	//class ACard* TargetCard;
	
	void BindCardEffect(UCardData* CardData);

	UFUNCTION()
	void TriggerCardEffect(ACard* Actor);

	UFUNCTION()
	void DamageToCard(ACard* Actor, int32 Amount);

	UFUNCTION()
	void HealToCard(ACard* Actor, int32 Amount);
	
	UFUNCTION()
	void EnhancePower(ACard* Actor, int32 Amount);

	UFUNCTION()
	void WeakenPower(ACard* Actor, int32 Amount);
};
