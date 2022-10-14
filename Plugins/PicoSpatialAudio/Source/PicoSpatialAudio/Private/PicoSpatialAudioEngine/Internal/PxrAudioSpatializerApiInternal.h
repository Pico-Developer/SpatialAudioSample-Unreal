#pragma once
#include "pxr_audio_spatializer_types.h"

namespace Pxr_Audio
{
	namespace Spatializer
	{
		//	Internal API base for Internal API implementation for various audio engine host (Unreal, Wwise, etc.) 
		class APIInternal
		{
		public:
			APIInternal() = default;
			virtual ~APIInternal() = default;

			virtual void UpdateAbsorptionMultiband(PxrAudioSpatializer_Context* Ctx, int GeomId, float* Absorption) = 0;
			virtual void UpdateScattering(PxrAudioSpatializer_Context* Ctx, int GeomId, float Scattering) = 0;
			virtual void UpdateTransmission(PxrAudioSpatializer_Context* Ctx, int GeomId, float Transmission) = 0;
		};
	}
}