// It's mine. Leave it alone

#include "BattleTank2.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay(){
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank){
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing tank"))
	} else{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing: %s"), *(ControlledTank->GetName()))
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

ATank* ATankPlayerController::GetControlledTank() const{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair(){
	if (!GetControlledTank()) { return; }

	
}
