// Copyright Carlos Salazar - For Polyglot Week Code Chrysalis
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Grabber.h"

#define OUT
// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	PhysicsHandle = GetOwner() -> FindComponentByClass<UPhysicsHandleComponent>();
	if(PhysicsHandle)
	{
		//Physics handle is found
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No physics handle component found on %s!"), *GetOwner()->GetName());
	}

	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if(InputComponent){
		UE_LOG(LogTemp, Warning, TEXT("Input component found"),*GetOwner()->GetName());
		InputComponent->BindAction("Grab",IE_Pressed,this,&UGrabber::Grab);
	}
	// else 
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("Input component MISSING"),*GetOwner()->GetName());
	// }

}

void UGrabber::Grab()
{
	UE_LOG(LogTemp,Warning,TEXT("Grabber Press"));
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation, 
		OUT PlayerViewPointRotation
	); //OUT parameters, Out is a keyowrd we deffined outselves near the header, it doesnt do anyuthing is only for readibility

	// UE_LOG(LogTemp, Warning, TEXT("Location: %s Rotation: %s"), 
	// *PlayerViewPointLocation.ToString(),
	// *PlayerViewPointRotation.ToString()
	// ); //%s is string

	//Draw a line from player showing the reach
	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;

	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(0,255,0),
		false,
		0.f,
		0,
		5.f
	);

	FHitResult Hit;
	//ray cast out to a certain distance
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams
	);

	//See what it hits
	AActor* ActorHit = Hit.GetActor();
	if(ActorHit){
		UE_LOG(LogTemp, Error, TEXT("Line trace has hit: %s"), *(ActorHit -> GetName()))
	}


}

