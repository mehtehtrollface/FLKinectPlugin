#pragma once

//#include "FLKinectPluginPrivatePCH.h"
#include "CoreUObject.h"
#include "Vector.h"
#include "KinectPluginCore.generated.h"
/*
#include "AllowWindowsPlatformTypes.h"
#include "Kinect.h"
#include "HideWindowsPlatformTypes.h"
*/

UENUM(BlueprintType)
enum class EFLKinect_HandState : uint8
{
	Unknown = 0, NotTracking = 1, Open = 2, Closed = 3, Lasso = 4
};

UENUM(BlueprintType)
enum class EFLKinect_JointType : uint8
{
	SpineBase = 0,
	SpineMid = 1,
	Neck = 2,
	Head = 3,
	ShoulderLeft = 4,
	ElbowLeft = 5,
	WristLeft = 6,
	HandLeft = 7,
	ShoulderRight = 8,
	ElbowRight = 9,
	WristRight = 10,
	HandRight = 11,
	HipLeft = 12,
	KneeLeft = 13,
	AnkleLeft = 14,
	FootLeft = 15,
	HipRight = 16,
	KneeRight = 17,
	AnkleRight = 18,
	FootRight = 19,
	SpineShoulder = 20,
	HandTipLeft = 21,
	ThumbLeft = 22,
	HandTipRight = 23,
	ThumbRight = 24,
	//HACK (OS): this compiler doesn't support 	Count = (ThumbRight + 1)
	Count = 25
};

UENUM(BlueprintType)
enum class EFLKinect_TrackingState : uint8
{  
	Not_Tracked = 0, Inferred = 1, Tracking = 2
};

USTRUCT(BlueprintType)
struct FFLKinect_Body
{	
	GENERATED_BODY()
	static const uint8 nJoints{ static_cast<uint8>(EFLKinect_JointType::Count) };
	UPROPERTY(BlueprintReadOnly) EFLKinect_HandState HandLeftState;
	UPROPERTY(BlueprintReadOnly) EFLKinect_HandState HandRightState;
	FVector positions[nJoints];
	FRotator orientations[nJoints];
	EFLKinect_TrackingState trackingStates[nJoints];
};



class FKinectPluginCore : public FRunnable
{
public:	
	
	/* Begin FRunnable interface. */
	virtual bool	Init()	override;
	virtual uint32	Run()	override;
	virtual void	Stop()	override;
	/* End FRunnable interface */

	/* Begin Singleton Interface*/
	static FKinectPluginCore* const GetInstance();
	/* End Singleton Interface*/

	FFLKinect_Body const& GetBody(uint8 number);

	bool			TrackFlags[BODY_COUNT];
	
private:
	FKinectPluginCore();
	FKinectPluginCore(FKinectPluginCore const&);
	FKinectPluginCore& operator=(FKinectPluginCore const&);
	~FKinectPluginCore();
	
	void ProcessBody(INT64 nTime, int nBodyCount, IBody** ppBodies);
	void Update();
	HRESULT InitializeDefaultSensor();
	

	// Current Kinect
	IKinectSensor*          m_pKinectSensor;
	ICoordinateMapper*      m_pCoordinateMapper;
	uint32                  m_nFramesSinceUpdate;
	int64                   m_nStartTime;
	int64                   m_nLastCounter;
	int64                   m_nNextStatusTime;
	double                  m_fFreq;
	IBodyFrameReader*       m_pBodyFrameReader;

	FRunnableThread* Thread;
	
	FFLKinect_Body	bodies[BODY_COUNT];
	
	/* Frunnable Helper. */
	bool bRunning;
	static FKinectPluginCore* Instance;
};



