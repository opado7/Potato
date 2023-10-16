// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Switch.generated.h"

UCLASS()
class UNREALCODE_API ASwitch : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASwitch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION()//���ε� �Լ��� �ݵ�� UFUNCTION���� ������ ��
	void OnSwitchBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void OnSwitchEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	// TObjectPtr �𸮾󿡼� AMoveLeftRight�� ��� ���� ��� Ŭ������ ����ų�� �ִ� ����
	// EditAnywhere : �ν��Ͻ� ��������(���� ��ġ�� �ν��Ͻ����� ������ â���� ���� �����ϰ� �����ش�)
	// class : #include Ŭ������ �߰����� �ʰ� ���Ŀ� Ŭ������ �����Ŷ�� ������ �ܰ迡���� �˷��ִ� Ű����
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<TObjectPtr<class AMoveLeftRight>> leftright;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<class AMoveRect> rect;

	//TArray: �𸮾󿡼� �迭(vector) ���� [ ��) TArray ]

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<TObjectPtr<class AActor>> All_actor;
};