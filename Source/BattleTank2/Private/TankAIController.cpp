// It's mine. Leave it alone

#include "BattleTank2.h"
#include "Tank.h"
#include "TankAIController.h"

/**
 * \brief Begin Play
 */
void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaSeconds){
	Super::Tick(DeltaSeconds);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if(PlayerTank){
		//UE_LOG(LogTemp, Warning, TEXT("Player     at %s"), *PlayerTank->GetActorLocation().ToString())
		//	UE_LOG(LogTemp, Warning, TEXT("Controlled at %s"), *ControlledTank->GetActorLocation().ToString())
		//	UE_LOG(LogTemp, Warning, TEXT("AR %f"), AcceptanceRadius)
		// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius);	// TODO check in cm

		// Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation()); // +FVector(1000, 0, 0));	// TODO remove offset

		//ControlledTank->Fire();  // TODO don't fire every frame
	}
}

