#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Structure for storing a person's data
struct person
{
    string name;
    int age;
};

int main()
{
    // ==========================================
    // Step 1: Request data from the user and save it to the file
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

    for (int i = 0; i < count; i++)
    {
        person p_input;
        cout << "Enter details for person " << i + 1 << " (Name Age): ";
        cin >> p_input.name >> p_input.age;

        // Save the data to the file as a string followed by an integer, separated by a space.
        outputFile << p_input.name << " " << p_input.age << "\n";
    }
    outputFile.close();
    cout << "Data saved to 'persons.txt' successfully.\n\n";


    // ==========================================
    // Step 2: Reading data from the file and processing it
    // ==========================================
    vector<person> persons;
    person p;

    // Open the file for reading
    ifstream inputFile("persons.txt");
    if (!inputFile)
    {
        cerr << "Error: Could not open input file!" << endl;
        return 1;
    }

    // Loading data into the vecto
    while (inputFile >> p.name >> p.age)
    {
        persons.push_back(p);
    }
    inputFile.close();

    // Verify that the file contains data
    if (persons.empty())
    {
        cerr << "No data found in the file." << endl;
        return 1;
    }

    // اFinding the youngest and oldest person
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

    // Save the results to the results file
    ofstream resultsFile("results.txt");
    if (!resultsFile)
    {
        cerr << "Error: Could not create results file!" << endl;
        return 1;
    }

    resultsFile << "Youngest Person:\n" << youngest.name << " " << youngest.age << "\n\n";
    resultsFile << "Oldest Person:\n" << oldest.name << " " << oldest.age << "\n";

    resultsFile.close();

    cout << "Data processed successfully. Results saved to 'results.txt'." << endl;

    return 0;
}
