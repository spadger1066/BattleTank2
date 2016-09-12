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
		// TODO Move towards the player

		// Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->Fire();  // TODO don't fire every frame
	}
}

