#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string Fullname;
    string studentID;
    string Grade;

    cout << "Enter Student's full name : ";
    getline (cin,Fullname);
    cout << "Enter Student ID : ";
    getline (cin,studentID);
    cout << "Enter Student Grade :";
    getline(cin,Grade);
    fstream outputfile("Student.txt");
    if (outputfile.is_open()) {
        outputfile << "Full Name: " << Fullname << endl;
        outputfile << "ID: " << studentID << endl;
        outputfile << "Grade: " << Grade << endl;
        outputfile.close();
        cout << "\nData successfully written to \"Student.txt\".\n";
    }
    else {
        cerr << "\nError: Could not create or open the file.\n";
    }

    return 0;
}
