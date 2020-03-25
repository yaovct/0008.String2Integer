/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
	var p, ans, found;
	p = ans = found = 0;
	var sign = 1;
	while (p < str.length) {
		if(!found) {
			if(str[p] == " ") {
				p += 1;
				continue;
			} else if(str[p] == "-") {
				sign = -1;
				found = 1;
				p += 1;
				continue;
			} else if(str[p] == "+") {
				found = 1;
				p += 1;
				continue;
			}
		}
		var k = str[p].charCodeAt() - 0x30;
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
			return ans*sign;
		}
		p += 1;
	}
	return ans*sign;
};

var sample = ["42", "   -42", "4193 with words", "words and 987", "-91283472332", "3.14159", "  2147483648", "", "+1", "  ", "0    98", "+-1a"];
sample.forEach(function (m) {
	console.log(m, myAtoi(m));
});
