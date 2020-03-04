<?php

//选择排序
//时间复杂度为n^2

function selectSort(array $arr)
{
    $length = count($arr);
    for ($i=1;$i<$length;$i++) {
        $temp = $arr[$i];
        for ($j=$i-1;$j>=0;$j--) {
            if ($temp<$arr[$j]) {
                $arr[$j+1] = $arr[$j];
            }
        }

        $arr[$j+1] = $temp;
    }

    return $arr;
}