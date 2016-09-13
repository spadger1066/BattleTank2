// It's mine. Leave it alone

#include "BattleTank2.h"
#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle){
	//auto Time = GetWorld()->GetTimeSeconds();
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *Name, Throttle)

}
