// Fill out your copyright notice in the Description page of Project Settings.


#include "SecretEffectManager.h"
#include "SecretCardData.h"
#include "SpellCardData.h"

// Sets default values
ASecretEffectManager::ASecretEffectManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
}

void ASecretEffectManager::CheckAndTriggerSecrets(FString EventName, AActor* Target)
{
	for(USecretCardData* Secret : ActiveSecrets)
	{
		//for문이 길어지면 FString 대신 FName도 고려
		if(Secret && Secret->IsConditionMet(EventName))
		{
			Secret->ActivateSecret(Target);
			ActiveSecrets.Remove(Secret);
			//break 하고 이후 애니메이션 재생 등의 로직 우선 처리
			break;
		}
	}
}

// Called when the game starts or when spawned
void ASecretEffectManager::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASecretEffectManager::SummonMinionEvent(ACard* Target)
{
}
