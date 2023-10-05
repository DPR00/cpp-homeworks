#include <iostream>
#include <iomanip>
#include "html_writer.hpp"

using std::cout;
using std::endl;

namespace html_writer
{

    void OpenDocument()
    {
        cout << "<!DOCTYPE html>" << endl;
        cout << "<html>" << endl;
    }

    void CloseDocument()
    {
        cout << "</html>" << endl;
    }

    void AddCSSStyle(const std::string &stylesheet)
    {
        cout << "<head>" << endl;
        cout << "<link rel=\"stylesheet\" type=\"text/css\" href=\"" << stylesheet << "\" />" << endl;
        cout << "</head>" << endl;
    }

    void AddTitle(const std::string &title)
    {
        cout << "<title>" << title << "</title>" << endl;
    }

    void OpenBody()
    {
        cout << "<body>" << endl;
    }

    void CloseBody()
    {
        cout << "</body>" << endl;
    }

    void OpenRow()
    {
        cout << "<div class=\"row\">" << endl;
    }

    void CloseRow()
    {
        cout << "</div>" << endl;
    }

    void AddImage(const std::string &img_path, float score, bool highlight)
    {
        std::string img_ext = img_path.substr(img_path.length() - 3);
        if (img_ext == "png" || img_ext == "jpg")
        {
            cout << "<div class = \"column\" ";

            if (highlight)
            {
                cout << "style=\" border : 5px solid green;\"";
            }
            cout << ">" << endl;

            size_t last_slash_position = img_path.find_last_of('/');
            std::string result = img_path.substr(last_slash_position + 1);

            cout << "<h2>" << result << "</h2>" << endl;
            cout << "<img src=\"" << img_path << "\" />" << endl;
            cout << "<p>score = ";
            cout << std::setprecision(2) << std::fixed << score;
            cout << "</p>" << endl;
            cout << "</div>" << endl;
        }
        else
        {
            std::cerr << "got an error (404)" << endl;
            exit(EXIT_FAILURE);
        }
    }
}