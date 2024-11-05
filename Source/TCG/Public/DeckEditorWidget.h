// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DeckEditorWidget.generated.h"

/**
 * 
 */
class ADeck;
class UCardWidget;
class UOverlay;

UCLASS()
class TCG_API UDeckEditorWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	//TArray<ACard*> DeckCards;
	
	void InitializeDeck();

	UPROPERTY(meta=(BindWidget))
	UOverlay* Overlay;
	
	UPROPERTY(EditAnywhere, Category="CardWidget")
	TSubclassOf<UCardWidget> CardWidgetClass;

	UFUNCTION()
	void DisplayCardFromDeck(ADeck* Deck);

};
