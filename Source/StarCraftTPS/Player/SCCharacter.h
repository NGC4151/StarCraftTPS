// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCCharacter.generated.h"

class USkeletalMeshComponent;

UCLASS()
class STARCRAFTTPS_API ASCCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
		class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
		class UCameraComponent* FirstCamera;
	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
		 UCameraComponent* ThirdCamera;




protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
		USkeletalMeshComponent* FirstMesh;

};
