﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayMessageRuntime/GameplayMessageProcessor.h"
#include "FLATCore/Framework/StackStateMachine/StackStateMachineComponent.h"
#include "UObject/Object.h"
#include "UserInterfaceManager.generated.h"

class UUI_State;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable,
	meta=(BlueprintSpawnableComponent, ShortTooltip =
		"UI Manager"))
class FLATCORE_API UUserInterfaceManager : public UStackStateMachineComponent
{
	GENERATED_BODY()

	UUserInterfaceManager();
public:
	UFUNCTION(BlueprintCallable,Category="UI Manager")
	void InitUIStates();

	UFUNCTION(BlueprintCallable,Category="UI Manager")
	bool AddUIState(FGameplayTag Tag,TSubclassOf<UUI_State> StateClass);

	UFUNCTION(BlueprintCallable,Category="UI Manager")
	bool RemoveUIState(FGameplayTag Tag);
	
	UFUNCTION(BlueprintPure,Category="UI Manager")
	UUI_State* GetUI(FGameplayTag Tag);

	UFUNCTION(BlueprintCallable,Category="UI Manager")
	void PushUIState(FGameplayTag StateTag);


	//UActorComponent Interface
virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	//end



	



private:
	UPROPERTY(EditDefaultsOnly)
	TMap<FGameplayTag,TSubclassOf<UUI_State>> StatesToInitialize;

	UPROPERTY()
	TMap<FGameplayTag,UUI_State*> UIInstancesMap;

	
	
};
