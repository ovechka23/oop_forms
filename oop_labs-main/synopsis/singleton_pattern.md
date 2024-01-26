# Паттерн синглтона

> NOTE: в многопоточном коде синглтоны работают плохо.

## Пример синглтона с указателем

```cpp
class Singleton
{
    static Singleton* instance; // in *.h
    // in *.cpp: Singleton* Singeton::instance = nullptr;

    // for calling Singleton::instance, but u cant do this because of private
    Signleton();
    Singleton(const Singleton&);

public:
    // static method dont have this
    static Singleton* getInstance()
    {
	if (instance == nullptr)
	   instance = new Singleton();
	return instance;
    }
};

int main()
{
    Singleton* s = Singleton::getInstance();
    // recieving access to the 1 object
}
```

## Пример синглтона с ссылкой

```cpp
class Singleton2
{
public:
	static Singleton2& GetInstance()
	{
		static Singleton2 instance;
		return instance;
	}
private:
	Singleton2(){}
public:
	Singleton2(const Singleton2&) = delete;
	Singleton2& operator=(const Singleton2&) = delete;
	// Note: Scott Meyers mentions in his Effective Modern
        //       C++ book, that deleted functions should generally
        //       be public as it results in better error messages
        //       due to the compilers behavior to check accessibility
        //       before deleted status
};

int main(int argn, char** argv)
{
	Singleton2& var = Singleton::GetInstance();
	return 0;
}
```
