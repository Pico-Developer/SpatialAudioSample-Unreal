#include "PxrAudioSpatializerApiNativeInternal.h"

namespace Pxr_Audio
{
	namespace Spatializer
	{
		void APINativeInternal::UpdateAbsorptionMultiband(PxrAudioSpatializer_Context* Ctx, int GeomId,
		                                                  float* Absorption)
		{
			PxrAudioSpatializer_UpdateAbsorptionMultiband(Ctx, GeomId, Absorption);
		}

		void APINativeInternal::UpdateScattering(PxrAudioSpatializer_Context* Ctx, int GeomId, float Scattering)
		{
			PxrAudioSpatializer_UpdateScattering(Ctx, GeomId, Scattering);
		}

		void APINativeInternal::UpdateTransmission(PxrAudioSpatializer_Context* Ctx, int GeomId, float Transmission)
		{
			PxrAudioSpatializer_UpdateTransmission(Ctx, GeomId, Transmission);
		}
	}
}
