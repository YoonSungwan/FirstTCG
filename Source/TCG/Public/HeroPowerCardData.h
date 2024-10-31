// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardData.h"
#include "HeroPowerCardData.generated.h"

/**
 * 
 */
class ACard;
UCLASS()
class TCG_API UHeroPowerCardData : public UCardData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HeroPowerCardData");
	FString EffectDescription;

	bool GiveDamage(ACard* Card, int32 Damage);

	bool RecoveryHealth(ACard* Card, int32 Damage);
	
	void SpawnTotem(int32 SpawnNum);

	virtual void ApplyEffect_Implementation(AActor* Target) override;
};
