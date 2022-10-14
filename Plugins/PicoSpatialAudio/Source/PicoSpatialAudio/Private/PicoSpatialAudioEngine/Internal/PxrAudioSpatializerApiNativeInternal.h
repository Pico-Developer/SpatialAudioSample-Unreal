#pragma once
#include "PxrAudioSpatializerApiInternal.h"
#include "internal/pxr_audio_spatializer_internal_api.h"
#include "pxr_audio_spatializer_types.h"

namespace Pxr_Audio
{
	namespace Spatializer
	{
		class APINativeInternal : APIInternal
		{
		public:
			virtual ~APINativeInternal() override = default;
			virtual void
			UpdateAbsorptionMultiband(PxrAudioSpatializer_Context* Ctx, int GeomId, float* Absorption) override;
			virtual void UpdateScattering(PxrAudioSpatializer_Context* Ctx, int GeomId, float Scattering) override;
			virtual void UpdateTransmission(PxrAudioSpatializer_Context* Ctx, int GeomId, float Transmission) override;
		};
	}
}
