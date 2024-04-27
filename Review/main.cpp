#include <iostream>
#include <queue>
using namespace std;

template <class T>
struct Node
{
    T value;
    Node<T> *left, *right;
    Node(T &val)
    {
        value = val;
        left = right = nullptr;
    }
};

template <class T>
class BTS
{
    Node<T> *root;
public:
    BTS()
    {
        root = nullptr;
    }

    bool isEmpty() // Corrected function name to isEmpty
    {
        return root == nullptr;
    }

    T *search(T &target)
    {
        if (root == nullptr)
            return nullptr;  // Return nullptr if tree is empty
        Node<T> *p = root;

        while (p != nullptr)
        {
            if (p->value == target)
                return &p->value;
            else if (p->value < target)
                p = p->left;
            else
                p = p->right;
        }
        return nullptr; // Return nullptr if target is not found
    }

    void breadthFirst() {

        Node<T> *p = root;
        queue<Node<T>*> q;
        if (p != nullptr) {
            q.push(p);

            while (!q.empty())
            {
                *p = q.front();
                cout << p->value;
                q.pop();
                if (p->left != nullptr)
                    q.push(p->left);
                else if (p->right != nullptr)
                    q.push(p->right);
                /* code */

            }
            
        }
    }

    void inOrder(Node<T> *node) {

        if (node == nullptr) 
            return;

        inOrder(node->left);
        cout << node->value << " ";
        inOrder(node->right);
    }

    void preOrder(Node<T> *node) {

        if (node == nullptr)
            return;
        cout << node->value << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void posOrder(Node<T> *node) {

        if (node == nullptr)
            return;
        
        posOrder(node->left);
        posOrder(node->right);
        cout << node->value << " ";
    }

    void insert(T &el) {

        Node<T> *p = root, *pre = nullptr;
        while (p != nullptr) {

            if (el < p->value) {
                p = p->left;
            }
            else 
                p = p->right;
        }

        if (p == nullptr)
            root = new Node(el);
        else if (el < p->value) 
            p->left = new Node(el);
        else 
            p->right = new Node(el);
    }
};

int main()
{
    return 0;
}
