// Fill out your copyright notice in the Description page of Project Settings.


#include "DeckEditorWidget.h"
#include "Deck.h"
#include "Card.h"
#include "CardWidget.h"
#include "Components/UniformGridPanel.h"

void UDeckEditorWidget::OpenDeckEditor()
{
	UE_LOG(LogTemp, Display, TEXT("Open Deck Editor..."));
	AddToViewport();

	bIsEditorOpen = true;
}

void UDeckEditorWidget::DisplayCardFromDeck(ADeck* Deck, TSubclassOf<UCardWidget> CardWidgetClass)
{
	//Deck != nullptr && 
	if(CardWidgetClass)
	{
		TArray<ACard*> Cards = Deck->GetDeck();

		for(int32 i=0; i<Cards.Num(); ++i)
		{
			UCardWidget* CardWidget = CreateWidget<UCardWidget>(this, CardWidgetClass);
			ACard* Card = Cards[i];
			
			CardWidget->SetCardData(Card->CardData);
			GridPanel->AddChildToUniformGrid(CardWidget, i/4, i%4);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("DeckEditorWidget : CardWidgetClass is not Setting"));
	}
}
