// It's mine. Leave it alone

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class AProjectile;

UCLASS()
class BATTLETANK2_API ATank : public APawn
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

private:
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;

	// TODO remove once firing is moved to aiming component
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;
	UTankBarrel* Barrel = nullptr;	// TODO Remove
	double LastFireTime = 0;
};
