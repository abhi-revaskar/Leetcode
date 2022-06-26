class Solution:
    def invalidTransactions(self, t: List[str]) -> List[str]:
        ans = []
        name , time, amt, city,add =[],[],[],[],[0]*len(t)
        for i in t:
            x = i.split(",")
            name.append(x[0])
            time.append(int(x[1]))
            amt.append(int(x[2]))
            city.append(x[3])
        for i in range(len(name)):
            if amt[i]>1000:
                add[i]=1
            for j in range(i+1,len(name)):
                if name[i] == name[j] and abs(time[i]-time[j])<=60  and city[i]!=city[j]:
                    add[j]=1
                    add[i]=1
        for i in range(len(add)):
            if add[i]:
                ans.append(t[i])
        return ans;
                    