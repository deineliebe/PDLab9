#include <iostream>

float** makeBMatrix(const int N, float A[][4])
{
    float **B = new float* [N];
    for (int i = 0; i < N; i++)
    {
        B[i] = new float[N];
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

float* makeC(const int N, float A[][4], float* b)
{
    float* c = new float [N];
    for (int i = 0; i < N; i++)
    {
        c[i] = -1 * b[i] / A[i][i];
    }
    return c;
}

void task1(const int N, float A[][4], float *b)
{
    float **B = makeBMatrix(N, A);
    float *c = makeC(N, A, b);

}

int main()
{
    std::cout << "This is the nineth lab of project design.\n\n";
    std::cout << "First task is to execute the system by a method of simple iterations.\n";
    const int N = 4;
    float A[N][N] = { { 1.70, 0.03, 0.04, 0.05 },
        {0.00, 0.80, 0.01, 0.02},
        {-0.03, -0.02, -0.10, 0.00},
        {-0.05, -0.04, -0.03, -1.00} };
    std::cout << "A matrix:\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << A[i][j] << ' ';
        }
        std::cout << '\n';
    }
    float b[N] = { 0.6810 , 0.4803, -0.0802, -1.0007 };
    std::cout << "b vector: ";
    for (int i = 0; i < N; i++)
    {
        std::cout << b[i] << ' ';
    }
    std::cout << '\n';
    task1(N, A, b);
}