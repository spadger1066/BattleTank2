// It's mine. Leave it alone

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK2_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	// Screen coordinates
	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.3333;
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.0;

	virtual void BeginPlay() override;

	ATank* GetControlledTank() const;

	virtual void Tick(float DeltaSeconds) override;

	// Start the tank moving the barrel so that a shot would hit where
	// the cross hair intersects the world
	void AimTowardsCrosshair();
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetSightRayHitLocation(FVector &HitLocation) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
