#include <iostream>
#include <cstdlib>
#include <random>

using namespace std;

int main()
{
    random_device rd;
    uniform_int_distribution<int> dist(0, 99);

    int random_number = dist(rd);
    int guessed_number = 100;

    while (guessed_number != random_number)
    {
        cin >> guessed_number;

        if (cin.fail())
        {
            cerr << "Error encountered, exiting..." << endl;
            cout << random_number << endl;
            exit(EXIT_FAILURE);
        }
        else
        {
            if (0 <= guessed_number && guessed_number <= 99)
            {

                if (guessed_number > random_number)
                    cout << "Number is smaller" << endl;
                else if (guessed_number < random_number)
                {
                    cout << "Number is larger" << endl;
                }
                else
                {
                    cout << "You won" << endl;
                    cout << random_number << endl;
                    exit(EXIT_SUCCESS);
                }
            }
            else
            {
                cerr << "[WARNING] : Number must be between 0 and 99" << endl;
            }
        }
    }

    return 0;
}