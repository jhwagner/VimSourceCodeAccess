#include "VimSourceCodeAccessPrivatePCH.h"
#include "Runtime/Core/Public/Features/IModularFeatures.h"
#include "VimSourceCodeAccessModule.h"

IMPLEMENT_MODULE( FVimSourceCodeAccessModule, VimSourceCodeAccess );

void FVimSourceCodeAccessModule::StartupModule()
{
	// Bind our source control provider to the editor
	IModularFeatures::Get().RegisterModularFeature(TEXT("SourceCodeAccessor"), &VimSourceCodeAccessor );
}

void FVimSourceCodeAccessModule::ShutdownModule()
{
	// Unbind provider from editor
	IModularFeatures::Get().UnregisterModularFeature(TEXT("SourceCodeAccessor"), &VimSourceCodeAccessor);
}
