#include "Image.h"
#include "Ray.h"

#include <iostream>

bool hitSphere(const Eigen::Vector3f &center, float radius, const sol::Ray &ray) {
    Eigen::Vector3f oc = ray.getOrigin() - center;
    const auto a = ray.getDirection().dot(ray.getDirection());
    const auto b = 2.0 * oc.dot(ray.getDirection());
    const auto c = oc.dot(oc) - radius * radius;
    const auto discriminant = b * b - 4 * a * c;
    return discriminant > 0;
}

Eigen::Vector3f color(const sol::Ray &ray) {
    if (hitSphere(Eigen::Vector3f(0.0, 0.0, -1.0), 0.5, ray)) {
        return Eigen::Vector3f(1.0, 0.0, 0.0);
    }
    const auto unitDirection = ray.getDirection().normalized();
    const auto t = 0.5 * (unitDirection.y() + 1.0);
    return (1.0 - t) * Eigen::Vector3f(1.0, 1.0, 1.0) + t * Eigen::Vector3f(0.5, 0.7, 1.0);
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

    for (int j = 0; j < ny; j++) {
        for (int i = 0; i < nx; i++) {
            const auto u = float(i) / float(nx);
            const auto v = float(j) / float(ny);

            const sol::Ray ray(origin, lowerLeftCorner + u * horizontal + v * vertical);
            const auto col = color(ray);

            const auto r = int(255.99 * col[0]);
            const auto g = int(255.99 * col[1]);
            const auto b = int(255.99 * col[2]);

            image.setPixel(i, (ny - 1) - j, r, g, b);
        }
    }

    image.write("test.png");

    return 0;
}
