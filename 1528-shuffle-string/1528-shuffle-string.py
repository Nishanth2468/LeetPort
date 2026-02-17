class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        res = [''] * len(s)

        for i in range(len(s)):
            res[indices[i]] = s[i]
        
        result = "".join(res)

        return result