#include "Image.h"
#include "Ray.h"

int main(int, char**) {
    sol::Ray ray(Eigen::Vector3f(0, 0, 0), Eigen::Vector3f(1, 0, 0));

    sol::Image image(128, 128);
    for (unsigned int y = 0; y < image.getHeight(); ++y) {
        for (unsigned int x = 0; x < image.getWidth(); ++x) {
            image.setPixel(x, y, 255, 0, 0);
        }
    }
    image.write("test.png");

    return 0;
}
