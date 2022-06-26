// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "SplineGenerator.generated.h"

UCLASS()
class VIZEXPERTS_API ASplineGenerator : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASplineGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;

	UFUNCTION()
		void OnSpawn();
	UFUNCTION()
		void GenerateComponents(USplineComponent* spline);
	UFUNCTION()
		void GetLTSAtDistance(float distance, FVector& loc, FVector& tan, FVector& sca);
	UPROPERTY()
		TArray<USplineMeshComponent*> components;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General")
		USplineComponent* splineComponent = nullptr;
	UPROPERTY(BlueprintReadWrite, Category = "General")
		bool showMesh = true;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General")
		float segmentLength = 50;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General")
		FVector2D scale = FVector2D(1, 1);
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General")
		UStaticMesh* mesh = nullptr;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General")
		TEnumAsByte<ESplineMeshAxis::Type> forwardAxis = ESplineMeshAxis::Y;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General")
		UMaterial* material = nullptr;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General")
		TArray<FVector> points;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General")
		float width = 1.0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General")
		UTexture2D* texture = nullptr;




private:

	FRandomStream rng;
	FTimerHandle hSpawnTimer;


};
