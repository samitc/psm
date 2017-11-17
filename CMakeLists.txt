cmake_minimum_required(VERSION 3.6)
project(psm)

if ("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
	add_definitions(-DWINDOWS)
elseif ("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
	add_definitions(-DLINUX)
endif()
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse3")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mavx")
endif()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules")
INCLUDE(AddGTest)
if (AddGTest_FOUND)
    set(TEST_SOURCE_FILES
            Test/main.cpp Test/Vector.cpp)
    add_executable(psmTesting ${TEST_SOURCE_FILES})
    target_compile_options(psmTesting PUBLIC -I${psm_SOURCE_DIR}/Src/Vector)
    add_dependencies(psmTesting gtest)
    target_link_libraries(psmTesting
            debug ${GTEST_DEBUG_LIBRARIES}
            optimized ${GTEST_RELEASE_LIBRARIES}
            )
endif (AddGTest_FOUND)
