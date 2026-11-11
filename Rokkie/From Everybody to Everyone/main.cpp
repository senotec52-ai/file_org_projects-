#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // 1. Writing the first sentence in the file
    ofstream file("welcome.txt");
    if (!file.is_open()) {
        cout << "Error opening the file" << endl;
        return 1;
    }

    string text = "Hello Everybody";
    file << text;
    file.close(); // Closing the file to save the first text

    // 2. Using appropriate functions for replacement (string::replace)
    size_t pos = text.find("body");
    if (pos != string::npos) {
        text.replace(pos, 4, "one"); // Replacing "body" (4 letters) with "one" (3 letters)
    }

    // 3. Print the final result "Hello Everyone" in the same file
    file.open("welcome.txt", ios::trunc); // Reopen the file and clear its previous content
    if (file.is_open()) {
        file << text;
        file.close();
    }

    cout << "Done! Final text: " << text << endl;

    return 0;
}
