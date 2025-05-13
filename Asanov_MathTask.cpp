#include <iostream>
#include "Asanov_MathTask.h"
using namespace std;

int main()
{
    int X, N;
    cout << "Введите трехзначное число X: ";
    cin >> X;

    if (!isValidThreeDigit(X))
    {
        cout << "Ошибка: Число не является трехзначным!" << endl;
        return 1;
    }

    cout << "Введите номер цифры N (0 — последняя, 1 — средняя, 2 — первая): ";
    cin >> N;

    if (!isValidDigitPosition(N))
    {
        cout << "Ошибка: N должно быть от 0 до 2" << endl;
        return 1;
    }

    cout << "Первая цифра числа X: " << getFirstDigit(X) << endl;
    cout << N << "-я цифра числа X справа налево: " << getNthDigitFromRight(X, N) << endl;

    return 0;
}
