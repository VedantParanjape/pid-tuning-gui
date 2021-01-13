set(LIBRARY_NAME "${PROJECT_NAME}")

#Configure paths
set(LIBRARY_MODULE_PATH  "${PROJECT_SOURCE_DIR}/src")
set(LIBRARY_SRC_PATH     "${LIBRARY_MODULE_PATH}")
set(LIBRARY_PUBLIC_INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include")
set(LIBRARY_PRIVATE_INCLUDE_PATH "${LIBRARY_MODULE_PATH}")

set(LIB_SOURCE_FILES "${LIBRARY_SRC_PATH}/server.cpp")

add_library(${LIBRARY_NAME} ${LIB_SOURCE_FILES})

target_include_directories(${LIBRARY_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${LIBRARY_PUBLIC_INCLUDE_PATH}>
    PRIVATE
        ${LIBRARY_MODULE_PATH}
)
set(BOOST_ROOT /opt/boost)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED)
target_compile_features(${LIBRARY_NAME} PRIVATE cxx_std_17)

target_link_libraries(${LIBRARY_NAME} pthread ${Boost_ASIO} ${Boost_SHARED_PTR} ${Boost_SYSTEM_LIBRARY})

#target_link_libraries(${LIBRARY_NAME}
#    PUBLIC
#        CONAN_PKG::PublicLibs # List all libraries needed externally (i.e. part of the lib interface)
#    PRIVATE
#        CONAN_PKG::PrivateLibs # List all libraries only needed internally
#)

set(LIBRARY_NAME ${LIBRARY_NAME} PARENT_SCOPE)
