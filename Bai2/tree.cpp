#include<iostream>
#include"queue.cpp"


#ifndef __TREE__CPP
#define __TREE__CPP


using namespace std;

template<class T>
class TreeNode{
	private:
		T elm;
		TreeNode* right;
		TreeNode* left;
		TreeNode* parent;
	public:
		TreeNode();
		TreeNode(T,TreeNode* right=nullptr, TreeNode* left=nullptr, TreeNode* parent=nullptr);
		T getElm();
		void setElm(T);
		TreeNode* getRight();
		void setRight(TreeNode*);
		TreeNode* getLeft();
		void setLeft(TreeNode*);
		TreeNode* getParent();
		void setParent(TreeNode*);
		bool hasRight();
		bool hasLeft();
};

template<class T>
TreeNode<T> ::TreeNode(){
	elm=0;
	right=left=parent=nullptr;
}

template<class T>
TreeNode<T> ::TreeNode(T elm, TreeNode<T>* right, TreeNode<T>* left, TreeNode<T>* parent){
	this->elm=elm;
	this->right=right;
	this->left=left;
	this->parent=parent;
}

template<class T>
T TreeNode<T>::getElm(){
	return this->elm;
}

template<class T>
void TreeNode<T>::setElm(T elm){
	this->elm=elm;
}

template<class T>
TreeNode<T>* TreeNode<T>::getRight(){
	return this->right;
}

template<class T>
void TreeNode<T>::setRight(TreeNode* node){
	this->right=node;
}

template<class T>
TreeNode<T>* TreeNode<T>::getLeft(){
	return this->left;
}

template<class T>
void TreeNode<T>:: setLeft(TreeNode* node){
	this->left=node;
}

template<class T>
TreeNode<T>* TreeNode<T>::getParent(){
	return this->parent;
}

template<class T>
void TreeNode<T>::setParent(TreeNode* node){
	this->parent=node;
}

template<class T>
bool TreeNode<T>::hasRight(){
	return this->right != nullptr;
}

template<class T>
bool TreeNode<T>::hasLeft(){
	return this->left != nullptr;
}

template<class T>
class Tree{
	private:
		TreeNode<T>* root;
	public:
		Tree();
		TreeNode<T>* getroot();
		int size(TreeNode<T>*);
		bool Empty();
		bool isInternal(TreeNode<T>*);
		bool isExternal(TreeNode<T>*);
		bool isRoot(TreeNode<T>*);
		void preOder(TreeNode<T>*, void(*visit)(TreeNode<T>*));
		void inOder(TreeNode<T>*, void(*visit)(TreeNode<T>*)); 	
		void postOder(TreeNode<T>*, void(*visit)(TreeNode<T>*));
		void levelOder(TreeNode<T>*, void(*visit)(TreeNode<T>*));
		void insert(T elm);
		TreeNode<T>* find(TreeNode<T>*, T);
		void remove(TreeNode<T>*);
};

template<class T>
Tree<T>::Tree(){
	root=nullptr;
}

template<class T>
TreeNode<T>* Tree<T>::getroot(){
	return this->root;
}

template<class T>
int Tree<T>::size(TreeNode<T>* node){
	if(node==nullptr) return 0;
	return 1+ size(node->getRight())+ size(node->getLeft());
}

template<class T>
bool Tree<T>::Empty(){
	return root==nullptr;
}

template<class T>
bool Tree<T>::isExternal(TreeNode<T>* node){
	return !node->getLeft() && !node->getRight();
}

template<class T>
bool Tree<T>::isInternal(TreeNode<T>* node){
	return node->getLeft() || node->getRight();
}

template<class T>
bool Tree<T>::isRoot(TreeNode<T>* node){

	return node==root;
}

template<class T>
void Tree<T>::insert(T elm){
	TreeNode<T>* newTreeNode = new TreeNode<T>(elm);
	if(root==nullptr){
		root=newTreeNode;
		return;
	}
	queue<TreeNode<T>*> q;
	q.push(root);

	while(!q.empty()){
		TreeNode<T>* t=q.front();
		q.pop();
		if(t->getLeft()==nullptr){
			t->setLeft(newTreeNode);
			return;
		} else{
			q.push(t->getLeft());
		}
		if(t->getRight()==nullptr){
			t->setRight(newTreeNode);
			return;
		} else{
			q.push(t->getRight());
		}

	}
}
template<class T>
void Tree<T>::preOder(TreeNode<T>* node, void(*visit)(TreeNode<T>* node)){
	if(node!=nullptr){
		visit(node);
		preOder(node->getLeft(), visit);
		preOder(node->getRight(), visit);
	}
}

template<class T>
void Tree<T>::inOder(TreeNode<T>* node, void(*visit)(TreeNode<T>* node)){
	if(node!=nullptr){
		inOder(node->getLeft(),visit);
		visit(node);
		inOder(node->getRight(),visit);
	}
}

template<class T>
void Tree<T>::postOder(TreeNode<T>* node, void(*visit)(TreeNode<T>* node)){
	if(node!=nullptr){
		postOder(node->getLeft(),visit);
		postOder(node->getRight(),visit);
		visit(node);
	}
}

template<class T>
void Tree<T>::levelOder(TreeNode<T>* node, void(*visit)(TreeNode<T>* node)){
	if(node!=nullptr){
		queue<TreeNode<T>*> q;
		q.push(node);
		while (!q.empty())
		{
			TreeNode<T>* t=q.front();
			q.pop();
			visit(t);
			if(t->getLeft()!=nullptr){
				q.push(t->getLeft());
			}
			if(t->getRight()!=nullptr){
				q.push(t->getRight());
			}
		}
	}
}

template<class T>
TreeNode<T>* Tree<T>::find(TreeNode<T>* node,T elm){
	if(node!=nullptr){
	queue<TreeNode<T>*> q;
	q.push(root);
	while (!q.empty())
	{
		TreeNode<T> *t=q.front();
		q.pop();
		if(t->getElm()==elm){
			return t;
		}
		if(t->hasLeft()){
			q.push(t->getLeft());
		}
		if(t->hasRight()){
			q.push(t->getRight());
		}
	}
	return nullptr;
	}
	return nullptr;
}

template<class T>
void Tree<T>::remove(TreeNode<T>* node){
	if(node==nullptr){
		return;
	}
	remove(node->getLeft());
	remove(node->getRight());
	delete node;
}
template<class T>
void print(TreeNode<T>* node){
	if(node!=nullptr){
		cout << node->getElm() << " ";
	}
}

#endif
// int main(){
// 	Tree<int> a;
//     a.insert(1);
//     a.insert(2);
//     a.insert(3);
// 	   a.insert(4);
//     a.insert(5);
//     a.insert(6);
//     a.insert(7);
// 	a.preOder(a.getroot(),print);
// 	cout << endl;
// 	a.inOder(a.getroot(),print);
// 	cout <<endl;
// 	a.postOder(a.getroot(),print);
// 	cout<<endl;
// 	a.levelOder(a.getroot(),print);
// }