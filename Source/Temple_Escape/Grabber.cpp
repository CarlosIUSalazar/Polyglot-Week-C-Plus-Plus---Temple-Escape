// Copyright Carlos Salazar - For Polyglot Week Code Chrysalis
#include "Grabber.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

#define OUT

// Sets default values for this component's properties

UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	FindPhysicsHandle();
	SetupInputComponent();
}

void UGrabber::SetupInputComponent(){
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent){
		//UE_LOG(LogTemp, Warning, TEXT("Input component found"),*GetOwner()->GetName());
		InputComponent->BindAction("Grab",IE_Pressed,this,&UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released,this,&UGrabber::Release);
	}

}

	//Checking for Physics Handle
void UGrabber::FindPhysicsHandle(){
	PhysicsHandle = GetOwner() -> FindComponentByClass<UPhysicsHandleComponent>();
	if(!PhysicsHandle)
	{
		UE_LOG(LogTemp, Warning, TEXT("No physics handle component found on %s!"), *GetOwner()->GetName());
	}
}


void UGrabber::Grab()
{
	//UE_LOG(LogTemp,Warning,TEXT("Grabber Press"));
	//Get players viewpoint
	FHitResult HitResult = GetFirstPhysicsBodyInReach();
	UPrimitiveComponent* ComponentToGrab = HitResult.GetComponent();
	AActor* ActorHit = HitResult.GetActor();

//If we hit somerthing the attach the physics handle
if(ActorHit){
	if(!PhysicsHandle){return;} //To protect pointer
	PhysicsHandle->GrabComponentAtLocation
	(
	ComponentToGrab,
	NAME_None,
	GetPlayersReach()
	);
}
}


void UGrabber::Release()
{
	if(!PhysicsHandle){return;}
	UE_LOG(LogTemp,Warning,TEXT("Grabber Released"));
	PhysicsHandle->ReleaseComponent();
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//Get players viewpoint
	// FVector PlayerViewPointLocation;
	// FRotator PlayerViewPointRotation;

	// GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
	// 	OUT PlayerViewPointLocation, 
	// 	OUT PlayerViewPointRotation
	// ); //OUT parameters, Out is a keyowrd we deffined outselves near the header, it doesnt do anyuthing is only for readibility

	// FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
	//If the physics handle is attach
	if(!PhysicsHandle){return;}
	if (PhysicsHandle->GrabbedComponent){
		//Move object we are holding
		PhysicsHandle->SetTargetLocation(GetPlayersReach());
	}
}

FHitResult UGrabber::GetFirstPhysicsBodyInReach() const
{
	//Get players viewpoint
	FHitResult Hit;
	//ray cast out to a certain distance
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		GetPlayersWorldPos(),
		GetPlayersReach(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams
	);
	return Hit;
	//See what it hits
	// AActor* ActorHit = Hit.GetActor();
	// if(ActorHit){
	// 	UE_LOG(LogTemp, Error, TEXT("Line trace has hit: %s"), *(ActorHit -> GetName()))
	// }
	// if(ActorHit){
	// 	UE_LOG(LogTemp,Warning,TEXT("Line trace has hit: %s"),*(ActorHit->GetName()))
	// }
	// return Hit;
}

FVector UGrabber::GetPlayersWorldPos() const
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation, 
		OUT PlayerViewPointRotation
	); //OUT parameters, Out is a keyowrd we deffined outselves near the header, it doesnt do anyuthing is only for readibility
	//THIS IS A DEBUG FUNCTIUON THAT Draws a laser like line from player showing the reach
	// DrawDebugLine(
	// 	GetWorld(),
	// 	PlayerViewPointLocation,
	// 	LineTraceEnd,
	// 	FColor(0,255,0),
	// 	false,
	// 	0.f,
	// 	0,
	// 	5.f
	// );
	
	return PlayerViewPointLocation;
}
	FVector UGrabber::GetPlayersReach() const
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation, 
		OUT PlayerViewPointRotation
	); //OUT parameters, Out is a keyowrd we deffined outselves near the header, it doesnt do anyuthing is only for readibility

	//THIS IS A DEBUG FUNCTIUON THAT Draws a laser like line from player showing the reach
	// DrawDebugLine(
	// 	GetWorld(),
	// 	PlayerViewPointLocation,
	// 	LineTraceEnd,
	// 	FColor(0,255,0),
	// 	false,
	// 	0.f,
	// 	0,
	// 	5.f
	// );
	return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach; 
}
