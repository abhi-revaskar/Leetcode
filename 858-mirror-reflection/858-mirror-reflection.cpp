class Solution {
public:
    int mirrorReflection(int p, int q) {
        int d=0,l=1,og=p;
        while(true)
        {
            // cout<<p<<endl;
            if(!d && !l)
            {
                if(p%q==0 && (p/q)&1)
                    return 2;
                if(p%q ==0)
                    return 1;
                if((p/q)%2==0)
                    l=1;
                d=1;      
            }
            else if(!d && l)
            {
                if(p%q==0 && (p/q)&1)
                    return 1;
                if(p%q ==0)
                    return 2;
                if((p/q)%2==0)
                    l=0;
                d=1;                    
            }
            else if(d && l)
            {
                if(p%q==0 && (p/q)&1)
                    return 0;
                if(p%q ==0)
                    return 1;
                if((p/q)%2==0)
                    l=0;
                d=0;                    
            }
            else if(d && !l)
            {
                if(p%q==0 && (p/q)&1)
                    return 2;
                if(p%q ==0)
                    return 0;
                if((p/q)%2==0)
                    l=1;
                d=0;                    
            }
            p=og-q+(p%q);
        }
        return 0;
    }
};