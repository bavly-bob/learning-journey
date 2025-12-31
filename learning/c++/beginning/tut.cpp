#include <iostream>
using namespace std;

int square(int x)
{
    return x*x;
}

bool big(int x)
{
    if (x> 100)
    {
        return true;
    }
    return false;
}

int count()
{
    int len;
    string phrase;
    cout << "phrase: " ;
    cin >> phrase;
    len = phrase.length();
    return len;
}

int main()
{
    int x;
    cout << "what number: ";
    cin  >> x;
    x = square(x);
    cout << x << endl;

    if (big(x))
    {
        cout << "big number" << endl ;
    }
    cout << count() << endl;

}
