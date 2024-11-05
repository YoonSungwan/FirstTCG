// Fill out your copyright notice in the Description page of Project Settings.


#include "DeckEditorWidget.h"
#include "Deck.h"
#include "Card.h"
#include "CardWidget.h"
#include "Components/Overlay.h"

void UDeckEditorWidget::InitializeDeck()
{
	
}

void UDeckEditorWidget::DisplayCardFromDeck(ADeck* Deck)
{
	if(Deck != nullptr && Overlay)
	{
		UCardWidget* CardWidget = CreateWidget<UCardWidget>(this, CardWidgetClass);
		if(CardWidget)
		{
			TArray<ACard*> Cards = Deck->GetDeck();

			for(ACard* Card : Cards)
			{
				CardWidget->SetCardData(Card->CardData);
				Overlay->AddChild(CardWidget);
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("DeckEditorWidget : CardWidget is not Setting"));
		}
	}
}
