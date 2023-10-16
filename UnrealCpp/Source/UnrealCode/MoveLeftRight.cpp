// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveLeftRight.h"


// Sets default values for this actor's properties
// Sets default values

inline AMoveLeftRight::AMoveLeftRight():LocX(0), IsmoveRight(true), m_IsPlay(false)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//CreateDefaultSubobject: new 키워드와 같이 언리얼에서 동적으로 객체를 생성하는 키워드
	//TEXT: 언리얼에서 사용하는 문자형 중 하나
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRootRoot")); //USceneComponent 객체를 SceneRootRoot 이름으로 동적생성
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mymyMesh"));

	SetRootComponent(Scene); //Scene을 Root Componen로 올리겠다.

	//AttachToComponent: 컴포넌트를 씬 루트에 붙이겠다
	//현재 좌표값을 Scene 기준에 Relative(상대) 좌표계로 붙인다.
	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);

	StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &AMoveLeftRight::OnmoveBeginOverlap);
	//현재 좌표값을 RootComponent 기준에 Relative(상대) 좌표계로 붙인다.
	//StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	//UAsset 가져오기
	//ConstructorHelpers::FObjectFinder: 오브젝트 에셋 찾기
	//<UStaticMesh> 찾을 에셋 타입
	//sm: 찾아서 넣을 객체 이름
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> sm(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));
	//
	//if (sm.Succeeded()) {//에셋 불러오기 성공 여부 체크
	//	StaticMesh->SetStaticMesh(sm.Object); //staticmeshobject에 mesh 적용
	//}
}

AMoveLeftRight::~AMoveLeftRight()
{
}

// Called when the game starts or when spawned
void AMoveLeftRight::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMoveLeftRight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);//오버라이드한 함수인 경우 부모 함수를 실행한다.

	if (m_IsPlay == false)
		return;

	//Make_Line();//좌우로 왔다갔다
	//Make_Square();//사각형 그리기
	if (IsmoveRight)Make_Square();//원 그리기
}

void AMoveLeftRight::Code_Doplay_Implementation(bool IsPlay)
{
	m_IsPlay = IsPlay;
}

void AMoveLeftRight::Make_Line() {

	//SetRelativeLocation: 상대적인 위치값을 설정한다.
	//FVector: 언리얼에서 사용하는 3차원 좌표 변수
	if (IsmoveRight) {
		LocX += 1;
		StaticMesh->SetRelativeLocation(FVector(LocX, 0, 0));
		if (LocX > 50) IsmoveRight = false;
	}
	else {
		LocX -= 1;
		StaticMesh->SetRelativeLocation(FVector(LocX, 0, 0));
		if (LocX < -50) IsmoveRight = true;
	}
}

void AMoveLeftRight::Make_Circle(float time) {
	angle += time;
	Yaw += 2;

	if (angle > 180) angle = 0;
	if (Yaw > 360) Yaw = 0;

	Posx = 200 + (cos(angle) * 400);
	Posy = 200 + (sin(angle) * 400);

	StaticMesh->SetRelativeLocation(FVector(Posx, Posy, 0));
	StaticMesh->SetRelativeRotation(FRotator(0, Yaw, 0));

}

void AMoveLeftRight::Make_Square() {
	switch (move)
	{
	case 0:
		LocX += 1;
		StaticMesh->SetRelativeLocation(FVector(LocX, 0, LocZ));
		if (LocX > 200) move++;
		break;
	case 1:
		LocZ += 1;
		StaticMesh->SetRelativeLocation(FVector(LocX, 0, LocZ));
		if (LocZ > 200) move++;
		break;
	case 2:
		LocX -= 1;
		StaticMesh->SetRelativeLocation(FVector(LocX, 0, LocZ));
		if (LocX < 0) move++;
		break;
	case 3:
		LocZ -= 1;
		StaticMesh->SetRelativeLocation(FVector(LocX, 0, LocZ));
		if (LocZ < 0) move = 0;
		break;
	default:
		break;
	}
}

void AMoveLeftRight::OnmoveBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){
	
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("Destroy Cube!"));
	OverlappedComponent->DestroyComponent();


}