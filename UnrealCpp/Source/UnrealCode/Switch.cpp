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

	//if (!IsValid(leftright) || !IsValid(rect))// IsValid : 언리얼에서 객체의 유효 여부 채크 기능
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

	//if (!IsValid(leftright) || !IsValid(rect))// IsValid : 언리얼에서 객체의 유효 여부 채크 기능
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
		//상속한 interface casting(형변환) 성공 후 execute_함수이름으로 interface 함수 호출
		//Excute_함수이름의 첫번째 파라메타는 함수 호출 대상 객체, 이후는 함수 파라메타
		if (Interfaceobj) {
			Interfaceobj->Execute_Code_Doplay(pactor, false);
		}
	}
}