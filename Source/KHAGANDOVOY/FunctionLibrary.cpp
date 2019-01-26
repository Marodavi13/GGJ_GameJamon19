// Fill out your copyright notice in the Description page of Project Settings.

#include "FunctionLibrary.h"

EDirectionMovement UFunctionLibrary::SetDirection(FVector2D NormalizedVelocity)
{
	float Angle = FMath::RadiansToDegrees(FMath::Acos(FVector2D::DotProduct(NormalizedVelocity, FVector2D(1.f, 0.f))));
	float CrossProduct = FVector::CrossProduct(FVector::ForwardVector, FVector(NormalizedVelocity, 0)).Z;
	EDirectionMovement Return = EDirectionMovement::NONE;
	if (CrossProduct < 0)
	{
		Angle = 360.f - Angle;
	}
	bool bDirectionDetected = false;
	int8 Counter = -1;
	float BaseAngle = -22.5;
	float Ceilangle = BaseAngle + 45.f;
	float Total;

	

	while (!bDirectionDetected)
	{
		++Counter;
		Total = FMath::Abs((FMath::FindDeltaAngleDegrees(Angle, BaseAngle))) + FMath::Abs(FMath::FindDeltaAngleDegrees(Angle, Ceilangle));
		if (Total <= 45.f)
		{
			/*Print("Total: " + FString::SanitizeFloat(Total), 1.f, RED);


			Print("Delta: " + FString::SanitizeFloat(FMath::Abs((FMath::FindDeltaAngleDegrees(Angle, Ceilangle)))), 1.f, RED);
			Print("Ceil: " + FString::SanitizeFloat(Ceilangle), 1.f, RED);
			Print("Delta: " + FString::SanitizeFloat(FMath::Abs((FMath::FindDeltaAngleDegrees(Angle, BaseAngle)))), 1.f, RED);
			Print("Base: " + FString::SanitizeFloat(BaseAngle), 1.f, RED);

			Print("Angle: " + FString::SanitizeFloat(Angle), 1.f, RED);*/

		

			bDirectionDetected = true;
		}
		else
		{
			BaseAngle += 45.f;
			Ceilangle += 45.f;
			/*if(BaseAngle > 360.f)
			{
				BaseAngle -= 360.f;
			}
			if (Ceilangle > 360.f)
			{
				Ceilangle -= 360.f;
			}*/
		}
	}

	switch (Counter)
	{
	case (0):
		Return = EDirectionMovement::UP;
		break;
	case (1):
		Return = EDirectionMovement::UPRIGHT;
		break;
	case (2):
		Return = EDirectionMovement::RIGHT;
		break;
	case (3):
		Return = EDirectionMovement::DOWNRIGHT;
		break;
	case (4):
		Return = EDirectionMovement::DOWN;
		break;
	case (5):
		Return = EDirectionMovement::DOWNLEFT;
		break;
	case (6):
		Return = EDirectionMovement::LEFT;
		break;
	case (7):
		Return = EDirectionMovement::UPLEFT;
		break;
	default:
		Return = EDirectionMovement::NONE;

	}
	return Return;
}

float UFunctionLibrary::FindDeltaAngle(float A, float B)
{
	if (A < 0 && B < 0)
	{
		return FMath::Abs(A + B);
	}
	else if (A >= 0 && B < 0)
	{
		return A - B;
	}
	else if (A < 0 && B >= 0)
	{
		return B - A;
	}
	else if (A >= 0 && B >= 0)
	{
		return FMath::Abs(A - B);
	}
	return 0;
}
