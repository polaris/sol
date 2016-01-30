#include "Metal.h"
#include "Ray.h"
#include "Hitable.h"

namespace sol {

Metal::Metal(const Eigen::Vector3f &a)
: albedo(a) {
}

static Eigen::Vector3f reflect(const Eigen::Vector3f &v, const Eigen::Vector3f &n) {
    return v - 2 * v.dot(n) * n;
}

bool Metal::scatter(const Ray &inRay, const HitRecord &hitRecord, Eigen::Vector3f &attenuation, Ray &scattered) {
    const auto reflected = reflect(inRay.getDirection(), hitRecord.normal);
    scattered = Ray(hitRecord.point, reflected);
    attenuation = albedo;
    return scattered.getDirection().dot(hitRecord.normal) > 0;
}

}