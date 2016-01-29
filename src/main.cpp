#include "Image.h"
#include "Ray.h"
#include "Sphere.h"

#include <iostream>

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

int main(int, char**) {
    const int nx = 2000;
    const int ny = 1000;

    const auto aspectRatio = float(nx) / float(ny);

    sol::Image image(nx, ny);

    Eigen::Vector3f lowerLeftCorner(-1.0 * aspectRatio, -1.0, -1.0);
    Eigen::Vector3f horizontal(2.0 * aspectRatio, 0.0, 0.0);
    Eigen::Vector3f vertical(0.0, 2.0, 0.0);
    Eigen::Vector3f origin(0.0, 0.0, 0.0);

    sol::Sphere sphere(Eigen::Vector3f(0, 0, -1), 0.5);

    for (int j = 0; j < ny; j++) {
        for (int i = 0; i < nx; i++) {
            const auto u = float(i) / float(nx);
            const auto v = float(j) / float(ny);

            const sol::Ray ray(origin, lowerLeftCorner + u * horizontal + v * vertical);
            const auto col = color(ray, sphere);

            const auto r = int(255.99 * col[0]);
            const auto g = int(255.99 * col[1]);
            const auto b = int(255.99 * col[2]);

            image.setPixel(i, (ny - 1) - j, r, g, b);
        }
    }

    image.write("test.png");

    return 0;
}
