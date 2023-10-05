#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "serialize.hpp"

namespace ipb::serialization
{
    void Serialize(const cv::Mat &m, const std::string &filename)
    {
        std::ofstream file(filename, std::ios_base::out | std::ios_base::binary);

        int rows = m.rows;
        int cols = m.cols;
        int type = m.type();
        file.write(reinterpret_cast<char *>(&rows), sizeof(int));
        file.write(reinterpret_cast<char *>(&cols), sizeof(int));
        file.write(reinterpret_cast<char *>(&type), sizeof(int));
        file.write(reinterpret_cast<char *>(m.data), m.total() * m.elemSize());
        file.close();
    }

    cv::Mat Deserialize(const std::string &filename)
    {
        cv::Mat loaded_image;

        std::ifstream inFile(filename, std::ios::in | std::ios::binary);
        if (!inFile.is_open())
        {
            std::cerr << "Failed to open the file for reading." << std::endl;
        }
        int rows, cols, type;

        inFile.read(reinterpret_cast<char *>(&rows), sizeof(int));
        inFile.read(reinterpret_cast<char *>(&cols), sizeof(int));
        inFile.read(reinterpret_cast<char *>(&type), sizeof(int));

        loaded_image.create(rows, cols, type);

        // total: Returns the total number of array elements
        // elemSize: returns the matrix element size in bytes
        inFile.read(reinterpret_cast<char *>(loaded_image.data), loaded_image.total() * loaded_image.elemSize());
        inFile.close();

        return loaded_image;
    }
}