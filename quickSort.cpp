#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int partition(vector<int>& arr, int start, int end) {
    int pivot = arr[start];
    int i = start + 1;
    int j = end;

    while (i <= j) {
        while (i <= end && arr[i] < pivot) i++;
        while (j >= start + 1 && arr[j] > pivot) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    swap(arr[start], arr[j]);
    return j;
}

void quicksort(vector<int>& arr, int start, int end) {
    if (start >= end) return;

    int p = partition(arr, start, end);
    quicksort(arr, start, p - 1);
    quicksort(arr, p + 1, end);
}

int main() {
    vector<int> original = {
        73,12,88,45,6,91,34,17,59,2,
        84,26,67,9,53,41,98,21,75,14,
        62,8,90,33,57,19,86,4,48,71,
        25,64,11,97,38,5,82,29,69,16,
        55,93,7,44,80,23,61,10,76,35,
        89,1,52,68,18,95,27,60,13,83,
        40,99,20,72,31,56,94,15,65,46,
        3,87,24,58,70,36,92,22,79,50
    };

    const int ITER = 100000;
    volatile int sink = 0;

    // warm-up
    {
        auto arr = original;
        quicksort(arr, 0, arr.size() - 1);
        sink ^= arr[0];
    }

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < ITER; i++) {
        auto arr = original;  // copy each time
        quicksort(arr, 0, arr.size() - 1);
        sink ^= arr[i % arr.size()];
    }

    auto end = chrono::high_resolution_clock::now();

    auto totalNs = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    auto avgNs = totalNs / ITER;

    cout << "Total Time: " << totalNs << " ns\n";
    cout << "Avg Time : " << avgNs << " ns/run\n";
    cout << "sink: " << sink << "\n";
}
