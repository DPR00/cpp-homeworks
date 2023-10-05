#include "image.hpp"

using igg::io_tools::ImageData;

namespace igg
{
    int Image::rows() const
    {
        return rows_;
    }

    int Image::cols() const
    {
        return cols_;
    }

    uint8_t &Image::at(int row, int col)
    {
        int pos = row * cols_ + col;
        return data_[pos];
    }

    uint8_t Image::at(int row, int col) const
    {
        int pos = row * cols_ + col;
        return data_[pos];
    }

    bool Image::FillFromPgm(const std::string &file_name)
    {
        ImageData im_data = igg::io_tools::ReadFromPgm(file_name);

        rows_ = im_data.rows;
        cols_ = im_data.cols;
        max_val_ = im_data.max_val;
        std::copy(im_data.data.begin(), im_data.data.end(), std::back_inserter(data_));

        if (rows_ == 0 && cols_ == 0)
        {
            return false;
        }

        return true;
    }

    void Image::WriteToPgm(const std::string &file_name)
    {
        ImageData im_data{rows_, cols_, max_val_, data_};
        igg::io_tools::WriteToPgm(im_data, file_name);
    }

    std::vector<float> Image::ComputeHistogram(int bins) const
    {

        std::vector<float> hist(bins, 0);
        for (auto &element : data_)
        {
            int pos = element * (bins - 1) / max_val_;
            hist[pos]++;
        }
        for (size_t i = 0; i < hist.size(); i++)
        {
            hist[i] /= rows_ * cols_;
        }

        return hist;
    }

    void Image::DownScale(int scale)
    {
        std::vector tmp_data(rows_ * cols_ / scale / scale, 0);

        int cont = 0;
        for (int r = 0; r < rows_; r += scale)
        {
            for (int c = 0; c < cols_; c += scale)
            {
                tmp_data[cont] = at(r, c);
                cont++;
            }
        }

        rows_ = rows_ / scale;
        cols_ = cols_ / scale;
        data_.clear();
        data_.resize(rows_ * cols_);
        for (int i = 0; i < data_.size(); i++)
            data_[i] = tmp_data[i];
    }

    void Image::UpScale(int scale)
    {

        std::vector<uint8_t> tmp_data(rows_ * cols_ * scale * scale, 0);

        for (int r = 0; r < rows_; r++)
        {
            for (int c = 0; c < cols_; c++)
            {
                uint8_t pixel = at(r, c);
                for (int si = 0; si < scale; si++)
                {
                    for (int sj = 0; sj < scale; sj++)
                    {
                        tmp_data[(r * scale + si) * cols_ * scale + c * scale + sj] = pixel;
                    }
                }
            }
        }

        data_.clear();
        data_.reserve(tmp_data.size());
        data_.insert(data_.begin(), tmp_data.begin(), tmp_data.end());

        rows_ = rows_ * scale;
        cols_ = cols_ * scale;
    }
}