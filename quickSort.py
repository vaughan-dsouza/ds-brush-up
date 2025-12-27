import time

def quicksort(arr, start=0, end=None):
    if end is None:
        end = len(arr) - 1
    if start >= end:
        return

    p = partition(arr, start, end)
    quicksort(arr, start, p - 1)
    quicksort(arr, p + 1, end)


def partition(arr, start, end):
    pivot = arr[start]
    i = start + 1
    j = end

    while i <= j:
        while i <= end and arr[i] < pivot:
            i += 1
        while j >= start + 1 and arr[j] > pivot:
            j -= 1

        if i <= j:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1

    arr[start], arr[j] = arr[j], arr[start]
    return j


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

# warm-up (use a copy so original stays unsorted)
tmp = original.copy()
quicksort(tmp)
sink ^= tmp[0]

start_ns = time.perf_counter_ns()

for i in range(ITER):
    arr = original.copy()     # fresh input each run
    quicksort(arr)            # in-place
    sink ^= arr[i % len(arr)]

end_ns = time.perf_counter_ns()

total_ns = end_ns - start_ns
avg_ns = total_ns // ITER

print(f"Total Time: {total_ns} ns")
print(f"Avg Time : {avg_ns} ns/run")
print("sink:", sink)
