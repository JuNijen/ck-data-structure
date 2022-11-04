#include "LarvaGameLinkedList.h"
#include <iostream>
using namespace std;


CLinkedList::CLinkedList() : m_head(nullptr), m_tail(nullptr), m_count(0)
{
}


CLinkedList::~CLinkedList()
{
}

void CLinkedList::insert(int pos, GameObject* data)
{
	if (pos < 0 || pos > m_count)
		return;

	node * inData = new node;
	node * temp = m_head;
	inData->data = data;
	if (pos == 0) {
		inData->next = m_head;
		m_head = inData;
		if(m_count == 0)
			m_tail = inData;
	}
	else {
		for (int i = 0; i < pos - 1; i++)
			temp = temp->next;
		inData->next = temp->next;
		temp->next = inData;
		if (pos == m_count)
			m_tail = inData;
	}
	m_count++;
}

void CLinkedList::append(GameObject* data)
{
	node *inData = new node;
	inData->data = data;
	inData->next = nullptr;
	if (m_tail) {
		m_tail->next = inData;
		m_tail = inData;
	}
	else {
		m_head = inData;
		m_tail = inData;
	}
	m_count++;
}

void CLinkedList::remove(int pos)
{
	if (pos < 0 || pos > m_count-1 || !m_head)
		return;
	node *delData;
	node *temp = m_head;
	if (pos == 0) {
		delData = m_head;
		m_head = m_head->next;
		if (m_count == 1)
			m_tail = m_head;
	}
	else {
		for (int i = 0; i < pos - 1; i++)
			temp = temp->next;
		delData = temp->next;
		temp->next = delData->next;
		if (pos == m_count - 1)
			m_tail = temp;
	}
	delete delData;
	m_count--;
}

GameObject* CLinkedList::retrieve(int pos)
{
	if (pos < 0 || pos > m_count-1 || !m_head)
		return nullptr;
	node *temp = m_head;
	for (int i = 0; i < pos; i++)
		temp = temp->next;
	return temp->data;
}

void CLinkedList::update()
{
	node* curNode = m_head;
	for (int count = 0; count < m_count; count++) 
	{
		curNode->data->Update();
		curNode = curNode->next;
	}
}

void CLinkedList::draw()
{
	node *temp = m_head;
	while(temp != nullptr) {
		temp->data->Draw();
		temp = temp->next;
	}
	cout << endl;
}
