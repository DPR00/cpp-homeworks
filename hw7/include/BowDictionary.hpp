#include <filesystem>
#include <vector>
#include <kmeans.hpp>

#include <opencv2/core/mat.hpp>

using cv::Mat;
using std::vector;

namespace ipb
{

    class BowDictionary
    {
    private:
        BowDictionary() = default;
        ~BowDictionary() = default;

        int max_iter_;
        int dict_size_;
        vector<Mat> in_descriptors_;
        Mat codebook_;

    public:
        // Singleton pattern
        BowDictionary(const BowDictionary &) = delete;
        void operator=(const BowDictionary &) = delete;
        static BowDictionary &GetInstance()
        {
            static BowDictionary instance;
            return instance;
        }

        // Getters methods
        int max_iterations() const;
        int size() const;
        vector<Mat> descriptors() const;
        Mat vocabulary() const;
        int total_features() const;
        bool empty() const;

        // Setters methods
        void set_params(int max_iter, int dict_size, vector<Mat> &descriptors);
        void set_max_iterations(int iters);
        void set_size(int size);
        void set_descriptors(vector<Mat> &descriptors);
    };
}