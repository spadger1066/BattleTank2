// It's mine. Leave it alone

#include "BattleTank2.h"
#include "TankAIController.h"

/**
 * \brief Begin Play
 */
void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController cannot find player tank"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()))
	}
}

void ATankAIController::Tick(float DeltaSeconds){
	Super::Tick(DeltaSeconds);
	if(GetPlayerTank()){
		// TODO Move towards the player

		// Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire if ready
	}
}

/**
 * \brief Get the controlled Tank
 * \return Pointer to the tank
 */
ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

/**
 * \brief Get the player tank
 * \return Pointer to the tank
 */
ATank* ATankAIController::GetPlayerTank() const{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}