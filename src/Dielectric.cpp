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
    float reflectProb = 0.0;
    float cosine = 0.0;

    if (inRay.getDirection().dot(hitRecord.normal) > 0) {
        outwardNormal = -hitRecord.normal;
        niOverNt = refractionIndex;
        cosine = refractionIndex * inRay.getDirection().dot(hitRecord.normal) / inRay.getDirection().norm();
    } else {
        outwardNormal = hitRecord.normal;
        niOverNt = 1.0 / refractionIndex;
        cosine = -inRay.getDirection().dot(hitRecord.normal) / inRay.getDirection().norm();
    }

    if (refract(inRay.getDirection(), outwardNormal, niOverNt, refracted)) {
        reflectProb = schlick(cosine, refractionIndex);
    } else {
        scattered = Ray(hitRecord.point, reflected);
        reflectProb = 1.0;
    }

    if (drand48() < reflectProb) {
        scattered = Ray(hitRecord.point, reflected);
    } else {
        scattered = Ray(hitRecord.point, refracted);
    }

    return true;
}

}
