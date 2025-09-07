#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int value, weight;
};

// ---------------- GREEDY (Fractional Knapsack) ----------------
bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; // sort by ratio descending
}

double fractionalKnapsack(int W, vector<Item> items)
{
    sort(items.begin(), items.end(), cmp);

    int curWeight = 0;
    double finalValue = 0.0;

    for (auto &item : items)
    {
        if (curWeight + item.weight <= W)
        {
            curWeight += item.weight;
            finalValue += item.value;
        }
        else
        {
            int remain = W - curWeight;
            finalValue += item.value * ((double)remain / item.weight);
            break;
        }
    }
    return finalValue;
}

// ---------------- DYNAMIC PROGRAMMING (0/1 Knapsack) ----------------
int knapSackDP(int W, vector<Item> items, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (items[i - 1].weight <= w)
            {
                dp[i][w] = max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight],
                               dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

// ---------------- MAIN ----------------
int main()
{
    int W = 50;                                            // Knapsack capacity
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}}; // {value, weight}

    cout << "Capacity = " << W << endl;
    cout << "Items: (value, weight)" << endl;
    for (auto &i : items)
        cout << "(" << i.value << "," << i.weight << ") ";
    cout << "\n\n";

    // Greedy (Fractional Knapsack)
    double maxValFractional = fractionalKnapsack(W, items);
    cout << "Greedy (Fractional Knapsack): " << maxValFractional << endl;

    // Dynamic Programming (0/1 Knapsack)
    int maxValDP = knapSackDP(W, items, items.size());
    cout << "DP (0/1 Knapsack): " << maxValDP << endl;

    return 0;
}
