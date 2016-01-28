#include <gmock/gmock.h>

#include "Ray.h"

TEST(RayTest, pointAt) {
    sol::Ray ray(Eigen::Vector3f(1, 2, 3), Eigen::Vector3f(3, 2, 1));
    ASSERT_EQ(Eigen::Vector3f(31, 22, 13), ray.pointAt(10.0f));
}
