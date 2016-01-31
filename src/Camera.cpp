#include "Camera.h"
#include "Utilities.h"

#include <Eigen/Geometry>

namespace sol {

Camera::Camera(const Eigen::Vector3f &o, const Eigen::Vector3f &lookat, const Eigen::Vector3f &up, float fov, float aspect, float aperture, float focusDist) 
: origin(o) {
    lensRadius = aperture / 2.0;
    const auto theta = fov * M_PI/180;
    const auto halfHeight = tan(theta/2);
    const auto halfWidth = aspect * halfHeight;
    w = (origin - lookat).normalized();
    u = up.cross(w).normalized();
    v = w.cross(u).normalized();
    lowerLeftCorner = origin - halfWidth * focusDist * u - halfHeight * focusDist * v - focusDist * w;
    horizontal = 2 * halfWidth * focusDist * u;
    vertical = 2 * halfHeight * focusDist * v;
}

Ray Camera::getRay(float s, float t) const {
    const auto rd = lensRadius * randomInUnitSphere();
    const auto offset = u * rd.x() + v * rd.y();
    const auto o = origin + offset;
    return Ray(o, lowerLeftCorner + s * horizontal + t * vertical - o);
}

}
