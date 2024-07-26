//Header files
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

const int MAX = 256; //Max number of characters

int main() {

        //Variables
        char answer;
        char input[MAX];
        string fileName = "register.txt"; //Declare textfile variable
        ofstream output; //Declare type of stream

        //Writing to file
        output.open(fileName);

        //Error control
        if (output.fail()) {
                cout << "Cannot open file for writing." << endl;
                return 1;
        }

        cout << "Enter personal information, and it will be saved to file: " << fileName << endl;

        do {

                //Ger user info and send to txt file
                cout << "Enter a name, phone number, and address, each separated by a comma: " << endl;
                cin.getline(input, MAX);
                output << input << endl;
                memset(input, 0, sizeof input); //Rest memory
                cout << "Want to add more information : (Y/N)? ";
                cin >> answer;
                cin.ignore(); //Clear buffer 

        } while (toupper(answer) == 'Y');

        output.close();
        return 0;
}
