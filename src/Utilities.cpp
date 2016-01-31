#include "Utilities.h"

namespace sol {

Eigen::Vector3f randomInUnitSphere() {
    Eigen::Vector3f p;
    do {
        p = 2.0 * Eigen::Vector3f(drand48(), drand48(), drand48()) - Eigen::Vector3f(1, 1, 1);
    } while (p.dot(p) > 1.0);
    return p;
}

Eigen::Vector3f reflect(const Eigen::Vector3f &v, const Eigen::Vector3f &n) {
    return v - 2 * v.dot(n) * n;
}

bool refract(const Eigen::Vector3f &v, const Eigen::Vector3f &n, float niOverNt, Eigen::Vector3f &refracted) {
    const auto uv = v.normalized();
    const auto dt = uv.dot(n);
    const auto discriminant = 1.0 - niOverNt * niOverNt * (1 - dt * dt);
    if (discriminant > 0) {
        refracted = niOverNt * (v - n * dt) - n * sqrt(discriminant);
        return true;
    } else {
        return false;
    }
}

float schlick(float cosine, float refractionIndex) {
    auto r0 = (1 - refractionIndex) / (1 + refractionIndex);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow(1 - cosine, 5);
}

}
