#include <iostream>
using namespace std;

class SNP
{
    public:
        string name, surname, patronymic;
        string initials = " . . ";

        void set(string s, string n, string p)
        {
            surname = s;
            name = n;
            patronymic = p;

            inits[0] = s[0];
            inits[2] = n[0];
            inits[4] = p[0];
        }

        void print_full()
        {
            cout << surname << " " << name << " " << patronymic;
        }

        void print_inits()
        {
            cout << inits;
        }
};

class SNP_V2
{
    private:
        string name, surname, patronymic;
        string initials = " . . ";

    public:
        void set(string s, string n, string p)
        {
            surname = s;
            name = n;
            patronymic = p;

            inits[0] = s[0];
            inits[2] = n[0];
            inits[4] = p[0];
        }

        void setSurname(string s)
        {
            surname = s;
            inits[0] = s[0];
        }

        void print_full()
        {
            cout << surname << " " << name << " " << patronymic;
        }

        void print_inits()
        {
            cout << inits;
        }
};

int main()
{
    {
        SNP x;
        x.set("Ivanov", "Ivan", "Ivanovich");
        x.print_full();
        x.print_inits(); // I.I.I

        x.surname = "Petrov";
        x.print_full();
        x.print_inits(); // I.I.I
    }

    {
        SNP_V2 x;
        x.set("Ivanov", "Ivan", "Ivanovich");
        x.print_full();
        x.print_inits(); // I.I.I

        x.surname = "Petrov";
        x.print_full();
        x.print_inits(); // P.I.I
    }
}
