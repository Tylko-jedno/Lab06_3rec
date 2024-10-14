#include <iostream>
#include <iomanip>

using namespace std;

int f(int* a, const int size, int i, int res) {
    if (i > size - 1)
        return res;
    else {
        if (a[i] % 2 == 0 && a[i] > res)
            return f(a, size, i + 1, a[i]);
        else
            return f(a, size, i + 1, res);
    }
}

template <typename T, typename T2>
T f2(T2* a, const T size, T i, T res) {
    if (i > size - 1)
        return res;
    else {
        if (a[i] % 2 == 0 && a[i] > res)
            return f(a, size, i + 1, a[i]);
        else
            return f(a, size, i + 1, res);
    }
}

void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}


void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

int main()
{
    int c;
    cout << "n = "; cin >> c;

    int* a = new int[c];

    Create(a, c, -10, 10, 0);
    Print(a, c, 0);

    int res = f(a, c, 0, -10);
    cout << "res = " << res << endl;
    res = f2(a, c, 0, -10);
    cout << "res = " << res << endl;

    delete[] a;
}
