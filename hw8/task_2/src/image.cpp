#include "image.hpp"

namespace igg {

    int Image::rows() const { return rows_; }

    int Image::cols() const { return cols_; }

    Image::Pixel &Image::at(int row, int col) {
        int pos = row * cols_ + col;
        return data_[pos];
    }

    Image::Pixel Image::at(int row, int col) const {
        int pos = row * cols_ + col;
        return data_[pos];
    }

    void Image::DownScale(int scale) {
        std::vector<Image::Pixel> tmp_data(rows_ * cols_ / scale / scale);

        int cont = 0;
        for (int r = 0; r < rows_; r += scale) {
            for (int c = 0; c < cols_; c += scale) {
                tmp_data[cont] = at(r, c);
                cont++;
            }
        }

        rows_ = rows_ / scale;
        cols_ = cols_ / scale;
        data_.clear();
        data_.resize(rows_ * cols_);
        for (int i = 0; i < data_.size(); i++) data_[i] = tmp_data[i];
    }

    void Image::UpScale(int scale) {
        std::vector<Image::Pixel> tmp_data(rows_ * cols_ * scale * scale);

        for (int r = 0; r < rows_; r++) {
            for (int c = 0; c < cols_; c++) {
                Image::Pixel pixel = at(r, c);
                for (int si = 0; si < scale; si++) {
                    for (int sj = 0; sj < scale; sj++) {
                        tmp_data[(r * scale + si) * cols_ * scale + c * scale +
                                 sj] = pixel;
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

    bool Image::ReadFromDisk(const std::string &file) {
        if (io_strategy_ == nullptr) {
            exit(1);
        }

        ImageData img_data = io_strategy_->Read(file);
        rows_ = img_data.rows;
        cols_ = img_data.cols;
        max_val_ = img_data.max_val;

        for (auto i = 0; i < img_data.data.size(); i++) {
            Pixel pix{img_data.data[i][0], img_data.data[i][1],
                      img_data.data[i][2]};
            data_.emplace_back(pix);
        }

        return true;
    }

    bool Image::WriteToDisk(const std::string &file,
                            const std::vector<Pixel> &data_) {
        ImageData img_data;
        img_data.rows = rows_;
        img_data.cols = cols_;
        img_data.max_val = max_val_;

        std::vector<std::vector<int>> out_data;
        out_data.reserve(rows_ * cols_);
        for (auto i = 0; i < img_data.data.size(); i++) {
            std::vector<int> pix({
                data_[i].red,
                data_[i].green,
                data_[i].blue,
            });

            out_data.emplace_back(pix);
        }

        if (io_strategy_->Write(file, img_data)) {
            return true;
        } else {
            exit(1);
        }
    }
}  // namespace igg