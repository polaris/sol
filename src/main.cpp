#include <Eigen/Core>

#include "Image.h"

int main(int, char**) {
    Eigen::Vector3f v1;

    sol::Image image(128, 128);
    for (unsigned int y = 0; y < image.getHeight(); ++y) {
        for (unsigned int x = 0; x < image.getWidth(); ++x) {
            image.setPixel(x, y, 255, 0, 0);
        }
    }
    image.write("test.png");

    return 0;
}
