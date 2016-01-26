#ifndef _Image_h
#define _Image_h

#include <memory>

namespace sol {

class Image {
public:
    Image(unsigned int width, unsigned int height);

    Image(const Image&) = delete;

    Image(const Image&&) = delete;

    Image& operator =(const Image&) = delete;

    Image& operator =(const Image&&) = delete;

    virtual ~Image();

    unsigned int getWidth() const;

    unsigned int getHeight() const;

    void write(const char * const filename);

    void setPixel(unsigned int x, unsigned int y, unsigned char r, unsigned char g, unsigned char b);

private:
    struct ImageImpl;

    std::unique_ptr<ImageImpl> pimpl;
};

}

#endif  // _Image_h
