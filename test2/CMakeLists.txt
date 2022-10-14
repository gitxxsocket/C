cmake_minimum_required("VERSION""3.5")

set(EXECUTABLE_OUTPUT_PATH${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH${PROJECT_BINARY_DIR}/lib)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(TOOLCHAIN_DIR /home/book/Desktop/book/gcc-arm-10.3-2021.07-x86_64-arm-none-linux-gnueabihf)
set(CMAKE_SYSROOT${TOOLCHAIN_DIR}/arm-none-linux-gnueabihf)

set(CMAKE_C_COMPILE_ ${TOOLCHAIN_DIR}/home/book/Desktop/book/gcc-arm-10.3-2021.07-x86_64-arm-none-linux-gnueabihf/bin/arm-none-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILE ${TOOLCHAIN_DIR}/home/book/Desktop/book/gcc-arm-10.3-2021.07-x86_64-arm-none-linux-gnueabihf/bin/arm-none-linux-gnueabihf-g++)

set(CMAKE_C_FLAGS "")
set(CMAKE_CXX_FLAGS "")
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)


project(HELLO VERSION 1.1.0)



include_directories(include)
add_library(hello SHARED include/hello.c)
add_executable(main main.c)
target_link_libraries(main PRIVATE hello)