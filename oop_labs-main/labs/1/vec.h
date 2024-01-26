#pragma once
#include <iostream>

class vec
{
    double* data = 0;
    int size = 0;
public:
    vec();
    vec(const std::initializer_list<double>& list);
    vec(const vec& v);
    ~vec();

    void append(double val);

    double pop(int idx);
    double& peek(int idx) const;

    double get_size() const;
    double get_len() const;

    void print() const;

    void clear();

    vec const& operator=(vec const& v);

    vec& operator<<(double val);
    double& operator[](int idx) const;

    bool operator==(vec& v);
    bool operator!=(vec& v);
    bool operator<(vec& v);
    bool operator>(vec& v);

    bool operator==(double val);
    bool operator!=(double val);
    bool operator<(double val);
    bool operator>(double val);

    friend bool operator==(double val, vec const &v);
    friend bool operator!=(double val, vec const &v);
    friend bool operator<(double val, vec const &v);
    friend bool operator>(double val, vec const &v);

    friend std::ostream& operator<<(std::ostream& out, vec const& v);
    friend std::istream& operator>>(std::istream& in, vec& v);

    vec operator+(vec const &v) const;
    friend vec operator+(vec const &v, double val);
    friend vec operator+(double val, vec const &v);

    vec operator*(vec const &v) const;
    friend vec operator*(vec const &v, double val);
    friend vec operator*(double val, vec const &v);
};

