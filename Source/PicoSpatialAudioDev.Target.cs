// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class PicoSpatialAudioDevTarget : TargetRules
{
	public PicoSpatialAudioDevTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "PicoSpatialAudioDev" } );
		if (Target.Platform == UnrealTargetPlatform.Mac)
		{
			bOverrideBuildEnvironment = true;
			AdditionalCompilerArguments = "-Wno-unused-but-set-variable";
		}
		
		ProjectDefinitions.Add("PICO_SPATIAL_AUDIO_FEATURE_TEST");
	}
}
