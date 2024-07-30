// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "Bird.generated.h"

class UCapsuleComponent;
class USkeletalMeshComponent;
class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;
class UFloatingPawnMovement;

UCLASS()
class SLASH_API ABird : public APawn
{
	GENERATED_BODY()

public:
	ABird();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* LookAction;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

private:

	UPROPERTY(VisibleAnywhere, Category=Components)
	UCapsuleComponent* Capsule;

	UPROPERTY(VisibleAnywhere, Category=Components)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category=Components)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category=Components)
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category=Components)
	UFloatingPawnMovement* FloatingMovementComponent;
};
