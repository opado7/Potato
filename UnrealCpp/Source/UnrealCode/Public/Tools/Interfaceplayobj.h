// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interfaceplayobj.generated.h"

/**
 * 
 */
UINTERFACE(Blueprintable)//�������Ʈ ȣ�� interface Ŭ���� ����
class UNREALCODE_API UInterfaceplayobj : public UInterface
{
	GENERATED_BODY()
};


class UNREALCODE_API IInterfaceplayobj//interface �Լ� ���� Ŭ����
{
	GENERATED_BODY()

public:
	//BlueprintCallable: �������Ʈ���� ȣ�Ⱑ��
	//BlueprintNativeEvent: �������Ʈ���� ��� �籸�� ���� �Լ� ó��
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Code_Doplay(bool IsPlay);//�������Ʈ ȣ��� �Լ��� ����
	virtual void Code_Doplay_Implementation(bool IsPlay) {}; 
	//c++ ���� ����� �Լ� 
};
