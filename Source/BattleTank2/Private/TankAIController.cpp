// It's mine. Leave it alone

#include "BattleTank2.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController not possesing tank"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController possesing: %s"), *(ControlledTank->GetName()))
	}
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}
