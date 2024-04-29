// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterCPlusPLus.h"

// Sets default values
ACharacterCPlusPLus::ACharacterCPlusPLus()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Initialize jumping state
    bIsJumping = false;

}

// Called when the game starts or when spawned
void ACharacterCPlusPLus::BeginPlay()
{
	Super::BeginPlay();
	
    
}

// Called every frame
void ACharacterCPlusPLus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterCPlusPLus::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    check(PlayerInputComponent);

    // Bind movement inputs
    PlayerInputComponent->BindAxis("MoveForward", this, &ACharacterCPlusPLus::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ACharacterCPlusPLus::MoveRight);

    // Bind jump input
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacterCPlusPLus::StartJump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacterCPlusPLus::StopJump);

    PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ACharacterCPlusPLus::Interact);
}

// Move the character forward/backward
void ACharacterCPlusPLus::MoveForward(float Value)
{
    if (Value != 0.0f)
    {
        // Find out which way is forward
        FVector Direction = GetActorForwardVector();
        AddMovementInput(Direction, Value);
    }
}

// Move the character right/left
void ACharacterCPlusPLus::MoveRight(float Value)
{
    if (Value != 0.0f)
    {
        // Find out which way is right
        FVector Direction = GetActorRightVector();
        AddMovementInput(Direction, Value);
    }
}

void ACharacterCPlusPLus::StartJump() 
{
    Jump();
}

void ACharacterCPlusPLus::StopJump()
{
    if (bIsJumping && GetCharacterMovement())
    {
        // Reset jumping flag
        bIsJumping = false;

        // Stop character jump
        StopJumping();
    }
}

void ACharacterCPlusPLus::Interact() 
{
    
}


void ACharacterCPlusPLus::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
   


}

void ACharacterCPlusPLus::OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{


}



