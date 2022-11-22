// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>
#include <iomanip>
#include <assert.h>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector
{
protected:
    size_t sz;
    T* pMem;
public:
    TDynamicVector(size_t size = 1) : sz(size)
    {
        if (sz <= 0 || sz > MAX_VECTOR_SIZE)
            throw exception("error");
        else
            pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
    }
    TDynamicVector(T* arr, size_t s) : sz(s)
    {
        assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
        pMem = new T[sz]();
        std::copy(arr, arr + sz, pMem);
    }
    TDynamicVector(const TDynamicVector& v)
    {
        sz = v.sz;
        pMem = new T[sz]();
        std::copy(v.pMem, v.pMem + sz, pMem);
    }
    TDynamicVector(TDynamicVector&& v) noexcept
    {
        pMem = nullptr;
        sz = 0;
        swap(*this, v);
    }
    ~TDynamicVector()
    {
        delete[] pMem;
    }
    TDynamicVector& operator=(const TDynamicVector& v)
    {
        if (this == &v)
            return *this;
        sz = std::max(sz, v.sz);
        TDynamicVector tmp(v);
        swap(*this, tmp);
        return *this;
    }
    TDynamicVector& operator=(TDynamicVector&& v) noexcept
    {
        delete[] pMem;
        pMem = nullptr;
        sz = 0;
        swap(*this, v);
        return *this;
    }

    size_t size() const noexcept { return sz; }

    // индексация
    T& operator[](size_t ind)
    {
        return pMem[ind];
    }
    const T& operator[](size_t ind) const
    {
        return pMem[ind];
    }
    // индексация с контролем
    T& at(size_t ind)
    {
        if (ind < sz && ind >= 0)
        {
            return pMem[ind];
        }
        else
            throw exception("error");
    }
    const T& at(size_t ind) const
    {
        if (ind < sz && ind >= 0)
            return pMem[ind];
        throw exception("error");
    }

    // сравнение
    bool operator==(const TDynamicVector& v) const noexcept
    {
        if (sz != v.sz)
            return false;
        for (size_t i = 0; i < sz; i++)
            if (pMem[i] != v.pMem[i])
                return false;

        return true;
    }

    bool operator!=(const TDynamicVector& v) const noexcept
    {
        if (sz != v.sz)
            return true;
        for (size_t i = 0; i < sz; i++)
            if (pMem[i] != v.pMem[i])
                return true;

        return false;
    }

    // скалярные операции
    TDynamicVector operator+(T val)
    {
        TDynamicVector tmp(sz);
        for (size_t i = 0; i < sz; i++)
            tmp.pMem[i] = pMem[i] + val;
        return tmp;
    }
    TDynamicVector operator-(T val)
    {
        TDynamicVector tmp(sz);
        for (size_t i = 0; i < sz; i++)
            tmp.pMem[i] = pMem[i] - val;
        return tmp;
    }
    TDynamicVector operator*(T val)
    {
        TDynamicVector tmp(sz);
        for (size_t i = 0; i < sz; i++)
            tmp.pMem[i] = pMem[i] * val;
        return tmp;
    }

    // векторные операции
    TDynamicVector operator+(const TDynamicVector& v)
    {
        if (sz == v.sz)
        {
            TDynamicVector tmp(sz);
            for (size_t i = 0; i < sz; i++)
                tmp.pMem[i] = this->pMem[i] + v.pMem[i];
            return tmp;
        }
        else
            throw exception("error");
    }
    TDynamicVector operator-(const TDynamicVector& v)
    {
        if (sz == v.sz)
        {
            TDynamicVector tmp(sz);
            for (size_t i = 0; i < sz; i++)
                tmp.pMem[i] = pMem[i] - v.pMem[i];
            return tmp;
        }
        else
            throw exception("error");
    }
    T operator*(const TDynamicVector& v)
    {
        int result = 0;
        if (sz == v.sz)
        {
            for (size_t i = 0; i < sz; i++)
                result += (pMem[i] * v.pMem[i]);
            return result;
        }
        else
            throw exception("error");
    }

    friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
    {
        std::swap(lhs.sz, rhs.sz);
        std::swap(lhs.pMem, rhs.pMem);
    }

    // ввод/вывод
    friend istream& operator>>(istream& istr, TDynamicVector& v)
    {
        for (size_t i = 0; i < v.sz; i++)
        { 
            istr >> v.pMem[i]; // требуется оператор>> для типа T
        }
        return istr;
    }
    friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
    {
        for (size_t i = 0; i < v.sz; i++)
        {
            ostr << v.pMem[i] << std::setw(8); // требуется оператор<< для типа T
            ostr << "\n";
        }
        return ostr;
    }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
    using TDynamicVector<TDynamicVector<T>>::pMem;
    using TDynamicVector<TDynamicVector<T>>::sz;
public:
    TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
    {
        if (s > MAX_MATRIX_SIZE)
            throw exception("error");
        for (size_t i = 0; i < s; i++)
            this->pMem[i] = TDynamicVector<T>(s);
    }

    size_t size() const noexcept
    {
        return sz*sz;
    }

    using TDynamicVector<TDynamicVector<T>>::operator[];

    T& at(size_t ind1, size_t ind2)
    {
        if (ind1 < sz && ind1 >= 0 && ind2 < sz && ind2 >= 0)
        {
            return pMem[ind1][ind2];
        }
        else
            throw exception("error");
    }

    // сравнение
    bool operator==(const TDynamicMatrix& m) const noexcept
    {
        return TDynamicVector<TDynamicVector<T>>::operator==(m);
    }

    bool operator!=(const TDynamicMatrix& m) const noexcept
    {
        return TDynamicVector<TDynamicVector<T>>::operator!=(m);
    }

    // матрично-скалярные операции
    TDynamicMatrix operator*(const T& val)
    {
        TDynamicMatrix<T> result(sz);
        for (size_t i = 0; i < sz; i++)
            result.pMem[i] = pMem[i] * val;
        return result;
    }

    // матрично-векторные операции
    TDynamicVector<T> operator*(const TDynamicVector<T>& v)
    {
        TDynamicVector<T> result(sz);
        for (size_t i = 0; i < sz; i++)
            result[i] = pMem[i] * v;
        return result;
    }

    // матрично-матричные операции
    TDynamicMatrix operator+(const TDynamicMatrix& m)
    {
        if (m.size() == size())
        {
            TDynamicMatrix<T> result(sz);
            for (size_t i = 0; i < sz; i++)
                result[i] = pMem[i] + m[i];
            return result;
        }
        else
            throw exception("error");
    }
    TDynamicMatrix operator-(const TDynamicMatrix& m)
    {
        if (m.size() == size())
        {
            TDynamicMatrix<T> result(sz);
            for (size_t i = 0; i < sz; i++)
                result[i] = pMem[i] - m[i];
            return result;
        }
        else
            throw exception("error");
    }
    TDynamicMatrix operator*(const TDynamicMatrix& m)
    {
        if (m.size() == size())
        {
            TDynamicMatrix<T> result(sz);
            for (size_t i = 0; i < sz; i++)
                for (size_t j = 0; j < sz; j++)
                    for (size_t k = 0; k < sz; k++)
                        result[i][j] += pMem[i][k] * m[k][j];
            return result;
        }
        else
            throw exception("error");
    }

    // ввод/вывод
    friend istream& operator>>(istream& istr, TDynamicMatrix& v)
    {
        for (size_t i = 0; i < v.sz; i++)
        {
            for (size_t j = 0; j < v.sz; j++)
                istr >> v.pMem[i][j];
        }
        return istr;
    }
    friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
    {
        for (size_t i = 0; i < v.sz; i++)
        {
            for (size_t j = 0; j < v.sz; j++)
                ostr << right << setw(10) << v.pMem[i][j];
            ostr << "\n";
        }
        return ostr;
    }
};
#endif
