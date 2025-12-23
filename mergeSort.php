<?php 
// echo "Merge Sort Algorithm in PHP\n\n";

// function compare($a, $b){
//     return $a > $b; // simple boolean compare
// }

// function mergeSort($arr, $start, $end){
//     $length = $end - $start;
//     if($length <= 1) 
//         return array_slice($arr, $start, $length);

//     $pivot = intdiv($length, 2);
//     $left = mergeSort($arr, $start, $start + $pivot);
//     $right = mergeSort($arr, $start + $pivot, $end);

//     $i = $j = 0;
//     $combined = [];

//     while($i < count($left) || $j < count($right)){
//         if($i < count($left) && $j < count($right)){
//             if(compare($left[$i], $right[$j]))
//                 $combined[] = $right[$j++];
//             else 
//                 $combined[] = $left[$i++];
//         } else if($i < count($left)){
//             $combined[] = $left[$i++];
//         } else {
//             $combined[] = $right[$j++];
//         }
//     }

//     return $combined;
// }

// function main(){
//     $arr = [
//         73,12,88,45,6,91,34,17,59,2,
//         84,26,67,9,53,41,98,21,75,14,
//         62,8,90,33,57,19,86,4,48,71,
//         25,64,11,97,38,5,82,29,69,16,
//         55,93,7,44,80,23,61,10,76,35,
//         89,1,52,68,18,95,27,60,13,83,
//         40,99,20,72,31,56,94,15,65,46,
//         3,87,24,58,70,36,92,22,79,50
//     ];

//     $ITER = 100000;
//     $sink = 0;

//     // warm-up
//     $tmp = mergeSort($arr, 0, count($arr));
//     $sink ^= $tmp[0];

//     // benchmark (ns)
//     $startNs = hrtime(true);

//     for($i = 0; $i < $ITER; $i++){
//         $sorted = mergeSort($arr, 0, count($arr));
//         $sink ^= $sorted[$i % count($sorted)];
//     }

//     $endNs = hrtime(true);

//     $totalNs = $endNs - $startNs;
//     $avgNs = intdiv($totalNs, $ITER);

//     echo "Total Time: {$totalNs} ns\n";
//     echo "Avg Time : {$avgNs} ns/run\n";
//     echo "sink: {$sink}\n";
// }

// main();

echo "In-place Merge Sort Algorithm in PHP\n\n";

function mergeSortInPlace(array &$arr): void {
    $n = count($arr);
    if ($n <= 1) return;

    // One reusable temp buffer for all merges
    $tmp = array_fill(0, $n, 0);

    sortRange($arr, $tmp, 0, $n - 1);
}

function sortRange(array &$arr, array &$tmp, int $lo, int $hi): void {
    if ($lo >= $hi) return;

    $mid = intdiv($lo + $hi, 2);
    sortRange($arr, $tmp, $lo, $mid);
    sortRange($arr, $tmp, $mid + 1, $hi);
    mergeRange($arr, $tmp, $lo, $mid, $hi);
}

function mergeRange(array &$arr, array &$tmp, int $lo, int $mid, int $hi): void {
    $i = $lo;
    $j = $mid + 1;
    $k = $lo;

    // Merge into tmp
    while ($i <= $mid && $j <= $hi) {
        if ($arr[$i] <= $arr[$j]) {
            $tmp[$k++] = $arr[$i++];
        } else {
            $tmp[$k++] = $arr[$j++];
        }
    }
    while ($i <= $mid) $tmp[$k++] = $arr[$i++];
    while ($j <= $hi)  $tmp[$k++] = $arr[$j++];

    // Copy back into arr
    for ($x = $lo; $x <= $hi; $x++) {
        $arr[$x] = $tmp[$x];
    }
}

// ---- benchmark ----
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

// warm-up (and correctness check option)
$warm = $arr;
mergeSortInPlace($warm);
$sink ^= $warm[0];

// benchmark
$startNs = hrtime(true);

for ($i = 0; $i < $ITER; $i++) {
    $work = $arr;              // keep input identical each run
    mergeSortInPlace($work);   // in-place sort
    $sink ^= $work[$i % $n];
}

$endNs = hrtime(true);

$totalNs = $endNs - $startNs;
$avgNs = intdiv($totalNs, $ITER);

echo "Total Time: {$totalNs} ns\n";
echo "Avg Time : {$avgNs} ns/run\n";
echo "sink: {$sink}\n";
