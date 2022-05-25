class Solution:
    def reverseWords(self, s: str) -> str:
        words = list(s.split(' '))
        words = [i for i in words if i != '']
        # print(words) 
        words.reverse()
        print(words)
        f_str = ""
        for i in words:
            f_str += i + " "
        return f_str[:-1]