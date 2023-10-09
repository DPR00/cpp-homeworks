#include <fstream>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/flann.hpp>
#include <opencv2/opencv.hpp>
#include <ostream>
#include <sstream>
#include <vector>

#include "BowDictionary.hpp"

namespace ipb {

    class Histogram {
      private:
        std::vector<int> hist_data_;
        void histogram(const cv::Mat &descriptors, BowDictionary &dictionary);

      public:
        Histogram();
        Histogram(std::vector<int> &data) : hist_data_(data){};
        Histogram(cv::Mat &descriptors, BowDictionary &dictionary) {
            histogram(descriptors, dictionary);
        }

        // vector functionality
        inline int size() const { return hist_data_.size(); };
        inline bool empty() const { return !(size() > 0); };
        inline std::vector<int> data() const { return hist_data_; };
        inline std::vector<int>::iterator begin() {
            return hist_data_.begin();
        };
        inline std::vector<int>::const_iterator cbegin() const {
            return hist_data_.cbegin();
        };
        inline std::vector<int>::iterator end() { return hist_data_.end(); };
        inline std::vector<int>::const_iterator cend() {
            return hist_data_.cend();
        };

        // overloading
        inline int operator[](int id) const { return hist_data_[id]; };
        inline int &operator[](int id) { return hist_data_[id]; };

        std::ostream &operator<<(std::ostream &stream) const;
        friend std::ostream &operator<<(std::ostream &out, const Histogram &B) {
            for (int i = 0; i < B.size() - 1; i++) {
                out << B[i] << ",";
            }
            out << B[B.size() - 1];

            return out;
        };

        // Type Functionality
        static Histogram ReadFromCSV(const std::string &file);
        void WriteToCSV(const std::string &file) const;
    };
}  // namespace ipb