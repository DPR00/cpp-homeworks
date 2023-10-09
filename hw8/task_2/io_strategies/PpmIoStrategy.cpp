#include "PpmIoStrategy.hpp"

namespace igg {

    ImageData PpmIoStrategy::Read(const std::string &file) const {
        std::ifstream in(file, std::ios_base::in);
        if (!in) {
            return {0, 0, 0, {}};
        }

        // Read integers, if we read chars, we get 1 digit instead of the whole
        // number
        std::string type;
        int rows = 0;
        int cols = 0;
        int max_val = 0;
        std::vector<std::vector<int>> data;
        in >> type >> rows >> cols >> max_val;

        data.resize(rows * cols);
        int red = 0, green = 0, blue = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                in >> red >> green >> blue;
                data[r * cols + c] = {red, green, blue};
            }
        }

        return {rows, cols, static_cast<uint8_t>(max_val), data};
    }

    bool PpmIoStrategy::Write(const std::string &file,
                              const ImageData &image_data) const {
        std::ofstream out(file);
        if (!out) {
            return false;
        }

        out << "P3" << std::endl
            << image_data.rows << " " << image_data.cols << std::endl
            << image_data.max_val << std::endl;
        for (int r = 0; r < image_data.rows; ++r) {
            for (int c = 0; c < image_data.cols; ++c) {
                out << image_data.data[r * image_data.cols + c][0] << " ";
                out << image_data.data[r * image_data.cols + c][1] << " ";
                out << image_data.data[r * image_data.cols + c][2] << " ";
            }
            out << std::endl;
        }
        return true;
    }
}  // namespace igg