#ifndef Asanov_MathTask_H
#define Asanov_MathTask_H

int getFirstDigit(int number)
{
    number = abs(number);
    while (number >= 10)
        number /= 10;
    return number;
}

int getNthDigitFromRight(int number, int N)
{
    number = abs(number);
    for (int i = 0; i < N; ++i)
        number /= 10;
    return number % 10;
}

bool isValidThreeDigit(int number)
{
    return abs(number) >= 100 && abs(number) <= 999;
}

bool isValidDigitPosition(int N)
{
    return N >= 0 && N <= 2;
}

#endif
