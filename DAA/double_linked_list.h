#pragma once
#ifndef ZYDOUBLELINKEDLIST_H_
#define ZYDOUBLELINKEDLIST_H_
//˫�����Ľṹ�嶨��
class double_linked_list {
public:
	int data;//data�д�Žڵ������� Ĭ����int
	double_linked_list* prior;//ָ��ǰ���ڵ��ָ��
	double_linked_list* next;//ָ���̽���ָ��
};

#endif