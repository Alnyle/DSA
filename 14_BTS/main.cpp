#include<iostream>
#include<queue>
using namespace std;

template<class T>
class BTSNode {
    private:
    T item;
    BTSNode *left;
    BTSNode *right;
    public:

    BTSNode(T el, BTSNode *l = 0, BTSNode r = 0) {
        item = el;
        left = l;
        right = r;
    }    

    BTSNode* getKey() {return item;}
    BTSNode* getLeft() {return left;}
    BTSNode* getRight() {return right;}

    void setLeft(T &value) { 
        left = new BTSNode(value);
    }

    void setRight(T &value) {
        right = new BTSNode(value);
    }
};


template <class T>
class BTS {
    protected:
    BTSNode<T>* root;
    BTS() {root = 0;}
    void clear() {root = 0;}
    bool isEmpty() {return root == 0;}

    T* search(T& target) {
        BTSNode<T>* p = root;

        while (p != 0) {
            if (p->getKey() == target) 
                return &p->getKey();
            else if (target < p->getKey())
                p = p->getLeft();
            else 
                p = p->getRight();
        }
    }

    void BreadthFirst() {
        BTSNode<T> *p = root;
        queue<BTSNode<T>*> level;
        if(!isEmpty()) {

            level.push(p);
            while(!level.empty()) {

                *p = level.front();
                cout << p->getKey() << " ";
                level.pop();

                if (p->getLeft() != 0) 
                    level.push(p->getLeft());
                if (p->getRight() != 0) 
                    level.push(p->getRight());
            }
        }
    }


    void inOrder(BTSNode<T> *node) {

        if (node == 0)
            return;
            
        return inOrder(node->getLeft());
        cout << node->getKey() << " ";
        return inOrder(node->getRight());
    }

    void postOrder(BTSNode<T> *node) {

        if(node == 0)
            return;
        
        return postOrder(node->getRight());
        return postOrder(node->getRight());
        cout << node->getKey() << " ";
    }

    void preOrder(BTSNode<T> *node) {

        if(node == 0)
            return;

        cout << node->getKey() << " ";
        return preOrder(node->getLeft());
        return preOrder(node->getRight());
    }

    void insert(T &value) {

        BTSNode<T> *p = root, *pre = 0;
        while(p != 0) {
            pre = p;
            if (p->getKey() < value) 
                p = p->getLeft();
            else p = p->getRight();
        }

        if (isEmpty()) 
            BTSNode<T> *root = new BTSNode(value);
        else if (pre->getKey() < value) 
            pre->setLeft(value);
        else pre->setRight(value);             
    }


    void deleteByCopying(BTSNode<T>*& node) {

        BTSNode<T> *pre, *temp = 0;

        if (node->getLeft() == 0)
            node = node->getLeft();
        else if (node->getRight() == 0)
            node = node->getRight();
        else {
            temp = node->getRight();
            pre = node;

            while(temp->getRight != 0) {
                pre = temp;
                temp = temp->getLeft();
            }

            node->getKey() = temp->getKey();
            if (prev == node) 
                pre->setLeft(temp->getLeft());
            else pre->setRight(temp->getLeft());

        }
        delete temp;
    }
};



int main() {

}