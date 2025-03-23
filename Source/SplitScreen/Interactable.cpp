// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable.h"

// Add default functionality here for any IInteractable functions that are not pure virtual.
// FVector IInteractable::GetInteractionPromptOffset()
// {
// 	return FVector::UpVector * 100.0f;
// }
FVector IInteractable::GetInteractionPromptOffset_Implementation()
{
	return FVector::UpVector * 100.0f;
}
