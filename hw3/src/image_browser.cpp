#include <iostream>
#include "html_writer.hpp"
#include "image_browser.hpp"

using std::cout;
using std::endl;

namespace image_browser
{

    void AddFullRow(const ImageRow &row, bool first_row)
    {
        html_writer::OpenRow();
        html_writer::AddImage(std::get<0>(row[0]), std::get<1>(row[0]), first_row);
        html_writer::AddImage(std::get<0>(row[1]), std::get<1>(row[1]));
        html_writer::AddImage(std::get<0>(row[2]), std::get<1>(row[2]));
        html_writer::CloseRow();
    }

    void CreateImageBrowser(const std::string &title, const std::string &stylesheet,
                            const std::vector<ImageRow> &rows)
    {
        html_writer::OpenDocument();
        html_writer::AddTitle(title);
        html_writer::AddCSSStyle(stylesheet);
        html_writer::OpenBody();
        for (size_t i = 0; i < rows.size(); i++)
        {
            if (i == 0)
            {
                AddFullRow(rows[i], true);
            }
            else
            {
                AddFullRow(rows[i]);
            }
        }
        html_writer::CloseBody();
        html_writer::CloseDocument();
    }
}