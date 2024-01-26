# iostream

`cin`, `cout` - объекты ввода, вывода для консоли.

## `ostream`

`ostream` - ввод в поток.

```cpp
myclass
{
public:
	friend ostream& operator << (ostream& out, myclass& x);
}

ostream& operator << (ostream& out, myclass& x) {
	 out << x.smt;
	 return out;
}
```

## `istream`

`istream` - вывод из потока.

```cpp
myclass
{
public:
	friend ostream& operator << (ostream& out, myclass& x);
}

istream& operator << (istream& out, myclass& x) {
	 in >> x.smt;
	 return in;
}
```