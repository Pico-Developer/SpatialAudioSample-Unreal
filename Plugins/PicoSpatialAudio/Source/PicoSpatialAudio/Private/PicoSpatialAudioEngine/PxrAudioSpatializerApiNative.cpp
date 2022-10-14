#include "PxrAudioSpatializerApiNative.h"

namespace Pxr_Audio
{
	namespace Spatializer
	{
		const char* APINative::GetVersion(int* Major, int* Minor, int* Patch)
		{
			return PxrAudioSpatializer_GetVersion(Major, Minor, Patch);
		}

		PxrAudioSpatializer_Result APINative::CreateContext(PxrAudioSpatializer_Context** Ctx,
		                                                    PxrAudioSpatializer_RenderingMode Mode,
		                                                    size_t FramesPerBuffer,
		                                                    size_t SampleRate)
		{
			return PxrAudioSpatializer_CreateContext(Ctx, Mode, FramesPerBuffer, SampleRate);
		}

		PxrAudioSpatializer_Result APINative::InitializeContext(PxrAudioSpatializer_Context* Ctx)
		{
			return PxrAudioSpatializer_InitializeContext(Ctx);
		}

		PxrAudioSpatializer_Result APINative::SubmitMesh(PxrAudioSpatializer_Context* Ctx,
		                                                 const float* Vertices,
		                                                 int VerticesCount,
		                                                 const int* Indices,
		                                                 int IndicesCount,
		                                                 PxrAudioSpatializer_AcousticsMaterial
		                                                 Material,
		                                                 int* GeometryId)
		{
			return PxrAudioSpatializer_SubmitMesh(Ctx, Vertices, VerticesCount, Indices, IndicesCount, Material,
			                                      GeometryId);
		}

		PxrAudioSpatializer_Result APINative::SubmitMeshAndMaterialFactor(
			PxrAudioSpatializer_Context* Ctx,
			const float* Vertices,
			int VerticesCount,
			const int* Indices,
			int IndicesCount,
			const float* AbsorptionFactor,
			float ScatteringFactor,
			float TransmissionFactor,
			int* GeometryId)
		{
			return PxrAudioSpatializer_SubmitMeshAndMaterialFactor(Ctx, Vertices, VerticesCount, Indices, IndicesCount,
			                                                       AbsorptionFactor, ScatteringFactor,
			                                                       TransmissionFactor,
			                                                       GeometryId);
		}

		PxrAudioSpatializer_Result APINative::GetAbsorptionFactor(
			PxrAudioSpatializer_AcousticsMaterial Material, float* AbsorptionFactor)
		{
			return PxrAudioSpatializer_GetAbsorptionFactor(Material, AbsorptionFactor);
		}

		PxrAudioSpatializer_Result APINative::GetScatteringFactor(
			PxrAudioSpatializer_AcousticsMaterial Material, float* ScatteringFactor)
		{
			return PxrAudioSpatializer_GetScatteringFactor(Material, ScatteringFactor);
		}

		PxrAudioSpatializer_Result APINative::GetTransmissionFactor(
			PxrAudioSpatializer_AcousticsMaterial Material, float* TransmissionFactor)
		{
			return PxrAudioSpatializer_GetTransmissionFactor(Material, TransmissionFactor);
		}

		PxrAudioSpatializer_Result APINative::CommitScene(PxrAudioSpatializer_Context* Ctx)
		{
			return PxrAudioSpatializer_CommitScene(Ctx);
		}

		PxrAudioSpatializer_Result APINative::AddSource(PxrAudioSpatializer_Context* Ctx,
		                                                PxrAudioSpatializer_SourceMode SourceMode,
		                                                const float* Position,
		                                                int* SourceId,
		                                                bool bIsAsync)
		{
			return PxrAudioSpatializer_AddSource(Ctx, SourceMode, Position, SourceId, bIsAsync);
		}

		PxrAudioSpatializer_Result APINative::AddSourceWithOrientation(
			PxrAudioSpatializer_Context* Ctx,
			PxrAudioSpatializer_SourceMode Mode,
			const float* Position,
			const float* Front,
			const float* Up,
			float Radius,
			int* SourceId,
			bool bIsAsync)
		{
			return PxrAudioSpatializer_AddSourceWithOrientation(Ctx, Mode, Position, Front, Up, Radius, SourceId,
			                                                    bIsAsync);
		}

		PxrAudioSpatializer_Result APINative::AddSourceWithConfig(PxrAudioSpatializer_Context* Ctx,
		                                                          const PxrAudioSpatializer_SourceConfig* SourceConfig,
		                                                          int* SourceId,
		                                                          bool bIsAsync)
		{
			return PxrAudioSpatializer_AddSourceWithConfig(Ctx, SourceConfig, SourceId, bIsAsync);
		}

		PxrAudioSpatializer_Result APINative::SetSourceAttenuationMode(
			PxrAudioSpatializer_Context* Ctx,
			int SourceId,
			PxrAudioSpatializer_SourceAttenuationMode Mode,
			DistanceAttenuationCallback DirectDistanceAttenuationCallback,
			DistanceAttenuationCallback IndirectDistanceAttenuationCallback)
		{
			return PxrAudioSpatializer_SetSourceAttenuationMode(Ctx, SourceId, Mode, DirectDistanceAttenuationCallback,
			                                                    IndirectDistanceAttenuationCallback);
		}

		PxrAudioSpatializer_Result APINative::SetSourceRange(
			PxrAudioSpatializer_Context* Ctx, int SourceId, float RangeMin, float RangeMax)
		{
			return PxrAudioSpatializer_SetSourceRange(Ctx, SourceId, RangeMin, RangeMax);
		}

		PxrAudioSpatializer_Result APINative::RemoveSource(
			PxrAudioSpatializer_Context* Ctx, int SourceId)
		{
			return PxrAudioSpatializer_RemoveSource(Ctx, SourceId);
		}

		PxrAudioSpatializer_Result APINative::SubmitSourceBuffer(PxrAudioSpatializer_Context* Ctx,
		                                                         int SourceId,
		                                                         const float* InputBufferPtr,
		                                                         size_t NumFrames)
		{
			return PxrAudioSpatializer_SubmitSourceBuffer(Ctx, SourceId, InputBufferPtr, NumFrames);
		}

		PxrAudioSpatializer_Result
		APINative::SubmitAmbisonicChannelBuffer(PxrAudioSpatializer_Context* Ctx,
		                                        const float* AmbisonicChannelBuffer,
		                                        int Order,
		                                        int Degree,
		                                        PxrAudioSpatializer_AmbisonicNormalizationType NormType,
		                                        float Gain)
		{
			return PxrAudioSpatializer_SubmitAmbisonicChannelBuffer(Ctx, AmbisonicChannelBuffer, Order, Degree,
			                                                        NormType,
			                                                        Gain);
		}

		PxrAudioSpatializer_Result APINative::SubmitInterleavedAmbisonicBuffer(
			PxrAudioSpatializer_Context* Ctx,
			const float* AmbisonicBuffer,
			int AmbisonicOrder,
			PxrAudioSpatializer_AmbisonicNormalizationType NormType,
			float Gain)
		{
			return PxrAudioSpatializer_SubmitInterleavedAmbisonicBuffer(Ctx, AmbisonicBuffer, AmbisonicOrder, NormType,
			                                                            Gain);
		}

		PxrAudioSpatializer_Result APINative::SubmitMatrixInputBuffer(PxrAudioSpatializer_Context* Ctx,
		                                                              const float* InputBuffer,
		                                                              int InputChannelIndex)
		{
			return PxrAudioSpatializer_SubmitMatrixInputBuffer(Ctx, InputBuffer, InputChannelIndex);
		}

		PxrAudioSpatializer_Result APINative::GetInterleavedBinauralBuffer(
			PxrAudioSpatializer_Context* Ctx,
			float* OutputBufferPtr,
			size_t NumFrames,
			bool bIsAccumulative)
		{
			return PxrAudioSpatializer_GetInterleavedBinauralBuffer(Ctx, OutputBufferPtr, NumFrames, bIsAccumulative);
		}

		PxrAudioSpatializer_Result APINative::GetPlanarBinauralBuffer(PxrAudioSpatializer_Context* Ctx,
		                                                              float* const * OutputBufferPtr,
		                                                              size_t NumFrames,
		                                                              bool bIsAccumulative)
		{
			return PxrAudioSpatializer_GetPlanarBinauralBuffer(Ctx, OutputBufferPtr, NumFrames, bIsAccumulative);
		}

		PxrAudioSpatializer_Result APINative::GetInterleavedLoudspeakersBuffer(PxrAudioSpatializer_Context* Ctx,
		                                                                       float* OutputBufferPtr, size_t NumFrames)
		{
			return PxrAudioSpatializer_GetInterleavedLoudspeakersBuffer(Ctx, OutputBufferPtr, NumFrames);
		}

		PxrAudioSpatializer_Result APINative::GetPlanarLoudspeakersBuffer(PxrAudioSpatializer_Context* Ctx,
		                                                                  float* const* OutputBufferPtr,
		                                                                  size_t NumFrames)
		{
			return PxrAudioSpatializer_GetPlanarLoudspeakersBuffer(Ctx, OutputBufferPtr, NumFrames);
		}

		PxrAudioSpatializer_Result APINative::UpdateScene(PxrAudioSpatializer_Context* Ctx)
		{
			return PxrAudioSpatializer_UpdateScene(Ctx);
		}

		PxrAudioSpatializer_Result APINative::SetDopplerEffect(PxrAudioSpatializer_Context* Ctx, int SourceId, int On)
		{
			return PxrAudioSpatializer_SetDopplerEffect(Ctx, SourceId, On);
		}

		PxrAudioSpatializer_Result APINative::SetPlaybackMode(PxrAudioSpatializer_Context* Ctx,
		                                                      PxrAudioSpatializer_PlaybackMode PlaybackMode)
		{
			return PxrAudioSpatializer_SetPlaybackMode(Ctx, PlaybackMode);
		}

		PxrAudioSpatializer_Result APINative::SetLoudspeakerArray(PxrAudioSpatializer_Context* Ctx,
		                                                          const float* Positions,
		                                                          int NumLoudspeakers)
		{
			return PxrAudioSpatializer_SetLoudspeakerArray(Ctx, Positions, NumLoudspeakers);
		}

		PxrAudioSpatializer_Result APINative::SetMappingMatrix(PxrAudioSpatializer_Context* Ctx, const float* Matrix,
		                                                       int NumInputChannels, int NumOutputChannels)
		{
			return PxrAudioSpatializer_SetMappingMatrix(Ctx, Matrix, NumInputChannels, NumOutputChannels);
		}

		PxrAudioSpatializer_Result APINative::SetAmbisonicOrientation(PxrAudioSpatializer_Context* Ctx,
		                                                              const float* Front,
		                                                              const float* Up)
		{
			return PxrAudioSpatializer_SetAmbisonicOrientation(Ctx, Front, Up);
		}

		PxrAudioSpatializer_Result APINative::SetListenerPosition(PxrAudioSpatializer_Context* Ctx,
		                                                          const float* Position)
		{
			return PxrAudioSpatializer_SetListenerPosition(Ctx, Position);
		}

		PxrAudioSpatializer_Result APINative::SetListenerOrientation(PxrAudioSpatializer_Context* Ctx,
		                                                             const float* Front,
		                                                             const float* Up)
		{
			return PxrAudioSpatializer_SetListenerOrientation(Ctx, Front, Up);
		}

		PxrAudioSpatializer_Result APINative::SetListenerPose(PxrAudioSpatializer_Context* Ctx, const float* Position,
		                                                      const float* Front, const float* Up)
		{
			return PxrAudioSpatializer_SetListenerPose(Ctx, Position, Front, Up);
		}

		PxrAudioSpatializer_Result APINative::SetSourcePosition(PxrAudioSpatializer_Context* Ctx, int SourceId,
		                                                        const float* Position)
		{
			return PxrAudioSpatializer_SetSourcePosition(Ctx, SourceId, Position);
		}

		PxrAudioSpatializer_Result APINative::SetSourceGain(PxrAudioSpatializer_Context* Ctx, int SourceId, float Gain)
		{
			return PxrAudioSpatializer_SetSourceGain(Ctx, SourceId, Gain);
		}

		PxrAudioSpatializer_Result APINative::SetSourceSize(PxrAudioSpatializer_Context* Ctx, int SourceId,
		                                                    float VolumetricSize)
		{
			return PxrAudioSpatializer_SetSourceSize(Ctx, SourceId, VolumetricSize);
		}

		PxrAudioSpatializer_Result APINative::UpdateSourceMode(PxrAudioSpatializer_Context* Ctx, int SourceId,
		                                                       PxrAudioSpatializer_SourceMode Mode)
		{
			return PxrAudioSpatializer_UpdateSourceMode(Ctx, SourceId, Mode);
		}

		PxrAudioSpatializer_Result APINative::Destroy(PxrAudioSpatializer_Context* Ctx)
		{
			return PxrAudioSpatializer_Destroy(Ctx);
		}
	}
}
