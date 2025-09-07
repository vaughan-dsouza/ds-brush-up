#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <cmath>
using namespace std;
using namespace chrono;

// ------------------- 1. Recursive -------------------
long long fibRecursive(int n)
{
    if (n <= 1)
        return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// ------------------- 2. DP Memoization -------------------
unordered_map<int, long long> memo;
long long fibMemo(int n)
{
    if (n <= 1)
        return n;
    if (memo.count(n))
        return memo[n];
    return memo[n] = fibMemo(n - 1) + fibMemo(n - 2);
}

// ------------------- 3. DP Tabulation -------------------
long long fibTab(int n)
{
    if (n <= 1)
        return n;
    vector<long long> dp(n + 1);
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// ------------------- 4. Iterative (Constant Space) -------------------
long long fibIter(int n)
{
    if (n <= 1)
        return n;
    long long prev2 = 0, prev1 = 1, cur;
    for (int i = 2; i <= n; i++)
    {
        cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

// ------------------- 5. Matrix Exponentiation -------------------
struct Matrix
{
    long long m[2][2];
};

Matrix multiply(Matrix a, Matrix b)
{
    Matrix res = {{{0, 0}, {0, 0}}};
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                res.m[i][j] += a.m[i][k] * b.m[k][j];
    return res;
}

Matrix power(Matrix base, int n)
{
    if (n == 1)
        return base;
    if (n % 2 == 0)
    {
        Matrix half = power(base, n / 2);
        return multiply(half, half);
    }
    else
    {
        return multiply(base, power(base, n - 1));
    }
}

long long fibMatrix(int n)
{
    if (n == 0)
        return 0;
    Matrix F = {{{1, 1}, {1, 0}}};
    Matrix res = power(F, n - 1);
    return res.m[0][0];
}

// ------------------- 6. Binet’s Formula -------------------
long long fibBinet(int n)
{
    double phi = (1 + sqrt(5)) / 2;
    return round(pow(phi, n) / sqrt(5));
}

// ------------------- Main -------------------
int main()
{
    int n = 40; // change for testing
    cout << "Fibonacci comparison for n = " << n << endl;

    auto test = [&](auto func, string name)
    {
        auto start = high_resolution_clock::now();
        long long ans = func(n);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start).count();
        cout << name << ": " << ans << " (Time: " << duration << " microseconds)" << endl;
    };

    test(fibRecursive, "Recursive");
    test(fibMemo, "DP Memoization");
    test(fibTab, "DP Tabulation");
    test(fibIter, "Iterative (O(1) space)");
    test(fibMatrix, "Matrix Exponentiation");
    test(fibBinet, "Binet Formula");

    return 0;
}
