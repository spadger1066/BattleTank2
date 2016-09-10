// It's mine. Leave it alone

#include "BattleTank2.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed){
	// Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0, 1.0);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxsElevationDegree);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
