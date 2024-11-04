// Fill out your copyright notice in the Description page of Project Settings.


#include "TCG/Public/CardData.h"

void UCardData::ApplyEffect_Implementation(AActor* Target)
{
	UE_LOG(LogTemp, Log, TEXT("%s: 기본효과 적용"), *CardName);
	
}
