// It's mine. Leave it alone

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK2_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	// How close can the AI player get
	UPROPERTY(EditAnywhere, Category = "Setup")	// Consider EditDefaultsOnly	8:24
	float AcceptanceRadius = 3000;
	
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
};
