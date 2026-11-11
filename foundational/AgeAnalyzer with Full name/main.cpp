#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct person
{
    string name;
    int age;
};

int main()
{
    // ==========================================
    // Step 1: Request the data and save it to the file
    // ==========================================
    ofstream outputFile("persons.txt");
    if (!outputFile)
    {
        cerr << "Error: Could not create persons.txt!" << endl;
        return 1;
    }

    int count;
    cout << "Enter how many persons you want to add: ";
    cin >> count;

    // Clearing the buffer after `cin >> count` to get rid of the Enter key (`\n`)
    cin.ignore();

    for (int i = 0; i < count; i++)
    {
        person p_input;
        cout << "Enter name for person " << i + 1 << ": ";
        getline(cin, p_input.name); // Read the full name, including spaces

        cout << "Enter age for person " << i + 1 << ": ";
        cin >> p_input.age;

        // Clearing the buffer after reading the age, in preparation for the next `getline` call.
        cin.ignore();

        // Save the data to the file, separating the name from the age with a special symbol, such as a comma (,).
        // Because the name now contains spaces
        outputFile << p_input.name << "," << p_input.age << "\n";
    }
    outputFile.close();
    cout << "Data saved to 'persons.txt' successfully.\n\n";


    // ==========================================
    // Step 2: Reading data from the file and processing it
    // ==========================================
    vector<person> persons;
    person p;

    ifstream inputFile("persons.txt");
    if (!inputFile)
    {
        cerr << "Error: Could not open input file!" << endl;
        return 1;
    }

    // Reading the file line by line based on the comma delimiter
    string age_str;
    while (getline(inputFile, p.name, ',') && getline(inputFile, age_str))
    {
        p.age = stoi(age_str); // Converting age from text to a number
        persons.push_back(p);
    }
    inputFile.close();

    if (persons.empty())
    {
        cerr << "No data found in the file." << endl;
        return 1;
    }

    person youngest = persons[0];
    person oldest = persons[0];

    for (size_t i = 1; i < persons.size(); i++)
    {
        if (persons[i].age < youngest.age)
        {
            youngest = persons[i];
        }
        if (persons[i].age > oldest.age)
        {
            oldest = persons[i];
        }
    }

    ofstream resultsFile("results.txt");
    if (!resultsFile)
    {
        cerr << "Error: Could not create results file!" << endl;
        return 1;
    }

    resultsFile << "Youngest Person:\n" << youngest.name << " (" << youngest.age << " years old)\n\n";
    resultsFile << "Oldest Person:\n" << oldest.name << " (" << oldest.age << " years old)\n";
    resultsFile.close();

    cout << "Data processed successfully. Results saved to 'results.txt'." << endl;

    return 0;
}
