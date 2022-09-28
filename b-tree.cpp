#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *n;
    n = new struct Node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preTraversal(struct Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preTraversal(root->left);
        preTraversal(root->right);
    }
}

void postTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postTraversal(root->left);
        postTraversal(root->right);
        cout << root->data << " ";
    }
}
void inTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inTraversal(root->left);
        cout << root->data << " ";
        inTraversal(root->right);
    }
}
int isBst(struct Node *root)
{
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBst(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBst(root->right);
    }
    else
    {
        return 1;
    }
}
struct Node *isPresentRecursive(struct Node *root, int n)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (n == root->data)
    {
        return root;
    }
    else if (n < root->data)
    {
        return isPresentRecursive(root->left, n);
    }
    else
    {
        return isPresentRecursive(root->right, n);
    }
}

struct Node *isPresentIterative(struct Node *root, int n)
{
    while (root != NULL)
    {
        if (n == root->data)
        {
            return root;
        }
        else if (n < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

void insertion(struct Node *root, int n)
{
    // struct Node* prev =;
    while (root != NULL)
    {
        if (n == root->data)
        {
            cout << "The item already in BST" << endl;
            return;
        }
        else if (n < root->data)
        {
            if (root->left != NULL)
            {
                root = root->left;
            }
            else
            {
                struct Node *newNode = createNode(n);
                root->left = newNode;
            }
        }
        else
        {
            if (root->right != NULL)
            {
                root = root->right;
            }
            else
            {
                struct Node *newNode = createNode(n);
                root->right = newNode;
            }
        }
    }
}

// find inorder predecessor
struct Node* inOrderPredecessor(struct Node* root){
    root = root->left;
    while(root->right == NULL){
        root = root->right;
    }
    return root;
}

// deletion
struct Node *deleteNode(struct Node *root, int value){

    // struct Node* iPre = new struct Node();
    // iPre = NULL;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
        free(root);
    }

    //searching for the node to be deleted
    if (value < root->data){
        deleteNode(root->left,value);
    }
    else if (value > root->data){
        deleteNode(root->right,value);
    }
    //deletion strategy when the node is found
    else{
        struct Node* iPre = new struct Node();
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        deleteNode(root->left, iPre->data);
    }
    return root;
}


int main()
{

    struct Node *root = createNode(12);
    struct Node *p1 = createNode(6);
    struct Node *p2 = createNode(18);
    struct Node *p3 = createNode(3);
    struct Node *p4 = createNode(11);
    struct Node *p5 = createNode(14);

    root->left = p1;
    root->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;

    //     12
    //    /  \
        //   6    18
    //  / \   /
    // 3  11 14

    preTraversal(root);
    cout << endl;
    postTraversal(root);
    cout << endl;
    inTraversal(root);
    cout << endl;

    // check bst
    if (isBst(root))
    {
        cout << "is BST" << endl;
    }
    else
    {
        cout << "not a BST" << endl;
    }

    // recursive search
    if (isPresentRecursive(root, 19) != NULL)
    {
        cout << "is present" << endl;
    }
    else
    {
        cout << "not present" << endl;
    }

    // iteraive search
    if (isPresentIterative(root, 18) != NULL)
    {
        cout << "is present" << endl;
    }
    else
    {
        cout << "not present" << endl;
    }

    // insertion
    insertion(root, 19);
    inTraversal(root);
    cout << endl;

    // deletion
    deleteNode(root, 12);
    inTraversal(root);
    cout << endl;
    cout<<root->data<<endl;

    return 0;
}