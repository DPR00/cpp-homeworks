#include "histogram.hpp"

namespace ipb {

    void Histogram::histogram(const cv::Mat &descriptors,
                              BowDictionary &dictionary) {
        if (descriptors.size().height == 0) return;
        hist_data_.reserve(dictionary.size());
        for (int i = 0; i < hist_data_.capacity(); i++) {
            hist_data_.push_back(0.);
        }

        static cv::flann::Index flann_index(dictionary.vocabulary(),
                                            cv::flann::KDTreeIndexParams(1));

        cv::Mat indices, dists;

        for (int i = 0; i < descriptors.rows; i++) {
            flann_index.knnSearch(descriptors.row(i), indices, dists,
                                  dictionary.size(),
                                  cv::flann::SearchParams(32));
            hist_data_[indices.at<int>(0, 0)] += 1;
        }
    }

    // Type Functionality
    Histogram Histogram::ReadFromCSV(const std::string &file) {
        std::ifstream ifs_file(file);
        std::vector<int> data;

        for (std::string line; std::getline(ifs_file, line, ',');) {
            data.emplace_back(stoi(line));
        }

        return Histogram(data);
    }

    void Histogram::WriteToCSV(const std::string &file) const {
        std::ofstream out_file;
        out_file.open(file);

        for (int i = 0; i < hist_data_.size() - 1; i++) {
            out_file << hist_data_[i] << ",";
        }
        out_file << hist_data_[hist_data_.size() - 1];
        out_file.close();
    }
}  // namespace ipb