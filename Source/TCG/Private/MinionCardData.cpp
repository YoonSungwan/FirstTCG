// Fill out your copyright notice in the Description page of Project Settings.


#include "TCG/Public/MinionCardData.h"
#include "Card.h"

void UMinionCardData::ApplyEffect_Implementation(ACard* Target)
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

void UMinionCardData::ApplyBattlecryEffect(ACard* Target)
{
}

void UMinionCardData::ApplyDeathrattleEffect(ACard* Target)
{
}

void UMinionCardData::ApplyWindfuryEffect(ACard* Target)
{
}

void UMinionCardData::ApplyTauntEffect(ACard* Target)
{
}

void UMinionCardData::ApplyDivineShieldEffect(ACard* Target)
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

