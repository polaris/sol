#include "Metal.h"
#include "Ray.h"
#include "Hitable.h"
#include "Utilities.h"

namespace sol {

Metal::Metal(const Eigen::Vector3f &a, float f)
: albedo(a)
, fuzziness(f) {
}

bool Metal::scatter(const Ray &inRay, const HitRecord &hitRecord, Eigen::Vector3f &attenuation, Ray &scattered) {
    const auto reflected = reflect(inRay.getDirection(), hitRecord.normal);
    scattered = Ray(hitRecord.point, reflected + fuzziness * randomInUnitSphere());
    attenuation = albedo;
    return scattered.getDirection().dot(hitRecord.normal) > 0;
}

}