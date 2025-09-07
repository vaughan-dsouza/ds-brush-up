def find_max(arr: list[int]) -> int:
    maximum = arr[0]
    for n in arr:
        if n > maximum:
            maximum = n
    return maximum

def swap_values(a: int, b: int) -> tuple[int, int]:
    return b, a

def main():
    arr = [5, 2, 8, 1, 9]
    print("List:", arr)

    # Find maximum value
    maximum = find_max(arr)
    max_val = max(arr)
    print("Maximum value:", max_val)

    # Test swap
    x, y = 5, 10
    x, y = swap_values(x, y)
    x, y = y, x

    print("After swap: x =", x, "y =", y)

if __name__ == "__main__":
    main()
