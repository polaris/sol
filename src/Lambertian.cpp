#include "Lambertian.h"
#include "Ray.h"
#include "Hitable.h"
#include "Utilities.h"

#include <cstdlib>

namespace sol {

Lambertian::Lambertian(const Eigen::Vector3f &a)
: albedo(a) {
}

bool Lambertian::scatter(const Ray &, const HitRecord &hitRecord, Eigen::Vector3f &attenuation, Ray &scattered) {
    const auto target = hitRecord.normal + randomInUnitSphere();
    scattered = Ray(hitRecord.point, target);
    attenuation = albedo;
    return true;
}

}