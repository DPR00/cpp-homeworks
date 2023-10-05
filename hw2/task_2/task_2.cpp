#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{

    if (argc != 3)
    {
        cerr << "got an error" << endl;
        exit(EXIT_FAILURE);
    }

    std::stringstream file1{argv[1]};
    std::stringstream file2{argv[2]};

    int num_file1, num_file2;
    std::string ext_file1, ext_file2;

    file1 >> num_file1 >> ext_file1;
    file2 >> num_file2 >> ext_file2;

    if (ext_file1 == ".txt" && ext_file2 == ".txt")
    {
        cout << (num_file1 + num_file2) / 2 << endl;
    }
    else if (ext_file1 == ".png" && ext_file2 == ".png")
    {
        cout << num_file1 + num_file2 << endl;
    }
    else if (ext_file1 == ".txt" && ext_file2 == ".png")
    {
        cout << num_file1 % num_file2 << endl;
    }
    else
    {
        cerr << "got an error" << endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}