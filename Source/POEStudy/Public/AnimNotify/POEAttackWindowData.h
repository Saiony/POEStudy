// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "POEAttackWindowData.generated.h"

enum class EAttackTraceShape : uint8;
/**
 * 
 */
UCLASS()
class POESTUDY_API UPOEAttackWindowData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName Socket;

	UPROPERTY()
	EAttackTraceShape TraceShape;

	UPROPERTY()
	float TraceSize;

	void Init(const FName InSocket, const EAttackTraceShape InTraceShape, const float InTraceSize)
	{
		Socket = InSocket;
		TraceShape = InTraceShape;
		TraceSize = InTraceSize;
	}
};
