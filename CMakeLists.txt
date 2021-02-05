cmake_minimum_required(VERSION 3.8)

project(QtVtkViewer)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# List source files & resources
file (GLOB Sources *.cpp)
file (GLOB Headers *.h)
file (GLOB Resources *.qrc)
file (GLOB UIs *.ui)

# Find package Qt
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5OpenGL REQUIRED)

# Use Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find package VTK
find_package(VTK
    9.0
    REQUIRED
    COMPONENTS
        GUISupportQt
        IOLegacy)

# Build executable
add_executable(QtVtkViewer WIN32 ${Sources} ${Headers} ${Resources} ${UIs})

target_link_libraries(QtVtkViewer PRIVATE Qt5::Widgets Qt5::OpenGL VTK::GUISupportQt VTK::IOLegacy)

vtk_module_autoinit(
    TARGETS QtVtkViewer
    MODULES VTK::GUISupportQt VTK::IOLegacy)
