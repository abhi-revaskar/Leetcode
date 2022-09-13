class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int lead = 248,trail = 192,i=0,n = data.size();
        while(i<data.size())
        {
            if((data[i]&lead)<128)
            {
                i++;
            }
            else if((data[i]&lead)<=216)
            {
                if(i==n-1 || (data[i+1]&trail)!=128)
                    return false;
                i+=2;
            }
            else if((data[i]&lead)<=232)
            {
                if(i==n-1 || i==n-2 || (data[i+1]&trail)!=128 || (data[i+2]&trail)!=128)
                    return false;
                i+=3;
            }
            else if((data[i]&lead)==240)
            {
                if(i==n-1 || i==n-2 || i==n-3 || (data[i+1]&trail)!=128 || (data[i+2]&trail)!=128 || (data[i+3]&trail)!=128)
                    return false;
                i+=4;
            }
            else
                return false;
        }
        return true;
    }
};