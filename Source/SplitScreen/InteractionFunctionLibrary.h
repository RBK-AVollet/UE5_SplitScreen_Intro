// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Components/WidgetComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InteractionFunctionLibrary.generated.h"

/**
 *
 */
UCLASS()
class SPLITSCREEN_API UInteractionFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void AppendInteractionPromptToInteractableActor(TScriptInterface<IInteractable> interactable,
		UWidgetComponent* Widget, FTransform Transform);
	
	UFUNCTION(BlueprintCallable)
	static void HideInteractionPrompt(UWidgetComponent* Widget);
};
