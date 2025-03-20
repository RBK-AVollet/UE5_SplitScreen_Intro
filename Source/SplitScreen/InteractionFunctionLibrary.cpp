// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionFunctionLibrary.h"

#include "Interactable.h"

void UInteractionFunctionLibrary::AppendInteractionPromptToInteractableActor(TScriptInterface<IInteractable> interactable, UWidgetComponent* Widget,
	FTransform Transform)
{
	FVector pos = Transform.GetLocation();
	Widget->SetWorldLocation(pos + interactable.GetInterface()->GetInteractionPromptOffset());
	Widget->SetVisibility(true);
}

void UInteractionFunctionLibrary::HideInteractionPrompt(UWidgetComponent* Widget)
{
	Widget->SetVisibility(false);
}
