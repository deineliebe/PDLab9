#include <iostream>

long double inDegree(float number, int degree)
{
    double temp = 1;
    if (degree > 0)
    {
        for (int i = 0; i < degree; i++)
        {
            temp *= number;
        }
    }
    else
    {
        for (int i = 0; i > degree; i--)
        {
            temp /= number;
        }
    }
    return temp;
}

double** makeBMatrix(const int N, double A[][4])
{
    double**B = new double* [N];
    for (int i = 0; i < N; i++)
    {
        B[i] = new double[N];
        for (int j = 0; j < i; j++)
        {
            B[i][j] = -1 * (A[i][j]) / (A[i][i]);
        }
        B[i][i] = 0;
        for (int j = i + 1; j < N; j++)
        {
            B[i][j] = -1 * (A[i][j]) / (A[i][i]);
        }
    }
    return B;
}

double* makeC(const int N, double A[][4], double* b)
{
    double* c = new double[N];
    for (int i = 0; i < N; i++)
    {
        c[i] = -1 * b[i] / A[i][i];
    }
    return c;
}

double* executeX(const int N, double** B, double* c)
{
    double* x = new double[N];
    double* temp = new double[N];
    for (int i = 0; i < N; i++)
    {
        x[i] = c[i];
        temp[i] = double('inf');
    }
    bool error = 1;
    while (error)
    {
        error = 0;
        for (int i = 0; i < N; i++)
        {
            temp[i] = 0;
            for (int j = 0; j < N; j++)
            {
                temp[i] += x[j] * B[i][j];
            }
            temp[i] += c[i];
            if (abs(temp[i] - x[i]) > inDegree(10, -7)) error = 1;
            x[i] = temp[i];
        }
    }
    return x;
}

void task1(const int N, double A[][4], double*b)
{
    double**B = makeBMatrix(N, A);
    double*c = makeC(N, A, b);
    double* x = executeX(N, B, c);
    for (int i = 0; i < N; i++)
    {
        std::cout << "x(" << i << ") = " << x[i] << '\n';
    }
    std::cout << '\n';
}

int main()
{
    std::cout << "This is the nineth lab of project design.\n\n";
    std::cout << "First task is to execute the system by a method of simple iterations.\n";
    const int N = 4;
    
    /*std::cout << "Example:\n";
    double A[N][N] = { { 0.4000, 0.0003, 0.0008, 0.0014 },
        {-0.0029, -0.5000, -0.0018, -0.0012},
        {-0.0055, -0.0050, -1.4000, -0.0039},
        {-0.0082, -0.0076, -0.0070, -2.3000} };
    double b[N] = { 0.1220 , -0.2532, -0.9876, -2.0812 };*/
    
    double A[N][N] = { { 1.70, 0.03, 0.04, 0.05 },
        {0.00, 0.80, 0.01, 0.02},
        {-0.03, -0.02, -0.10, 0.00},
        {-0.05, -0.04, -0.03, -1.00} };
    double b[N] = { 0.6810 , 0.4803, -0.0802, -1.0007 };
    
    std::cout << "A matrix:\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << A[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "b vector: ";
    for (int i = 0; i < N; i++)
    {
        std::cout << b[i] << ' ';
    }
    std::cout << '\n';
    task1(N, A, b);
}