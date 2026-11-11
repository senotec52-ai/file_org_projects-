#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

// Struct to store person details
struct person {
    string name;
    int age;
};

int main()
{
    // ==========================================
    // Step 1: Input data and save to file
    // ==========================================
    int numperosns;
    cout << "Enter how many persons you want to the file: ";
    cin >> numperosns;
    cin.ignore();

    // Open file for writing person data
    ofstream outFile("person.txt");
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }
    for (int i = 0; i < numperosns ;i++)
    {
        string name;
        int age;

        cout << "\nEnter details for person " << i+1 << ":" << endl;
        cout << "Name: ";
        getline(cin,name);
        cout << "Age: ";
        cin >> age;
        cin.ignore();

        // Save to file as string and integer
        outFile << name << endl;
        outFile << age << endl;
    }
    outFile.close();
    cout << "\nData successfully saved to 'person.txt'." <<endl;

    // ==========================================
    // Step 2: Load data into a vector and analyze
    // ==========================================
    ifstream inFile ("person.txt");
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }
    vector<person> people;
    string tempName;
    int tempAge;

    // Read names and ages from the file sequentially
    while(getline(inFile,tempName))
    {
        if (inFile >> tempAge)
        {
            inFile.ignore(); // Consume the newline character after the age integer
            person p = {tempName,tempAge};
            people.push_back(p);
        }
    }
    inFile.close();

    // Check if any records were loaded
     if (people.empty()) {
        cout << "No data found to analyze!" << endl;
        return 1;
    }

    // Find the youngest and oldest persons
    person younger = people[0];
    person older = people[0];
    for (const auto& p:people)
    {
        if (p.age < younger.age)
        {
            younger = p;
        }
        if (p.age > older.age)
        {
         older =p;
        }
    }

    // Save the results to a results file
    ofstream resFile ("results.txt");
    if (!resFile)
    {
        cerr << "Error creating results file!" << endl;
        return 1;
    }
     resFile << "--- Analysis Results ---" << endl;
     resFile << "Youngest Person: "<< younger.name << "(Age: " << younger.age <<")" << endl;
     resFile << "Oldest person:" << older.name << "(Age: " << older.age << ")" << endl;
     resFile.close();
    cout << "Analysis complete. Results saved to 'results.txt'." << endl;

    return 0;
}
