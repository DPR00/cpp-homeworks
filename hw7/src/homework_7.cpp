#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>
#include "homework_7.h"

// using namespace cv;
// using namespace std;
namespace fs = std::filesystem;

/// Images

int main()
{
    fs::path path_dataset = "data/freiburg/images/";
    fs::path bin_path = "data/freiburg/bin/";
    ipb::serialization::sifts::ConvertDataset(path_dataset);
    auto dataset = ipb::serialization::sifts::LoadDataset(bin_path);
    // std::cout << dataset.size() << std::endl;
    cv::Mat hola = ipb::kMeans(dataset, 3, 10);
    return 0;
}