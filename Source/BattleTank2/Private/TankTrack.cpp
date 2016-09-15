// It's mine. Leave it alone

#include "BattleTank2.h"
#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle){

	// TODO clamp actual throttle value so player can't override

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
