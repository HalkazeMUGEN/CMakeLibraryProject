# CMakeList.txt : CMakeLibraryProject の CMake プロジェクト。ソースを含めて、次を定義します:
# プロジェクト専用ロジックはこちらです。
#
cmake_minimum_required (VERSION 3.12)

project ("CMakeLibraryProject")

add_library (
	${PROJECT_NAME} SHARED
	"src/CMakeLibraryProject.cpp"
	"share/CMakeLibraryProject.h"
	"src/dllmain.cpp"
	"include/framework.h"
 "include/_CMakeLibraryProject.h")

set_property (
	TARGET ${PROJECT_NAME}
	PROPERTY CXX_STANDARD 20
)

target_compile_definitions (${PROJECT_NAME} PUBLIC CMAKELIBRARYPROJECT_EXPORT)

target_include_directories (
	${PROJECT_NAME}
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

install (
	TARGETS ${PROJECT_NAME}
	CONFIGURATIONS Release
	RUNTIME DESTINATION bin
	ARCHIVE DESTINATION lib
)
