#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Merge two sorted halves
vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < left.size() || j < right.size()) {
        if (i < left.size() && j < right.size()) {
            if (left[i] > right[j]) {
                result.push_back(right[j++]);
            } else {
                result.push_back(left[i++]);
            }
        } else if (i < left.size()) {
            result.push_back(left[i++]);
        } else {
            result.push_back(right[j++]);
        }
    }

    return result;
}

// Merge sort
vector<int> mergeSort(const vector<int>& arr) {
    if (arr.size() <= 1) return arr;

    int mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
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

    cout << "Original Array:\n";
    for (int n : arr) cout << n << " ";
    cout << "\n";

    // Start time
    auto start = chrono::high_resolution_clock::now();

    vector<int> sorted = mergeSort(arr);

    // End time
    auto end = chrono::high_resolution_clock::now();

    cout << "Sorted Array:\n";
    for (int n : sorted) cout << n << " ";
    cout << "\n";

    // Execution time in milliseconds
    chrono::duration<double, nano> duration = end - start;
    cout << "Execution Time: " << duration.count() << " ns\n";


    return 0;
}
