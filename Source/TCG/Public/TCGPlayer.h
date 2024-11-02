// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "TCGPlayer.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHitPlayer);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealedPlayer);

class ADeck;
class UHand;
UCLASS()
class TCG_API ATCGPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATCGPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TCGPlayer")
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TCGPlayer")
	class USkeletalMeshComponent* SkeletalMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TCGPlayer")
	class USpringArmComponent* SpringArmComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TCGPlayer")
	class UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TCGPlayer")
	int32 Health;

	UPROPERTY()
	FOnHitPlayer OnHitPlayer;

	UPROPERTY()
	FOnHealedPlayer OnHealedPlayer;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* InputMapping;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* ClickInputAction;

	UHand* Hand;	

	//타일을 선택하는 함수
	void CardClick(const FInputActionValue& Value); 
};
