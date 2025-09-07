#include <iostream>
#include <vector>
using namespace std;

void swap2D(vector<int, int> &a, vector<int, int> &b)
{
    vector<int, int> temp = a;
    a = b;
    b = temp;
}
void bubbleSort(vector<vector<int>> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 1; j < n - i; j++)
        {
            if (arr[i] > arr[j])
            {
                swap2D(arr[i], arr[j]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    // first fort using bulbble
    // then make a for loop that does the following
    //  initialize a count =1, if [a,b] < [c,d], count ++ or break
}

// swap two values
template <typename T>
void swapValues(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// find max element in vector
int maxValue(const vector<int> &arr)
{
    int maximum = arr[0];
    for (int val : arr)
    {
        if (val > maximum)
        {
            maximum = val;
        }
    }
    return maximum;
}

// show dynamic allocation using vector
void dynamicAllocation()
{
    vector<int> arr2 = {5, 2, 8, 1, 9};

    cout << "Vector size: " << arr2.size() << endl;
    cout << "Vector max: " << maxValue(arr2) << endl;
}

int main()
{
    vector<int> arr = {5, 2, 8, 1, 9};

    cout << "Original array: ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    // test swap
    swapValues(arr[0], arr[1]);

    cout << "After swap first two: ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    cout << "Maximum value: " << maxValue(arr) << endl;

    dynamicAllocation();

    return 0;
}
