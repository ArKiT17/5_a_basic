#include <iostream>
#include <locale>
#define m 10 
#define n 10

using namespace std;

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    int k = 0;
    double a;
    double mas[m][n];
    cout << "Введiть число а: ";
    cin >> a;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            *(*(mas + i) + j) = rand() % 10;
            cout << *(*(mas + i) + j) << " ";
            if (*(*(mas + i) + j) == a)
                k++;
        }
        cout << endl;
    }
    cout << endl << "Кiлькiсть чисел " << a << ": " << k;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (*(*(mas + i) + j) == a)
                cout << endl << "Ряд: " << i + 1 << " Стовпець: " << j + 1;
        }
    }
}