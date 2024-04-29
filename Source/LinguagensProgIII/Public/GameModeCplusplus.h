// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ControllerCplusplus.h"
#include "GameModeCplusplus.generated.h"

/**
 * 
 */
UCLASS()
class LINGUAGENSPROGIII_API AGameModeCplusplus : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AGameModeCplusplus();

	virtual void StartPlay() override;

};
