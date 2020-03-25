class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        p = 0
        ans = 0
        found = 0
        sign = 1
        while p < len(str):
        	if found == 0:
        		if str[p] == " ":
        			p += 1
        			continue
        		elif str[p] == "-":
        			sign = -1
        			found = 1
        			p += 1
        			continue
        		elif str[p] == "+":
        			found = 1
        			p += 1
        			continue
        	k = ord(str[p]) - 0x30
        	if k >= 0 and k < 10:
        		found = 1
        		if ans > 0:
        			ans *= 10
        		ans += k
        		if ans > 0x7FFFFFFF:
        			if sign == 1:
	        			return 0x7FFFFFFF
	        		else:
	        			return -1<<31
	        else:
        		return ans*sign
        	p += 1
        return ans*sign

my_test = Solution()
sample = ["42", "   -42", "4193 with words", "words and 987", "-91283472332", "3.14159", "  2147483648", "", "+1", "  ", "0    98", "+-1a"]
answer = [42, -42, 4193, 0, -2147483648, 3]

for m in sample:
  print("%s => %d" % (m, my_test.myAtoi(m)))
