#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Merge two sorted halves
vector<int> mergeVec(const vector<int>& left, const vector<int>& right) {
    vector<int> result;
    result.reserve(left.size() + right.size());
    size_t i = 0, j = 0;

    while (i < left.size() || j < right.size()) {
        if (i < left.size() && j < right.size()) {
            if (left[i] > right[j]) result.push_back(right[j++]);
            else result.push_back(left[i++]);
        } else if (i < left.size()) {
            result.push_back(left[i++]);
        } else {
            result.push_back(right[j++]);
        }
    }
    return result;
}

// Merge sort
vector<int> mergeSort(const vector<int>& arr, size_t start, size_t end) {
    if (end - start <= 1) return vector<int>(arr.begin() + start, arr.begin() + end);

    size_t mid = (end - start) / 2;
    vector<int> left(arr.begin() + start, arr.begin() + start + mid);
    vector<int> right(arr.begin() + start + mid, arr.begin() + end);

    left = mergeSort(left, 0, left.size());
    right = mergeSort(right, 0, right.size());

    return mergeVec(left, right);
}

int main() {
    vector<int> arr = {73,12,88,45,6,91,34,17,59,2,
        84,26,67,9,53,41,98,21,75,14,
        62,8,90,33,57,19,86,4,48,71,
        25,64,11,97,38,5,82,29,69,16,
        55,93,7,44,80,23,61,10,76,35,
        89,1,52,68,18,95,27,60,13,83,
        40,99,20,72,31,56,94,15,65,46,
        3,87,24,58,70,36,92,22,79,50};

    const int ITER = 100000;
    volatile int sink = 0;

    // warm-up
    auto tmp = mergeSort(arr, 0, arr.size());
    sink ^= tmp[0];

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < ITER; i++) {
        auto sorted = mergeSort(arr, 0, arr.size());
        sink ^= sorted[i % (int)sorted.size()];
    }

    auto end = chrono::high_resolution_clock::now();

    auto totalNs = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    auto avgNs = totalNs / ITER;

    cout << "Total Time: " << totalNs << " ns\n";
    cout << "Avg Time : " << avgNs << " ns/run\n";
    cout << "sink: " << sink << "\n";

    return 0;
}
