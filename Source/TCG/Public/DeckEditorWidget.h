// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DeckEditorWidget.generated.h"

/**
 * 
 */
class ADeck;
class UDeckEditorWidget;
class UCardWidget;
class UOverlay;
class UGridPanel;
class UUniformGridPanel;

UCLASS()
class TCG_API UDeckEditorWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	//TArray<ACard*> DeckCards;

	//UPROPERTY(meta=(BindWidget))
	//UOverlay* Overlay;
	float bIsEditorOpen = false;

	UPROPERTY(meta=(BindWidget))
	UUniformGridPanel* GridPanel;
	
	//UPROPERTY(EditAnywhere, Category="CardWidget")
	//TSubclassOf<UCardWidget> CardWidgetClass;

	UFUNCTION()
	void OpenDeckEditor();
	
	UFUNCTION()
	void DisplayCardFromDeck(ADeck* Deck, TSubclassOf<UCardWidget> CardWidgetClass);

};
