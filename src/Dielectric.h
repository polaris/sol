#ifndef _Dielectric_H
#define _Dielectric_H

#include "Material.h"
#include <Eigen/Core>

namespace sol {

class Dielectric
: public Material {
public:
    Dielectric(float refractionIndex);

    bool scatter(const Ray &inRay, const HitRecord &hitRecord, Eigen::Vector3f &attenuation, Ray &scattered) override;

private:
    const float refractionIndex;
};

}

#endif  // _Dielectric_H
