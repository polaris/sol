#include "Ray.h"

namespace sol {

Ray::Ray(const Eigen::Vector3f &o, const Eigen::Vector3f &d)
: origin(o)
, direction(d) {
}

Ray::Ray(const Ray &rhs)
: origin(rhs.origin)
, direction(rhs.direction) {
}

}