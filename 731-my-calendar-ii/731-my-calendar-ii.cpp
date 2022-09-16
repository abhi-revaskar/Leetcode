class MyCalendarTwo {
    struct node{
        int l,r,val,add;
        node *left,*right;
        node(int _l,int _r,int k)
        {
            l = _l;
            r = _r;
            val= k;
            add = 0;left = NULL;right = NULL;
        }
    };
    node *root;
public:
    MyCalendarTwo() {
        root = new node(0,1e9,0);
    }
    void push(node *root)
    {
        int m = (root->l+root->r)/2;
        if(!root->left)
        {
            root->left = new node(root->l,m,root->val);
            root->right = new node(m+1,root->r,root->val);
        }
        else
        {
            root->left->val+=root->add;
            root->right->val+=root->add;
        }
        root->left->add+=root->add;
        root->right->add+=root->add;
        root->add = 0;
    }
    void update(node *root,int l,int r)
    {
        if(l>r || root==NULL)
            return;
        if(root->l ==l && root->r ==r)
        {
            root->add++;
            root->val++; //change
            return;
        }
        int m = (root->l+root->r)/2;
        push(root);
        update(root->left,l,min(r,m));
        update(root->right,max(m+1,l),r);
        root->val = max(root->left->val,root->right->val);
    }
    int query(node *root,int l,int r)
    {
        if(l>r || root==NULL)
            return 0;
        if(root->l==l && root->r == r)
            return root->val;
        int m = (root->l+root->r)/2;
        push(root);
        return max(query(root->left,l,min(r,m)),query(root->right,max(l,m+1),r));
    }
    bool book(int start, int end) {
        // cout<<start<<" "<<end<<endl;
        if(query(root,start,end-1)>=2)
        {
            // for(int i=start;i<=end;i++)
            //     cout<<query(root,start,i)<<endl;
            return false;
        }
        update(root,start,end-1);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */