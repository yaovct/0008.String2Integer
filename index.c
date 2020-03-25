#include<stdio.h>
#include<stdlib.h>

int myAtoi(char * str){
	int len = 0;
	char *m = str;
	while(*m++) len++;
	
	int p, found;
	p = found = 0;
	long long ans = 0;
	int sign = 1;
	while(p < len) {
		if(found == 0) {
			if(str[p] == ' ') {
				p += 1;
				continue;
			} else if(str[p] == '-') {
				sign = -1;
				found = 1;
				p += 1;
				continue;
			} else if(str[p] == '+') {
				found = 1;
				p += 1;
				continue;
			}
		}
		int k = (int)str[p] - 0x30;
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
					//return -1<<31;
					return INT_MIN;
				}
			}
		} else {
			return (int)ans*sign;
		}
		p += 1;
	}
	return (int)ans*sign;
}

int main(int argc, char *argv[]) {

  char* sample[] = {"42", "   -42", "4193 with words", "words and 987", "-91283472332", "3.14159", "  2147483648", "", "+1", "  ", "0    98", "+-1a"};
  for(int i=0; i<sizeof(sample)/sizeof(sample[0]); i++) {
		printf("%s => %d\n", sample[i], myAtoi(sample[i]));
	}
}