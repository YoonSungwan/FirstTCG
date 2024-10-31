// Fill out your copyright notice in the Description page of Project Settings.


#include "TCG/Public/MinionCardData.h"

#include "AsyncTreeDifferences.h"

void UMinionCardData::ApplyEffect_Implementation(AActor* Target)
{
	//하수인 고유 효과
	if(!Target) return;

	switch(MinionEffectType)
	{
		case EMinionEffectType::Battlecry:
			ApplyBattlecryEffect(Target);
			break;
		case EMinionEffectType::Deathrattle:
			ApplyDeathrattleEffect(Target);
			break;
		case EMinionEffectType::Windfury:
			ApplyWindfuryEffect(Target);
			break;
		case EMinionEffectType::Taunt:
			ApplyTauntEffect(Target);
			break;
		case EMinionEffectType::DivineShield:
			ApplyDivineShieldEffect(Target);
			break;
		default:
			break;
	}
}

void UMinionCardData::ApplyBattlecryEffect(AActor* Target)
{
}

void UMinionCardData::ApplyDeathrattleEffect(AActor* Target)
{
}

void UMinionCardData::ApplyWindfuryEffect(AActor* Target)
{
}

void UMinionCardData::ApplyTauntEffect(AActor* Target)
{
}

void UMinionCardData::ApplyDivineShieldEffect(AActor* Target)
{
}


void UMinionCardData::AffectBuff(EStatusBuff Buff)
{
	this->StatusBuff = Buff;
}

void UMinionCardData::AffectDebuff(EStatusDebuff Debuff)
{
	if(this->StatusDebuff == Debuff)
	{
		SetEnhanceHealth(-3);
	}
	else
	{
		this->StatusDebuff = Debuff;	
	}
}


void UMinionCardData::SetEnhancePower(int32 Amount)
{
	this->AttackPower += Amount;
}

void UMinionCardData::SetEnhanceHealth(int32 Amount)
{
	this->Health += Amount;
}

void UMinionCardData::SetEnhanceShield(int32 Amount)
{
	this->Shield += Amount;
}

