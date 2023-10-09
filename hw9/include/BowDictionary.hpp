#include <filesystem>
#include <opencv2/core/mat.hpp>
#include <vector>

#include "kmeans.hpp"

using cv::Mat;
using std::vector;

namespace ipb {

    class BowDictionary {
      private:
        BowDictionary() = default;
        ~BowDictionary() = default;

        int max_iter_;
        int dict_size_;
        Mat vocabulary_;

      public:
        // Singleton pattern
        BowDictionary(const BowDictionary &) = delete;
        void operator=(const BowDictionary &) = delete;
        static BowDictionary &GetInstance() {
            static BowDictionary instance;
            return instance;
        }

        // Getters methods
        int size() const;
        Mat vocabulary() const;
        bool empty() const;

        // Setters methods
        void build(int max_iter, int dict_size, const vector<Mat> &descriptors);
        void set_vocabulary(Mat vocabulary);
        void set_size(int size);
    };
}  // namespace ipb