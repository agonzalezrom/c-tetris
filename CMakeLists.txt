cmake_minimum_required(VERSION 3.26)
project(tetris C)

set(CMAKE_C_STANDARD 17)

set(SDL2_DIR "lib/SDL2/lib/cmake/SDL2")
set(SDL2_MIXER_LIBRARY "${CMAKE_SOURCE_DIR}/lib/SDL2_mixer/lib/libSDL2_mixer.a")

find_package(SDL2 REQUIRED)

add_executable(
        tetris
        src/main.c
        include/config.h
        include/render.h
        include/game.h
        include/input.h
        include/utility.h
        include/figures.h
        include/music.h
        src/render.c
        src/game.c
        src/input.c
        src/utility.c
        src/figures.c
        src/music.c
)

target_include_directories(tetris PRIVATE ${SDL2_INCLUDE_DIRS} "${CMAKE_SOURCE_DIR}/lib/SDL2_mixer/include")
target_link_libraries(tetris ${SDL2_MIXER_LIBRARY} ${SDL2_LIBRARIES} winmm)

if (WIN32)
    message(STATUS "Copying SDL2 DLLs")
    set(SDL2_DLLS "${CMAKE_SOURCE_DIR}/lib/SDL2/bin/SDL2.dll")
    set(SDL2_MIXER_DLLS "${CMAKE_SOURCE_DIR}/lib/SDL2_mixer/bin/SDL2_mixer.dll")
    foreach(_DLL ${SDL2_DLLS} ${SDL2_MIXER_DLLS})
        message(STATUS "Copying ${_DLL}")
        add_custom_command(TARGET tetris POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${_DLL} $<TARGET_FILE_DIR:tetris>)
    endforeach()
endif()
