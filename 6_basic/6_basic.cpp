#include <iostream>
#define N 20

using namespace std;

int main()
{
    int a[N];
    bool k = false;
    for (int i = 0; i < N; i++) {
        a[i] = rand() % 10 + 1;
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        if (a[i] == 7)
            k = true;
    }
    if (k == true)
        cout << "YES";
    else
        cout << "NO";
}