// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionFunctionLibrary.h"

#include "Interactable.h"

void UInteractionFunctionLibrary::AppendInteractionPromptToInteractableActor(UWidgetComponent* Widget, FVector Offset,
	FTransform Transform)
{
	FVector pos = Transform.GetLocation();
	Widget->SetWorldLocation(pos + Offset);
	Widget->SetVisibility(true);
}

void UInteractionFunctionLibrary::HideInteractionPrompt(UWidgetComponent* Widget)
{
	Widget->SetVisibility(false);
}
