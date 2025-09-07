int m = 5;
    int *arr2 = new int[m]{5, 2, 8, 1, 9};

    // sizeof(arr) here will give size of the pointer (usually 8 bytes), ❌ not the array length
    cout << "sizeof(arr): " << sizeof(arr2) << endl;

    // So we MUST track 'n' ourselves
    cout << "Dynamic array length: " << m << endl;

    delete[] arr2;