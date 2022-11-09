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
    int n, choose, ch;

    srand(time(0) * 5575 + 343434);
    setlocale(LC_ALL, "Russian");
    cout << "Тестирование класс работы с матрицами\nВведите размер квадратной матрицы:";
    cin >> n;
    TDynamicMatrix<int> a(n);
    cout << "Каким образом вводить матрицу?\n1 - поэлементно\n2 - рандомно\n";
    cin >> ch;
    if (ch == 1)
    {
        cout << "Введите первую матрицу:\n";
        cin >> a;
    }
    else
    {
        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < n; j++)
                a[i][j] = rand() % 100;

        cout << "Первая матрица:\n" << a;
    }
    cout << "Выберите операцию:\n1 - Умножение матриц\n2 - вычитание матриц\n3 - сложение матриц\n4 - умножение матрицы на вектор\n5 - умножение матриц на число" << endl;
    cin >> choose;

    switch (choose)
    {
        case(1):
        {
            TDynamicMatrix<int> b(n), result(n);
            if (ch == 1)
            {
                cout << "Введите вторую матрицу:\n";
                cin >> b;
            }
            else
            {
                for (size_t i = 0; i < n; i++)
                    for (size_t j = 0; j < n; j++)
                        b[i][j] = 1 + (int)(100.0 * (rand() / (RAND_MAX + 1.0)));

                cout << "Вторая матрица:\n" << b;
            }
            result = a * b;
            cout << "Ответ:\n";
            cout << result;
            break;
        }
        case(2):
        {
            TDynamicMatrix<int> b(n), result(n);
            if (ch == 1)
            {
                cout << "Введите вторую матрицу:\n";
                cin >> b;
            }
            else
            {
                for (size_t i = 0; i < n; i++)
                    for (size_t j = 0; j < n; j++)
                        b[i][j] = 1 + (int)(100.0 * (rand() / (RAND_MAX + 1.0)));

                cout << "Вторая матрица:\n" << b;
            }
            result = a - b;
            cout << "Ответ:\n";
            cout << result;
            break;
        }
        case(3):
        {
            TDynamicMatrix<int> b(n), result(n);
            if (ch == 1)
            {
                cout << "Введите вторую матрицу:\n";
                cin >> b;
            }
            else
            {
                for (size_t i = 0; i < n; i++)
                    for (size_t j = 0; j < n; j++)
                        b[i][j] = 1 + (int)(100.0 * (rand() / (RAND_MAX + 1.0)));

                cout << "Вторая матрица:\n" << b;
            }
            result = a + b;
            cout << "Ответ:\n";
            cout << result;
            break;
        }
        case(4):
        {
            TDynamicVector<int> b(n);
            TDynamicVector<int> result(n);
            if (ch == 1)
            {
                cout << "Введите вектор:\n";
                cin >> b;
            }
            else
            {
                for (size_t i = 0; i < n; i++)
                    b[i] = 1 + (int)(100.0 * (rand() / (RAND_MAX + 1.0)));

                cout << "Второй вектор:\n" << b;
            }
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
