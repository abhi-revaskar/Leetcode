class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        d = {}
        for i in paths:
            direct = i.split()
            for j in range(1,len(direct)):
                file = direct[j].split('(')
                # print(file)
                if file[1] not in d.keys():
                    d[file[1]] = []
                d[file[1]].append(direct[0]+'/'+file[0])
                # print(d[file[1]])
        # print(d)
        ans = []
        for k in d:
            # print(d[k])
            if(len(d[k])>1):
                ans.append(d[k])
        return ans
            