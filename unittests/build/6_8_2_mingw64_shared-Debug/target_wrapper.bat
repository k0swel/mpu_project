@echo off
SetLocal EnableDelayedExpansion
(set PATH=C:\msys64\mingw64\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=C:\msys64\mingw64\share\qt6\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=C:\msys64\mingw64\share\qt6\plugins
)
%*
EndLocal
