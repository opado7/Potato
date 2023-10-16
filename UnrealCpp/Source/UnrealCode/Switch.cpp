// Fill out your copyright notice in the Description page of Project Settings.


#include "Switch.h"
#include "MoveLeftRight.h"
#include "MoveRect.h"
#include "Public/Tools/Interfaceplayobj.h"

// Sets default values
ASwitch::ASwitch()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRootRoot"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mymyMesh"));

	SetRootComponent(Scene);

	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);

	StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &ASwitch::OnSwitchBeginOverlap);
	StaticMesh->OnComponentEndOverlap.AddDynamic(this, &ASwitch::OnSwitchEndOverlap);
}

// Called when the game starts or when spawned
void ASwitch::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASwitch::OnSwitchBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("BeginOverlap"));

	//if (!IsValid(leftright) || !IsValid(rect))// IsValid : �𸮾󿡼� ��ü�� ��ȿ ���� äũ ���
		//return;
	/*for (AMoveLeftRight* left : leftright) {
		left->IsPlay = true;
	}*/
	//leftright->IsPlay = true;
	//rect->playg = true;

	for (AActor* pactor : All_actor) {

		IInterfaceplayobj* Interfaceobj = Cast<IInterfaceplayobj>(pactor);

		if (Interfaceobj) {
			Interfaceobj->Execute_Code_Doplay(pactor, true);
		}
	}
	
	

}


void ASwitch::OnSwitchEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {

	//if (!IsValid(leftright) || !IsValid(rect))// IsValid : �𸮾󿡼� ��ü�� ��ȿ ���� äũ ���
		//return;

	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("Endoverlap"));

	for (int i = 0; i < leftright.Num(); ++i) {
		leftright[i]->m_IsPlay = false;
	}
	
	//rect->playg = false;
	for (AActor* pactor : All_actor) {
		/*AMoveLeftRight* peftRight = Cast<AMoveLeftRight>(pactor);
		if (peftRight) {
			peftRight->m_IsPlay = false;
			continue;
		}

		AMoveRect* prect = Cast<AMoveRect>(pactor);
		if (prect) {
			prect->playg = false;
			continue;
		}*/

		IInterfaceplayobj* Interfaceobj = Cast<IInterfaceplayobj>(pactor);
		//����� interface casting(����ȯ) ���� �� execute_�Լ��̸����� interface �Լ� ȣ��
		//Excute_�Լ��̸��� ù��° �Ķ��Ÿ�� �Լ� ȣ�� ��� ��ü, ���Ĵ� �Լ� �Ķ��Ÿ
		if (Interfaceobj) {
			Interfaceobj->Execute_Code_Doplay(pactor, false);
		}
	}
}