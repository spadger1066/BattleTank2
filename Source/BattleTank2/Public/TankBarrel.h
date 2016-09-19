// It's mine. Leave it alone

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK2_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward speed, and +1 is max up speed
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxDegreesPerSecond = 10;  
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxsElevationDegree = 40;
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MinElevationDegrees = 0;

};
