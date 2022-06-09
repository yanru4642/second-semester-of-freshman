#include <iostream>
using namespace std;

int countStrings(int*& a, int*& b, int n);

int main() {
    int n;
    int* a;
    int* b;
    int ans;
    cout << "n-bit string without consecutive 1" << endl;
    cout << "Enter n> ";
    cin >> n;
    a = new int[n];
    b = new int[n];
    ans = countStrings(a, b, n);
    cout << n << "-bit: " << ans << endl;
    return 0;
}

int countStrings(int*& a, int*& b, int n) {
    a[0] = b[0] = 1;
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i - 1] + b[i - 1];
        b[i] = a[i - 1];
    }
    return a[n - 1] + b[n - 1];
}