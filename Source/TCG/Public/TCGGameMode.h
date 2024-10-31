// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameRule.h"
#include "TCGGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameStateDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTurnStateDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSummonPhaseDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSpellPhaseDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTurnEndDelegate);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTurnStart);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTurnEnd);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCardDraw);

/**
 * 
 */
UCLASS()
class TCG_API ATCGGameMode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

public:

	FOnGameStateDelegate GameStateDelegate;
	FOnTurnStateDelegate TurnStateDelegate;
	FOnSummonPhaseDelegate SummonPhaseDelegate;
	FOnSpellPhaseDelegate SpellPhaseDelegate;
	FOnTurnEndDelegate TurnEndDelegate;

	FOnTurnStart OnTurnStart;
	FOnCardDraw OnCardDraw;
	FOnTurnEnd OnTurnEnd;

	EGamePhase GetCurrentPhase() const;

	void SetCurrentPhase(EGamePhase NewPhase);
	
private:
	EGamePhase CurrentPhase;

	void HandleGameStartPhase();
	void HandleTurnStartPhase();
	void HandleCardDrawPhase();
	void HandleSummonMinionPhase();
	void HandleCastSpellPhase();
	void HandleTurnEndPhase();
	void HandleGameEndPhase();
};
