import time

def merge_sort(arr, start, end):
    length = end - start
    if length <= 1:
        return arr[start:end]

    mid = length // 2
    left = merge_sort(arr, start, start + mid)
    right = merge_sort(arr, start + mid, end)
    i = j = 0
    result = []

    while i < len(left) or j < len(right):
        if i < len(left) and j < len(right):
            if left[i] > right[j]:
                result.append(right[j])
                j += 1
            else:
                result.append(left[i])
                i += 1
        elif i < len(left):
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    return result


arr = [
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

# warm-up
tmp = merge_sort(arr, 0, len(arr))
sink ^= tmp[0]

# benchmark (ns)
start_ns = time.perf_counter_ns()

for i in range(ITER):
    sorted_arr = merge_sort(arr, 0, len(arr))
    sink ^= sorted_arr[i % len(sorted_arr)]

end_ns = time.perf_counter_ns()

total_ns = end_ns - start_ns
avg_ns = total_ns // ITER

print(f"Total Time: {total_ns} ns")
print(f"Avg Time : {avg_ns} ns/run")
print("sink:", sink)
