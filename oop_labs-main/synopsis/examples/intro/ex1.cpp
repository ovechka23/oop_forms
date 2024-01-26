class Human
{
private:
    int age;
    string name;

public:
    void set(int age, string name)
    {
        // внутри каждого нестатического метода имеется указатель на объект,
        // у которого этот метод вызван
        this->age = age;
        this->name = name;
    }

    int get_age()
    {
        return this->age;
    }

    int get_name()
    {
        return name;
    }
};
