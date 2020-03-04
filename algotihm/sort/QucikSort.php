<?php


//快速排序
//最优时间复杂度是多少nlogn
//最差时间复杂度n^2
//平均时间复杂度nlogn



//非递归
function quickSort($arr)
{
    $left = 0;
    $right = count($arr) - 1;

    $limit[0] = ['left'=>$left,'right'=>$right];


    $i = 0;
    $j = 1;
    while($i < $j){
        $left = $limit[$i]['left'];	//左边界下标
        $right = $limit[$i]['right'];	//右边界下标

        $key = $left;	//取第一个值
        $flage = false;	        //标志位
        while($left <= $right) {//
            if($flage == false) {
                if($arr[$right] < $arr[$key]) {
                    $t = $arr[$key];
                    $arr[$key] = $arr[$right];
                    $arr[$right] = $t;
                    $key = $right;
                    $flage = true;
                }
                $right--;
            } else {
                if($arr[$left] > $arr[$key]) {
                    $t = $arr[$key];
                    $arr[$key] = $arr[$left];
                    $arr[$left] = $t;
                    $key = $left;
                    $flage = false;
                }
                $left++;
            }
        }

        if($limit[$i]['left'] < $key - 1) {//左边界
            $limit[$j++] = ['left'=>$limit[$i]['left'], 'right'=>$key-1];
        }

        if($limit[$i]['right'] > $key + 1) {//有边界
            $limit[$j++] = ['left'=>$key + 1, 'right'=>$limit[$i]['right']];
        }


        $i++;
    }
    return $arr;
}

//递归
function quickSortTwo(array $arr)
{
    if (count($arr) == 1) {
        return $arr;
    }

    $arr_left = [];
    $arr_right = [];

    $key = $arr[0];
    for ($i=1;$i<count($arr);$i++) {
        if ($arr[$i]>$key) {
            $arr_right[] = $arr[$i];
        } else {
            $arr_left[] =$arr[$i];
        }
    }

    $left = $this->quickSort($arr_left);
    $right = $this->quickSort($arr_right);

    return array_merge($left,[$key],$right);
}
