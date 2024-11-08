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
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAllDamageDelegate, int32, Amount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDamageDelegate, ACard*, Target, int32, Amount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAllHealDelegate, int32, Amount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealDelegate, ACard*, Target, int32, Amount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEnhanceDelegate, ACard*, Target, ESpellEffectType, Buff);

class ACard;
UCLASS()
class TCG_API USpellCardData : public UCardData
{
	GENERATED_BODY()

public:
	//Delegate 변수들
	FOnAllDamageDelegate OnAllDamageDelegate;
	FOnDamageDelegate OnDamageDelegate;
	FOnAllHealDelegate OnAllHealDelegate;
	FOnHealDelegate OnHealDelegate;
	FOnEnhanceDelegate OnEnhanceDelegate;

	//Spell Card Data
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpellCardData")
	FString EffectDescription;		//효과 설명

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpellCardData")
	ESpellEffectType EffectType;	//효과 유형

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpellCardData")
	ESpellTargetType TargetType;	//타겟 유형

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpellCardData")
	int32 EffectAmount;				//효과 강도

	//효과에 따른 BroadCast
	virtual void ApplyEffect_Implementation(ACard* Target) override;

protected:
	void ApplyDamageEffect(ACard* Target);
	void ApplyHealEffect(ACard* Target);
	void ApplyBuffEffect(ACard* Target);
	void ApplyDebuffEffect(ACard* Target);
};
