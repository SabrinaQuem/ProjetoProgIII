// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InterfaceFinalC.h"
#include "CharacterCplusplus.generated.h"

UCLASS()
class LINGUAGENSPROGIII_API ACharacterCplusplus : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterCplusplus();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Configure")
	float MouseSensitivity = 0.5f;

	// Function to handle overlap begin event
	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY()
	AActor* Other;


private:

	void MoveForward(float Value);
	void MoveRight(float Value);
	void CheckJump();
	void Interact();

	UPROPERTY()
	bool jumping;

	UPROPERTY(EditAnywhere)
	float InteractLineTraceLength = 350.f;

	
};
