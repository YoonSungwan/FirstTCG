// Fill out your copyright notice in the Description page of Project Settings.


#include "TCGPlayer.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/SpringArmComponent.h"
#include "Deck.h"
#include "Card.h"
#include "CardData.h"

// Sets default values
ATCGPlayer::ATCGPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Health = 20;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);
	//SpringArmComp->SetRelativeLocationAndRotation(FVector(0, 0, 50), FRotator(-20, 0, 0));
	SpringArmComp->TargetArmLength = 250;
	SpringArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);
	//CameraComp->SetRelativeLocation(FVector(0.f, 0.f, 0.0f));
	CameraComp->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void ATCGPlayer::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	
	if(APlayerController* PlayerController = Cast<APlayerController>(GetWorld()->GetFirstPlayerController()))
	{
		//UEnhancedInputLocalPlayerSubSystem* SubSystem = UEnhancedInputLocalPlayerSubSystem::Get();
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if(Subsystem)
		{
			//우선순위 0으로 설정
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}
}

// Called every frame
void ATCGPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATCGPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if(UEnhancedInputComponent* EnhancedInputCompo = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputCompo->BindAction(ClickInputAction, ETriggerEvent::Started, this, &ATCGPlayer::CardClick);
	}
}

void ATCGPlayer::CardClick(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Click Event"));

	FHitResult Hit;
	GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if(Hit.bBlockingHit)
	{
		ADeck* ClickedDeck = Cast<ADeck>(Hit.GetActor());

		if(ClickedDeck)
		{
			TArray<ACard*> Cards = ClickedDeck->GetDeck();
			for(ACard* Card : Cards)
			{
				UE_LOG(LogTemp, Warning, TEXT("Click Card Name : %s"), *Card->CardData->CardName);
			}
		}
	}
}

