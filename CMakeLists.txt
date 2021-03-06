project(curveintersection CXX)
set (CMAKE_CXX_STANDARD 14)


cmake_minimum_required(VERSION 2.6)
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")	

set ( SRC_DIR ${PROJECT_SOURCE_DIR}/src )
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/include/)
list(APPEND SRC ${SRC_DIR}/curve_intersection/Curves/Bezier.cxx)
list(APPEND SRC ${SRC_DIR}/curve_intersection/Curves/CircleCurve.cxx)
list(APPEND SRC ${SRC_DIR}/curve_intersection/Curves/LineSegment.cxx)
list(APPEND SRC ${SRC_DIR}/curve_intersection/Curves/Ellipse.cxx)
list(APPEND SRC ${SRC_DIR}/curve_intersection/Curves/ICurve.cxx)
list(APPEND SRC ${SRC_DIR}/curve_intersection/Intersection/ConjugateGradientMethod.cxx)
list(APPEND SRC ${SRC_DIR}/curve_intersection/Intersection/CurveIntersection.cxx)
list(APPEND SRC ${SRC_DIR}/curve_intersection/Intersection/EvaluationLipschitzConstant.cxx)
list(APPEND SRC ${SRC_DIR}/curve_intersection/Intersection/GoldenRatio.cxx)
list(APPEND SRC ${SRC_DIR}/curve_intersection/Intersection/MethodDivisionThree.cxx)
list(APPEND SRC ${SRC_DIR}/curve_intersection/Serializer/BezierCurveSerializer.cxx)
list(APPEND SRC ${SRC_DIR}/curve_intersection/Serializer/CircleCurveSerializer.cxx)
list(APPEND SRC ${SRC_DIR}/curve_intersection/Serializer/CurveExchanger.cxx)
list(APPEND SRC ${SRC_DIR}/curve_intersection/Serializer/EllipseSerializer.cxx)
list(APPEND SRC ${SRC_DIR}/curve_intersection/Serializer/FormattedCurveSerializer.cxx)
list(APPEND SRC ${SRC_DIR}/curve_intersection/Serializer/LineSegmentSerializer.cxx)
add_library(${PROJECT_NAME} ${SRC})

add_subdirectory(3rdParty)
add_subdirectory(tests)
SET(LIBRARY_NAME ${PROJECT_NAME})
add_custom_target(post_build ALL DEPENDS Tests
    COMMAND ${CMAKE_COMMAND} -E make_directory bin
	COMMAND ${CMAKE_COMMAND} -E make_directory lib
	COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:${LIBRARY_NAME}> lib/$<TARGET_FILE_NAME:${LIBRARY_NAME}>
	COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Tests> bin/$<TARGET_FILE_NAME:Tests>
	COMMAND bin/$<TARGET_FILE_NAME:Tests>)
