// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardData.h"
#include "WeaponCardData.generated.h"

/**
 * 
 */
class ACard;
UCLASS()
class TCG_API UWeaponCardData : public UCardData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WeaponCardData");
	int32 AttackDamage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WeaponCardData");
	int32 Durability;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WeaponCardData");
	int32 EnhancedPower;
	
	bool RecoveryHealth(ACard* TargetCard, int32 RecoveryHealth);

	bool PlusDurability(ACard* TargetCard, int32 Durability);

	virtual void ApplyEffect_Implementation(AActor* Target) override;
};
