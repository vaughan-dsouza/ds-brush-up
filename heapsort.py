import time

def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[left] > arr[largest]:
        largest = left

    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)


def heap_sort(arr):
    n = len(arr)

    # Build max heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Extract elements
    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i, 0)

    return arr


# Demo
# arr = [4, 10, 3, 5, 1]
# print(heap_sort(arr))  # [1, 3, 4, 5, 10]
original = [
    73,12,88,45,6,91,34,17,59,2,
    84,26,67,9,53,41,98,21,75,14,
    62,8,90,33,57,19,86,4,48,71,
    25,64,11,97,38,5,82,29,69,16,
    55,93,7,44,80,23,61,10,76,35,
    89,1,52,68,18,95,27,60,13,83,
    40,99,20,72,31,56,94,15,65,46,
    3,87,24,58,70,36,92,22,79,50
]

ITER = 100000
sink = 0

tmp = original.copy()
heap_sort(tmp)
sink ^= tmp[0]

start_ns = time.perf_counter_ns()
for i in range(ITER):
    arr = original.copy()     
    heap_sort(arr)            
    sink ^= arr[i % len(arr)]

end_ns = time.perf_counter_ns()
total_ns = end_ns - start_ns
avg_ns = total_ns // ITER

print(f"Total Time: {total_ns} ns")
print(f"Avg Time : {avg_ns} ns/run")
print("sink:", sink)
