import java.lang.*;
import java.util.*;

class Solution {
  public int myAtoi(String str) {
  	int p, found;
  	p = found = 0;
  	long ans = 0;
  	int sign = 1;
  	while(p < str.length()) {
  		if(found == 0) {
  			if(str.charAt(p) == ' ') {
					p += 1;
					continue;
				} else if(str.charAt(p) == '-') {
					sign = -1;
					found = 1;
					p += 1;
					continue;
				} else if(str.charAt(p) == '+') {
					found = 1;
					p += 1;
					continue;
				}
			}
			long k = (int)str.charAt(p) - 0x30;
			if(k >= 0 && k < 10) {
				found = 1;
				if(ans > 0) {
					ans *= 10;
				}
				ans += k;
				if(ans > 0x7FFFFFFF){
					if(sign == 1) {
						return 0x7FFFFFFF;
					} else {
						return -1<<31;
					}
				}
			} else {
				return (int)ans*sign;
			}
			p += 1;
		}
  	return (int)ans*sign;
  }
}

public class index {

	public static void main(String[] args) {
		String[] sample = {"42", "   -42", "4193 with words", "words and 987", "-91283472332", "3.14159", "  2147483648", "", "+1", "  ", "0    98", "+-1a"};

    Solution demo = new Solution();
    for(String m : sample) {
    	System.out.printf("%s => %d\n", m, demo.myAtoi(m));
    }
	}
}