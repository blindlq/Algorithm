<?php

//归并排序
//时间复杂度nlogn


function mergeSort(array &$arr,int $left,int $right)
{

   if ($left < $right) {
        $mid = floor(($left+$right)/2);
        mergeSort($arr,$left,$mid);
        mergeSort($arr,$mid+1,$right);

        merge($arr,$left,$mid,$right);
   }

}


function merge(array $arr,int $left, int $mid, int $right)
{
    $temp = [];
    $i = $left;
    $j = $mid+1;
    while ($i <= $mid && $j<= $right) {
        if ($arr[$i] < $arr[$j]) {
            $temp[] = $arr[$i];
            $i++;
        } else {
            $temp[] = $arr[$j];
            $j++;
        }
    }

    while ($i <= $mid) {
        $temp[] = $arr[$i];
        $i++;
    }

    while ($j <= $right) {
        $temp[] = $arr[$j];
        $j++;
    }

    //最后合并
    for ($k=0;$k<count($temp);$k++) {
        $arr[$left+$k] = $temp[$k];
    }

}