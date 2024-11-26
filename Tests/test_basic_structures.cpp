/**
* @author Tim Luchterhand
* @date 26.11.24
* @brief
*/

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(basic_structures, construct) {
    FAIL();
}

#ifndef __RUN_ALL_TESTS__

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif