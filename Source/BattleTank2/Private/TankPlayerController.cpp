// It's mine. Leave it alone

#include "BattleTank2.h"
#include "TankAimingComponent.h"
#include "TankPlayerController.h"

/**
 * \brief Begin Play
 */
void ATankPlayerController::BeginPlay(){
	Super::BeginPlay();
	auto AimingComponet = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponet)) { return; }
	FoundAimingComponent(AimingComponet);
}

/**
 * \brief Tick Method
 * \param DeltaTime 
 */
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

/**
 * \brief Start the tank moving the barrel so that a shot would hit where the cross hair intersects the world
 */
void ATankPlayerController::AimTowardsCrosshair() const{
	if (!GetPawn()) { return; }	// E.g. if not possessing
	auto AimingComponet = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponet)) { return; }

	FVector HitLocation;	// Out parameter
	if (GetSightRayHitLocation(HitLocation)) {
		AimingComponet->AimAt(HitLocation);
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
