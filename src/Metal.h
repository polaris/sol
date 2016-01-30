#ifndef _Metal_H
#define _Metal_H

#include "Material.h"
#include <Eigen/Core>

namespace sol {

class Metal
: public Material {
public:
    Metal(const Eigen::Vector3f &albedo, float fuzziness);

    bool scatter(const Ray &inRay, const HitRecord &hitRecord, Eigen::Vector3f &attenuation, Ray &scattered) override;

private:
    const Eigen::Vector3f albedo;
    const float fuzziness;
};

}

#endif  // _Metal_H
