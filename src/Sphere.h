#ifndef _Sphere_H
#define _Sphere_H

#include "Hitable.h"
#include "Material.h"

#include <Eigen/Core>

namespace sol {

class Sphere
: public Hitable {
public:
    Sphere(const Eigen::Vector3f &center, float radius, MaterialPtr material);

    bool hit(const Ray &ray, float tmin, float tmax, HitRecord &hitRecord) override;

private:
    const Eigen::Vector3f &center;
    const float radius;
    MaterialPtr material;
};

}

#endif  // _Sphere_H
