#ifndef PNGIOSTRATEGY_HPP_
#define PNGIOSTRATEGY_HPP_

#include <iostream>
#include <png++/png.hpp>
#include <string>

#include "IoStrategy.hpp"

using igg::ImageData;

namespace igg {

    class PngIoStrategy : public IoStrategy {
      public:
        ImageData Read(const std::string &file) const override;
        bool Write(const std::string &file,
                   const ImageData &img) const override;
    };

}  // namespace igg

#endif