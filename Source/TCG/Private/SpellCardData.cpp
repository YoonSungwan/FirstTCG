// Fill out your copyright notice in the Description page of Project Settings.


#include "TCG/Public/SpellCardData.h"

/*int32 USpellCardData::AttackDamage(ACard* Card)
{
	return 0;
}*/

void USpellCardData::ApplyEffect_Implementation(AActor* Target)
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

void USpellCardData::ApplyDamageEffect(AActor* Target)
{
	switch (TargetType)
	{
		case ESpellTargetType::SingleEnemy:
			if(Target)
			{
				
			}
			break;
		case ESpellTargetType::AllEnemies:
			if(Target)
			{
				
			}
			break;
		default:
			break;
	}
}

void USpellCardData::ApplyHealEffect(AActor* Target)
{
	switch (TargetType)
	{
	case ESpellTargetType::SingleAlly:
		if(Target)
		{
				
		}
		break;
	case ESpellTargetType::AllAllies:
		if(Target)
		{
				
		}
		break;
	case ESpellTargetType::Self:
		if(Target)
		{
				
		}
		break;
	default:
		break;
	}
}

void USpellCardData::ApplyBuffEffect(AActor* Target)
{
}

void USpellCardData::ApplyDebuffEffect(AActor* Target)
{
}
