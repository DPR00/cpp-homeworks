#include "convert_dataset.hpp"

namespace fs = std::filesystem;

namespace ipb::serialization::sifts
{

    void ConvertDataset(const std::filesystem::path &img_path)
    {
        std::string path = "data/freiburg/bin/";
        std::string data_path, path_bin, path_img;
        for (const auto &entry : fs::directory_iterator(img_path))
        {

            if (entry.is_regular_file() && (entry.path().filename().extension().string() == ".png"))
            {
                data_path = entry.path().filename();
                path_bin = data_path.substr(0, data_path.length() - 4);
                path_bin = path + path_bin + ".bin";
                path_img = img_path.string() + data_path;
                cv::Mat img = cv::imread(path_img);

                // Compute sift
                auto detector = cv::SiftFeatureDetector::create();
                std::vector<cv::KeyPoint> keypoints;
                detector->detect(img, keypoints);

                cv::Mat descriptors;
                auto extractor = cv::SiftDescriptorExtractor::create();
                extractor->compute(img, keypoints, descriptors);

                ipb::serialization::Serialize(descriptors, path_bin);
            }
        }
    }

    std::vector<cv::Mat> LoadDataset(const std::filesystem::path &bin_path)
    {
        std::vector<cv::Mat> dataset;
        cv::Mat des_sift;
        std::string data_path, bin_file;

        for (const auto &entry : fs::directory_iterator(bin_path))
        {
            if (entry.is_regular_file() && (entry.path().filename().extension().string() == ".bin"))
            {
                data_path = entry.path().filename();
                bin_file = bin_path.string() + data_path;
                des_sift = ipb::serialization::Deserialize(bin_file);
                dataset.push_back(des_sift);
            }
        }

        return dataset;
    }
}