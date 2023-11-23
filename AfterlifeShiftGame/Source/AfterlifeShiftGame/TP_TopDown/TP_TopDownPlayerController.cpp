// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP_TopDownPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "TP_TopDownCharacter.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

ATP_TopDownPlayerController::ATP_TopDownPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	CachedDestination = FVector::ZeroVector;
	FollowTime = 0.f;
}

void ATP_TopDownPlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void ATP_TopDownPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Setup mouse input events
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Started, this,
		                                   &ATP_TopDownPlayerController::OnInputStarted);
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Triggered, this,
		                                   &ATP_TopDownPlayerController::OnSetDestinationTriggered);
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Completed, this,
		                                   &ATP_TopDownPlayerController::OnSetDestinationReleased);
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Canceled, this,
		                                   &ATP_TopDownPlayerController::OnSetDestinationReleased);

		// Setup touch input events
		EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Started, this,
		                                   &ATP_TopDownPlayerController::OnInputStarted);
		EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Triggered, this,
		                                   &ATP_TopDownPlayerController::OnTouchTriggered);
		EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Completed, this,
		                                   &ATP_TopDownPlayerController::OnTouchReleased);
		EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Canceled, this,
		                                   &ATP_TopDownPlayerController::OnTouchReleased);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error,
		       TEXT(
			       "'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."
		       ), *GetNameSafe(this));
	}
}

void ATP_TopDownPlayerController::OnInputStarted()
{
	StopMovement();
}

// Triggered every frame when the input is held down
void ATP_TopDownPlayerController::OnSetDestinationTriggered()
{
	//Convert screen location to world space
	FVector WorldLocation;
	FVector WorldDirection;
	DeprojectMousePositionToWorld(WorldLocation, WorldDirection);

	//log the world location
	UE_LOG(LogTemp, Warning, TEXT("World Location: %s"), *WorldLocation.ToString());

	//raycast from the mouse cursor to see if we hit anything
	FHitResult HitResult;
	FVector StartPoint = WorldLocation;
	FVector EndPoint = WorldLocation + WorldDirection * 10000.f;
	GetWorld()->LineTraceSingleByChannel(HitResult, StartPoint, EndPoint, ECC_WorldStatic);
	
	//log start and end point
	UE_LOG(LogTemp, Warning, TEXT("Start Point: %s"), *StartPoint.ToString());
	UE_LOG(LogTemp, Warning, TEXT("End Point: %s"), *EndPoint.ToString());
	if (HitResult.bBlockingHit)
	{
		//log the name of the actor we hit
		UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *HitResult.GetActor()->GetName());
	}
}

void ATP_TopDownPlayerController::OnSetDestinationReleased()
{
	// If it was a short press
	if (FollowTime <= ShortPressThreshold)
	{
		/*// We move there and spawn some particles
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CachedDestination);
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, CachedDestination, FRotator::ZeroRotator,
		                                               FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);*/
	}

	FollowTime = 0.f;
}

// Triggered every frame when the input is held down
void ATP_TopDownPlayerController::OnTouchTriggered()
{
	bIsTouch = true;
	OnSetDestinationTriggered();
}

void ATP_TopDownPlayerController::OnTouchReleased()
{
	bIsTouch = false;
	OnSetDestinationReleased();
}
