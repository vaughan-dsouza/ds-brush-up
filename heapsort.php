<?php

function heapify(&$arr, $n, $i) {
    $largest = $i;
    $left = 2 * $i + 1;
    $right = 2 * $i + 2;

    if ($left < $n && $arr[$left] > $arr[$largest]) {
        $largest = $left;
    }

    if ($right < $n && $arr[$right] > $arr[$largest]) {
        $largest = $right;
    }

    if ($largest !== $i) {
        $tmp = $arr[$i];
        $arr[$i] = $arr[$largest];
        $arr[$largest] = $tmp;

        heapify($arr, $n, $largest);
    }
}

function heapSort(&$arr) {
    $n = count($arr);

    // Build max heap
    for ($i = intdiv($n, 2) - 1; $i >= 0; $i--) {
        heapify($arr, $n, $i);
    }

    // Extract elements
    for ($i = $n - 1; $i > 0; $i--) {
        $tmp = $arr[0];
        $arr[0] = $arr[$i];
        $arr[$i] = $tmp;

        heapify($arr, $i, 0);
    }
}

// Demo
// $arr = [4, 10, 3, 5, 1];
// heapSort($arr);
// print_r($arr); // [1, 3, 4, 5, 10]
$arr = [
    73,12,88,45,6,91,34,17,59,2,
    84,26,67,9,53,41,98,21,75,14,
    62,8,90,33,57,19,86,4,48,71,
    25,64,11,97,38,5,82,29,69,16,
    55,93,7,44,80,23,61,10,76,35,
    89,1,52,68,18,95,27,60,13,83,
    40,99,20,72,31,56,94,15,65,46,
    3,87,24,58,70,36,92,22,79,50
];

$ITER = 100000;
$sink = 0;
$n = count($arr);

$warm = $arr;
heapSort($warm);
$sink ^= $warm[0];

$startNs = hrtime(true);
for ($i = 0; $i < $ITER; $i++) {
    $work = $arr;      
    heapSort($work);   
    $sink ^= $work[$i % $n];
}
$endNs = hrtime(true);
$totalNs = $endNs - $startNs;
$avgNs = intdiv($totalNs, $ITER);

echo "Total Time: {$totalNs} ns\n";
echo "Avg Time : {$avgNs} ns/run\n";
echo "sink: {$sink}\n";