cmake_minimum_required(VERSION 3.12)

project(coursework VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test Widgets)  # Svg
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test Widgets)
# find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Svg)


file(GLOB coursework_src CONFIGURE_DEPENDS
  "resource.qrc"
  "*.cpp" "*.h" "*.ui"
  "text/*.cpp" "text/*.h" "text/*.ui"
  "randomPoints/*.cpp" "randomPoints/*.h" "randomPoints/*.ui"
  "figures/*/*.cpp" "figures/*/*.h" "figures/*/*.ui"
  "myGraphicsScene/*.cpp" "myGraphicsScene/*.h" "myGraphicsScene/*.ui"
  "myGraphicsView/*.cpp" "myGraphicsView/*.h" "myGraphicsView/*.ui"
  "main_window/*.cpp" "main_window/*.h" "main_window/*.ui"
  # "*/*/*.cpp" "*/*/*.h" "*/*/*.ui"
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(coursework
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(coursework SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(coursework
            ${coursework_src}
        )
    endif()
endif()


target_link_libraries(coursework PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Test
    # Qt${QT_VERSION_MAJOR}::Svg
)

install(TARGETS coursework
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(coursework)
endif()

