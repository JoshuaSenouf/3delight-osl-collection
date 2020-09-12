@ECHO OFF

@for %%i in (..\osl\materials\*) do (oslc.exe %%i)
@for %%i in (..\osl\materials\lobes\*) do (oslc.exe %%i)
@for %%i in (..\osl\patterns\*) do (oslc.exe %%i)
