#pragma once
#ifndef ZYSINGLELINKEDLIST_H_
#define ZYSINGLELINKEDLIST_H_
//单链表表的结构体定义
class single_linked_list {
public:
	int data;//data中存放节点数据域 默认是int
	single_linked_list* next;//指向后继结点的指针
};

#endif