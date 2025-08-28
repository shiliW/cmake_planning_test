cmake_minimum_required(VERSION 3.29.0)
project(planning)
set(CMAKE_CXX_STANDARD 17)

# 动态库和exe都指定到bin目录下面
# exe和dll需要放置到同一目录下面
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
# CMAKE_LIBRARY_OUTPUT_DIRECTORY --- linux 动态库
# CMAKE_ARCHIVE_OUTPUT_DIRECTORY --- 静态库

# src目录下面的cpp文件打包到SRC_LISTS变量中
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LISTS)
# src目录下所有cpp文件生成动态库（.dll) --- common动态库
add_library(common
SHARED
${SRC_LISTS}
)

# 动态库（.dll）包含include头文件目录
target_include_directories(common
PUBLIC
${PROJECT_SOURCE_DIR}/include
)

# # 设置可执行文件的输出目录：${PROJECT_SOURCE_DIR}/bin --- 根目录/bin
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


# 添加可执行文件：planning_main可执行文件由planning_main.cpp生成
add_executable(planning_main planning_main.cpp)

# 可执行文件包含include头文件目录
target_include_directories(planning_main
PUBLIC
${PROJECT_SOURCE_DIR}/include
)

# 可执行文件planning_main.exe链接到动态库common.dll
target_link_libraries(planning_main
PUBLIC
common
)

