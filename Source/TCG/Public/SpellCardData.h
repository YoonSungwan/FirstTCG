// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActivateCardInterface.h"
#include "CardData.h"
#include "SpellCardData.generated.h"

//효과 유형을 정의하는 열거형
UENUM(BlueprintType)
enum class ESpellEffectType	: uint8
{
	Damage,
	Heal,
	Buff,
	Debuff
};

UENUM(BlueprintType)
enum class ESpellTargetType	: uint8	//멀티타겟은 TArray를 사용해서 SingleEnemy를 여러 번 해도 가능
{
	SingleEnemy,
	SingleAlly,
	AllEnemies,
	AllAllies,
	Self
};
/**
 * 
 */
class ACard;
UCLASS()
class TCG_API USpellCardData : public UCardData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpellCardData")
	FString EffectDescription;		//효과 설명

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpellCardData")
	ESpellEffectType EffectType;	//효과 유형

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpellCardData")
	ESpellTargetType TargetType;	//타겟 유형

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpellCardData")
	int32 EffectAmount;				//효과 강도

	virtual void ApplyEffect_Implementation(AActor* Target) override;

protected:
	void ApplyDamageEffect(AActor* Target);
	void ApplyHealEffect(AActor* Target);
	void ApplyBuffEffect(AActor* Target);
	void ApplyDebuffEffect(AActor* Target);
};
