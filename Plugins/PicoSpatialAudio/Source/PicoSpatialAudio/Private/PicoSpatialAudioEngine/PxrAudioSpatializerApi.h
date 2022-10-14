#pragma once
#include "pxr_audio_spatializer_types.h"

namespace Pxr_Audio
{
	namespace Spatializer
	{
		//	API base for API implementation for various audio engine host (Unreal, Wwise, etc.) 
		class API
		{
		public:
			API() = default;
			virtual ~API() = default;

			virtual const char* GetVersion(int* Major, int* Minor, int* Patch) = 0;
			virtual PxrAudioSpatializer_Result CreateContext(PxrAudioSpatializer_Context** Ctx,
			                                                 PxrAudioSpatializer_RenderingMode Mode,
			                                                 size_t FramesPerBuffer,
			                                                 size_t SampleRate) = 0;
			virtual PxrAudioSpatializer_Result InitializeContext(PxrAudioSpatializer_Context* Ctx) = 0;
			virtual PxrAudioSpatializer_Result SubmitMesh(PxrAudioSpatializer_Context* Ctx,
			                                              const float* Vertices,
			                                              int VerticesCount,
			                                              const int* Indices,
			                                              int IndicesCount,
			                                              PxrAudioSpatializer_AcousticsMaterial
			                                              Material,
			                                              int* GeometryId) = 0;
			virtual PxrAudioSpatializer_Result SubmitMeshAndMaterialFactor(
				PxrAudioSpatializer_Context* Ctx,
				const float* Vertices,
				int VerticesCount,
				const int* Indices,
				int IndicesCount,
				const float* AbsorptionFactor,
				float ScatteringFactor,
				float TransmissionFactor,
				int* GeometryId) = 0;
			virtual PxrAudioSpatializer_Result GetAbsorptionFactor(
				PxrAudioSpatializer_AcousticsMaterial Material, float* AbsorptionFactor) = 0;
			virtual PxrAudioSpatializer_Result GetScatteringFactor(
				PxrAudioSpatializer_AcousticsMaterial Material, float* ScatteringFactor) = 0;
			virtual PxrAudioSpatializer_Result GetTransmissionFactor(
				PxrAudioSpatializer_AcousticsMaterial Material, float* TransmissionFactor) = 0;
			virtual PxrAudioSpatializer_Result CommitScene(PxrAudioSpatializer_Context* Ctx) = 0;
			virtual PxrAudioSpatializer_Result AddSource(PxrAudioSpatializer_Context* Ctx,
			                                             PxrAudioSpatializer_SourceMode SourceMode,
			                                             const float* Position,
			                                             int* SourceId,
			                                             bool bIsAsync = false) = 0;
			virtual PxrAudioSpatializer_Result AddSourceWithOrientation(
				PxrAudioSpatializer_Context* Ctx,
				PxrAudioSpatializer_SourceMode Mode,
				const float* Position,
				const float* Front,
				const float* Up,
				float Radius,
				int* SourceId,
				bool bIsAsync = false) = 0;
			virtual PxrAudioSpatializer_Result AddSourceWithConfig(PxrAudioSpatializer_Context* Ctx,
			                                                       const PxrAudioSpatializer_SourceConfig* SourceConfig,
			                                                       int* SourceId,
			                                                       bool bIsAsync = false) = 0;
			virtual PxrAudioSpatializer_Result SetSourceAttenuationMode(
				PxrAudioSpatializer_Context* Ctx,
				int SourceId,
				PxrAudioSpatializer_SourceAttenuationMode Mode,
				DistanceAttenuationCallback DirectDistanceAttenuationCallback = nullptr,
				DistanceAttenuationCallback IndirectDistanceAttenuationCallback = nullptr) = 0;
			virtual PxrAudioSpatializer_Result SetSourceRange(
				PxrAudioSpatializer_Context* Ctx, int SourceId, float RangeMin, float RangeMax) = 0;
			virtual PxrAudioSpatializer_Result RemoveSource(
				PxrAudioSpatializer_Context* Ctx, int SourceId) = 0;
			virtual PxrAudioSpatializer_Result SubmitSourceBuffer(PxrAudioSpatializer_Context* Ctx,
			                                                      int SourceId,
			                                                      const float* InputBufferPtr,
			                                                      size_t NumFrames) = 0;
			virtual PxrAudioSpatializer_Result
			SubmitAmbisonicChannelBuffer(PxrAudioSpatializer_Context* Ctx,
			                             const float* AmbisonicChannelBuffer,
			                             int Order,
			                             int Degree,
			                             PxrAudioSpatializer_AmbisonicNormalizationType NormType,
			                             float Gain) = 0;
			virtual PxrAudioSpatializer_Result SubmitInterleavedAmbisonicBuffer(
				PxrAudioSpatializer_Context* Ctx,
				const float* AmbisonicBuffer,
				int AmbisonicOrder,
				PxrAudioSpatializer_AmbisonicNormalizationType NormType,
				float Gain) = 0;
			virtual PxrAudioSpatializer_Result SubmitMatrixInputBuffer(PxrAudioSpatializer_Context* Ctx,
			                                                           const float* InputBuffer,
			                                                           int InputChannelIndex) = 0;
			virtual PxrAudioSpatializer_Result GetInterleavedBinauralBuffer(
				PxrAudioSpatializer_Context* Ctx,
				float* OutputBufferPtr,
				size_t NumFrames,
				bool bIsAccumulative = false) = 0;
			virtual PxrAudioSpatializer_Result GetPlanarBinauralBuffer(PxrAudioSpatializer_Context* Ctx,
			                                                           float* const * OutputBufferPtr,
			                                                           size_t NumFrames,
			                                                           bool bIsAccumulative = false) = 0;
			virtual PxrAudioSpatializer_Result GetInterleavedLoudspeakersBuffer(
				PxrAudioSpatializer_Context* Ctx,
				float* OutputBufferPtr,
				size_t NumFrames) = 0;
			virtual PxrAudioSpatializer_Result GetPlanarLoudspeakersBuffer(
				PxrAudioSpatializer_Context* Ctx,
				float* const * OutputBufferPtr,
				size_t NumFrames) = 0;
			virtual PxrAudioSpatializer_Result UpdateScene(PxrAudioSpatializer_Context* Ctx) = 0;
			virtual PxrAudioSpatializer_Result SetDopplerEffect(
				PxrAudioSpatializer_Context* Ctx, int SourceId, int On) = 0;
			virtual PxrAudioSpatializer_Result SetPlaybackMode(
				PxrAudioSpatializer_Context* Ctx, PxrAudioSpatializer_PlaybackMode PlaybackMode) = 0;
			virtual PxrAudioSpatializer_Result SetLoudspeakerArray(
				PxrAudioSpatializer_Context* Ctx, const float* Positions, int NumLoudspeakers) = 0;
			virtual PxrAudioSpatializer_Result SetMappingMatrix(PxrAudioSpatializer_Context* Ctx,
			                                                    const float* Matrix,
			                                                    int NumInputChannels,
			                                                    int NumOutputChannels) = 0;
			virtual PxrAudioSpatializer_Result SetAmbisonicOrientation(
				PxrAudioSpatializer_Context* Ctx, const float* Front, const float* Up) = 0;
			virtual PxrAudioSpatializer_Result SetListenerPosition(
				PxrAudioSpatializer_Context* Ctx, const float* Position) = 0;
			virtual PxrAudioSpatializer_Result SetListenerOrientation(
				PxrAudioSpatializer_Context* Ctx, const float* Front, const float* Up) = 0;
			virtual PxrAudioSpatializer_Result SetListenerPose(PxrAudioSpatializer_Context* Ctx,
			                                                   const float* Position,
			                                                   const float* Front,
			                                                   const float* Up) = 0;
			virtual PxrAudioSpatializer_Result SetSourcePosition(
				PxrAudioSpatializer_Context* Ctx, int SourceId, const float* Position) = 0;
			virtual PxrAudioSpatializer_Result SetSourceGain(
				PxrAudioSpatializer_Context* Ctx, int SourceId, float Gain) = 0;
			virtual PxrAudioSpatializer_Result SetSourceSize(
				PxrAudioSpatializer_Context* Ctx, int SourceId, float VolumetricSize) = 0;
			virtual PxrAudioSpatializer_Result UpdateSourceMode(PxrAudioSpatializer_Context* Ctx,
			                                                    int SourceId,
			                                                    PxrAudioSpatializer_SourceMode Mode) = 0;
			virtual PxrAudioSpatializer_Result Destroy(PxrAudioSpatializer_Context* Ctx) = 0;
		};
	}
}
