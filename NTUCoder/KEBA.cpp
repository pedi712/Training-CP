#include <iostream>
using namespace std;
struct node{
  int data;
  node* next;
  node* pre;
};
int main()
{
    int n,m;cin >> n >> m;
    node** add = new node*[n];
    node* curr = new node;
    for (int i = 0;i<n;i++){
      node* nodes = new node;
      nodes->data = i+1;
      curr->next = nodes;
      nodes->pre = curr;
      curr = nodes;
      add[i] = curr;
    }
    node* dau = add[0];
    node* cuoi = add[n-1];
    dau->pre = cuoi;
    cuoi->next = dau;
    for (int i = 0;i<m;i++){
      int x,y;cin >> x >> y;
      x-=1; y-=1;
      node* nodex = add[x];
      (nodex->pre)->next = nodex->next;
      (nodex->next)->pre = nodex->pre;
      node* nodey = add[y];
      (nodey->next)->pre = nodex;
      nodex->next = nodey->next;
      nodey->next = nodex;
      nodex->pre = nodey;
   }
   node* currs = add[0];
   for (int i =0 ;i<n;i++){
     cout << currs->data<<" ";
     currs = currs->next;
   }
}

