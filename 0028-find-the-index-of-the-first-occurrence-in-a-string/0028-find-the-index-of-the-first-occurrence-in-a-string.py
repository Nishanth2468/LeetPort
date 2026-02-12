class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        # s = haystack.find(needle)

        # if s != -1:
        #     return s
        # else :
        #     return -1
        n = len(haystack)
        m = len(needle)

        for i in range(n - m + 1):
            size = i
            if haystack[i:m+i] == needle:
                return size
        
        return -1