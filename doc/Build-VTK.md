# Building VTK 9.0 with Qt 5.15
This guide will help you build VTK 9.0 with Qt 5.15. 
This procedure has been tested on Windows 10 and Debian-based Linux.

## Prerequisites
- CMake 3.8+ installed

- Qt 5.x downloaded. 
The Qt directory will be refered to as \<QT-DIR\>

- C++ compiler installed (like  GCC or  VS 2019). 
The compiler name will be refered to as \<COMPILER\>

## Building VTK
**1. Download VTK source code**

Download the source code from [http://VTK.org/download/](http://www.vtk.org/download/) and unpack it to a directory. This directory will be refered to as \<VTK-SOURCE-DIR\>

**2. Start CMake**

Start the CMake GUI application 

**3. Specify source  and build directory**

Source directory = \<VTK-SOURCE-DIR\> 

Build directory = \<VTK-SOURCE-DIR\>/Build (For example) 

**4. Start project configuration**

Specify a generator like 'Unix makefiles' on linux or 'MS Visual Studio 16 2019' on Windows.

**5. Specify entries and re-configure untill no more changes occur**

Set the following values when asked for:


| Name | Value |
| --- | --- |
| VTK_GROUP_ENABLE_Qt | YES |
| Qt5_DIR | \<QT-DIR\>/5.15.1/\<COMPILER\>/lib/cmake/Qt5 |
| VTK_Group_Qt | YES |
| VTK_MODULE_ENABLE_VTK_GUISupportQt | YES |
| CMAKE_BUILD_TYPE (Linux only, Makefiles) | Release |
| CMAKE_CONFIGURATION_TYPES (Windows only, MSVC) | Release |

Enable 'advanced' to see all entries and specify other Qt entries if they are not found automatically.

**6. Generate project**

Click on 'generate'. A buildable project will be created based on the chosen generator.

**7. Build project**

Build generated project using make (on Linux) or Visual Studio (on Windows)
