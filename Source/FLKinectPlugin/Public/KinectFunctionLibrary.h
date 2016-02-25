#pragma once
#include "KinectPluginCore.h"
#include "KinectFunctionLibrary.generated.h"

UCLASS()
class FLKINECTPLUGIN_API UKinectPluginFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category = "Kinect")
		static FVector GetJointPosition(UPARAM(ref) FFLKinect_Body const& body, EFLKinect_JointType type);

	UFUNCTION(BlueprintPure, Category = "Kinect")
		static FRotator GetJointOrientation(UPARAM(ref) FFLKinect_Body const& body, EFLKinect_JointType type);

	UFUNCTION(BlueprintPure, Category = "Kinect")
		static EFLKinect_TrackingState GetTrackingState(UPARAM(ref) FFLKinect_Body const& body, EFLKinect_JointType type);

	UFUNCTION(BlueprintCallable, Category = "Kinect")
		static void GetKinectTrackedBodies(TArray<bool>& out);

	UFUNCTION(BlueprintCallable, Category = "Kinect")
		static void GetKinectBody(uint8 number, FFLKinect_Body& out);

	UFUNCTION(BlueprintCallable, Category = "Kinect")
		static bool IsKinectBodyTracked(uint8 number);

};