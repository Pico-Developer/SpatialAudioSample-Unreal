#pragma once
#include "pxr_audio_spatializer_types.h"
#include "PicoSpatialAudioEnums.h"

DECLARE_LOG_CATEGORY_EXTERN(LogPicoSpatialAudio, Display, All);

#define PXR_AUDIO_CHECK_RESULT(Result) if ((Result) != PASP_SUCCESS) return (Result);

namespace Pxr_Audio
{
	namespace Spatializer
	{
		void ConvertToPicoSpatialAudioCoordinates(const FVector& VectorUnrealCoordinate, float* VectorPicoCoordinate);
		PxrAudioSpatializer_RenderingMode ConvertToInternalRenderingMode(
			EPxrAudioSpatializer_RenderingMode RenderingModeUe);

		float DB2Mag(float DB);
	}
}
