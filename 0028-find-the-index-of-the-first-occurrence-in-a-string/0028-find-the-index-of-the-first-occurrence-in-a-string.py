class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        s = haystack.find(needle)

        if s != -1:
            return s
        else :
            return -1