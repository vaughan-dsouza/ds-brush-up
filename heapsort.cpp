#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    // vector<int> arr = {4, 10, 3, 5, 1};
    // heapSort(arr);

    // for (int x : arr) cout << x << " ";
    // 1 3 4 5 10

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
        heapSort(arr);
        sink ^= arr[0];
    }

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < ITER; i++) {
        auto arr = original;  // copy each time
        heapSort(arr);
        sink ^= arr[i % arr.size()];
    }

    auto end = chrono::high_resolution_clock::now();

    auto totalNs = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    auto avgNs = totalNs / ITER;

    cout << "Total Time: " << totalNs << " ns\n";
    cout << "Avg Time : " << avgNs << " ns/run\n";
    cout << "sink: " << sink << "\n";
}
