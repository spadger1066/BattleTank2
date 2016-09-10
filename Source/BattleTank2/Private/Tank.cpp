// It's mine. Leave it alone

#include "BattleTank2.h"
#include "GameFramework/Pawn.h"
#include "Tank.h"


// Sets default values
ATank::ATank(){
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// No need to protect pointers as added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay(){
	Super::BeginPlay();
}

// Called every frame
// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent){
	Super::SetupPlayerInputComponent(InputComponent);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet) {
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}

void ATank::SetTurretReference(UTankTurret* TurretToSet) {
	TankAimingComponent->SetTurretReference(TurretToSet);
}

/**
 * \brief aim the tank at its target
 * \param HitLocation the location at which to aim
 */
void ATank::AimAt(FVector HitLocation) const{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire(){
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Tank fires"), Time)

}
