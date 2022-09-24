#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node* createNode(int data){
    struct Node* n;
    n = new struct Node();
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void preTraversal(struct Node* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preTraversal(root->left);
        preTraversal(root->right);
    }
}

void postTraversal(struct Node* root){
    if(root!=NULL){
        postTraversal(root->left);
        postTraversal(root->right);
        cout<<root->data<<" ";
    }
}
void inTraversal(struct Node* root){
    if(root!=NULL){
        inTraversal(root->left);
        cout<<root->data<<" ";
        inTraversal(root->right);
    }
}

int main(){

    struct Node* root = createNode(2); 
    struct Node* first = createNode(1); 
    struct Node* second = createNode(4); 

    root->left = first;
    root->right = second;

    preTraversal(root);
    cout<<endl;
    postTraversal(root);
    cout<<endl;
    inTraversal(root);
    cout<<endl;
    
    return 0;
}