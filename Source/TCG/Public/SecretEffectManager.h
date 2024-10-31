// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardData.h"
#include "GameFramework/Actor.h"
#include "SecretEffectManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHeroAttacked);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMinionSummoned);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnManaCostCardPlayed);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDamageDelegate, ACard*, Inisiator);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSummonDelegate, AHand*, SummonedMinion);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSpellDelegate, ACard*, Inisiator, UCardData*, CardData);

class USecretCardData;
UCLASS()
class TCG_API ASecretEffectManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASecretEffectManager();

	//Secret 카드 리스트 배열(전체가 아니고 게임 중에 생긴 Secret 배열)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Secret")
	TArray<USecretCardData*> ActiveSecrets;

	//델리게이트로 선언 -> Secret 발동되었음을 알림
	UPROPERTY(BlueprintAssignable, Category="Secret")
	FOnHeroAttacked OnHeroAttacked;
	UPROPERTY(BlueprintAssignable, Category="Secret")
	FOnMinionSummoned OnMinionSummoned;
	UPROPERTY(BlueprintAssignable, Category="Secret")
	FOnManaCostCardPlayed OnManaCostCardPlayed;

	//Secret 카드 조건 검사 함수
	UFUNCTION()
	void CheckAndTriggerSecrets(FString EventName, AActor* Target);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UFUNCTION()
	void SummonMinionEvent(ACard* Target);

};
