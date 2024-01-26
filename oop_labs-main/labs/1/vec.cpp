#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <iostream>

#include "vec.h"

vec::vec()
{
}

vec::vec(const std::initializer_list<double>& list)
{
    size = list.size();
    delete[] data;
    data = new double[size];
    std::copy(list.begin(), list.end(), data);
}

vec::vec(const vec& v)
{
    size = 0;
    delete[] data;
    for (int i = 0; i < v.size; i++)
        append(v[i]);
}

vec::~vec()
{
    delete[] data;
    size = 0;
}

void vec::append(double val)
{
    double* new_data = new double[++size];
    for (int i = 0; i < size - 1; i++)
        new_data[i] = data[i];
    new_data[size-1] = val;
    delete[] data;
    data = new_data;
}

double vec::pop(int idx = -1)
{
    double* new_data = new double[--size];
    double elem = data[idx < 0 && idx > size ? size : idx];

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

double& vec::peek(int idx) const
{
    if (idx >= size || -size > idx)
        throw std::out_of_range("index > size");
    if (idx < 0)
        idx = size + idx;
    return data[idx];
}

double vec::get_size() const
{
    return size;
}

double vec::get_len() const
{
    double sum = 0;
    for (double i = 0; i < get_size(); i++)
        sum += (*this)[i] * (*this)[i];
    return sqrt(sum);
}

void vec::print() const
{
    std::cout << std::endl;
    for (int i = 0; i < get_size(); i++)
        std::cout << "[" << i << "] " << this->peek(i) << std::endl;
    std::cout << std::endl;
}

void vec::clear()
{
    if (!data)
        return;
    delete[] data;
    size = 0;
    data = 0;
}

vec const& vec::operator=(vec const& v)
{
    size = 0;
    delete[] data;
    data = new double[v.size];
    for (int i = 0; i < v.size; i++)
        this->append(v[i]);
    return *this;
}

vec& vec::operator<<(double elem)
{
    append(elem);
    return *this;
}

double& vec::operator[](int idx) const
{
    return peek(idx);
}

bool vec::operator==(vec& v)
{
    return get_len() == v.get_len();
}

bool vec::operator!=(vec& v)
{
    return !(*this == v);
}

bool vec::operator<(vec& v)
{
    return get_len() < v.get_len();
}

bool vec::operator>(vec& v)
{
    return get_len() > v.get_len();
}

bool vec::operator==(double val)
{
    return get_len() == val;
}

bool vec::operator!=(double val)
{
    return get_len() != val;
}

bool vec::operator<(double val)
{
    return get_len() < val;
}

bool vec::operator>(double val)
{
    return get_len() > val;
}

bool operator==(double val, vec const& v)
{
    return val == v.get_len();
}

bool operator!=(double val, vec const& v)
{
    return val != v.get_len();
}

bool operator<(double val, vec const& v)
{
    return val < v.get_len();
}

bool operator>(double val, vec const& v)
{
    return val > v.get_len();
}

std::ostream& operator<<(std::ostream& out, vec const& v)
{
    for (double i = 0; i < v.size; i++)
        out << " " << v[i] << " ";
    return out;
}

std::istream& operator>>(std::istream& in, vec& v)
{
    for (double i = 0; i < v.size; i++)
        in >> v[i];
    return in;
}

vec vec::operator+(vec const& v) const
{
    vec other;
    int tmp_size = size > v.size ? size : v.size;
    for (int i = 0; i < tmp_size; i++)
    {
        double val = 0;
        if (i < size)
            val += peek(i);
        if (i < v.size)
            val += v[i];
        other << val;
    }
    return other;
}

vec operator+(vec const& v, double val)
{
    vec other;
    for (int i = 0; i < v.size; i++)
        other << v[i] + val;
    return other;
}

vec operator+(double val, vec const& v)
{
    vec other;
    for (int i = 0; i < v.size; i++)
        other << v[i] + val;
    return other;
}

vec vec::operator*(vec const& v) const
{
    vec other;
    int tmp_size = size > v.size ? size : v.size;
    for (int i = 0; i < tmp_size; i++)
    {
        double val = 1;
        if (i < size)
            val *= peek(i);
        if (i < v.size)
            val *= v[i];
        other << val;
    }
    return other;
}

vec operator*(vec const& v, double val)
{
    vec other;
    for (int i = 0; i < v.size; i++)
        other << v[i] * val;
    return other;
}

vec operator*(double val, vec const& v)
{
    vec other;
    for (int i = 0; i < v.size; i++)
        other << v[i] * val;
    return other;
}
