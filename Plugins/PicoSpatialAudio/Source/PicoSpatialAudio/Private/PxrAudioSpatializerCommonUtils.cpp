#include "PxrAudioSpatializerCommonUtils.h"

DEFINE_LOG_CATEGORY(LogPicoSpatialAudio);

namespace Pxr_Audio
{
	namespace Spatializer
	{
		void ConvertToPicoSpatialAudioCoordinates(const FVector& VectorUnrealCoordinate, float* VectorPicoCoordinate)
		{
			//	Unreal: Z+: Up, Y+: Right, X+: Front
			//	Pico: Y+: Up, X+: Right, Z-: Front

			//	Pico.X
			VectorPicoCoordinate[0] = VectorUnrealCoordinate.Y / 100.f;
			//	Pico.Y
			VectorPicoCoordinate[1] = VectorUnrealCoordinate.Z / 100.f;
			//	Pico.Z
			VectorPicoCoordinate[2] = VectorUnrealCoordinate.X / -100.f;
		}

		PxrAudioSpatializer_RenderingMode ConvertToInternalRenderingMode(
			const EPxrAudioSpatializer_RenderingMode RenderingModeUe)
		{
			switch (RenderingModeUe)
			{
			case EPxrAudioSpatializer_RenderingMode::Low_Quality:
				return PASP_LOW_QUALITY;
			case EPxrAudioSpatializer_RenderingMode::Medium_Quality:
				return PASP_MEDIUM_QUALITY;
			case EPxrAudioSpatializer_RenderingMode::High_Quality:
				return PASP_HIGH_QUALITY;
			case EPxrAudioSpatializer_RenderingMode::Ambisonic_First_Order:
				return PASP_AMBISONIC_FIRST_ORDER;
			case EPxrAudioSpatializer_RenderingMode::Ambisonic_Second_Order:
				return PASP_AMBISONIC_SECOND_ORDER;
			case EPxrAudioSpatializer_RenderingMode::Ambisonic_Third_Order:
				return PASP_AMBISONIC_THIRD_ORDER;
			case EPxrAudioSpatializer_RenderingMode::Ambisonic_Fourth_Order:
				return PASP_AMBISONIC_FOURTH_ORDER;
			case EPxrAudioSpatializer_RenderingMode::Ambisonic_Fifth_Order:
				return PASP_AMBISONIC_FIFTH_ORDER;
			case EPxrAudioSpatializer_RenderingMode::Ambisonic_Sixth_Order:
				return PASP_AMBISONIC_SIXTH_ORDER;
			case EPxrAudioSpatializer_RenderingMode::Ambisonic_Seventh_Order:
				return PASP_AMBISONIC_SEVENTH_ORDER;
			default:
				return PASP_MEDIUM_QUALITY;
			}
		}

		float DB2Mag(const float DB)
		{
			return FMath::Pow(10.0f, DB / 20.0f);
		}
	}
}
