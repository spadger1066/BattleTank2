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
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair(){
	if (!GetControlledTank()) { return; }

	FVector HitLocation;	// Out parameter
	if (GetSightRayHitLocation(HitLocation)) {
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString())
	}
}

/**
 * \brief Get world location of line trace through crosshair, true if hits landscape
 * \param HitLocation 
 * \return true if an object is hit
 */
bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const{
	
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	FVector LookDirection;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	if (GetLookDirection(ScreenLocation, LookDirection)){
		// Line trace along that look direction and see what we hit(up to max target)
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}

	return true;
}

/**
 * \brief De-project the screen position of the crosshair to a world direction
 * \param ScreenLocation - target
 * \param LookDirection - OUT direction looking in
 * \return The direction in which the subject is looking
 */
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

/**
 * \brief Find the location pointed at by LookDirection
 * \param LookDirection - the direction in which to look
 * \param HitLocation - OUT the location being looked at
 * \return true if a valid location
 */
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + LookDirection * LineTraceRange;
	if(GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
		){
		HitLocation = HitResult.Location;
		return true;
	}
	return false;	
}
