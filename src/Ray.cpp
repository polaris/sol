#include "Ray.h"

namespace sol {

Ray::Ray(const Eigen::Vector3f &o, const Eigen::Vector3f &d)
: origin(o)
, direction(d.normalized()) {
}

Ray::Ray(const Ray &rhs)
: origin(rhs.origin)
, direction(rhs.direction) {
}

Ray& Ray::operator =(const Ray &rhs) {
    this->origin = rhs.origin;
    this->direction = rhs.direction;
    return *this;
}

Eigen::Vector3f Ray::pointAt(float t) const {
    return origin + t * direction;
}

}