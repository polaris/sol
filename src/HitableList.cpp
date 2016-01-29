#include "HitableList.h"

namespace sol {

void HitableList::add(std::shared_ptr<Hitable> hitable) {
    list.push_back(hitable);
}

bool HitableList::hit(const Ray &ray, float tmin, float tmax, HitRecord &hitRecord) {
    HitRecord temp;
    auto hitAnything = false;
    auto closest = tmax;
    for (auto hitablePtr : list) {
        if (hitablePtr->hit(ray, tmin, closest, temp)) {
            hitAnything = true;
            closest = temp.distance;
            hitRecord = temp;
        }
    }
    return hitAnything;
}

}