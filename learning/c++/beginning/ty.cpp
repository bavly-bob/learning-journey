#include <iostream>
using namespace std;

int main()
{
   for (int i =0 ; i <3;i++)
   {
        int num =0;
        cout << "enter a num: \n";
        cin >> num;
        int temp = num/2+1;
        if (num < 0) return 1;
        for(int j =1; j < temp;j++)
        {
            if((num%j)==0) cout<<j << " ";
        }
        cout << endl;
   }
}
