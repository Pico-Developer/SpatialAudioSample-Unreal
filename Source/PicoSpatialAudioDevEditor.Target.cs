// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class PicoSpatialAudioDevEditorTarget : TargetRules
{
	public PicoSpatialAudioDevEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
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
