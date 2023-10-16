// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h" //컴파일 속도를 빠르게 하기위해 기본적인 최소한의 라이브러리를 포함한 헤더
#include "GameFramework/Actor.h"//AActor 클래스 헤더 파일
#include "Public/Tools/Interfaceplayobj.h"
//AMoveLeftRight 생성 처리 헤더
//모든 언리얼 글래스가 생성되려면 아래 코드를 넣어줘야함
//반드시 모든 #include의 마지막에 배치해야함
#include "MoveLeftRight.generated.h"


//언리얼 클래스 선언
//이 클래스는 UNREALCODE_API 모듈에 포함된다.
//언리얼 코드 생성 함수 - 언리얼 클래스 생성 기본 규칙
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

	UFUNCTION()//바인딩 함수는 반드시 UFUNCTION으로 만들어야 됨
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
