#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>
#include "convert_dataset.hpp"
// using namespace cv;
// using namespace std;
namespace fs = std::filesystem;

/// Images

int main()
{

    // std::string path_file = "data/lenna.png";
    // std::string path_bin = "data/lenna.bin";
    // cv::Mat img = cv::imread(path_file);
    // cv::imshow("Image before serialization", img);

    // ipb::serialization::Serialize(img, path_bin);
    // cv::Mat img_des = ipb::serialization::Deserialize(path_bin);

    // if (!img_des.empty())
    // {
    //     cv::imshow("Loaded Image", img_des);
    //     cv::waitKey(0);
    // }
    // else
    // {
    //     std::cerr << "Failed to load the image." << std::endl;
    //     return -1;
    // }
    // cv::waitKey(0);

    // fs::path path_dataset = "/home/diegopalma/datasets/freiburg/data1/";
    fs::path path_dataset = "data/freiburg/images/";
    fs::path bin_path = "data/freiburg/bin/";
    ipb::serialization::sifts::ConvertDataset(path_dataset);
    auto dataset = ipb::serialization::sifts::LoadDataset(bin_path);
    for (const auto &descriptor : dataset)
    {
        if (!descriptor.empty())
        {
            std::cout << "All good" << std::endl;
        }
        else
        {
            std::cout << "Everything is wrong" << std::endl;
        }
    }
    return 0;
}