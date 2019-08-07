cmake_minimum_required(VERSION 3.14)
project(littlelionman)

set(CMAKE_CXX_STANDARD 11)
set(TEXTURES_PATH "${CMAKE_SOURCE_DIR}/resources/textures")
set(SHADERS_PATH "${CMAKE_SOURCE_DIR}/resources/shaders")
set(TARGET_RESOURCES_PATH "${CMAKE_BINARY_DIR}/resources")
set(TARGET_SHADERS "${TARGET_RESOURCES_PATH}/shaders")
set(TARGET_TEXTURES "${TARGET_RESOURCES_PATH}/textures")

add_executable(littlelionman src/main.cpp)

# Including OS include paths. Idk why this is required, but it is.
include_directories("/usr/local/include")
include_directories("/usr/local/lib")
include_directories("/usr/local/include/GL")
include_directories("/usr/local/include/GLEW")
include_directories("/usr/local/include/GLFW3")

# Including OS include paths. Idk why this is required, but it is.
include_directories(
        "${CMAKE_SOURCE_DIR}/src"
        "${CMAKE_SOURCE_DIR}/include"
        ${OPENGL_INCLUDE_DIR}
        ${GLFW3_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIR}
        ${GLM_INCLUDE_DIR}
)

find_package(OpenGL REQUIRED)
find_package(GLM REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLFW3 REQUIRED)
find_package(glfw3 3.3 REQUIRED)

target_link_libraries(littlelionman "-framework OpenGL")
target_link_libraries(littlelionman "-framework CoreFoundation")
target_link_libraries(littlelionman "-framework CoreVideo")
target_link_libraries(littlelionman "-framework IOKit")
target_link_libraries(littlelionman "-framework Cocoa")
target_link_libraries(littlelionman "/usr/local/lib/libSOIL.a")
target_link_libraries(littlelionman ${OPENGL_LIBRARIES} ${OPENGL_gl_LIBRARY} ${GLM_LIBRARIES} ${GLEW_LIBRARY} ${GLFW3_LIBRARY} glfw)

target_include_directories(littlelionman PUBLIC ${OPENGL_INCLUDE_DIR})

# copy files into build
configure_file(${TEXTURES_PATH}/brickTexture.jpg ${TARGET_TEXTURES}/brickTexture.jpg COPYONLY)
configure_file(${TEXTURES_PATH}/stoneTexture.jpg ${TARGET_TEXTURES}/stoneTexture.jpg COPYONLY)
configure_file(${TEXTURES_PATH}/woodTexture.jpg ${TARGET_TEXTURES}/woodTexture.jpg COPYONLY)

configure_file(${SHADERS_PATH}/core/core.frag ${TARGET_SHADERS}/core/core.frag COPYONLY)
configure_file(${SHADERS_PATH}/core/core.vert ${TARGET_SHADERS}/core/core.vert COPYONLY)
