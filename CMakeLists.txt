cmake_minimum_required(VERSION 3.8)

project(medium_monorepo LANGUAGES CXX C)

set(CMAKE_CONFIGURATION_TYPES "Debug" "Release")
set(CMAKE_MESSAGE_LOG_LEVEL VERBOSE) 
set(CMAKE_${lang}_FLAGS_RELEASE_INIT "-O3 -DNDEBUG")

# define runtime intermediate build directory, so that debugging the Visual Studio solution works as expected.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")

# set export directory for CMake config.
set(CMAKE_INSTALL_BINARY_DIR    "bin/")
set(CMAKE_INSTALL_LIBRARY_DIR   "bin/")
set(CMAKE_INSTALL_INCLUDE_DIR   "include/")
set(CMAKE_INSTALL_EXPORT_DIR    "cmake/")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

add_compile_options(-fdiagnostics-color)

# ADD NEW PROGRAM / LIBRARY

# ADD .c/.cpp FILES HERE 
file(GLOB_RECURSE SRC
    # GET ALL .cpp FILES
    "src/*.cpp"
    # GET ALL .c FILES
    "src/*.c"
)
 #      CHANGE THIS TO YOUR PROJECT NAME ALSO IN TASK.json
 #               lllllllllllllllll
 #               vvvvvvvvvvvvvvvvv
set(TARGET_NAME "Your_Project_Name")

# ADD NEW TARGET, TARGETS ARE .exe, .dll or .lib FILES FOR EXAMPLE, ON WINDOWS
add_executable(${TARGET_NAME} ${SRC})

# INCLUDE DIRECTORIES (IF ANY), LIKE THE HEADERS FILES OF A LIBRARY YOU ARE USING
target_include_directories(${TARGET_NAME}
PUBLIC
   #"${CMAKE_CURRENT_SOURCE_DIR}/some/cool/library/header/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# LINK LIBARARIES (IF ANY), .lib FILES ON WINDOWS FOR EXAMPLE (DOESN^T NEED FILE EXTENSION)
target_link_libraries(${TARGET_NAME}
PRIVATE
   #"some_cool_library"
)

# WHERE THE OUTPUT IS BUILT TO
set(output_directory "${CMAKE_BINARY_DIR}/bin/$<CONFIG>")

set_target_properties(${TARGET_NAME}
PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${output_directory}
    LIBRARY_OUTPUT_DIRECTORY ${output_directory}
    RUNTIME_OUTPUT_DIRECTORY ${output_directory}
)

# THIS WAY U CAN ADD OTHER "CMakeList.txt" FILES 
#add_subdirectory(source/common)
#add_subdirectory(source/cg-gjk)
#add_subdirectory(source/quick_guides/dot_and_cross)


