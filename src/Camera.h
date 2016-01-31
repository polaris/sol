#ifndef _Camera_H
#define _Camera_H

#include "Ray.h"
#include <Eigen/Core>

namespace sol {

class Camera {
public:
    Camera(const Eigen::Vector3f &origin, const Eigen::Vector3f &lookat, const Eigen::Vector3f &up, float fov, float aspect, float aperture, float focusDist);

    Ray getRay(float u, float v) const;

private:
    Eigen::Vector3f origin;
    Eigen::Vector3f lowerLeftCorner;
    Eigen::Vector3f horizontal;
    Eigen::Vector3f vertical;
    Eigen::Vector3f u, v, w;
    float lensRadius;
};

}

#endif  // _Camera_H
