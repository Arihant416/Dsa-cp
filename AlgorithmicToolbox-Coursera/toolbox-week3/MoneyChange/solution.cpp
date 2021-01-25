#include <iostream>

int get_change(int m)
{
    // Given Denominations are 1,5,10;
    if (m % 10 == 0)
        return m / 10;
    if (m < 10 && m >= 5)
    {
        return m - 5 + 1;
    }
    if (m < 5 && m >= 1)
        return m;
    int tens(0), fives(0), ones(0);
    while (m >= 10)
    {
        m -= 10;
        tens++;
    }
    while (m >= 5)
    {
        m -= 5;
        fives++;
    }
    return m + fives + tens;
}

int main()
{
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
