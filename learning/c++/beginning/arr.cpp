#include <iostream>
using namespace std;

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    cout << a[-1] << endl;  // Accessing out-of-bounds index

    return 0;
}