#include "Dielectric.h"
#include "Ray.h"
#include "Hitable.h"
#include "Utilities.h"

namespace sol {

Dielectric::Dielectric(float ri)
: refractionIndex(ri) {
}

bool Dielectric::scatter(const Ray &inRay, const HitRecord &hitRecord, Eigen::Vector3f &attenuation, Ray &scattered) {
    Eigen::Vector3f outwardNormal;
    Eigen::Vector3f reflected = reflect(inRay.getDirection(), hitRecord.normal);
    float niOverNt = 0.0;
    attenuation = Eigen::Vector3f(1.0, 1.0, 1.0);
    Eigen::Vector3f refracted;
    if (inRay.getDirection().dot(hitRecord.normal) > 0) {
        outwardNormal = -hitRecord.normal;
        niOverNt = refractionIndex;
    } else {
        outwardNormal = hitRecord.normal;
        niOverNt = 1.0 / refractionIndex;
    }
    if (refract(inRay.getDirection(), outwardNormal, niOverNt, refracted)) {
        scattered = Ray(hitRecord.point, refracted);
    } else {
        scattered = Ray(hitRecord.point, reflected);
        return false;
    }
    return true;
}

}
