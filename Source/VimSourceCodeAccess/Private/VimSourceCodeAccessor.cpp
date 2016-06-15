#include "VimSourceCodeAccessPrivatePCH.h"
#include "VimSourceCodeAccessor.h"
#include "DesktopPlatformModule.h"

#define LOCTEXT_NAMESPACE "VimSourceCodeAccessor"

DEFINE_LOG_CATEGORY_STATIC(LogVimAccessor, Log, All);

bool FVimSourceCodeAccessor::CanAccessSourceCode() const
{
	return FPaths::FileExists(TEXT("/usr/bin/clang"));
}

FName FVimSourceCodeAccessor::GetFName() const
{
	return FName("VimSourceCodeAccessor");
}

FText FVimSourceCodeAccessor::GetNameText() const
{
	return LOCTEXT("VimDisplayName", "Vim");
}

FText FVimSourceCodeAccessor::GetDescriptionText() const
{
	return LOCTEXT("VimDisplayDesc", "Open source code files in Vim");
}

bool FVimSourceCodeAccessor::OpenSolution()
{
	FString SolutionPath;
	if(FDesktopPlatformModule::Get()->GetSolutionPath(SolutionPath))
	{
                // Handle spaces in path names
                const FString FullPath = FString::Printf(TEXT("\"%s\""), *SolutionPath);
		if ( FPaths::FileExists( FullPath ) )
		{
			FPlatformProcess::LaunchFileInDefaultExternalApplication( *FullPath );
                        FString IDEPath = FString(TEXT("/usr/local/bin/vim"));
                        FProcHandle Proc = FPlatformProcess::CreateProc(*IDEPath, *SolutionPath, true, false, false, nullptr, 0, nullptr, nullptr);
                        if (Proc.IsValid())
                        {
                          return true;
                        }
		}
	}
	return false;
}

bool FVimSourceCodeAccessor::OpenFileAtLine(const FString& FullPath, int32 LineNumber, int32 ColumnNumber)
{
        // Handle spaces in path names
        const FString SourcePath = FString::Printf(TEXT("\"%s:%d:%d\""), *FullPath, LineNumber, ColumnNumber);

        if ( FPaths::FileExists( SourcePath ) )
	{
                FString IDEPath = FString(TEXT("/usr/local/bin/vim"));
                FProcHandle Proc = FPlatformProcess::CreateProc(*IDEPath, *SourcePath, true, false, false, nullptr, 0, nullptr, nullptr);
                if (Proc.IsValid())
                {
                      return true;
                }
        }
        return false;
}

bool FVimSourceCodeAccessor::OpenSourceFiles(const TArray<FString>& AbsoluteSourcePaths)
{
	for ( const FString& SourcePath : AbsoluteSourcePaths )
	{
                // Handle spaces in path names
                const FString FullPath = FString::Printf(TEXT("\"%s\""), *SourcePath);

                FString IDEPath = FString(TEXT("/usr/local/bin/vim"));
                FProcHandle Proc = FPlatformProcess::CreateProc(*IDEPath, *FullPath, true, false, false, nullptr, 0, nullptr, nullptr);
                if (Proc.IsValid())
                {
                      return true;
                }
	}

	return false;
}

bool FVimSourceCodeAccessor::AddSourceFiles(const TArray<FString>& AbsoluteSourcePaths, const TArray<FString>& AvailableModules)
{
        // Not supported
	return false;
}

bool FVimSourceCodeAccessor::SaveAllOpenDocuments() const
{
        // Not supported
        return false;
}

void FVimSourceCodeAccessor::Tick(const float DeltaTime)
{
}

#undef LOCTEXT_NAMESPACE
