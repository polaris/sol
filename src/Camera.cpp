#include "Camera.h"

namespace sol {

Camera::Camera() 
: origin(0.0, 0.0, 0.0)
, lowerLeftCorner(-2.0, -1.0, -1.0)
, horizontal(4.0, 0.0, 0.0)
, vertical(0.0, 2.0, 0.0) {
}

Ray Camera::getRay(float u, float v) const {
    return Ray(origin, lowerLeftCorner + u * horizontal + v * vertical);
}

}