#include <iostream>
using namespace std;

int main()
{
    string p = "name is bavly";
    cout << p.find("bavly", 4) << endl; // first arg is what to search for
                                        // second is from where to begin
                                        // the output is the location of the first char

    cout << p.substr(5,2) << endl;      //arg1 to pick start point, arg2 how many to pick
}
