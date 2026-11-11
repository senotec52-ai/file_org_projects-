#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ofstream file ("welcome.txt");
  if (!file.is_open())
  {
      cout << "Error opening the file";
  }
  else
  {
      cout << file.tellp() << endl;
      file << "Hello Everybody" ;
      cout << file.tellp() << endl;
      file.seekp(11);
      file << "one ";
      cout << file.tellp() << endl;
  }


    return 0;
}
