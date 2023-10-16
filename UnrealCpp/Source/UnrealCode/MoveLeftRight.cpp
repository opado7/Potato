// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveLeftRight.h"


// Sets default values for this actor's properties
// Sets default values

inline AMoveLeftRight::AMoveLeftRight():LocX(0), IsmoveRight(true), m_IsPlay(false)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//CreateDefaultSubobject: new Ű����� ���� �𸮾󿡼� �������� ��ü�� �����ϴ� Ű����
	//TEXT: �𸮾󿡼� ����ϴ� ������ �� �ϳ�
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRootRoot")); //USceneComponent ��ü�� SceneRootRoot �̸����� ��������
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mymyMesh"));

	SetRootComponent(Scene); //Scene�� Root Componen�� �ø��ڴ�.

	//AttachToComponent: ������Ʈ�� �� ��Ʈ�� ���̰ڴ�
	//���� ��ǥ���� Scene ���ؿ� Relative(���) ��ǥ��� ���δ�.
	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);

	StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &AMoveLeftRight::OnmoveBeginOverlap);
	//���� ��ǥ���� RootComponent ���ؿ� Relative(���) ��ǥ��� ���δ�.
	//StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	//UAsset ��������
	//ConstructorHelpers::FObjectFinder: ������Ʈ ���� ã��
	//<UStaticMesh> ã�� ���� Ÿ��
	//sm: ã�Ƽ� ���� ��ü �̸�
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> sm(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));
	//
	//if (sm.Succeeded()) {//���� �ҷ����� ���� ���� üũ
	//	StaticMesh->SetStaticMesh(sm.Object); //staticmeshobject�� mesh ����
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
	Super::Tick(DeltaTime);//�������̵��� �Լ��� ��� �θ� �Լ��� �����Ѵ�.

	if (m_IsPlay == false)
		return;

	//Make_Line();//�¿�� �Դٰ���
	//Make_Square();//�簢�� �׸���
	if (IsmoveRight)Make_Square();//�� �׸���
}

void AMoveLeftRight::Code_Doplay_Implementation(bool IsPlay)
{
	m_IsPlay = IsPlay;
}

void AMoveLeftRight::Make_Line() {

	//SetRelativeLocation: ������� ��ġ���� �����Ѵ�.
	//FVector: �𸮾󿡼� ����ϴ� 3���� ��ǥ ����
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