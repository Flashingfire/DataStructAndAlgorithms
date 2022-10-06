#ifndef BIN_TREE_H_
#define BIN_TREE_H_
#include<iostream>
using namespace std;
//链式存储二叉树
template<class T>
 struct BTNode//使用typedef 是为了 适配C语言
{
	 T data;//节点数据
	 struct BTNode<T>* lchild;
	 struct BTNode<T>* rchild;
};
 template<class T>
 void visit(BTNode<T>* root) {
	 cout << root->data << endl;
 }

 //先序遍历(递归)
 template<class T>
 void preorder(BTNode<T>* root) {
	 if (root != nullptr) {
		 visit(root);
		 preorder(root->lchild);
		 preorder(root->rchild);
	 }
 }
 //中序遍历(递归）
 template<class T>
 void inorder(BTNode<T>* root) {
	 if (root != nullptr) {
		 inorder(root->lchild);
		 visit(root);
		 inorder(root->rchild);
	 }
 }
 //后序遍历(递归）
 template<class T>
 void postorder(BTNode<T>* root) {
	 if (root != nullptr) {
		 postorder(root->lchild);
		 visit(root);
		 postorder(root->rchild);
	 }
 }





#endif