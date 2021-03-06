// It's mine. Leave it alone

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK2_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void UTankTurret::Rotate(float RelativeSpeed);
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MaxDegreesPerSecond = 25;

};
