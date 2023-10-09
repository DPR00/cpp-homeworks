#include "PngIoStrategy.hpp"

namespace igg {

    ImageData PngIoStrategy::Read(const std::string &file) const {
        png::image<png::rgb_pixel> image_png(
            file, png::require_color_space<png::rgb_pixel>());

        ImageData img_data;

        img_data.rows = image_png.get_height();
        img_data.cols = image_png.get_width();
        img_data.max_val = 255;

        for (png::uint_32 r = 0; r < img_data.rows; ++r) {
            for (png::uint_32 c = 0; c < img_data.cols; ++c) {
                std::vector<int> pixel{image_png[r][c].red,
                                       image_png[r][c].green,
                                       image_png[r][c].blue};

                img_data.data.emplace_back(pixel);
            }
        }

        return img_data;
    }

    bool PngIoStrategy::Write(const std::string &file,
                              const ImageData &img) const {
        png::image<png::rgb_pixel> image(img.rows, img.cols);

        for (png::uint_32 r = 0; r < img.rows; r++) {
            for (png::uint_32 c = 0; c < img.cols; c++) {
                std::vector<int> pixel = img.data[r * img.cols + c];
                image[r][c] = png::rgb_pixel(pixel[0], pixel[1], pixel[2]);
            }
        }

        image.write(file);

        return true;
    }
}  // namespace igg