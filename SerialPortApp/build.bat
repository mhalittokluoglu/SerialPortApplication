set MSBUILD_HOME="C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\MSBuild\\Current"
pushd BuildDirWin
%MSBUILD_HOME%\bin\MSBuild.exe SerialPortApp.sln /property:Configuration=Debug
popd