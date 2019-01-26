// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "KHAGANDOVOY.h"
#include "KhagaController.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EState : uint8 {
	NONE,					//Disabled
	STANDARD,				//Standard movement
	SHITTING
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStateChanged, EState, State);


UCLASS()
class KHAGANDOVOY_API AKhagaController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AKhagaController();
	virtual void BeginPlayingState() override;
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable)
		void SetState(EState State);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		EState GetCurrentState();
	//INPUTS

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void MoveForward(float Value);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void MoveRight(float Value);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void MoveForwardShit(float Value);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void MoveRightShit(float Value);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void Fart();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void Interact();

	FOnStateChanged OnStateChanged;


private:
	EState CurrentState;
};
