// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveRect.h"

// Sets default values
AMoveRect::AMoveRect():m_playg(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRootRoot")); //USceneComponent 객체를 SceneRootRoot 이름으로 동적생성
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mymyMesh"));

	SetRootComponent(Scene);

	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AMoveRect::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMoveRect::Code_Doplay_Implementation(bool IsPlay)
{
	m_playg = IsPlay;
}

// Called every frame
void AMoveRect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(!m_playg) return;

	//Make_Square(DeltaTime);
	Make_Circle(DeltaTime);

}

void AMoveRect::Make_Square(float time) {
	/*switch (move)
	{
	case EN_MoveTypeCode::MoveRight:
		LocX += 1;
		if (LocX > 200) move = EN_MoveTypeCode::MoveUp;
		break;
	case EN_MoveTypeCode::MoveUp:
		LocZ += 1;
		if (LocZ > 200) move = EN_MoveTypeCode::MoveLeft;
		break;
	case EN_MoveTypeCode::MoveLeft:
		LocX -= 1;
		if (LocX < 0) move = EN_MoveTypeCode::MoveDown;
		break;
	case EN_MoveTypeCode::MoveDown:
		LocZ -= 1;
		if (LocZ < 0) move = EN_MoveTypeCode::MoveRight;
		break;
	default:
		break;
	}

	
	
	StaticMesh->SetRelativeLocation(FVector(LocX, 0, LocZ));*/

	LocZ += 5;
	StaticMesh->SetRelativeLocation(FVector(0, 0, LocZ));
	StaticMesh->SetRelativeScale3D(FVector(scale1, scale2, scale3));
	if (scale1 > 0 || scale2 > 0 || scale3 > 0) {
		scale1 -= time / 15;
		scale2 -= time / 15;
		scale3 -= time / 15;
	}
}

void AMoveRect::Make_Circle(float time) {
	angle += time;
	Yaw += 2;

	if (angle > 180) angle = 0;
	if (Yaw > 360) Yaw = 0;

	Posx = 100 + (cos(angle) * 200);
	Posy = 100 + (sin(angle) * 200);

	StaticMesh->SetRelativeLocation(FVector(Posx, Posy, LocZ));
	//StaticMesh->SetRelativeRotation(FRotator(0, Yaw, 0));

}