#include "Sphere.h"
#include "Ray.h"

namespace sol {

Sphere::Sphere(const Eigen::Vector3f &c, float r) 
: center(c)
, radius(r) {
}

bool Sphere::hit(const Ray &ray, float tmin, float tmax, HitRecord &hitRecord) {
    const auto oc = ray.getOrigin() - center;
    const auto a = ray.getDirection().dot(ray.getDirection());
    const auto b = oc.dot(ray.getDirection());
    const auto c = oc.dot(oc) - radius * radius;
    const auto discriminant = b * b - a * c;
    if (discriminant > 0) {
        auto temp = (-b - sqrt(discriminant)) / a;
        if (temp < tmax && temp > tmin) {
            hitRecord.distance = temp;
            hitRecord.point = ray.pointAt(hitRecord.distance);
            hitRecord.normal = (hitRecord.point - center).normalized();
            return true;
        }
        temp = (-b + sqrt(discriminant)) / a;
        if (temp < tmax && temp > tmin) {
            hitRecord.distance = temp;
            hitRecord.point = ray.pointAt(hitRecord.distance);
            hitRecord.normal = (hitRecord.point - center).normalized();
            return true;
        }
    }
    return false;
}

}
