// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"
#include "Runtime/Engine/Classes/Components/ArrowComponent.h"
#include "KhagarPoint.generated.h"

UENUM(BlueprintType)
enum class ETargetPoint : uint8 {
	NONE,
	TRUNK,
	BARRIER,
	UFO,
	DOG,
	FORTASEC
};


/**
 * 
 */
UCLASS()
class KHAGANDOVOY_API AKhagarPoint : public ATargetPoint
{
	GENERATED_BODY()
public:
	AKhagarPoint();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ETargetPoint TargetPointType;

};
