#pragma once

#include "VimSourceCodeAccessor.h"

class FVimSourceCodeAccessModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	FVimSourceCodeAccessor VimSourceCodeAccessor;
};
