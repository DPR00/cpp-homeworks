#ifndef PPMIOSTRATEGY_HPP_
#define PPMIOSTRATEGY_HPP_

#include <iostream>
#include <png++/png.hpp>
#include <string>

#include "IoStrategy.hpp"

using igg::ImageData;

namespace igg {
    class PpmIoStrategy : public IoStrategy {
      public:
        ImageData Read(const std::string &file) const override;
        bool Write(const std::string &file,
                   const ImageData &image_data) const override;
    };

}  // namespace igg

#endif