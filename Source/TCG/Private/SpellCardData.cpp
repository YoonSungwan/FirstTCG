// Fill out your copyright notice in the Description page of Project Settings.


#include "TCG/Public/SpellCardData.h"

#include "CardEffectManager.h"

/*int32 USpellCardData::AttackDamage(ACard* Card)
{
	return 0;
}*/

void USpellCardData::ApplyEffect_Implementation(ACard* Target)
{
	Super::ApplyEffect_Implementation(Target);

	switch(EffectType)
	{
		case ESpellEffectType::Damage:
			ApplyDamageEffect(Target);
			break;
		case ESpellEffectType::Heal:
			ApplyHealEffect(Target);
			break;
		case ESpellEffectType::Buff:
			ApplyBuffEffect(Target);
			break;
		case ESpellEffectType::Debuff:
			ApplyDebuffEffect(Target);
			break;
		default:
			break;
	}
}

void USpellCardData::ApplyDamageEffect(ACard* Target)
{
	switch (TargetType)
	{
		case ESpellTargetType::SingleEnemy:
			if(Target)
			{
				OnDamageDelegate.Broadcast(Target, EffectAmount);
			}
			break;
		case ESpellTargetType::AllEnemies:
			if(Target)
			{
				OnAllDamageDelegate.Broadcast(EffectAmount);
			}
			break;
		/*
		 * 자해
		 */
		default:
			break;
	}
}

void USpellCardData::ApplyHealEffect(ACard* Target)
{
	switch (TargetType)
	{
	case ESpellTargetType::SingleAlly:
		if(Target)
		{
			OnHealDelegate.Broadcast(Target, EffectAmount);
		}
		break;
	case ESpellTargetType::AllAllies:
		if(Target)
		{
			OnAllHealDelegate.Broadcast(EffectAmount);
		}
		break;
	case ESpellTargetType::Self:
		if(Target)
		{
			OnHealDelegate.Broadcast(Target, EffectAmount);
		}
		break;
	default:
		break;
	}
}

void USpellCardData::ApplyBuffEffect(ACard* Target)
{
}

void USpellCardData::ApplyDebuffEffect(ACard* Target)
{
}
