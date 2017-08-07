#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* link;
};
typedef struct Node* node;

node create_node(int val){
    node member = (node)calloc(1,sizeof(struct Node));
    member->data = val;
    member->link = NULL;
    return member;
}
node delete_child(node parent){
    parent->link = (parent->link)->link;
    return parent;
}
void print_list(node head){
   node p = head;
    while(p!=NULL){
        cout<<p->data<<endl;
        p = p->link;
    }
    
}
int main(){
   node head;
   head = create_node(1);
   node p = head;
   for(int i=2;i<10;i++){
       p->link = create_node(i);
       p = p->link;
   }
   print_list(head);
   return 0;
}
