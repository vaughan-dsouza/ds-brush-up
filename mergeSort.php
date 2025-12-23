<?php 
echo "Merge Sort Algorithm in PHP\n\n";

function compare($a, $b){
    return $a > $b ?? 0;
}

function mergeSort($arr){
    $length = count($arr);
    if($length <= 1) 
        return $arr;

    $pivot = floor($length / 2);
    $left = mergeSort(array_slice($arr, 0, $pivot));
    $right = mergeSort(array_slice($arr, $pivot));

    $i = $j = 0;
    $combined = [];

    while($i < count($left) || $j < count($right)){
        if($i < count($left) && $j < count($right)){
            if(compare($left[$i] , $right[$j]))
                $combined[] = $right[$j++];
            else 
                $combined[] = $left[$i++];
        } else if($i < count($left)){
            $combined[] = $left[$i++];
        } else if($j < count($right)){
            $combined[] = $right[$j++];
        }
    }

    return $combined;

}

function main(){
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
    print_r($arr);

    $startTime = microtime(true);
    $newArr = mergeSort($arr);
    $endTime = microtime(true);

    echo "\nSorted Array:\n";
    print_r($newArr);

    $executionTimeNs = ($endTime - $startTime) * 1_000_000_000;
    echo "Execution Time: {$executionTimeNs} ns\n";
}
main();