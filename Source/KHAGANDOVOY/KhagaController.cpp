// Fill out your copyright notice in the Description page of Project Settings.

#include "KhagaController.h"

AKhagaController::AKhagaController() {}

void AKhagaController::BeginPlayingState()
{
	Super::BeginPlayingState();
	SetState(EState::NONE);
}

void AKhagaController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EState"), true);
	Print("State: " + EnumPtr->GetNameStringByIndex(static_cast<int32>(CurrentState)), DeltaSeconds, BLUE);
}

void AKhagaController::SetState(EState State)
{
	CurrentState = State;
	this->InputComponent->AxisBindings.Empty();
	this->InputComponent->ClearActionBindings();
	OnStateChanged.Broadcast(CurrentState);
	switch(State)
	{
	case EState::LOOKINGFORTARGET:
		this->InputComponent->BindAxis("MoveForward", this, &AKhagaController::MoveForward);
		this->InputComponent->BindAxis("MoveRight", this, &AKhagaController::MoveRight);
		this->InputComponent->BindAction("Interact", EInputEvent::IE_Released, this, &AKhagaController::Interact);
		this->InputComponent->BindAction("Fart", EInputEvent::IE_Released, this, &AKhagaController::Fart);
		break;
	case EState::HOMERUN:
		this->InputComponent->BindAxis("MoveForward", this, &AKhagaController::MoveForwardShit);
		this->InputComponent->BindAxis("MoveRight", this, &AKhagaController::MoveRightShit);
		break;
	}
}

EState AKhagaController::GetCurrentState()
{
	return CurrentState;
}
