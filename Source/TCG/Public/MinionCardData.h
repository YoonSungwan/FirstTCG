// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardData.h"
#include "MinionCardData.generated.h"

UENUM(BlueprintType)
enum class EStatusBuff : uint8
{
	Normal,
	Burning,
	Frozen,
	Hiding,
	Invincibility,
};

UENUM(BlueprintType)
enum class EStatusDebuff : uint8
{
	Normal,
	Burning,
	Frozen,
	Hiding,
	Invincibility,
};

//많으면 데이터 테이블
UENUM(BlueprintType)
enum class EMinionEffectType : uint8
{
	Battlecry,		//소환 시 발동
	Deathrattle,	//사망 시 발동
	Windfury,		//1턴에 두 번 공격
	Taunt,			//도발
	DivineShield,	//첫 피해 무효화
};
/**
 * 
 */
UCLASS()
class TCG_API UMinionCardData : public UCardData
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MinionCardData")
	int32 AttackPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MinionCardData")
	int32 Health;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MinionCardData")
	int32 Shield;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MinionCardData")
	EStatusBuff StatusBuff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MinionCardData")
	EStatusDebuff StatusDebuff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MinionCardData")
	EMinionEffectType MinionEffectType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MinionCardData")
	int32 EffectAmount;

	virtual void ApplyEffect_Implementation(AActor* Target) override;

protected:

	void ApplyBattlecryEffect(AActor* Target);
	void ApplyDeathrattleEffect(AActor* Target);
	void ApplyWindfuryEffect(AActor* Target);
	void ApplyTauntEffect(AActor* Target);
	void ApplyDivineShieldEffect(AActor* Target);
	
	void AffectBuff(EStatusBuff Buff);
	void AffectDebuff(EStatusDebuff Debuff);
	void SetEnhancePower(int32 Amount);
	void SetEnhanceHealth(int32 Amount);
	void SetEnhanceShield(int32 Amount);
};
