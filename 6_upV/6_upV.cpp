#include <iostream>
#define N 5

using namespace std;

int main()
{
    int a[N * 2];
    int help;
    for (int i = 0; i < N * 2; i++) {
        *(a + i) = i + 1;
        cout << *(a + i) << " ";
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        help = *(a + i);
        *(a + i) = *(a + i + N);
        *(a + i + N) = help;
    }
    for (int i = 0; i < N / 2 + 1; i++) {
        help = *(a + i + N);
        *(a + i + N) = *(a + N * 2 - i - 1);
        *(a + N * 2 - i - 1) = help;
    }
    for (int i = 0; i < N * 2; i++)
        cout << *(a + i) << " ";
}