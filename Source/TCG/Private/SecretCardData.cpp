// Fill out your copyright notice in the Description page of Project Settings.


#include "TCG/Public/SecretCardData.h"

bool USecretCardData::IsConditionMet(const FString& EventName)
{
	//추후 Enum 혹은 DataTable로 만들자
	
	if(EventName == "HeroAttacked" && CardName == "Explosive Trap")
	{
		return true;
	}

	//같은 카드가 여러 개일 수도 있으니 else if 말고 별개의 if
	if(EventName == "HeroAttacked" && CardName == "Explosive Trap")
	{
		return true;
	}
	
	return false;
}

void USecretCardData::ActivateSecret(ACard* Target)
{
	UE_LOG(LogTemp, Warning, TEXT("Secret Activated : %s"), *CardName);
	//Secret 카드 고유 효과 구현
	if(!Target)
	{
		return;
	}
	switch(EffectType)
	{
		case ESecretEffectType::DamageEnemyHero :
			break;
		case ESecretEffectType::SummonMinions :
			break;
		case ESecretEffectType::CounterSpell :
			break;
		case ESecretEffectType::ProtectFriendlyHero :
			break;
		case ESecretEffectType::DamageAllEnemies :
			break;
		default:
			break;
	}
}

void USecretCardData::ApplyEffect_Implementation(ACard* Target)
{
	Super::ApplyEffect_Implementation(Target);
}
