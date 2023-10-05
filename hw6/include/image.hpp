#include <vector>
#include <iostream>
#include "io_tools.hpp"
#include <algorithm>

namespace igg
{
    class Image
    {
    public:
        Image() : rows_(0), cols_(0){};
        Image(int rows, int cols) : rows_(rows), cols_(cols)
        {
            data_.resize(rows_ * cols_, 0);
        };
        ~Image(){};

        int rows() const;
        int cols() const;
        uint8_t &at(int row, int col);
        uint8_t at(int row, int col) const;
        bool FillFromPgm(const std::string &file_name);
        void WriteToPgm(const std::string &file_name);
        void DownScale(int scale);
        void UpScale(int scale);
        std::vector<float> ComputeHistogram(int bins) const;

    private:
        int rows_;
        int cols_;
        uint8_t max_val_;
        std::vector<uint8_t> data_;
    };
}