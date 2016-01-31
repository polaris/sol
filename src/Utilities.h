#ifndef _Utils_H
#define _Utils_H

#include <Eigen/Core>

namespace sol {
    Eigen::Vector3f randomInUnitSphere();

    Eigen::Vector3f randomInUnitDisk();

    Eigen::Vector3f reflect(const Eigen::Vector3f &v, const Eigen::Vector3f &n);

    bool refract(const Eigen::Vector3f &v, const Eigen::Vector3f &n, float niOverNt, Eigen::Vector3f &refracted);

    float schlick(float cosine, float refractionIndex);
}

#endif  // _Utils_H
