cmake_minimum_required(VERSION 3.20)
project(untitled2)

set(CMAKE_CXX_STANDARD 14)
#link_directories("C:/Path_To_Library")
add_executable(untitled2 src/main.cpp src/Engine.cpp headers/Engine.h src/draw.cpp src/input.cpp src/Molecul.cpp headers/Molecul.h src/Moleculs.cpp headers/Moleculs.h headers/circle.cpp headers/circle.h)

include_directories(headers /usr/include c:/SFML/include)

set(SFML_ROOT c:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(untitled2 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build directory
if (WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/Users/Анна/OneDrive/Рабочий стол/всякая херня/mingw64/lib/gcc/x86_64-w64-mingw32/11.2.0/plugin/include/config/i386/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()


#set(SFML_STATIC_LIBRARIES TRUE)
#set(SFML_DIR C:/Users/Анна/Downloads/SFML/lib/cmake/SFML)
#find_package(SFML 2.5.1 COMPONENTS system window graphics audio network REQUIRED)

#include_directories(headers /usr/include c:/SFML/include)
#target_link_libraries(untitled2 sfml-system sfml-window sfml-graphics sfml-audio)