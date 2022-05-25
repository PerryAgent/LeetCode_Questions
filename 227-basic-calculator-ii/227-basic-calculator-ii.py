import re
class Solution:
    def calculate(self, s: str) -> int:
        
        def precedence(op):
            if op == '*' or op =='/':
                return 1
            else:
                return 0
        def operation(o1, o2, o3):
            i1 = int(o1)
            i2 = int(o2)
            if o3 == '+':
                return i1+i2
            if o3 == '-':
                return i1-i2
            if o3 == '*':
                return i1*i2
            if o3 == '/':
                return i1//i2
            
        op = ['+','-','*','/']
        opt = []
        opd = []
        opd = re.split('\+| |\*|-|/', s)
        opd = [i for i in opd if i != '']
        for i in s:
            if i in op:
                opt.append(i)
            
        if len(opt)==0:
            return opd[0]
        
        print(opt, opd)
        opds = []
        opts = []
        
        opds.append(opd[0])
        opds.append(opd[1])
        opts.append(opt[0])
        
        oti = 1
        odi = 2
        
        while(oti < len(opt) and odi < len(opd)):
            if (precedence(opts[-1]) < precedence(opt[oti])):
                opts.append(opt[oti])
                oti+=1
                opds.append(opd[odi])
                odi+=1
            else:
                while(len(opts)>0 and precedence(opts[-1]) >= precedence(opt[oti])):
                    o2 = opds[-1]
                    del opds[-1]
                    o1 = opds[-1]
                    del opds[-1]
                    o3 = opts[-1]
                    del opts[-1]

                    oans = str(operation(o1, o2, o3))
                    opds.append(oans)
                    
                opts.append(opt[oti])
                oti+=1
                opds.append(opd[odi])
                odi+=1
                
        oti -=1
        odi -=1
        while len(opts) > 0:
            o2 = opds[-1]
            del opds[-1]
            o1 = opds[-1]
            del opds[-1]
            o3 = opts[-1]
            del opts[-1]

            oans = str(operation(o1, o2, o3))
            opds.append(oans)
            
        return opds[0] 
                    
                
                
                
        
        # for 