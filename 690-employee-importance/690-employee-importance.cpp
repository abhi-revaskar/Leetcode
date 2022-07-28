/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int solve(int id,unordered_map<int,int> &imp,unordered_map<int,vector<int>> &sub)
    {
        int sum = imp[id];
        for(auto &x:sub[id])
            sum+=solve(x,imp,sub);
        return sum;
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,int> imp;
        unordered_map<int,vector<int>> sub;
        for(auto &x:employees)
        {
            imp[x->id]=x->importance;
            sub[x->id] = x->subordinates;
        }
        return solve(id,imp,sub);
    }
};