message(STATUS "Loading tests-cli module...")

if (NOT CONFIGURED_ONCE)
	set(APP_TESTS_CLI_SOURCE_DIR ${APP_TESTS_CLI_DIR}/src)
endif()

add_executable(aurorafw_app_tests_shell ${APP_TESTS_CLI_SOURCE_DIR}/test_shell.cpp)

set_target_properties(aurorafw_app_tests_shell PROPERTIES OUTPUT_NAME test_shell.out)
