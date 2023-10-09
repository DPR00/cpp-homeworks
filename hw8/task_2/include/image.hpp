#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

#include "IoStrategy.hpp"

namespace igg {

    class Image {
      public:
        struct Pixel {
            int red;
            int green;
            int blue;
        };
        Image() : rows_(0), cols_(0){};
        Image(int rows, int cols) : rows_(rows), cols_(cols) {
            data_.resize(rows_ * cols_);
        };
        ~Image() = default;

        int rows() const;
        int cols() const;
        Pixel &at(int row, int col);
        Pixel at(int row, int col) const;
        void DownScale(int scale);
        void UpScale(int scale);
        inline void SetIoStrategy(std::shared_ptr<IoStrategy> strategy_ptr) {
            io_strategy_ = strategy_ptr;
        }
        bool ReadFromDisk(const std::string &file);
        bool WriteToDisk(const std::string &file,
                         const std::vector<Pixel> &data_);

      private:
        int rows_;
        int cols_;
        uint8_t max_val_;
        std::vector<Pixel> data_;
        std::shared_ptr<IoStrategy> io_strategy_ = nullptr;
    };
}  // namespace igg
   // igg
   // igg