#ifndef _Lambertian_H
#define _Lambertian_H

#include "Material.h"
#include <Eigen/Core>

namespace sol {

class Lambertian
: public Material {
public:
    Lambertian(const Eigen::Vector3f &albedo);

    bool scatter(const Ray &inRay, const HitRecord &hitRecord, Eigen::Vector3f &attenuation, Ray &scattered) override;

private:
    const Eigen::Vector3f albedo;
};

}

#endif  // _Lambertian_H
