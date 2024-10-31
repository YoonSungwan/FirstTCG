// Fill out your copyright notice in the Description page of Project Settings.


#include "TCGGameMode.h"

void ATCGGameMode::BeginPlay()
{
	Super::BeginPlay();
	
}

EGamePhase ATCGGameMode::GetCurrentPhase() const
{
	return CurrentPhase;
}

void ATCGGameMode::SetCurrentPhase(EGamePhase NewPhase)
{
	if(CurrentPhase != NewPhase)
	{
		CurrentPhase = NewPhase;

		switch(CurrentPhase)
		{
			case EGamePhase::GameStart :
				HandleGameStartPhase();
				break;
			case EGamePhase::TurnStart :
				HandleTurnStartPhase();
				break;
			case EGamePhase::CardDraw :
				HandleCardDrawPhase();
				break;
			case EGamePhase::SummonMinion :
				HandleSummonMinionPhase();
				break;
			case EGamePhase::CastSpell :
				HandleCastSpellPhase();
				break;
			case EGamePhase::TurnEnd :
				HandleTurnEndPhase();
				break;
			case EGamePhase::GameEnd :
				HandleGameEndPhase();
				break;
			default:
				break;
		}
	}
}

void ATCGGameMode::HandleGameStartPhase()
{
	//선후공카드
	//Set
	OnTurnStart.Broadcast();
	SetCurrentPhase(EGamePhase::TurnStart);
}

void ATCGGameMode::HandleTurnStartPhase()
{
	SetCurrentPhase(EGamePhase::CardDraw);
}

void ATCGGameMode::HandleCardDrawPhase()
{
	OnCardDraw.Broadcast();
	SetCurrentPhase(EGamePhase::SummonMinion);
}

void ATCGGameMode::HandleSummonMinionPhase()
{
	SetCurrentPhase(EGamePhase::CastSpell);
}

void ATCGGameMode::HandleCastSpellPhase()
{
	SetCurrentPhase(EGamePhase::TurnEnd);
}

void ATCGGameMode::HandleTurnEndPhase()
{
	OnTurnEnd.Broadcast();
	SetCurrentPhase(EGamePhase::TurnStart);
}

void ATCGGameMode::HandleGameEndPhase()
{
}
