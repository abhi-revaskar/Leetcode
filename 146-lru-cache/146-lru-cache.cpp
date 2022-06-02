class Node{
public:
    Node* pr;
    Node* nxt;
    int key,value;
    Node(int k,int v)
    {
        pr=NULL;
        nxt=NULL;
        key=k;
        value=v;
    }
};
class LRUCache {
public:
    Node* head= new Node(0,0);
    Node* tail= new Node(0,0);
    unordered_map<int,Node*> mp;
    int cnt,cap;
    LRUCache(int capacity) {
        cap=capacity;
        head->nxt=tail;
        tail->pr=head;
        cnt=0;
    }
    void track()
    {
      Node* t=head;
      while (t)
      {
        cout<<t->key<<" "<<t->value<<endl;
        t=t->nxt;
      }
      
    }
    int get(int key) {
        if(mp[key]==NULL)
        return -1;
        if((tail->pr)==mp[key])
        {
          return mp[key]->value;
        }
        Node *t=mp[key];
        t->pr->nxt=t->nxt;
        t->nxt->pr=t->pr;
        tail->pr->nxt=t;
        t->nxt=tail;
        t->pr=tail->pr;
        tail->pr=t;
        return t->value;
    }
    
    void put(int key, int value) {
      if(mp[key]!=NULL)
      {
        Node* t=mp[key];
        t->nxt->pr=t->pr;
        t->pr->nxt=t->nxt;
        mp[key]->value=value;
        tail->pr->nxt=mp[key];
        mp[key]->nxt=tail;
        mp[key]->pr=tail->pr;
        tail->pr=mp[key];
        return;
      }
      Node* node= new Node(key,value);
      if(cnt==cap)
      {
        Node* t=head->nxt;
        head->nxt=head->nxt->nxt;
        head->nxt->pr=head;
        mp[t->key]=NULL;
        delete(t);
        tail->pr->nxt=node;
        node->nxt=tail;
        node->pr=tail->pr;
        tail->pr=node;
        mp[key]=node;
      }
      else
      {
        tail->pr->nxt=node;
        node->nxt=tail;
        node->pr=tail->pr;
        tail->pr=node;
        cnt++;
        mp[key]=node;
      }
        
    }
};