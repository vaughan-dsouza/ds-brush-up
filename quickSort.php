<?php

function quicksort(array &$arr, int $start = 0, ?int $end = null): void {
    if ($end === null) $end = count($arr) - 1;
    if ($start >= $end) return;

    $p = partition($arr, $start, $end);
    quicksort($arr, $start, $p - 1);
    quicksort($arr, $p + 1, $end);
}

function partition(array &$arr, int $start, int $end): int {
    $pivot = $arr[$start];
    $i = $start + 1;
    $j = $end;

    while ($i <= $j) {
        while ($i <= $end && $arr[$i] < $pivot) $i++;
        while ($j >= $start + 1 && $arr[$j] > $pivot) $j--;

        if ($i <= $j) {
            $tmp = $arr[$i];
            $arr[$i] = $arr[$j];
            $arr[$j] = $tmp;
            $i++;
            $j--;
        }
    }

    // Put pivot into final position
    $tmp = $arr[$start];
    $arr[$start] = $arr[$j];
    $arr[$j] = $tmp;

    return $j;
}

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

// warm-up (use a copy so the original stays unchanged)
$warm = $arr;
quicksort($warm);
$sink ^= $warm[0];

// benchmark
$startNs = hrtime(true);

for ($i = 0; $i < $ITER; $i++) {
    $work = $arr;       // fresh copy each run
    quicksort($work);   // in-place sort
    $sink ^= $work[$i % $n];
}

$endNs = hrtime(true);

$totalNs = $endNs - $startNs;
$avgNs = intdiv($totalNs, $ITER);

echo "Total Time: {$totalNs} ns\n";
echo "Avg Time : {$avgNs} ns/run\n";
echo "sink: {$sink}\n";
