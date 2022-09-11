#pragma once
#ifndef ZYDOUBLELINKEDLIST_H_
#define ZYDOUBLELINKEDLIST_H_
//双链表表的结构体定义
class double_linked_list {
public:
	int data;//data中存放节点数据域 默认是int
	double_linked_list* prior;//指向前驱节点的指针
	double_linked_list* next;//指向后继结点的指针
};

#endif