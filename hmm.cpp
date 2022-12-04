#include <bits/stdc++.h>
using namespace std;

class Human
{ // Base Class
    string name;
    int age;
    char gender;

public:
    Human(string n, int a, char g)
    {
        this->name = n;
        this->age = a;
        this->gender = g;
    }
    void getter()
    {
        cout << this->name << endl;
        cout << this->age << endl;
        cout << this->gender << endl;
    }
};

class Man : public Human
{ // Derived class via Single-level inheritance
    string religion;
    string race;
    string occupation;

public:
    Man(string n, int a, char g, string rel, string race, string occ) : Human(n, a, g)
    {
        this->religion = rel;
        this->race = race;
        this->occupation = occ;
    }
    void getter1()
    {
        getter();
        cout << this->religion << endl;
        cout << this->race << endl;
        cout << this->occupation << endl;
    }
};

int main(int argc, char const *argv[]) // Driver Program
{
    Man man("Nirmit Mishra", 20, 'M', "Hindu", "Aryan", "Engineering Student");
    man.getter1();
    return 0;
}
