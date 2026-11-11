#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string x ,y ,z ;
    fstream in ("fruit.txt");
    in >> x >> y >> z;

    in.close();

    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    cout << "Fresh Fruits" << endl;


    return 0;
}
