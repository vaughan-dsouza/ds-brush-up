#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

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
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
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

// Function to measure sorting time
template <typename Func>
void measureTime(Func sortFunction, vector<int> arr, const string &sortName)
{
    auto start = high_resolution_clock::now();
    sortFunction(arr);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << sortName << " Result: ";
    printArray(arr);
    cout << sortName << " Time: " << duration.count() << " microseconds" << endl;
}

int main()
{
    // vector<int> arr = {64, 25, 12, 22, 11};
    // srand(time(0));
    srand(10);

    int size = 10000;
    vector<int> arr(size);

    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100000;

    cout << "Array of " << size << " elements generated.\n";

    int choice;

    do
    {
        cout << "\n--- Sorting Menu ---\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Insertion Sort\n";
        cout << "3. Selection Sort\n";
        cout << "4. Run All & Compare\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            measureTime(bubbleSort, arr, "Bubble Sort");
            break;
        case 2:
            measureTime(insertionSort, arr, "Insertion Sort");
            break;
        case 3:
            measureTime(selectionSort, arr, "Selection Sort");
            break;
        case 4:
            measureTime(bubbleSort, arr, "Bubble Sort");
            measureTime(insertionSort, arr, "Insertion Sort");
            measureTime(selectionSort, arr, "Selection Sort");
            break;
        case 5:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
