#pragma once
#include <iostream>
#include <typeinfo>

template <class T>
class vec
{
    T* data = 0;
    int size = 0;
public:
    vec()
    {
    }

    vec(std::initializer_list<T> list)
    {
        size = list.size();
        delete[] data;
        data = new T[size];
        std::copy(list.begin(), list.end(), data);
    }

    vec(const vec& v)
    {
        size = 0;
        delete[] data;
        for (int i = 0; i < v.size; i++)
            append(v[i]);
    }

    ~vec()
    {
        delete[] data;
        size = 0;
    }

    void append(T elem)
    {
        T* new_data = new T[++size];
        for (int i = 0; i < size - 1; i++)
            new_data[i] = data[i];
        new_data[size-1] = elem;
        delete[] data;
        data = new_data;
    }

    T pop(int idx)
    {
        T* new_data = new T[--size];
        T elem = data[idx < 0 && idx > size ? size : idx];

        for (int i = 0, off = 0; i < size; i++)
        {
            if (i == idx)
                off++;
            new_data[i] = data[i+off];
        }
        delete[] data;
        data = new_data;

        return elem;
    }

    T& peek(int idx) const
    {
        if (idx >= size || -size > idx)
            throw std::out_of_range("index > size");
        if (idx < 0)
            idx = size + idx;
        return data[idx];
    }

    T get_size() const
    {
        return size;
    }

    T get_len() const
    {
        if (size < 1)
            return 0;
        T sum = 0;
        for (int i = 0; i < get_size(); i++)
            sum += (int)peek(i);
        return sum;
    }

    void print() const
    {
        std::cout << std::endl;
        for (int i = 0; i < get_size(); i++)
            std::cout << "[" << i << "] " << this->peek(i) << std::endl;
        std::cout << std::endl;
    }

    void clear()
    {
        if (!data)
            return;
        delete[] data;
        size = 0;
        data = 0;
    }

    vec const& operator=(vec const& v)
    {
        size = 0;
        delete[] data;
        data = new T[v.size];
        for (int i = 0; i < v.size; i++)
            this->append(v[i]);
        return *this;
    }

    vec& operator<<(T elem)
    {
        append(elem);
        return *this;
    }

    T& operator[](int idx) const
    {
        return peek(idx);
    }

    bool operator==(vec& v)
    {
        return get_len() == v.get_len();
    }

    bool operator!=(vec& v)
    {
        return !(*this == v);
    }

    bool operator<(vec& v)
    {
        return get_len() < v.get_len();
    }

    bool operator>(vec& v)
    {
        return get_len() > v.get_len();
    }

    bool operator==(T val)
    {
        return get_len() == val;
    }

    bool operator!=(T val)
    {
        return get_len() != val;
    }

    bool operator<(T val)
    {
        return get_len() < val;
    }

    bool operator>(T val)
    {
        return get_len() > val;
    }

    friend bool operator==(T val, vec const& v)
    {
        return val == v.get_len();
    }

    friend bool operator!=(T val, vec const& v)
    {
        return !(val == v.get_len);
    }

    friend bool operator<(T val, vec const& v)
    {
        return val < v.get_len():
    }

    friend bool operator>(T val, vec const& v)
    {
        return val > v.get_len();
    }

    friend std::ostream& operator<<(std::ostream& out, vec const& v)
    {
        for (int i = 0; i < v.size; i++)
            out << " " << v[i] << " ";
        return out;
    }

    friend std::istream& operator>>(std::istream& in, vec& v)
    {
        for (int i = 0; i < v.size; i++)
            in >> v[i];
        return in;
    }

    vec operator+(vec const& v) const
    {
        vec other;
        int tmp_size = size > v.size ? size : v.size;
        for (int i = 0; i < tmp_size; i++)
        {
            T val = 0;
            if (i < size)
                val += peek(i);
            if (i < v.size)
                val += v[i];
            other << val;
        }
        return other;
    }

    friend vec operator+(vec const& v, T val)
    {
        vec other;
        for (int i = 0; i < v.size; i++)
            other << v[i] + val;
        return other;
    }

    friend vec operator+(T val, vec const& v)
    {
        vec other;
        for (int i = 0; i < v.size; i++)
            other << v[i] + val;
        return other;
    }

    vec operator*(vec const& v) const
    {
        vec other;
        int tmp_size = size > v.size ? size : v.size;
        for (int i = 0; i < tmp_size; i++)
        {
            T val = 1;
            if (i < size)
                val *= peek(i);
            if (i < v.size)
                val *= v[i];
            other << val;
        }
        return other;
    }

    friend vec operator*(vec const& v, T val)
    {
        vec other;
        for (int i = 0; i < v.get_size(); i++)
            other << v[i] * val;
        return other;
    }

    friend vec operator*(T val, vec const& v)
    {
        vec other;
        for (int i = 0; i < v.get_size())
            other << v[i] * val;
        return other; 
    }
};
