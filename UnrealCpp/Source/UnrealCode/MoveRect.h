// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Public/Tools/Interfaceplayobj.h"
#include "GameFramework/Actor.h"
#include "MoveRect.generated.h"

//언리얼 ENUM을 블루프린트에서도 사용가능하도록 선언
UENUM(BlueprintType)
enum class EN_MoveTypeCode : uint8 {
	MoveRight UMETA(DisplayName = "Right"),//MoveRight(C++에서 사용하는 이름), UMETA옵션중 DISPLAYNAME은 블루프린트에서 보여질 이름
	MoveUp UMETA(DisplayName = "Up"),
	MoveLeft UMETA(DisplayName = "Left"),
	MoveDown UMETA(DisplayName = "Down"),
};

UCLASS()
class UNREALCODE_API AMoveRect : public AActor, public IInterfaceplayobj
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveRect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Code_Doplay(bool IsPlay);

	virtual void Code_Doplay_Implementation(bool IsPlay) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	float LocX = 0, LocZ = 0;
	float scale1 = 1, scale2 = 1, scale3 = 1;
	float angle = 0, Yaw = 0, Posx = 0, Posy = 0;
	bool m_playg;

	void Make_Square(float time);
	void Make_Circle(float time);

	EN_MoveTypeCode m_move = EN_MoveTypeCode::MoveRight;
};
