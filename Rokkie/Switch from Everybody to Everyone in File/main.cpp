#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // 1. Write "Hello Everybody" to the file "welcome.txt"
    ofstream outfile ("welcome.txt");
    if (!outfile)
    {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    outfile << "Hello Everybody";
    outfile.close();

    // 2. Read the content from "welcome.txt"
    ifstream infile ("welcome.txt");
    if (!infile)
        {
            cerr << "Error opening file for reading" << endl;
            return 1;
        }

        string text;
        getline (infile,text);
        infile.close();

        // 3. Find and replace "body" with "one"
        string toReplace ="body";
        string replacement = "one";
        size_t pos = text.find(toReplace);
        if ( pos!= string::npos)
        {
            text.replace(pos,toReplace.length(),replacement);
        }
        // 4. Print the final result back into the same file (overwriting it)
        ofstream finaloutfile ("welcome.txt");
        if (!outfile)
        {
            cerr << "Error opening file to update content!" << endl;
            return 1;
        }

        finaloutfile << text;
        finaloutfile.close();
        cout << "File updated successfully with " << text << endl;



    return 0;
}
