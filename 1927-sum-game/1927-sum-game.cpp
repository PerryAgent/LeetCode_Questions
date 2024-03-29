class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
    int sa = 0, sb = 0, qa = 0, qb = 0;
    for(int i = 0; i < n; i++)
    {
        if(i < n / 2)
            num[i] == '?' ? qa++ : sa += num[i] - '0';
        else
            num[i] == '?' ? qb++ : sb += num[i] - '0';
    }
    
    bool flag = true;
    while(qa > 0 || qb > 0)
    {
        if(flag)
        {
            if(sa < sb)
                qb > 0 ? (sb += 9, qb--) : (sa += (sb - sa < 9 ? 9 : 0), qa--);
            else 
                qa > 0 ? (sa += 9, qa--) : (sb += (sa - sb < 9 ? 9 : 0), qb--);   
        }
        else
        {
            if(sa > sb)
                qb > 0 ? (sb += min(9, sa - sb), qb--) : (qa--);
            else
                qa > 0 ? (sa += min(9, sb - sa), qa--) : (qb--);
        }
        
        flag = !flag;
    }
      
    return sa != sb;

        
    }
};