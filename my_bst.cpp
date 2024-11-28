#include <iostream>
#include "my_bst.h"
using namespace std;


// creazione nodo ricorsivo
Node*  Node::insert_r(Node *root, int k){
    if(root==nullptr){
        return new Node(k);
    }
    if(root->data==k){
        root->weight++;
        return root;
    }
    if(root->data>k){
        root->lchild=insert_r(root->lchild, k);
    }else{
        root->rchild=insert_r(root->rchild, k);
    }
}

// creazione nodo iterativo
Node* Node::insert_i(Node* root, int k){
    bool check{true};
    Node*current=root;
    Node*father=nullptr;
    do{
        if(current==nullptr){
            if(father->data>k){
                father->lchild=new Node(k);
                check=false;
                return root;
            }else{
                father->rchild=new Node(k);
                check=false;
                return root;
            }
        }
        if(current->data==k){
            check=false;
            current->weight++;
            return root;
        }
        if(current->data>k){
            father=current;
            current=current->lchild;
        }else{
            father=current;
            current=current->rchild;
        }
    }while(check);
    return root;
}

//cerco nodo con ricorsione
Node* Node::search_r(Node *root, int k){
    if(root==nullptr){
        cout << "nodo non trovato";
        return root;
    }
    if(root->data==k){
        cout << "nodo trovato";
        return root;
    }
    if(root->data>k){
        search_r(root->lchild, k);
    }else{
        search_r(root->rchild, k);
    }
    return root;
}

//cerca nodo con iterazione NON HO USATO FATHER E CURRENT
Node* Node::search_i(Node* root, int k){
    bool check{true};
    do{
    if(root==nullptr){
        cout << "nodo non trovato";
        check=false;
        return root;
    }
    if(root->data==k){
        cout << "nodo trovato";
        check=false;
        return root;
    }
    if(root->data>k){
        root=root->lchild;
    } else {
        root=root->rchild;
    }
    }while(check);
    return root;
}

//cancellazione nodo con ricorsione 
Node* Node::cancel_r(Node *root, int k){
    if(root==nullptr){
        cout << "nodo non trovato";
        return root;
    }
    if(root->data==k){
        if(root->rchild==nullptr && root->lchild==nullptr){
            delete root;
            return root;
        }
        if(root->rchild!=nullptr){
            Node* temp=root;
            root->data=root->rchild->data;
            root->rchild->data=temp->data;
            root->rchild->data=0;
            delete root->rchild;
            return root;
        }
        if(root->lchild!=nullptr){
            Node* temp=root;
            root->data=root->lchild->data;
            root->lchild->data=temp->data;
            root->lchild->data=0;
            delete root->lchild;
            return root;
        }
    }
    if(root->data>k){
        cancel_r(root->lchild, k);
    } else{
        cancel_r(root->rchild, k);
    }
}

//cancellazione nodo con iterazione
Node* Node::cancel_i(Node* root, int k){
    bool check{true};
    do{
    if(root==nullptr){
        cout << "nodo non trovato";
    }
    if(root->data==k){
        if(root->rchild!=nullptr && root->lchild!=nullptr){
            root->data=0;
            delete root;
        }
        if(root->rchild!=nullptr){
            Node*temp=root;
            root->data = root->rchild->data;
            root->rchild->data=temp->data;
            root->rchild->data=0;
            delete root->rchild;
            check=false;
            return root;
        }
        if(root->lchild!=nullptr){
            Node*temp=root;
            root->data = root->lchild->data;
            root->lchild->data=temp->data;
            root->lchild->data=0;
            delete root->lchild;
            check=false;
            return root;
        }
    }
    }while(check);
}

// scorrimento ricorsivo Inorder_Traversal
Node* Node::Inorder_Traversal(Node*r){
    if(r==NULL){
        cout<<"L'albero è vuoto"<<endl;
    }else{
        if(r->lchild!=NULL){
            Inorder_Traversal(r->lchild );
        }
        cout<<r->data<<" ";
        if(r->rchild!=NULL){
            Inorder_Traversal(r->rchild );
        }
    }
    return r;
}

// scorrimento ricorsivo Preorder traversal
Node* Node::Preorder_Traversal(Node*r){
    if(r==NULL){
        cout<<"L'albero è vuoto"<<endl;
    } else{
        cout<<r->data<<" ";
        if(r->lchild!=NULL){
            Preorder_Traversal(r->lchild );
        }
        if(r->rchild!=NULL){
            Preorder_Traversal(r->rchild );
        }
    }
    return r;
}

// scorrimento ricorsivo Postorder traversal
Node* Node::Postorder_Traversal(Node*r){
    if(r==NULL){
        cout<<"L'albero è vuoto"<<endl;
    } else{
        if(r->lchild!=NULL){
            Postorder_Traversal(r->lchild );
        }
        if(r->rchild!=NULL){
            Postorder_Traversal(r->rchild );
        }
        cout<<r->data<<" ";
    }
    return r;
}

// calcolo dei livelli
int Node::max(int sl,int sr){
    if (sl>sr){
        return sl;
    } else
    return sr;
}
int Node::height(Node *r){
    if(r==NULL){
        return 0;
    }
    int sl=height(r->lchild);
    int sr=height(r->rchild);
    return max(sl,sr)+1;
}

//verifica di un albero se e un BST
Node* Node::Preorder_Traversal_Test(Node* root){
    if(root==NULL){
        cout << "l'albero e vuoto";
        return root;
    }
    cout << root->data << " ";
    if(root->lchild!=NULL && root->lchild->data<root->data){
        Preorder_Traversal_Test(root->lchild);
    }else if(root->lchild!=NULL && root->lchild->data>root->data){
        cout << "non e un BST";
    }
    if(root->rchild!=NULL && root->rchild->data>root->data){
        Preorder_Traversal_Test(root->rchild);
    }else if(root->rchild!=NULL && root->rchild->data<root->data){
        cout << "non e un BST";
    }
    return root;
}

Node* Node::insertR(int k){
    if (k==this->data){
        this->weight++;
        return this;
    }
    if (k<this->data){
        if (this->lchild == NULL){
            this->lchild= new Node (k);
        } else{
            this->lchild= this->lchild->insertR(k);
        }
    } else if (this->rchild== NULL){
        this->rchild= new Node(k);
    } else {
        this->rchild= this->rchild->insertR(k);
    }
    return this;

}

void Node::inOrder(){
     if(this->lchild!=NULL){
        this->lchild->inOrder();
    }
    cout<<this->data<<" ";
    if(this->rchild!=NULL){
        this->rchild->inOrder();
    }
}

bool Node::searchI(int k){
    bool check{true};
    Node *current{this};
    while (check){

        if (current==NULL){
            cout << "non trovato" << " ";
            return false;
        }

        if(current->data==k){
            cout << "trovato" << " ";
            return true;
        }
        if (k<current->data){
            current = current->lchild;
        } else {
            current=current->rchild;
        }
    }
    return -1;
}

bool Node::searchR(int k){
    if (this==NULL){
        cout << "non trovato" << " ";
        return false;
    }
    if (this->data==k){
        cout << "trovato" << " ";
        return true;
    }
    if (k<this->data){
        return this->lchild->searchR(k);
    } else {
        return this->rchild->searchR(k);
    }
}

Node* Node::insertI(int k) {
    Node *current{this};
    Node *parent{nullptr};
    while (current != NULL) {
        if (current->data == k) {
            current->weight++;
            return this;
        }
        if (k < current->data) {
            parent = current;
            current = current->lchild;
        } else {
            parent = current;
            current = current->rchild;
        }
    }

    Node *n = new Node(k);
    if (k < parent->data) {
        parent->lchild = n;
    } else {
        parent->rchild = n;
    }
    return this;
}


