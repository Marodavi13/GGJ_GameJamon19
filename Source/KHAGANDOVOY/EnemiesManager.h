// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemiesManager.generated.h"

class AKhagarPoint;
USTRUCT(BlueprintType)
struct FEnemyData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float					InitialPercentage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float					PercentagePerSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32					RepeatEveryXRounds;
};
UCLASS()
class KHAGANDOVOY_API AEnemiesManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemiesManager();
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintImplementableEvent)
		void MoveTrunks();
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
		void SpawnEnemies();
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FEnemyData BarrierData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FEnemyData UFOData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FEnemyData FortasecData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FEnemyData DogData;
	UPROPERTY(BlueprintReadOnly)
		uint8	NumberOfRounds;

	UPROPERTY(BlueprintReadOnly)
		TArray<AKhagarPoint*> TrunkPoints;
	UPROPERTY(BlueprintReadOnly)
		TArray<AKhagarPoint*> DogPoints;
	UPROPERTY(BlueprintReadOnly)
		TArray<AKhagarPoint*> UFOPoints;
	UPROPERTY(BlueprintReadOnly)
		TArray<AKhagarPoint*> BarrierPoints;

};
