// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h" //������ �ӵ��� ������ �ϱ����� �⺻���� �ּ����� ���̺귯���� ������ ���
#include "GameFramework/Actor.h"//AActor Ŭ���� ��� ����
#include "Public/Tools/Interfaceplayobj.h"
//AMoveLeftRight ���� ó�� ���
//��� �𸮾� �۷����� �����Ƿ��� �Ʒ� �ڵ带 �־������
//�ݵ�� ��� #include�� �������� ��ġ�ؾ���
#include "MoveLeftRight.generated.h"


//�𸮾� Ŭ���� ����
//�� Ŭ������ UNREALCODE_API ��⿡ ���Եȴ�.
//�𸮾� �ڵ� ���� �Լ� - �𸮾� Ŭ���� ���� �⺻ ��Ģ
UCLASS()
class UNREALCODE_API AMoveLeftRight : public AActor, public IInterfaceplayobj
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	// Sets default values
	AMoveLeftRight();
	~AMoveLeftRight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Code_Doplay(bool IsPlay);

	virtual void Code_Doplay_Implementation(bool IsPlay) override;
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	UFUNCTION()//���ε� �Լ��� �ݵ�� UFUNCTION���� ������ ��
	void OnmoveBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void Make_Circle(float time);
	void Make_Square();
	void Make_Line();

	float LocX = 0;
	float LocZ = 0;
	float Posx = 0, Posy = 0, Yaw = 0;
	double angle = 0;
	bool IsmoveRight, m_IsPlay;
	int move = 0;
};
