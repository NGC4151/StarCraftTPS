// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StarCraftTPS/Public/Data/SCTPSType.h"
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

	//�л��ӽ�
	void ChangeView(EGameViewMode::Type NewViewMode);

public:
	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
		class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
		class UCameraComponent* FirstCamera;
	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
		 UCameraComponent* ThirdCamera;
	//��Ϸ�ӽ�
	EGameViewMode::Type GameViewMode;

	//�ϰ�������״̬
	EUpperBody::Type UpperType;

	//�Ƿ�����л��ӽ�
	bool bCanChangeView;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void OnStartJump();
	void OnStopJump();
	void OnStartRun();
	void OnStopRun();

private:

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
		USkeletalMeshComponent* FirstMesh;

	float LookUpRate;
	float TurnRate;

};
