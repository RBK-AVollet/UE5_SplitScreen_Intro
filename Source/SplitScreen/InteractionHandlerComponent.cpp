// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionHandlerComponent.h"

#include <string>

UInteractionHandlerComponent::UInteractionHandlerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UInteractionHandlerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* closestInteractable = nullptr;
	float closestDistance = SphereRadius + 1.f; // Defaults to outside of range
	FVector ownerLocation = GetOwner()->GetActorLocation(); // Character's position

	// Find the closest interactable
	for(AActor* interactable : InRangeInteractableActors)
	{
		if(interactable == nullptr) continue;
		
		float distance = FVector::Dist(ownerLocation, interactable->GetActorLocation());
		if(distance < closestDistance)
		{
			closestInteractable = interactable;
			closestDistance = distance;
		}
	}

	// Set the closest interactable if it is different from the current one
	if(closestInteractable == CurrentInteractable) return;

	CurrentInteractable = closestInteractable;
	OnInteractableChanged();
}

void UInteractionHandlerComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                                  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor != nullptr && OtherActor->Implements<UInteractable>())
	{
		InRangeInteractableActors.Add(OtherActor);
	}
}

void UInteractionHandlerComponent::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(OtherActor != nullptr && OtherActor->Implements<UInteractable>())
	{
		InRangeInteractableActors.Remove(OtherActor);
	}
}
