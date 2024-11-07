// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ActivateCardInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UActivateCardInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TCG_API IActivateCardInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void ActivateCard(AActor* Actor) = 0;
};
