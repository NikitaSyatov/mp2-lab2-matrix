// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------

void main()
{
    int n, choose;

    setlocale(LC_ALL, "Russian");
    cout << "Тестирование класс работы с матрицами\nВведите размер квадратной матрицы:";
    cin >> n;
    TDynamicMatrix<int> a(n);
    cout << "Введите первую матрицу:\n";
    cin >> a;
    cout << "Выберите операцию:\n1 - Умножение матриц\n2 - вычитание матриц\n3 - сложение матриц\n4 - умножение матрицы на вектор\n5 - умножение матриц на число" << endl;
    cin >> choose;

    switch (choose)
    {
        case(1):
        {
            TDynamicMatrix<int> b(n), result(n);
            cout << "Введите вторую матрицу:\n";
            cin >> b;
            result = a * b;
            cout << "Ответ:\n";
            cout << result;
            break;
        }
        case(2):
        {
            TDynamicMatrix<int> b(n), result(n);
            cout << "Введите вторую матрицу:\n";
            cin >> b;
            result = a - b;
            cout << "Ответ:\n";
            cout << result;
            break;
        }
        case(3):
        {
            TDynamicMatrix<int> b(n), result(n);
            cout << "Введите вторую матрицу:\n";
            cin >> b;
            result = a + b;
            cout << "Ответ:\n";
            cout << result;
            break;
        }
        case(4):
        {
            TDynamicVector<int> b(n);
            TDynamicVector<int> result(n);
            cout << "Введите вектор:\n";
            cin >> b;
            result = a * b;
            cout << "Ответ:\n";
            cout << result;
            break;
        }
        case(5):
        {
            TDynamicMatrix<int> result(n);
            int val;
            cout << "Введите число:\n";
            cin >> val;
            result = a * val;
            cout << "Ответ:\n";
            cout << result;
            break;
        }
        default:
        {
            cout << "ERROR";
            break;
        }
    }
}
//---------------------------------------------------------------------------
