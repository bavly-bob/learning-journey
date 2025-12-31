#include <iostream>
using namespace std;

int getlen(char str[]) {
    int len = 0;
    for(; str[len] != '\0'; len++);
    return len;
}

void stringCopy(char T[], char S[])
{
    int *p = S[];
    T[]= *p; 
}

int main() {

    char str[] = "Hello, World!";
    cout << "Length of the string is: " << getlen(str) << endl;

    stringCopy(str, str);
    
    return 0;
}