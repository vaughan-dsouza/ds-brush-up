#include <iostream>
#include <vector>
using namespace std;

// Utility function to print an array
void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

// Bubble Sort
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break; // optimization: stop if already sorted
    }
}

// Insertion Sort
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // shift larger elements to the right
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    vector<int> arr = {64, 25, 12, 22, 11};

    // Bubble Sort
    vector<int> bubbleArr = arr; // make a copy
    bubbleSort(bubbleArr);
    cout << "Bubble Sort: ";
    printArray(bubbleArr);

    // Insertion Sort
    vector<int> insertionArr = arr; // make a copy
    insertionSort(insertionArr);
    cout << "Insertion Sort: ";
    printArray(insertionArr);

    // Selection Sort
    vector<int> selectionArr = arr; // make a copy
    selectionSort(selectionArr);
    cout << "Selection Sort: ";
    printArray(selectionArr);

    return 0;
}
