// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameRule.h"
#include "GameField.generated.h"

class ATCGGameMode;
class ACard;
class ACardGrave;
class ADeck;
class ATCGPlayer;

//카드가 발동했을 때
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActivateCard, ACard*, ActivatedCard);
//카드가 묘지로 보내졌을 때
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSendCardToGrave, ACard*, SendCardToGrave);
//플레이어를 대상으로 하는 카드가 발동했을 때
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTargetPlayer, ATCGPlayer*, TargetPlayer, ACard*, ActivatedCard);

UCLASS()
class TCG_API AGameField : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGameField();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FOnActivateCard OnActivateCard;
	FOnSendCardToGrave OnSendCardToGrave;
	FOnTargetPlayer OnTargetPlayer;

	int32 CardSlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gamemode")
	ATCGGameMode* GameMode;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Field")
	TArray<ACard*> CardOnField;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grave")
	ACardGrave* Grave;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Deck")
	ADeck* Deck;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player")
	ATCGPlayer* GamePlayer;
	
	bool IsSlotFull() const;

	void ActivateCard(ATCGPlayer* TargetPlayer,ACard* Card);

	void SalvageCard(ACard* Card);
};