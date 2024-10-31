// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardData.h"
#include "SecretCardData.generated.h"

UENUM(BlueprintType)
enum class ESecretEffectType : uint8
{
	DamageEnemyHero,
	SummonMinions,
	CounterSpell,
	ProtectFriendlyHero,
	DamageAllEnemies,
};
/**
 * 
 */
UCLASS()
class TCG_API USecretCardData : public UCardData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SecretCardData");
	FString TriggerCondition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SecretCardData");
	FString EffectDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SecretCardData");
	ESecretEffectType EffectType;	//효과 유형

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SecretCardData");
	int32 EffectAmount;

	//Secret 발동 조건을 판별하는 함수
	UFUNCTION(BlueprintCallable, Category="SecretCardData")
	bool IsConditionMet(const FString& EventName);

	//Secret 말동 함수
	UFUNCTION(BlueprintCallable, Category="SecretCardData")
	void ActivateSecret(AActor* Target);

	virtual void ApplyEffect_Implementation(AActor* Target) override;
};
