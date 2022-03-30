# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.

cmake_minimum_required (VERSION 3.8)

Project ("Computer")
set (SOURCES 
# disk.h
        "disk.cpp"  "cpu.cpp" "gpu.cpp" "kbd.cpp" "ram.cpp"  "data.txt")
         # "cpu.h""   "gpu.h" "kbd.h")

# Включите подпроекты.
add_executable (Computer "main.cpp" ${SOURCES})
