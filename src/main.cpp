#include "Image.h"
#include "Ray.h"
#include "Sphere.h"
#include "HitableList.h"
#include "Camera.h"

#include <iostream>
#include <cstdlib>

Eigen::Vector3f color(const sol::Ray &ray, sol::Hitable &hitable) {
    sol::HitRecord hitRecord;
    if (hitable.hit(ray, 0.0, std::numeric_limits<float>::max(), hitRecord)) {
        return 0.5 * Eigen::Vector3f(hitRecord.normal.x() + 1, hitRecord.normal.y() + 1, hitRecord.normal.z() + 1);
    } else {
        const auto unitDirection = ray.getDirection().normalized();
        const auto t = 0.5 * (unitDirection.y() + 1.0);
        return (1.0 - t) * Eigen::Vector3f(1.0, 1.0, 1.0) + t * Eigen::Vector3f(0.5, 0.7, 1.0);
    }
}

float myRandom() {
    return drand48();
}

int main(int, char**) {
    const int nx = 2000;
    const int ny = 1000;
    const int ns = 100;

    //const auto aspectRatio = float(nx) / float(ny);

    sol::Image image(nx, ny);

    sol::Camera camera;

    sol::HitableList hitableList;
    hitableList.add(std::make_shared<sol::Sphere>(Eigen::Vector3f(0, 0, -1), 0.5));
    hitableList.add(std::make_shared<sol::Sphere>(Eigen::Vector3f(0, -100.5, -1), 100));

    for (int j = 0; j < ny; j++) {
        for (int i = 0; i < nx; i++) {
            Eigen::Vector3f col(0, 0, 0);

            for (int s = 0; s < ns; s++) {
                const auto u = float(i + myRandom()) / float(nx);
                const auto v = float(j + myRandom()) / float(ny);
                const auto ray = camera.getRay(u, v);
                col += color(ray, hitableList);
            }

            col /= ns;

            const auto r = int(255.99 * col[0]);
            const auto g = int(255.99 * col[1]);
            const auto b = int(255.99 * col[2]);

            image.setPixel(i, (ny - 1) - j, r, g, b);
        }
    }

    image.write("test.png");

    return 0;
}
