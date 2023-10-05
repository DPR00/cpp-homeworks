#include <iostream>
#include <filesystem>
#include "homework_3.hpp"

namespace fs = std::filesystem;

int main()
{
    image_browser::ScoredImage path_score;
    image_browser::ImageRow image_row;
    std::vector<image_browser::ImageRow> rows;

    std::string dirPath = "../web_app/data";
    std::string data_path = "data/";
    std::string title = "Image Browser";
    std::string stylesheet = "style.css";

    int contador = 0;

    for (const auto &entry : fs::directory_iterator(dirPath))
    {
        if (entry.is_regular_file())
        {
            int pos = contador % 3;
            data_path = entry.path().filename();
            data_path = "data/" + data_path;
            path_score = std::make_tuple(data_path, 0.9);
            image_row[pos] = path_score;
            contador++;
            if (pos == 2)
            {
                rows.push_back(image_row);
            }
        }
    }

    image_browser::CreateImageBrowser(title, stylesheet, rows);
    return 0;
}