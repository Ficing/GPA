## Copyright (c) 2018 Advanced Micro Devices, Inc. All rights reserved.
cmake_minimum_required(VERSION 3.5.1)

## Define the GPA version - currently placeholder, need to figure out how to use Version header file
set(GPA_MAJOR_VERSION 3)
set(GPA_MINOR_VERSION 0)

if(NOT DEFINED GPA_ROOT)
    set(GPA_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
endif()

if(NOT DEFINED GPA_OUTPUT_DIR)
    set(GPA_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Output)
endif()

## Set the Common Directories
set(COMMON_DIR                                              "${CMAKE_SOURCE_DIR}/../Common")
set(COMMON_DIR_LIB                                          "${COMMON_DIR}/Lib")
set(COMMON_DIR_SRC                                          "${COMMON_DIR}/Src")
set(GPA_SRC_COMMON_REL_PATH                                 "Src/GPUPerfAPI-Common")
set(GPA_SRC_COMMON                                          "${GPA_ROOT}/${GPA_SRC_COMMON_REL_PATH}")
set(GPA_SRC_COUNTER_GENERATOR_REL_PATH                      "Src/GPUPerfAPICounterGenerator")
set(GPA_SRC_COUNTER_GENERATOR                               "${GPA_ROOT}/${GPA_SRC_COUNTER_GENERATOR_REL_PATH}")
set(GPA_AUTOGEN_SRC_COUNTER_GENERATOR_REL_PATH              "Src/AutoGenerated/GPUPerfAPICounterGenerator")
set(GPA_AUTOGEN_SRC_COUNTER_GENERATOR                       "${GPA_ROOT}/${GPA_AUTOGEN_SRC_COUNTER_GENERATOR_REL_PATH}")
set(GPA_SRC_COUNTERS_REL_PATH                               "Src/GPUPerfAPICounters")
set(GPA_SRC_COUNTERS                                        "${GPA_ROOT}/${GPA_SRC_COUNTERS_REL_PATH}")
set(GPA_SRC_GL_REL_PATH                                     "Src/GPUPerfAPIGL")
set(GPA_SRC_GL                                              "${GPA_ROOT}/${GPA_SRC_GL_REL_PATH}")
set(GPA_SRC_DX_REL_PATH                                     "Src/GPUPerfAPIDX")
set(GPA_SRC_DX                                              "${GPA_ROOT}/${GPA_SRC_DX_REL_PATH}")
set(GPA_SRC_DX11_REL_PATH                                   "Src/GPUPerfAPIDX11")
set(GPA_SRC_DX11                                            "${GPA_ROOT}/${GPA_SRC_DX11_REL_PATH}")
set(GPA_SRC_DX12_REL_PATH                                   "Src/GPUPerfAPIDX12")
set(GPA_SRC_DX12                                            "${GPA_ROOT}/${GPA_SRC_DX12_REL_PATH}")
set(GPA_SRC_VK_REL_PATH                                     "Src/GPUPerfAPIVk")
set(GPA_SRC_VK                                              "${GPA_ROOT}/${GPA_SRC_VK_REL_PATH}")
set(GPA_SRC_CL_REL_PATH                                     "Src/GPUPerfAPICL")
set(GPA_SRC_CL                                              "${GPA_ROOT}/${GPA_SRC_CL_REL_PATH}")
set(GPA_SRC_TESTS_REL_PATH                                  "Src/GPUPerfAPIUnitTests")
set(GPA_SRC_TESTS                                           "${GPA_ROOT}/${GPA_SRC_TESTS_REL_PATH}")
set(GPA_AUTOGEN_SRC_TESTS_REL_PATH                          "Src/AutoGenerated/GPUPerfAPIUnitTests")
set(GPA_AUTOGEN_SRC_TESTS                                   "${GPA_ROOT}/${GPA_AUTOGEN_SRC_TESTS_REL_PATH}")
set(GPA_SRC_PUBLIC_COUNTER_COMPILER_REL_PATH                "Src/PublicCounterCompiler")
set(GPA_SRC_PUBLIC_COUNTER_COMPILER                         "${GPA_ROOT}/${GPA_SRC_PUBLIC_COUNTER_COMPILER_REL_PATH}")
set(GPA_SRC_PUBLIC_COUNTER_INPUT_FILES_REL_PATH             "Src/PublicCounterCompilerInputFiles")
set(GPA_SRC_PUBLIC_COUNTER_INPUT_FILES                      "${GPA_ROOT}/${GPA_SRC_PUBLIC_COUNTER_INPUT_FILES_REL_PATH}")
set(GPA_SRC_D3D12_COLOR_CUBE_REL_PATH                       "Src/Examples/DX12/D3D12ColorCube")
set(GPA_SRC_D3D12_COLOR_CUBE                                "${GPA_ROOT}/${GPA_SRC_D3D12_COLOR_CUBE_REL_PATH}")
set(GPA_SRC_VK_COLOR_CUBE_REL_PATH                          "Src/Examples/Vulkan/VkColorCube")
set(GPA_SRC_VK_COLOR_CUBE                                   "${GPA_ROOT}/${GPA_SRC_VK_COLOR_CUBE_REL_PATH}")
set(GPA_SPHINX_DOCS_REL_PATH                                "docs")
set(GPA_SPHINX_DOCS                                         "${GPA_ROOT}/${GPA_SPHINX_DOCS_REL_PATH}")
set(GPA_SRC_GOOGLE_TEST_REL_PATH                            "Src/GoogleTest")
set(GPA_SRC_GOOGLE_TEST                                     "${GPA_ROOT}/${GPA_SRC_GOOGLE_TEST_REL_PATH}")
set(GPA_AUTOGEN_PUBLIC_COUNTER_INPUT_FILES_REL_PATH         "Src/AutoGenerated/PublicCounterCompilerInputFiles")
set(GPA_AUTOGEN_PUBLIC_COUNTER_INPUT_FILES                  "${GPA_ROOT}/${GPA_AUTOGEN_PUBLIC_COUNTER_INPUT_FILES_REL_PATH}")
set(GPA_SRC_GL_TRIANGLE_REL_PATH                            "Src/Examples/OpenGL/GLTriangle")
set(GPA_SRC_GL_TRIANGLE                                     "${GPA_ROOT}/${GPA_SRC_GL_TRIANGLE_REL_PATH}")
set(GPA_SRC_D3D11_TRIANGLE_REL_PATH                         "Src/Examples/DX11/D3D11Triangle")
set(GPA_SRC_D3D11_TRIANGLE                                  "${GPA_ROOT}/${GPA_SRC_D3D11_TRIANGLE_REL_PATH}")

set(GOOGLETEST_DIR                                          ${COMMON_DIR_LIB}/Ext/GoogleTest)

## List of common cmake files
set(CMAKE_COMMON_SRC_GLOBAL_CMAKE_MODULE                    ${COMMON_DIR_SRC}/CMakeModules/Global-Common.cmake)
set(CMAKE_COMMON_SRC_GLOBAL_INTERNAL                        ${COMMON_DIR_SRC}/CMakeModules/Global-Internal.cmake)
set(CMAKE_COMMON_SRC_GLOBAL_ADL_UTIL                        ${COMMON_DIR_SRC}/ADLUtil/Global-ADLUtil.cmake)
set(CMAKE_COMMON_SRC_GLOBAL_AMD_DX_EXT                      ${COMMON_DIR_SRC}/AmdDxExt/Global-AmdDxExt.cmake)
set(CMAKE_COMMON_SRC_GLOBAL_AMD_VK_EXT                      ${COMMON_DIR_SRC}/AmdVkExt/Global-AmdVkExt.cmake)
set(CMAKE_COMMON_SRC_GLOBAL_DEVICE_INFO                     ${COMMON_DIR_SRC}/DeviceInfo/Global-DeviceInfo.cmake)
set(CMAKE_COMMON_SRC_GLOBAL_DYNAMIC_LIBRARY_MODULE          ${COMMON_DIR_SRC}/DynamicLibraryModule/Global-DynamicLibraryModule.cmake)
set(CMAKE_COMMON_SRC_GLOBAL_TSINGLETON                      ${COMMON_DIR_SRC}/TSingleton/Global-TSingleton.cmake)

set(CMAKE_COMMON_LIB_GLOBAL_AMD_ADL                         ${COMMON_DIR_LIB}/AMD/ADL/Global-ADL.cmake)
set(CMAKE_COMMON_LIB_GLOBAL_AMD_OPENCL_NO_LIB               ${COMMON_DIR_LIB}/AMD/APPSDK/Global-OpenCL-NoLib.cmake)
set(CMAKE_COMMON_LIB_GLOBAL_AMD_OPENCL                      ${COMMON_DIR_LIB}/AMD/APPSDK/Global-OpenCL.cmake)
set(CMAKE_COMMON_LIB_GLOBAL_EXT_OPENGL                      ${COMMON_DIR_LIB}/Ext/OpenGL/Global-OpenGL.cmake)
set(CMAKE_COMMON_LIB_GLOBAL_EXT_VULKAN                      ${COMMON_DIR_LIB}/Ext/Vulkan/Global-Vulkan.cmake)
set(CMAKE_COMMON_LIB_GLOBAL_EXT_WINDOWS_SDK                 ${COMMON_DIR_LIB}/Ext/Windows-Kits/Global-WindowsSDK.cmake)
