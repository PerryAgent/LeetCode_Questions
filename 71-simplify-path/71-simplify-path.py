class Solution:
    def simplifyPath(self, path: str) -> str:
        dic = path.split('/')
        dic = [i for i in dic if i!='' and i!='.']
        print(dic)
        f_path = ""
        i = 0
        new_dic = []
        # while(".." in dic):
        #     for i in range(len(dic)):
        #         if dic[i] == "..":
        #             dic = dic[:i-1]+dic[i+1:]
        #             print(dic)
        #             break
        # new_i = -1
        while i < (len(dic)):
            if dic[i] != "..":
                new_dic.append(dic[i])
                # new_i += 1
            else:
                if len(new_dic) != 0:
                    del new_dic[-1]
            i+=1
                
                
        print(new_dic)        
        for i in new_dic:
            f_path += '/'
            f_path += i
            
        if f_path == "":
            return "/"
        return f_path

