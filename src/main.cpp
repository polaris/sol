#include "Image.h"
#include "Ray.h"
#include "Sphere.h"
#include "HitableList.h"
#include "Camera.h"
#include "Lambertian.h"

#include <chrono>
#include <iostream>

const auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
auto realRand = std::bind(std::uniform_real_distribution<double>(0, 1), std::mt19937(seed));

static Eigen::Vector3f randomInUnitSphere() {
    Eigen::Vector3f p;
    do {
        p = 2.0 * Eigen::Vector3f(realRand(), realRand(), realRand()) - Eigen::Vector3f(1, 1, 1);
    } while (p.dot(p) > 1.0);
    return p;
}

Eigen::Vector3f color(const sol::Ray &ray, sol::Hitable &hitable, unsigned int curDepth, unsigned int maxDepth) {
    if (curDepth == maxDepth) {
        return Eigen::Vector3f(0, 0, 0);
    }
    sol::HitRecord hitRecord;
    if (hitable.hit(ray, 0.0, std::numeric_limits<float>::max(), hitRecord)) {
        const auto target = hitRecord.point + hitRecord.normal + randomInUnitSphere();
        return 0.5 * color(sol::Ray(hitRecord.point, target - hitRecord.point), hitable, curDepth + 1, maxDepth);
    } else {
        const auto unitDirection = ray.getDirection().normalized();
        const auto t = 0.5 * (unitDirection.y() + 1.0);
        return (1.0 - t) * Eigen::Vector3f(1.0, 1.0, 1.0) + t * Eigen::Vector3f(0.5, 0.7, 1.0);
    }
}

Eigen::Vector3f color(const sol::Ray &ray, sol::Hitable &hitable) {
    return color(ray, hitable, 0, 10);
}

int main(int, char**) {
    const int nx = 400;
    const int ny = 200;
    const int ns = 100;

    //const auto aspectRatio = float(nx) / float(ny);

    sol::Image image(nx, ny);

    sol::Camera camera;

    sol::HitableList hitableList;
    hitableList.add(std::make_shared<sol::Sphere>(Eigen::Vector3f(0, 0, -1), 0.5, std::make_shared<sol::Lambertian>(Eigen::Vector3f(0.8, 0.3, 0.3))));
    hitableList.add(std::make_shared<sol::Sphere>(Eigen::Vector3f(0, -100.5, -1), 100, std::make_shared<sol::Lambertian>(Eigen::Vector3f(0.8, 0.8, 0.0))));

    for (int j = 0; j < ny; j++) {
        for (int i = 0; i < nx; i++) {
            Eigen::Vector3f col(0, 0, 0);

            for (int s = 0; s < ns; s++) {
                const auto u = float(i + realRand()) / float(nx);
                const auto v = float(j + realRand()) / float(ny);
                const auto ray = camera.getRay(u, v);
                col += color(ray, hitableList);
            }

            col /= ns;

            col = Eigen::Vector3f(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));

            const auto r = int(255.99 * col[0]);
            const auto g = int(255.99 * col[1]);
            const auto b = int(255.99 * col[2]);

            image.setPixel(i, (ny - 1) - j, r, g, b);
        }
    }

    image.write("test.png");

    return 0;
}
