#include <iostream>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode* lchild;
    TreeNode* rchild;
};

template <class T> class Node
{
public:
    T data;
    Node<T>* next;
};
template <class T> class Stack
{
private:
    Node<T> *top;
public:
    Stack();
    ~Stack();
    void push(T x);
    T pop();
    T peek();
    int isEmpty();
    int isFull();
    void display();
};

template <class T> Stack<T> :: Stack()
{
    this->top = NULL;

}

template <class T> Stack<T> :: ~Stack() {
    Node<T> *p = top;
    while (top){
        top = top->next;
        delete p;
        p = top;
    }
}

template <class T> void Stack<T> :: push(T x)
{
    Node<T> *t = new Node<T>;
    if (t == NULL)
    {
        cout << "Stack Overflow!" << endl;
    } 
    else 
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

template <class T> T Stack<T> :: pop()
{
    Node<T> *t;
    T x = 0;
    if(this->top == NULL)
    {
        cout<<"Stack is empty" << endl;
    }

    else
    {
        t = this->top;
        x = t->data;
        top = top->next;
        delete t;
    }
    return x;

}

template <class T> T Stack<T> :: peek()
{
    Node<T> *t;
    T x = 0;
    if(this->top == NULL)
    {
        cout<<"Stack is empty" << endl;
    }

    else
    {
        t = this->top;
        x = t->data;
    }
    return x;

}

template <class T> int Stack<T>::isFull() {
    Node<T>* t = new Node<T>;
    if(t == NULL)
    {delete t;
        return 1;
    }
    else
    {delete t;
        return 0;
    }
    

}
 
template <class T> int Stack<T>::isEmpty() {
    return top ? 0 : 1;
}

template <class T> void Stack<T>::display()
{
    if(top == NULL)
    {
        cout<< "Stack is empty" << endl;
    }

    else
    {
        Node<T> *t;
        t = top;
        while(t != NULL)
        {
            cout << t->data;
            t = t->next;
        }
        cout << "" <<endl;
    }
}

class Queue
{
private:
    Node<TreeNode*>* front;
    Node<TreeNode*>* rear;
public:
    Queue();
    ~Queue();
    void enqueue(TreeNode *x);
    TreeNode* dequeue();
    bool isEmpty();
    void display();
};
 
Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}
void Queue::enqueue(TreeNode *x) {
    Node<TreeNode*>* t = new Node<TreeNode*>;
    if (t == nullptr){
        cout << "Queue Overflow" << endl;
    } else {
        t->data = x;
        t->next = nullptr;
        if (front == nullptr){
            front = t;
            rear = t;
        } else {
            rear->next = t;
            rear = t;
        }
    }
}
 
TreeNode* Queue::dequeue() {
    TreeNode* x = nullptr;
    Node<TreeNode*>* p;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}
 
bool Queue::isEmpty() {
    if (front == nullptr){
        return true;
    }
    return false;
}
 
Queue::~Queue() {
    Node<TreeNode*>* p = front;
    while (front){
        front = front->next;
        delete p;
        p = front;
    }
}
 
void Queue::display() {
    Node<TreeNode*>* p = front;
    while (p){
        cout << p->data << flush;
        p = p->next;
        if (p != nullptr){
            cout << " <- " << flush;
        }
    }
    cout << endl;
}

class BinaryTree
{
public:
    TreeNode *root;
    BinaryTree(){root=nullptr;}
    BinaryTree(TreeNode *r){root = r;}
    void createBinaryTree();
    void preorder(){preorder(root);}
    void preorder(TreeNode *p);
    void postorder(){postorder(root);}
    void postorder(TreeNode *p);
    void inorder(){inorder(root);}
    void inorder(TreeNode *p);
    void levelOrder(){levelOrder(root);}
    void levelOrder(TreeNode *p);
    void iterativePreorder(){iterativePreorder(root);}
    void iterativePreorder(TreeNode *p);
    void iterativeInorder(){iterativeInorder(root);}
    void iterativeInorder(TreeNode *p);
    void iterativePostorder(){iterativePostorder(root);}
    void iterativePostorder(TreeNode *p);
    void generateFromTraversal2(int *inorder, int *preorder, int inStart, int inEnd){root = generateFromTraversal(inorder, preorder, inStart, inEnd);}
    TreeNode* generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd);
    int countNodes(){return countNodes(root);}
    int countNodes(TreeNode *p);
    int height(){return height(root);}
    int height(TreeNode *root);

};
void BinaryTree::createBinaryTree()
{
    Queue q;
    TreeNode *p, *t;
    root = new TreeNode;
    int data;
    cout << "Enter root value : ";
    cin >> data;
    root->data = data;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter left Child : ";
        cin >> data;
        if(data != -1)
        {
            t = new TreeNode;
            t->data = data;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);

        }
        cout << "Enter Right Child : ";
        cin >> data;
        if(data != -1)
        {
            t = new TreeNode;
            t->data = data;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);

        }
    }


} 

void BinaryTree::preorder(TreeNode *p)
{
    if(p)
    {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void BinaryTree::postorder(TreeNode *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " ";
    }
}

void BinaryTree::inorder(TreeNode *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}

void BinaryTree::levelOrder(TreeNode *p)
{
    Queue q;
    TreeNode *t;
    cout << p->data << " ";
    q.enqueue(p);
    while(!q.isEmpty())
    {
        t = q.dequeue();
        if(t->lchild != nullptr)
        {
            cout << t->lchild->data << " ";
            q.enqueue(t->lchild);
        }

        if(t->rchild != nullptr)
        {
            cout << t->rchild->data << " ";
            q.enqueue(t->rchild);
        }
    }

}

void BinaryTree::iterativePreorder(TreeNode *p)
{
    Stack<TreeNode*> s;
    TreeNode *t = p;
    while(t != nullptr || !s.isEmpty())
    {
        if(t != nullptr)
        {
            cout << t->data << " ";
            s.push(t);
            t = t->lchild;
        }
        else
        {
            t = s.pop();
            t = t->rchild;
        }

    }

}

void BinaryTree::iterativeInorder(TreeNode *p)
{
    Stack<TreeNode*> s;
    TreeNode *t = p;
    while(t != nullptr || !s.isEmpty())
    {
        if(t != nullptr)
        {
            s.push(t);
            t = t->lchild;
        }
        else
        {
            t = s.pop();
            cout << t->data << " ";
            t = t->rchild;
        }

    }

}

void BinaryTree::iterativePostorder(TreeNode *p)
{
    Stack<long int> s;
    TreeNode *t = p;
    long int temp;
    while(t != nullptr || !s.isEmpty())
    {
        if(t != nullptr)
        {
            s.push((long int)t);
            t = t->lchild;
        }
        else
        {
            temp = s.pop();

            if(temp > 0)
            {
                s.push(-temp);
                t = ((TreeNode*)temp)->rchild;

            }
            else
            {
                cout << ((TreeNode*)(-1*temp))->data << " ";
                t = nullptr;
            }
            
            
        }

    }


}

int searchInorder(int inArray[], int inStart, int inEnd, int data){
    for (int i=inStart; i<=inEnd; i++){
        if (inArray[i] == data){
            return i;
        }
    }
    return -1;
}


TreeNode* BinaryTree::generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd) 
{
    static int preIndex = 0;
     if (inStart > inEnd){
        return nullptr;
    }
    cout << preIndex << endl;
    TreeNode *t = new TreeNode;
    t->data = preorder[preIndex++];
    t->lchild = nullptr;
    t->rchild = nullptr;

    if(inStart == inEnd)
    {
        return t;
    }

    int splitIndex = searchInorder(inorder, inStart, inEnd, t->data);
    t->lchild = generateFromTraversal(inorder, preorder, inStart, splitIndex-1);
    t->rchild = generateFromTraversal(inorder, preorder, splitIndex+1, inEnd);

    return t;
}

int BinaryTree::countNodes(TreeNode *p)
{
    if(p == nullptr)
    {
        return 0;
    }

    int x = countNodes(p->lchild);
    int y = countNodes(p->rchild);

    return x + y + 1;

}

int BinaryTree::height(TreeNode *p)
{
    if(p == nullptr)
    {
        return 0;
    }

    int x = height(p->lchild);
    int y = height(p->rchild);

    return max(x, y) + 1;

}

int main() {
    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
    BinaryTree s;
    s.generateFromTraversal2(inorder, preorder, 0, sizeof(inorder)/sizeof(inorder[0])-1);
    cout << endl;

    s.preorder();
    cout << endl;
    s.iterativePreorder();
    cout << endl;

    cout << endl;


    s.inorder();
    cout << endl;
    s.iterativeInorder();

    cout << endl;
    cout << endl;


    s.postorder();
    cout << endl;
    s.iterativePostorder();

    cout << endl;
    cout << endl;

    cout << "Total number of nodes = " << s.countNodes() << endl;
    cout << "height of tree = " << s.height() << endl;

    return 0;
}