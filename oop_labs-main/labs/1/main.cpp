#include <iostream>
using namespace std;

#include "vec.h"

int main()
{
    vec v1;
    v1.append(12);
    v1.append(13);
    v1.append(14);
    v1 << 15 << 16 << 17 << 18 << 20;
    v1.print();
    v1.pop(2);
    v1.print();
    cout << v1[0];

    vec v2;
    v2 << 1 << 2 << 4 << 10;
    v2.print();

    vec v3;
    v3 = v1 + v2;
    v3.print();

    vec v4;
    v4 << 4 << 3;

    cout << v4.get_len() << endl;
    if (v4 < v1)
        cout << "v4 less than" << endl;

    vec v5 = { 123, 213, 312, 312 };
    vec v6 = { 1 ,2 , 3 };
    v5.print();
    v5 = { 1, 2, 3 };
    cout << endl << "-1: " << v5[-1];

    cout << endl;
    system("pause");
}