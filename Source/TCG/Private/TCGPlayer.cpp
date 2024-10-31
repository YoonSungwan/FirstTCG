// Fill out your copyright notice in the Description page of Project Settings.


#include "TCGPlayer.h"
#include "TCG/Public/Card.h"

// Sets default values
ATCGPlayer::ATCGPlayer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Health = 20;
}

// Called when the game starts or when spawned
void ATCGPlayer::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void ATCGPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

