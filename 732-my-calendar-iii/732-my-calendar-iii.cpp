struct node{
    int l,r,lazy,val;
    node *left,*right;
    node(int l,int r,int val)
    {
        this->l = l;
        this->r = r;
        this->val = val;
        lazy = 0;
        left = right = NULL;
    }
};
class MyCalendarThree {
    node *root;
public:
    MyCalendarThree() {
        root = new node(0,1e9,0);
    }
    void push(node *root)
    {
        if(!root->left)
        {
            int m = (root->l+root->r)/2;
            root->left = new node(root->l,m,root->val);
            root->right = new node(m+1,root->r,root->val);
        }
        else if(root->lazy)
        {
            root->left->val+=root->lazy;
            root->right->val+=root->lazy;
            root->left->lazy+=root->lazy;
            root->right->lazy+=root->lazy;
        }
        root->lazy = 0;
    }
    void update(node *root,int l,int r,int val)
    {
        if(l>r)
            return;
        if(root->l==l &&root->r == r)
        {
            root->val+=val;
            root->lazy+=val;
            return;
        }
        push(root);
        int m = (root->l+root->r)/2;
        update(root->left,l,min(r,m),val);
        update(root->right,max(l,m+1),r,val);
        root->val = max(root->left->val,root->right->val);
    }
    int query(node *root,int l,int r)
    {
        if(l>r)
            return 0;
        if(root->l==l && root->r==r)
            return root->val;
        push(root);
        int m = (root->l+root->r)/2;
        return max(query(root->left,l,min(r,m)),query(root->right,max(l,m+1),r));
    }
    int book(int start, int end) {
        update(root,start,end-1,1);
        return query(root,0,1e9);
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */