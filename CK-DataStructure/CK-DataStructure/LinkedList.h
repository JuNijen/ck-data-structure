#pragma once
#include "GameObject.h"

struct node {
	GameObject* data;
	node * next;
};

class CLinkedList
{
	node * m_head;
	node * m_tail;
	int m_count;

public:
	CLinkedList();
	~CLinkedList();

	void insert(int pos, GameObject* data);
	void append(GameObject* data);
	void remove(int pos);
	GameObject* retrieve(int pos);
	bool isEmpty() { return m_head == nullptr; }

	void update();
	void draw();
};

