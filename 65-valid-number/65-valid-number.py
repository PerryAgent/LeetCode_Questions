class Solution:
    def isNumber(self, s: str) -> bool:
        def isDeci(num):
            nums = "0123456789"
            dec = num.split('.')
            if len(dec) > 2:
                return False
            if len(dec)==1:
                return False
            
            print("here")
            
            if dec[0] == "" and dec[1] == "":
                return False
            if dec[0] != "":
                
                if dec[0][0] == '+' or dec[0][0] == '-':
                    if len(dec[0]) == 1 and dec[1] == "":
                        return False
                    ind = 1
                else:
                    ind = 0

                    
                for i in dec[0][ind:]:
                    if i in nums:
                        continue
                    else:
                        return False
            if dec[1] != "":
                for i in dec[1]:
                    if i in nums:
                        continue
                    else:
                        return False
            
            return True
        
        def isInt(num):
            nums = "0123456789"
            dec = num.split('.')
            if len(dec) >= 2:
                return False
            
            if dec[0][0] == '+' or dec[0][0] == '-':
                    if len(dec[0]) == 1:
                        return False
                    ind = 1
            else:
                ind = 0

            
            for i in dec[0][ind:]:
                if i in nums:
                    continue
                else:
                    return False
                
            return True
        
        exp = re.split('e|E', s)
        if len(exp) >2:
            return False
        if len(exp) == 1:
            if (exp[0] == ""):
                return False
            return (isDeci(exp[0]) or isInt(exp[0]))
        
        if exp[0]=="" or exp[1]=="":
            return False
        p1 = (isDeci(exp[0]) or isInt(exp[0]))
        p2 = isInt(exp[1])
        
        return (p1 and p2)
            
            
