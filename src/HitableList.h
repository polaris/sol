#ifndef _HitableList_H
#define _HitableList_H

#include "Hitable.h"

#include <vector>
#include <memory>

namespace sol {

class HitableList
: public Hitable {
public:
    void add(std::shared_ptr<Hitable> hitable);

    bool hit(const Ray &ray, float tmin, float tmax, HitRecord &hitRecord) override;

private:
    std::vector<std::shared_ptr<Hitable>> list;
};

}

#endif  // _HitableList_H
