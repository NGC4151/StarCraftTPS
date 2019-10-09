// Fill out your copyright notice in the Description page of Project Settings.

#include "SCCharacter.h"
#include <ConstructorHelpers.h>
#include <Engine/SkeletalMesh.h>
#include"Components/SkeletalMeshComponent.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ASCCharacter::ASCCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetCollisionProfileName(FName("PlayerProfile"));

	//设置第一人称的属性
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>FirstMeshRes(TEXT("SkeletalMesh'/Game/Characters/HeroFPP/HeroFPP.HeroFPP'"));
	FirstMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstMesh"));
	FirstMesh->SetSkeletalMesh(FirstMeshRes.Object);
	FirstMesh->SetupAttachment((USceneComponent*)GetCapsuleComponent());
	FirstMesh->SetOnlyOwnerSee(true);
	FirstMesh->SetReceivesDecals (false);
	FirstMesh->bCastDynamicShadow = false;
	FirstMesh->bCastStaticShadow=false;
	FirstMesh->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::OnlyTickPoseWhenRendered;
	FirstMesh->PrimaryComponentTick.TickGroup = TG_PrePhysics;
	FirstMesh->SetCollisionObjectType(ECC_Pawn);
	FirstMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	FirstMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	FirstMesh->SetRelativeLocation(FVector(0.f, 0.f, -95.f));
	FirstMesh->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

	static ConstructorHelpers::FClassFinder<UAnimInstance>FPSAnimIns(TEXT("AnimBlueprint'/Game/BluePrint/PlayerAnim/FPS_Anim.FPS_Anim_C'"));
	FirstMesh->AnimClass = FPSAnimIns.Class;

	//设置第三人称Mesh的属性
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>ThMesh(TEXT("SkeletalMesh'/Game/Characters/HeroTPP/HeroTPP.HeroTPP'"));
	GetMesh()->SetSkeletalMesh(ThMesh.Object);
	GetMesh()->SetOnlyOwnerSee ( true);
	GetMesh()->SetReceivesDecals (false);
	GetMesh()->SetCollisionObjectType(ECC_Pawn);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetMesh()->SetCollisionResponseToAllChannels(ECR_Ignore);
	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -95.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

	//设置第三人称Mesh的动画
	static ConstructorHelpers::FClassFinder<UAnimInstance>TPSAnimIns(TEXT("AnimBlueprint'/Game/BluePrint/PlayerAnim/TPS_Anim.TPS_Anim_C'"));
	GetMesh()->AnimClass = TPSAnimIns.Class;

	//摄像机臂
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	//设置距离
	CameraBoom->TargetArmLength = 300.f;
	//设置偏移
	CameraBoom->TargetOffset = FVector(0.f, 0.f, 60.f);
	//设置相机臂的旋转跟随控制器的旋转
	CameraBoom->bUsePawnControlRotation = true;

	//设置第三人称相机
	ThirdCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdCamera"));
	ThirdCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	//设置第三人称的相机旋转不随控制器
	ThirdCamera->bUsePawnControlRotation = false;

	//设置第三人称相机
	FirstCamera= CreateDefaultSubobject<UCameraComponent>(TEXT("FirstCamera"));
	FirstCamera->SetupAttachment((USceneComponent*)GetCapsuleComponent());
	FirstCamera->bUsePawnControlRotation = true;
	FirstCamera->SetRelativeLocation(FVector(0.f, 0.f, 60.f));


	ThirdCamera->SetActive(true);
	FirstCamera->SetActive(false);

	FirstMesh->SetOwnerNoSee(true);
	GetMesh()->SetOwnerNoSee(false);

	LookUpRate = 45.f;
	TurnRate = 45.f;

	GetCharacterMovement()->MaxWalkSpeed = 150.f;

}

// Called when the game starts or when spawned
void ASCCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASCCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASCCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASCCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASCCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &ASCCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ASCCharacter::LookUp);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASCCharacter::OnStartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ASCCharacter::OnStopJump);

	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &ASCCharacter::OnStartRun);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &ASCCharacter::OnStopRun);


}

void ASCCharacter::MoveForward(float Value)
{
	if (Value!=0&&Controller)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ASCCharacter::MoveRight(float Value)
{
	if (Value!=0)
	{
		const FQuat Rotation = GetActorQuat();
		FVector Direction = FQuatRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void ASCCharacter::Turn(float Value)
{
	AddControllerYawInput(Value*LookUpRate*GetWorld()->GetDeltaSeconds());
}

void ASCCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value*TurnRate*GetWorld()->GetDeltaSeconds());
}

void ASCCharacter::OnStartJump()
{
	bPressedJump = true;
}

void ASCCharacter::OnStopJump()
{
	bPressedJump = false;
	StopJumping();
}

void ASCCharacter::OnStartRun()
{
	GetCharacterMovement()->MaxWalkSpeed = 375.f;
}

void ASCCharacter::OnStopRun()
{
	GetCharacterMovement()->MaxWalkSpeed = 150.f;
}

