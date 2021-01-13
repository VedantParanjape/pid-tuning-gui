set(TEST_APP_NAME "${LIBRARY_NAME}-test")

include(ParseAndAddCatchTests)

set(TEST_MODULE_PATH "${PROJECT_SOURCE_DIR}/tests")
set(TEST_SOURCE_PATH "${TEST_MODULE_PATH}")

set (TEST_SOURCE_FILES "${TEST_SOURCE_PATH}/main.cpp"
                       "${TEST_SOURCE_PATH}/example_test.cpp")

add_executable(${TEST_APP_NAME} ${TEST_SOURCE_FILES})

target_link_libraries(${TEST_APP_NAME} ${LIBRARY_NAME} ${CONAN_LIBS})

enable_testing()
ParseAndAddCatchTests(${TEST_APP_NAME})
