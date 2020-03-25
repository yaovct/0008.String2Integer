<?php

class Solution {

  /**
   * @param String $str
   * @return Integer
   */
  function myAtoi($str) {
  	$p = $ans = $found = 0;
  	$sign = 1;
		while ($p < strlen($str)) {
			if(!$found) {
				if($str[$p] == " ") {
					$p += 1;
					continue;
				} else if($str[$p] == "-") {
					$sign = -1;
					$found = 1;
					$p += 1;
					continue;
				} else if($str[$p] == "+") {
					$found = 1;
					$p += 1;
					continue;
				}
			}
			$k = ord($str[$p]) - 0x30;
			if($k >= 0 && $k < 10) {
				$found = 1;
				if($ans > 0) {
					$ans *= 10;
				}
				$ans += $k;
				if($ans > 0x7FFFFFFF){
					if($sign == 1) {
						return 0x7FFFFFFF;
					} else {
						return -1<<31;
					}
				}
			} else {
				return $ans*$sign;
			}
			$p += 1;
		}  	
		return $ans*$sign;
  }
}

$sample = array("42", "   -42", "4193 with words", "words and 987", "-91283472332", "3.14159", "  2147483648", "", "+1", "  ", "0    98", "+-1a");
$testSolution = new Solution();
foreach ($sample as &$m) {
	printf("%s => %d\n",$m, $testSolution->myAtoi($m));
}
?>