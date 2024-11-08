// Fill out your copyright notice in the Description page of Project Settings.


#include "CardEffectManager.h"
#include "Card.h"
#include "CardData.h"
#include "MinionCardData.h"

void UCardEffectManager::BindCardEffect(UCardData* CardData)
{
	if(CardData)
	{
		//CardData->OnCardTriggered.AddDynamic(this, &UCardEffectManager::TriggerCardEffect);
	}
}

void UCardEffectManager::TriggerCardEffect(ACard* Actor)
{
	ACard* Card = Cast<ACard>(Actor);
	if(Card && Card->CardData)
	{
		Card->CardData->ApplyEffect(Actor);
	}
}

void UCardEffectManager::DamageToCard(ACard* Actor, int32 Amount)
{
	ACard* Card = Cast<ACard>(Actor);
	if(Card)
	{
		UMinionCardData* MinionData = Cast<UMinionCardData>(Card->CardData);
		if(MinionData)
		{
			MinionData -= Amount;	
		}
	}
}

void UCardEffectManager::HealToCard(ACard* Actor, int32 Amount)
{ACard* Card = Cast<ACard>(Actor);
	if(Card)
	{
		UMinionCardData* MinionData = Cast<UMinionCardData>(Card->CardData);
		if(MinionData)
		{
			MinionData += Amount;	
		}
	}
}

void UCardEffectManager::EnhancePower(ACard* Actor, int32 Amount)
{
}

void UCardEffectManager::WeakenPower(ACard* Actor, int32 Amount)
{
}
