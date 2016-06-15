namespace UnrealBuildTool.Rules
{
	public class VimSourceCodeAccess : ModuleRules
	{
        public VimSourceCodeAccess(TargetInfo Target)
		{
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"SourceCodeAccess",
					"DesktopPlatform"
				}
			);
		}
	}
}
