# `Конструкторы`

- `базовый конструктор`
- `конструктор копирования`
- `все остальные`

## `Базовый конструктор`

`Базовый конструктор` - метод имеющий такое же название как и сам класс и не имеет типа
возвразаемого значения.

Оператор `new` возвращает указатель на класс. Он обязательно вызывает
конструктор класса.

```cpp
#intclude <iostream>
using namespace std;

class MyClass
{
public:
    MyClass()
    {
	cout << "Hello world";
    }
}

int main()
{
    MyClass x(...);
    MyClass *p = new MyClass(..);
}
```

## `Конструктор копирования`

`Конструктор копирования` - метод имеющий такое же название как и сам класс и
не имеет типа возвразаемого значения.

`Конструктор копирования` - `(const T&)`.

`Конструктор копирования` есть всегда, если он не будет создан, то скопирует
все поля.

```cpp
// ...

int main()
{
    Myclass y(x);
    // также
    // Myclass y = x;
    MyClass(const MyClass& m);
}
```

## Деструктор

`~` - деструктор.

У каждого класса может быть только 1 дeструктор. Он вызывается при уничтожении
объекта во время выхода из блока.

```cpp
    ~MyClass()
    {
    }
```

## `new`

`new` вызывает конструктор.

Выделения памяти для массива:

```cpp
auto arr = new int[12];
```

```cpp
myclass** mas;
mas = new myclass*[10];
for (int i = 0; i < 10; i++) {
    mas[i] = new myclass(...);
}
```

Высвобождение должно использоваться с `[]`: `delete [] mas`

Перед этим нужно освободить память для элементов массива.

```cpp
for (int i = 0; i < 10; i++) {
    delete mas[i];
}
```

Можно вызвать конструктор и деструктор не освобождая память объекта.

```cpp
T* p = new T;
p->~T();
p->T();
```

## `delete`

У всех элементов массива будет вызван базовый конструктор.

Можно вызвать `delete`, если класс был создан динамически: `detele p`.

## Примеры

- [пример 1](examples/special_methods/ex1.cpp)
- [пример 2](examples/special_methods/ex2.cpp)

## Ссылки

- [BestProg](https://www.bestprog.net/ru/2018/04/02/c-class-constructor-features-of-use-constructors-in-the-classes-the-default-constructor-parameterized-constructors-examples-of-classes-that-contain-constructors_ru)
