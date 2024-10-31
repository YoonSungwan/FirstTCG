// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TCGPlayer.generated.h"

class ATCGGameMode;
class AHand;
class ADeck;

//데미지를 받았을 때
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHitPlayer, ATCGPlayer*, HitPlayer);
//회복했을 때
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealedPlayer, ATCGPlayer*, HealedPlayer);

UCLASS()
class TCG_API ATCGPlayer : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATCGPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FOnHitPlayer OnHitPlayer;
	FOnHealedPlayer OnHealedPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TCGPlayer")
	int32 Health;
	
	ATCGGameMode* GameMode;
	ADeck* Deck;
	AHand* Hand;
	
};
