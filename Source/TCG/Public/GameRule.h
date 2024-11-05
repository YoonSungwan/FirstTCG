// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EGamePhase : uint8
{
	GameStart,
	TurnStart,
	CardDraw,
	SummonMinion,
	CastSpell,
	TurnEnd,
	GameEnd
};

UENUM(BlueprintType)
enum class ECardType : uint8
{
	Minion,
	Spell,
	Secret
};

class TCG_API GameRule
{
public:
	GameRule();
	~GameRule();

	EGamePhase GameRuleTest;
};
