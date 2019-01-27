// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemiesManager.h"
#include "KhagarPoint.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
// Sets default values
AEnemiesManager::AEnemiesManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemiesManager::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*> KhagarPoints;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AKhagarPoint::StaticClass(), KhagarPoints);
	for (AActor* Point : KhagarPoints)
	{
		AKhagarPoint* KP = Cast<AKhagarPoint>(Point);

		switch (KP->TargetPointType)
		{
		case ETargetPoint::BARRIER:
			BarrierPoints.AddUnique(KP);
			break;
		case ETargetPoint::DOG:
			DogPoints.AddUnique(KP);
			break;
		case ETargetPoint::TRUNK:
			TrunkPoints.AddUnique(KP);
		case ETargetPoint::UFO:
			UFOPoints.AddUnique(KP);
			break;
		case ETargetPoint::FORTASEC:
			FortasecPoints.AddUnique(KP);
		default: break;
		}
	}
	MoveTrunks();
	SpawnEnemies();
}

// Called every frame
void AEnemiesManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

