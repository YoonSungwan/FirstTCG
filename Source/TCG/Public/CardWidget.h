// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CardWidget.generated.h"

/**
 * 
 */
class UCardData;
class UImage;
class UTextBlock;

UCLASS()
class TCG_API UCardWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	//카드 이름
	UPROPERTY(meta = (BindWidget))
	UTextBlock* CardName;

	//카드 수량
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ManaCost;

	//카드 이미지
	UPROPERTY(meta = (BindWidget))
	UImage* CardImage;

public:
	UFUNCTION(BlueprintCallable, Category = "CardData")
	void SetCardData(const UCardData* CardData);
	
};
