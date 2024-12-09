#ifndef _MY_BST.H_
#define _MY_BST.H_

class Node{
    private:

    public:
    int data;
    int weight;
    Node *lchild;
    Node *rchild;
    Node(int k){
        data=k;
        weight=1;
        lchild=nullptr;
        rchild=nullptr;
    }

    Node* insert_r(Node *root, int k);
    Node* insert_i(Node* root, int k);
    Node* search_r(Node *root, int k);
    Node* search_i(Node* root, int k);
    Node* cancel_r(Node *root, int k);
    Node* cancel_i(Node* root, int k);
    Node* Inorder_Traversal(Node*r);
    Node* Preorder_Traversal(Node*r);
    Node* Postorder_Traversal(Node*r);
    int max(int sl,int sr);
    int height(Node *r);
    Node* Preorder_Traversal_Test(Node* root);

    Node* insertR(int k);
    Node* insertI(int k);  
    bool searchI(int k); 
    bool searchR(int k); 
    void inOrder(); 

    void preOrder();
    void postOrder();
    Node* deleteNode(int k);
    bool isBst();
};


#endif