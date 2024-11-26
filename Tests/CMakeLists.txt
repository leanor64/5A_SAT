project(Tests)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/62df7bdbc10887e094661e07ec2595b7920376fd.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/Tests/*.cpp)
add_executable(Tests ${SOURCES})
target_link_libraries(Tests gtest gmock)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
