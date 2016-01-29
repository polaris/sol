#ifndef _Camera_H
#define _Camera_H

#include "Ray.h"
#include <Eigen/Core>

namespace sol {

class Camera {
public:
    Camera();

    Ray getRay(float u, float v) const;

private:
    const Eigen::Vector3f origin;
    const Eigen::Vector3f lowerLeftCorner;
    const Eigen::Vector3f horizontal;
    const Eigen::Vector3f vertical;
};

}

#endif  // _Camera_H
