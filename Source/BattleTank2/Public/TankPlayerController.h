// It's mine. Leave it alone

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;
/**
 * Responsible for helping the player aim
 */
UCLASS()
class BATTLETANK2_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:
	// Screen coordinates
	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.3333;
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.0;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	void AimTowardsCrosshair() const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetSightRayHitLocation(FVector &HitLocation) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
