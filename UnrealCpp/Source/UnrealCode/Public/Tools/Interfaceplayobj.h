// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interfaceplayobj.generated.h"

/**
 * 
 */
UINTERFACE(Blueprintable)//블루프린트 호출 interface 클래스 선언
class UNREALCODE_API UInterfaceplayobj : public UInterface
{
	GENERATED_BODY()
};


class UNREALCODE_API IInterfaceplayobj//interface 함수 구현 클래스
{
	GENERATED_BODY()

public:
	//BlueprintCallable: 블루프린트에서 호출가능
	//BlueprintNativeEvent: 블루프린트에서 상속 재구현 가능 함수 처리
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Code_Doplay(bool IsPlay);//블루프린트 호출용 함수명 선언
	virtual void Code_Doplay_Implementation(bool IsPlay) {}; 
	//c++ 에서 실행될 함수 
};
