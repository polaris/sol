#ifndef _Material_H
#define _Material_H

#include <Eigen/Core>
#include <memory>

namespace sol {

class Ray;
struct HitRecord;

class Material {
public:
    virtual ~Material() = default;

    virtual bool scatter(const Ray &inRay, const HitRecord &hitRecord, Eigen::Vector3f &attenuation, Ray &scattered) = 0;
};

using MaterialPtr = std::shared_ptr<Material>;

}

#endif  // _Material_H
