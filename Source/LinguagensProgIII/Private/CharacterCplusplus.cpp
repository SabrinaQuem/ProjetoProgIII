// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterCplusplus.h"

// Sets default values
ACharacterCplusplus::ACharacterCplusplus()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    jumping = false;
}

// Called when the game starts or when spawned
void ACharacterCplusplus::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterCplusplus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (jumping)
    {
        Jump();
    }
}

// Called to bind functionality to input
void ACharacterCplusplus::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    check(PlayerInputComponent);

    // Bind movement inputs
    PlayerInputComponent->BindAxis("MoveForward", this, &ACharacterCplusplus::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ACharacterCplusplus::MoveRight);

    // Bind jump input
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacterCplusplus::CheckJump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacterCplusplus::CheckJump);

    PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ACharacterCplusplus::Interact);
}

// Move the character forward/backward
void ACharacterCplusplus::MoveForward(float Value)
{
    if (Value != 0.0f)
    {
        // Find out which way is forward
        FVector Direction = GetActorForwardVector();
        AddMovementInput(Direction, Value);
    }
}

// Move the character right/left
void ACharacterCplusplus::MoveRight(float Value)
{
    if (Value != 0.0f)
    {
        // Find out which way is right
        FVector Direction = GetActorRightVector();
        AddMovementInput(Direction, Value);
    }
}


// Start character jump
void ACharacterCplusplus::CheckJump()
{
    if (jumping)
    {
        jumping = false;
    }
    else
    {
        jumping = true;
    }
}

void ACharacterCplusplus::Interact()
{

}


