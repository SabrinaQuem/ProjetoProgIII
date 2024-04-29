// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeCplusplus.h"
#include "ControllerCplusplus.h"

AGameModeCplusplus::AGameModeCplusplus()
{
    // Set the default player controller class
    PlayerControllerClass = AControllerCplusplus::StaticClass();
}

void AGameModeCplusplus::StartPlay()
{
    Super::StartPlay();

}