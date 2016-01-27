#ifndef _Ray_H
#define _Ray_H

#include <Eigen/Core>

namespace sol {

class Ray {
public:
    Ray(const Eigen::Vector3f &origin, const Eigen::Vector3f &direction);

    Ray(const Ray &rhs);

    const Eigen::Vector3f& getOrigin() const {
        return origin;
    }

    const Eigen::Vector3f& getDirection() const {
        return direction;
    }

private:
    const Eigen::Vector3f origin;
    const Eigen::Vector3f direction;
};

}

#endif  // _Ray_H
