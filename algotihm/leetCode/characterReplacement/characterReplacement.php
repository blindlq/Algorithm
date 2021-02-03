<?php

$a = "AABABBA";

$k = 1;



function characterReplacement(string $foo, int $bar) {
    if (!$foo) return 0;
    $arr = str_split($foo);

    if (count($arr) == 1) return 1;

    $right = $left = 0;
    $max = 1;
    $temp = [];
    for ($right;$right< count($arr);$right++) {
       isset($temp[$arr[$right]]) ? $temp[$arr[$right]]++ : $temp[$arr[$right]] =1;
        $max = max($max,$temp[$arr[$right]]);
        if (($right-$left+1) > $max+$bar) {
            $left++;
            $temp[$arr[$left]]--;
        }
    }


    return [count($arr)-$left,$max,$bar,$right,$left,count($arr)];

}

print_r(characterReplacement($a,$k));