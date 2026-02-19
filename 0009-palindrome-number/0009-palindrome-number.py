class Solution:
    def isPalindrome(self, x: int) -> bool:
        # s = str(x)
        # rev = s[::-1]

        # if rev == s :
        #     return True
        # else :
        #     return False
        # OR TRADITIONAL METHOD:

        rev = 0
        temp = x 

        while x > 0 :
            digit = x % 10
            rev = rev * 10 + digit
            x //= 10

        if temp == rev:
            return True 
        else :
            return False
