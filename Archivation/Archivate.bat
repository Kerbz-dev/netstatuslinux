echo off & SETLOCAL ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION
IF NOT EXIST "..\Release" mkdir "..\Release"
if errorlevel 1 (
	echo Couldn't create release lib
	goto :EOF
)
SET lowername=%1
SET lowername
CALL :tolower lowername
SET lowername
echo %lowername% %1
copy "..\linux\Release\%lowername%.so" "..\Release"
copy "..\msvc\Release\%lowername%.dll" "..\Release"
echo "..\msvc\Release\%lowername%.dll"
copy "..\readme_RUS.txt" "..\Release"
copy "..\readme.txt" "..\Release"
cd "..\Release"
del "%1.zip" "%lowername%.tar.gz"
..\Archivation\bsdtar -z -c -f %lowername%.tar.gz %lowername%.so readme_RUS.txt readme.txt
..\Archivation\7za a -tzip %1.zip %1.dll readme_RUS.txt readme.txt
del %lowername%.so readme_RUS.txt readme.txt %1.dll
goto :EOF

 
:tolower
for %%L IN (a b c d e f g h i j k l m n o p q r s t u v w x y z) DO SET %1=!%1:%%L=%%L!
goto :EOF

:EOF