// Fill out your copyright notice in the Description page of Project Settings.


#include "CardWidget.h"
#include "CardData.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UCardWidget::SetCardData(const UCardData* CardData)
{
	if(!CardData)
	{
		UE_LOG(LogTemp, Warning, TEXT("CardWidget : No Card Data...."));
		return;
	}
	
	CardName->SetText(FText::FromString(CardData->CardName));
	ManaCost->SetText(FText::FromString(FString::FromInt(CardData->ManaCost)));
	CardImage->SetBrushFromTexture(CardData->CardTexture);
}
