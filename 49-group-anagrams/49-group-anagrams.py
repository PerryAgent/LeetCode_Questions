class Solution:
    
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
#         def count_w(word: str):
#             c = [0]*26
#             for i in word:
#                 c[ord(i)-97]+= 1
#             return c
       
#         c_words = []
#         co_words = dict()
#         h_set = set()
#         for i in strs:
#             c_words.append(count_w(i))
            
#             if i in h_set:
#                 co_words[i]+=1
#             else:
#                 h_set.add(i)
#                 co_words[i] = 1
        
            
#         print(c_words)
#         g_words = []
#         # done = set()
#         for i in range(len(c_words)):
                
#             if co_words[strs[i]] == 0:
#                 continue
#             nlist = [strs[i]]
#             co_words[strs[i]] -=1
#             # co_words[strs[i]] == 
#             # done.add(strs[i])
#             for j in range(i+1,len(c_words)):
#                 if (co_words[strs[j]] != 0) and c_words[i] == c_words[j]:
#                     nlist.append(strs[j])
#                     co_words[strs[j]]-=1
                    
#             g_words.append(nlist)
            
#         print(g_words)
#         return g_words
        g = []
        s = set()
        dic = dict()
        l = 0
        for i in strs:
            t = ''.join(sorted(i))
            if t in s:
                g[dic[t]].append(i)
            else:
                g.append([i])
                s.add(t)
                dic[t] = l
                l += 1
                
        print(g)
        return g
        
        