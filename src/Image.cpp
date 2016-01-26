#include "Image.h"

#include <png++/png.hpp>

namespace sol {

struct Image::ImageImpl {
    ImageImpl(unsigned int width, unsigned int height)
    : image(width, height) {
    }
    png::image<png::rgb_pixel> image;
};

Image::Image(unsigned int width, unsigned int height)
: pimpl(std::make_unique<ImageImpl>(width, height)) {
}

Image::~Image() {
}

unsigned int Image::getWidth() const {
    return pimpl->image.get_width();
}

unsigned int Image::getHeight() const {
    return pimpl->image.get_height();
}

void Image::write(const char * const filename) {
    pimpl->image.write(filename);
}

void Image::setPixel(unsigned int x, unsigned int y, unsigned char r, unsigned char g, unsigned char b) {
    png::rgb_pixel pixel(r, g, b);
    pimpl->image.set_pixel(x, y, pixel);
}

}