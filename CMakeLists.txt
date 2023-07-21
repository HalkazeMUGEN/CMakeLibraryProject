cmake_minimum_required (VERSION 3.12)

project (CMakeLibraryProject VERSION 0.1.0 LANGUAGES CXX)

file (GLOB src src/*.cpp src/*.c)
file (GLOB include include/*.hpp include/*.h)

add_library (
	${PROJECT_NAME} SHARED
	${src}
	${include}
	"share/CMakeLibraryProject.h"
)
add_library (${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_compile_features (${PROJECT_NAME} PRIVATE cxx_std_20)
target_compile_definitions (${PROJECT_NAME} PRIVATE CMAKELIBRARYPROJECT_EXPORT)

message (STATUS path=${CMAKE_INSTALL_PREFIX})

target_include_directories (
	${PROJECT_NAME}
	PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

install (
	TARGETS ${PROJECT_NAME}
	EXPORT ${PROJECT_NAME}-config
	ARCHIVE DESTINATION lib
)

install (
	EXPORT ${PROJECT_NAME}-config
	NAMESPACE ${PROJECT_NAME}::
	DESTINATION cmake
)

install (
	DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/share/
	DESTINATION include
)
