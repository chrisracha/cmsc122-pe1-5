#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

int main() {
    Node Tree(0);
    Node *root = NULL;
    int t;
    cin >> t;
    return 0;
}

Node* search(Node* root, int key) {
    if(root == NULL || root->data == key)
        return root;

    if(root-> data < key)
        return search(root->right, key);

    return search(root->left, key);
}

Node* insert(Node* root, int data) {
    if(root == NULL) {
        return new Node(data);
    } else {
        Node* cur;
        if(data == root -> data) {
            cur = insert(root->left, data);
            root->left = cur;
        } else {
            cur = insert(root->right, data);
            root->right = cur;
        }
        return root;
    }
}

Node* deletenode(Node* root, int k) {
    if(root == NULL)
        return root;

    if(root->data > k) {
        root->left = deletenode(root->left, k);
        return root;
    } else if(root->data < k) {
        root->right = deletenode(root->right, k);
        return root;
    }

    if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    } else if (root->right == NULL) {
        Node* temp = root-> left;
        delete root;
        return temp;
    } else {
        Node* Parent = root;
        Node* succ = root->right;
        while(succ->left != NULL) {
            Parent = succ;
            succ = succ->left;
        }

        if(Parent != root)
            Parent->left = succ->right;
        else
            Parent->right = succ->right;

        root->data = succ->data;

        delete succ;
        return root;
    }
}

void inorder(Node* root) {
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if(root == NULL)
        return;
    
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if(root == NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}