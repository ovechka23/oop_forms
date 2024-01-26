#include <iostream>
#include <vector>
using namespace std;

#include "vec.h"

int main()
{
    vec<int> v1;
    v1.append(12);
    v1.append(13);
    v1.append(14);
    v1 << 15 << 16 << 17 << 18 << 20;

    v1.print();
    v1.pop(2);
    v1.print();
    cout << v1[0];

    vec<int> v2;
    v2 << 1 << 2 << 4 << 10;
    v2.print();

    vec<int> v3;
    v3 = v1 + v2;
    v3.print();

    vec<int> v4;
    v4 << 4 << 3;

    cout << v4.get_len() << endl;
    if (v4 < v1)
        cout << "v4 less than" << endl;

    vec<int> v5 = { 123, 213, 312, 312 };
    v5.append(3);
    v5 << 6;
    v5.print();

    vec<float> v6 = { 1 ,2 , 3 };
    v5.print();
    cout << endl << "-1: " << v5[-1];

    vec<char*> v7;
    v7 << "hello";
    v7 << "world";
    cout << v7;

    cout << endl << endl;
    system("pause");
}