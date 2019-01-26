// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KHAGANDOVOY.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class KHAGANDOVOY_API UFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		static EDirectionMovement SetDirection(FVector2D NormalizedVelocity);
protected:
	static float FindDeltaAngle(float A, float B);
};

