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
	void Elevate(float DegreesPerSecond);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20;  
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxsElevationDegree = 40;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0;

};
