#ifndef _Hitable_H
#define _Hitable_H

#include <Eigen/Core>

namespace sol {

class Ray;

struct HitRecord {
    float distance;
    Eigen::Vector3f point;
    Eigen::Vector3f normal;
};

class Hitable {
public:
    virtual ~Hitable() = default;
    virtual bool hit(const Ray &ray, float tmin, float tmax, HitRecord &hitRecord) = 0;
};

}

#endif  // _Hitable_H
