#include "Utilities.h"

namespace sol {

Eigen::Vector3f randomInUnitSphere() {
    Eigen::Vector3f p;
    do {
        p = 2.0 * Eigen::Vector3f(drand48(), drand48(), drand48()) - Eigen::Vector3f(1, 1, 1);
    } while (p.dot(p) > 1.0);
    return p;
}

}
