<?php


//冒泡排序时间复杂度n^2

function bubbleSort(array $arr)
{
    $length = count($arr);
    for ($i=0;$i < $length-1;$i++) {
        for ($j=0;$j<$length-$i-1;$i++) {
            if ($arr[$j] < $arr[$j+1]) {
                $temp = $arr[$j];
                $arr[$j] = $arr[$j+1];
                $arr[$j+1] = $temp;
            }
        }
    }

    return $arr;
}