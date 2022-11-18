#include <iostream>

using namespace std;

class Node{
public:
	Node* lchild;
	int data;
	int height;
	Node* rchild;

}

class AVLTree{
public:
	Node* root;
	AVLTree(){
		root = nullptr;
	}

	// Helper methods for inserting
    int NodeHeight(Node* p);
    int BalanceFactor(Node* p);
    Node* LLRotation(Node* p);
    Node* RRRotation(Node* p);
    Node* LRRotation(Node* p);
    Node* RLRotation(Node* p);
 
    // Insert
    Node* insertNode(Node* p, int key);
 
    // Traversal
    void Inorder(Node* p);
    void Inorder(){ Inorder(root); }
    Node* getRoot(){ return root; 
};

int AVLTree::nodeHeight(Node* p){
	int l = 0;
	int r = 0;
	l = p && p->lchild ?p->lchild->height:0;
	r = p && p->rchild ?p->rchild->height:0;

	return l>r?l+1:r+1;
}

int AVLTree::balanceFactor(Node* p){
	int l = 0;
	int r = 0;
	l = p && p->lchild ?p->lchild->height:0;
	r = p && p->rchild ?p->rchild->height:0;

	return l-r;
}

Node* AVLTree::LLRotation(Node* p){
	Node* b = p->lchild;
	Node* br = b->rchild;
	b->rchild = p;
	p->lchild = br;

	p->height = nodeHeight(p);
	b->height = nodeHeight(b);

	if(root == p){
		root = b;
	}

	return b;

}

Node* AVLTree::RRRotation(Node* p){
	Node* b = p->rchild;
	Node* bl = p->lchild;
	b->lchild = p;
	p->rchild = bl;

	p->height = nodeHeight(p);
	b->height = nodeHeight(b);

	if(root == p){
		root = b;
	}

	return b;
}

Node* AVLTree::LRRotation(Node* p){
	Node* pl = p->lchild;
	Node* plr = p->lchild->rchild;

	pl->rchild = plr->lchild;
	p->lchild = plr->rchild;

	plr->lchild = pl;
	plr->rchild = p;

	pl->height = nodeHeight(pl);
	p->height = nodeHeight(p);
	plr->height = nodeHeight(plr);

	if(root==p){
		root=plr;
	}
	
	return plr;
}

Node* AVLTree::insertNode(Node* p, int key){
	Node* t;
	if(p == nullptr){
		t = new Node;
		t-> data = key;
		t->lchild = nullptr;
		t->rchild = nullptr;
		t->height = 1;
		return t;
	}

	if (key < p->data){
		p->lchild = insertNode(p->lchild, key);
	}
	else if(key > p->data){
		p->rchild = insertNode(p->rchild, key);
	}

	p->height = nodeHeight(p);
// Balance Factor and Rotation
    if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1) {
        return LLRotation(p);
    } else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1){
        return LRRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1){
        return RRRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1){
        return RLRotation(p);
    }
 
    return p;

}