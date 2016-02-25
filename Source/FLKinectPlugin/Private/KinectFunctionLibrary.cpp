#include "FLKinectPluginPrivatePCH.h"

FVector UKinectPluginFunctionLibrary::GetJointPosition(FFLKinect_Body const& body, EFLKinect_JointType type)
{
	return body.positions[static_cast<uint8>(type)];
}

FRotator UKinectPluginFunctionLibrary::GetJointOrientation(FFLKinect_Body const& body, EFLKinect_JointType type)
{
	return body.orientations[static_cast<uint8>(type)];
}

EFLKinect_TrackingState UKinectPluginFunctionLibrary::GetTrackingState(UPARAM(ref) FFLKinect_Body const& body, EFLKinect_JointType type)
{
	return body.trackingStates[static_cast<uint8>(type)];
}


void UKinectPluginFunctionLibrary::GetKinectBody(uint8 number, FFLKinect_Body& out)
{
	out = FKinectPluginCore::GetInstance()->GetBody(number);
}

void UKinectPluginFunctionLibrary::GetKinectTrackedBodies(TArray<bool>& out)
{
	out.Empty(BODY_COUNT);
	out.Append(FKinectPluginCore::GetInstance()->TrackFlags, BODY_COUNT);
}


bool UKinectPluginFunctionLibrary::IsKinectBodyTracked(uint8 number)
{
	check(number < BODY_COUNT);
	return FKinectPluginCore::GetInstance()->TrackFlags[number];
}