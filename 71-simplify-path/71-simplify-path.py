class Solution:
    def simplifyPath(self, path: str) -> str:
        dirs = path.split('/')
        finaldirs = [i for i in dirs if i != '' and i!='.']
        dirs = []
        for i in finaldirs:
            if(i=='..' and len(dirs)!=0):
                dirs.pop()
            elif i!='..':
                dirs.append(i)
        
        s = '/'.join(dirs)
        s='/'+s
        return s