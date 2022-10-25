#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int k = 0;  //лічильник "мама"
    string s;
    getline(cin, s);
    int a = s.find("мама"); //пересування курсору 
    if (a != -1) {
        cout << "Місця входження слова ""мама"": ";
        while (a != -1) {
            k++;
            cout << a + 1 << " ";
            a = s.find("мама", a + 1);
        }
        cout << endl << "Кількість входжень слова ""мама"": " << k;
    }
    else cout << "Слова ""мама"" не виявлено";

    return 0;
}