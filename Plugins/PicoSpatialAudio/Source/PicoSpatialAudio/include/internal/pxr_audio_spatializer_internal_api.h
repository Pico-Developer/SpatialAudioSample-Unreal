//
// Created by Xuzhou Ye on 2022/6/13.
// Copyright (c) 2022 ByteDance Ltd. All rights reserved.
//

#ifndef YGGDRASIL_PXR_AUDIO_SPATIALIZER_INTERNAL_API_H
#define YGGDRASIL_PXR_AUDIO_SPATIALIZER_INTERNAL_API_H
#include "pxr_audio_spatializer_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 * @param ctx
 * @param geom_id
 * @param absorption
 */
PXR_AUDIO_SPATIALIZER_EXPORT void PxrAudioSpatializer_UpdateAbsorptionMultiband(PxrAudioSpatializer_Context* ctx, int geom_id, float* absorption);

/**
 * @param ctx
 * @param scattering
 */
PXR_AUDIO_SPATIALIZER_EXPORT void PxrAudioSpatializer_UpdateScattering(PxrAudioSpatializer_Context* ctx, int geom_id, float scattering);

PXR_AUDIO_SPATIALIZER_EXPORT void PxrAudioSpatializer_UpdateTransmission(PxrAudioSpatializer_Context* ctx, int geom_id, float transmission);

#ifdef __cplusplus
}
#endif

#endif  // YGGDRASIL_PXR_AUDIO_SPATIALIZER_INTERNAL_API_H
