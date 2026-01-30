class Solution:
    def myPow(self, x: float, n: int) -> float:
        # res = 1
        # for i in range(abs(n)) :
        #     res *=  x
        
        # return 1/res if n < 0 else res
        if n < 0:
            n = -n
            x = 1/x

        res = 1
        while n > 0 :
            if n % 2 == 1:
                res *= x
            x **= 2
            n //= 2
        
        return res
