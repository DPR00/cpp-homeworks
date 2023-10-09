#ifndef IOSTRATEGY_HPP_
#define IOSTRATEGY_HPP_

#include <iostream>
#include <string>
#include <vector>

namespace igg {

    struct ImageData {
        int rows;
        int cols;
        uint8_t max_val;
        std::vector<std::vector<int>> data;
    };

    class IoStrategy {
      private:
      public:
        virtual ImageData Read(const std::string &file) const = 0;
        virtual bool Write(const std::string &file,
                           const ImageData &img) const = 0;
    };

}  // namespace igg

#endif