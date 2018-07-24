project(LaRouille)

cmake_minimum_required(VERSION 3.3)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

set(RUSTYADDER_SRC ${CMAKE_CURRENT_SOURCE_DIR}/rusty_adder)
add_executable(rusty_adder-exe ${RUSTYADDER_SRC}/rusty_adder.c)

# Enable ExternalProject CMake module
include(ExternalProject)

# Set default ExternalProject root directory
set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/Rust)

# Add rusty_common as a CMake target
ExternalProject_Add(
        rusty_common
        DOWNLOAD_COMMAND ""
        CONFIGURE_COMMAND ""
        BUILD_COMMAND cargo build
            COMMAND cargo build --release
        TEST_COMMAND cargo test
        BINARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/rusty_common"
        INSTALL_COMMAND ""
        LOG_BUILD ON
)

### Create dependency of RustyCommon on rusty_common
add_dependencies(rusty_adder-exe rusty_common)

### Specify RustyCommon's link libraries
target_link_libraries(
        rusty_adder-exe
        debug "${CMAKE_CURRENT_SOURCE_DIR}/rusty_common/target/debug/librusty_common.a"
        optimized "${CMAKE_CURRENT_SOURCE_DIR}/rusty_common/target/release/librusty_common.a"
)