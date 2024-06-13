@echo off
REM Change this to your Unreal Engine installation path
set UE_ENGINE_PATH="C:\Users\zee\source\repos\UE5\UE5"

REM Change this to your project path
set PROJECT_PATH="D:\repos\Playground\Unreal\ProjectPlayground"

REM Generate project files
%UE_ENGINE_PATH%\Engine\Build\BatchFiles\GenerateProjectFiles.bat -project="%PROJECT_PATH%\ProjectPlayground.uproject"
pause
