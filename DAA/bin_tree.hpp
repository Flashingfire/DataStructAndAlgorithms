#ifndef BIN_TREE_H_
#define BIN_TREE_H_
#include<iostream>
using namespace std;
//��ʽ�洢������
template<class T>
 struct BTNode//ʹ��typedef ��Ϊ�� ����C����
{
	 T data;//�ڵ�����
	 struct BTNode<T>* lchild;
	 struct BTNode<T>* rchild;
};
 template<class T>
 void visit(BTNode<T>* root) {
	 cout << root->data << endl;
 }

 //�������(�ݹ�)
 template<class T>
 void preorder(BTNode<T>* root) {
	 if (root != nullptr) {
		 visit(root);
		 preorder(root->lchild);
		 preorder(root->rchild);
	 }
 }
 //�������(�ݹ飩
 template<class T>
 void inorder(BTNode<T>* root) {
	 if (root != nullptr) {
		 inorder(root->lchild);
		 visit(root);
		 inorder(root->rchild);
	 }
 }
 //�������(�ݹ飩
 template<class T>
 void postorder(BTNode<T>* root) {
	 if (root != nullptr) {
		 postorder(root->lchild);
		 visit(root);
		 postorder(root->rchild);
	 }
 }





#endif