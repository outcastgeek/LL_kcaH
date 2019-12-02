
project(Tinkering)

cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set(CMAKE_VERBOSE_MAKEFILE TRUE)

find_package(fmt CONFIG REQUIRED)
set(TKFMT_SRC ${CMAKE_CURRENT_SOURCE_DIR}/TkFmt)
add_executable(tk_fmt-exe ${TKFMT_SRC}/main.cpp)
target_link_libraries(tk_fmt-exe PRIVATE fmt::fmt)

find_package(absl CONFIG REQUIRED)
set(TKABSEIL_SRC ${CMAKE_CURRENT_SOURCE_DIR}/TkAbseil)
add_executable(tk_abseil-exe ${TKABSEIL_SRC}/main.cpp)
target_link_libraries(tk_abseil-exe PRIVATE absl::base absl::strings)

find_package(cpp-httplib)
set(TKHTTPLIB_SRC ${CMAKE_CURRENT_SOURCE_DIR}/TkHttplib)
add_executable(tk_httplib-exe ${TKHTTPLIB_SRC}/main.cpp)
target_link_libraries(tk_httplib-exe fmt::fmt)

## Install LibTorch
#get_filename_component(PYTORCH_ARCHIVE_VAR
#        ${CMAKE_CURRENT_SOURCE_DIR}/libtorch-shared-with-deps-latest.zip
#        ABSOLUTE)
#download_file(https://download.pytorch.org/libtorch/nightly/cpu/libtorch-shared-with-deps-latest.zip
#        ${PYTORCH_ARCHIVE_VAR})
get_filename_component(PYTORCH_ARCHIVE_VAR
        ${CMAKE_CURRENT_SOURCE_DIR}/libtorch-macos-1.3.1.zip
        ABSOLUTE)
message(PYTORCH_ARCHIVE_VAR: ${PYTORCH_ARCHIVE_VAR})
get_filename_component(LIBTORCH_DIR_VAR
        ${CMAKE_CURRENT_SOURCE_DIR}/libtorch
        ABSOLUTE)
message(LIBTORCH_DIR_VAR: ${LIBTORCH_DIR_VAR})
set(ENV{TORCH_INSTALL_PREFIX} ${LIBTORCH_DIR_VAR})
download_file(https://download.pytorch.org/libtorch/cpu/libtorch-macos-1.3.1.zip
        ${PYTORCH_ARCHIVE_VAR})
unzip_file(${PYTORCH_ARCHIVE_VAR} libtorch ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND CMAKE_PREFIX_PATH ${LIBTORCH_DIR_VAR}/share/cmake/Torch)
## End Install LibTorch

set(ON true)
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

set(TK_TORCH_TENSOR_SRC ${CMAKE_CURRENT_SOURCE_DIR}/TkTorchTensor)
add_executable(tk_torch_tensor-exe ${TK_TORCH_TENSOR_SRC}/main.cpp)
target_link_libraries(tk_torch_tensor-exe "${TORCH_LIBRARIES}")

set(TK_TORCH_MNIST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/TkTorchMnist)
add_executable(tk_torch_mnist-exe ${TK_TORCH_MNIST_SRC}/main.cpp)
target_link_libraries(tk_torch_mnist-exe "${TORCH_LIBRARIES}")
