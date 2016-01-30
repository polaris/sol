#include "Lambertian.h"
#include "Ray.h"
#include "Hitable.h"

#include <cstdlib>

namespace sol {

Lambertian::Lambertian(const Eigen::Vector3f &a)
: albedo(a) {
}

static Eigen::Vector3f randomInUnitSphere() {
    Eigen::Vector3f p;
    do {
        p = 2.0 * Eigen::Vector3f(drand48(), drand48(), drand48()) - Eigen::Vector3f(1, 1, 1);
    } while (p.dot(p) > 1.0);
    return p;
}

bool Lambertian::scatter(const Ray &, const HitRecord &hitRecord, Eigen::Vector3f &attenuation, Ray &scattered) {
    const auto target = hitRecord.point + hitRecord.normal + randomInUnitSphere();
    scattered = Ray(hitRecord.point, target - hitRecord.point);
    attenuation = albedo;
    return true;
}

}