// It's mine. Leave it alone

#include "BattleTank2.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"

/**
 * \brief Begin Play
 */
void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaSeconds){
	Super::Tick(DeltaSeconds);
	auto PlayerTank = (GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = (GetPawn());
	if (!ensure(PlayerTank && ControlledTank)) { return; }

	// Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius);	// TODO check in cm

	// Aim towards the player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation()); // +FVector(1000, 0, 0));	// TODO remove offset

	//ControlledTank->Fire();  // TODO don't fire every frame + fix it
}
