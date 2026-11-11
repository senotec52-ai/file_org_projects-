#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string fileName = "fruit.txt";
    string line ;

    // 1. Read the list contents from the file

    ifstream inputFile (fileName);
    if (!inputFile.is_open()){
        cerr << "Error : Could not open the file" << fileName << "for reading" << endl;
        return 1;
    }
    cout << "Reading the current file \n";
    while (getline (inputFile,line)) {
        cout << line << endl;
    }
        inputFile.close();  // Close the file after reading

    // 2. Append the message "Fresh Fruits" to the same file

        ofstream outputFile(fileName, ios::app);
        if (!outputFile.is_open()){
        cerr << "Error : Could not open the file" << fileName << "for writing" << endl;
        return 1;

        }
        outputFile << "Fresh Fruits" << endl;
        outputFile.close(); // Close the file after writing

        cout << "\nSuccessfully appended Fresh Fruits to " << fileName << endl;

    return 0;
}
