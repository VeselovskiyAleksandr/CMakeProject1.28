# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.

cmake_minimum_required (VERSION 3.8)

Project ("Computer")
#SET(CMAKE_CXX_FLAGS "/EHsc")
set (SOURCES 

        "disk.cpp"  "cpu.cpp" "gpu.cpp" "kbd.cpp" "ram.cpp"  "data.txt")
        #"load.cpp" "save.cpp"

# Включите подпроекты.
add_executable (Computer "main.cpp" ${SOURCES})
