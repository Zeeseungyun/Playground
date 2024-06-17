@echo off
REM Change this to your Unreal Engine installation path
set UE_ENGINE_PATH="C:\Users\zee\source\repos\UE5\UE5"

REM Change this to your project path
set PROJECT_PATH=D:\repos\Playground\Unreal\ProjectPlayground

REM Generate project files
dotnet "%UE_ENGINE_PATH%\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.dll" -projectfiles -project="%PROJECT_PATH%\ProjectPlayground.uproject" -game -engine -progress
