#include <iostream>
using namespace std;


struct node 
{
	int data;
	node *next;
	node(int item) : data(item), next(nullptr) {};
};


class IntLinkedList 
{
private:
	node	*m_head;
	int		 m_count;

public:
	IntLinkedList() : m_count(0) 
	{
		m_head = new node(0);
	};
	~IntLinkedList() {};

	void insert(int pos, int item);
	void remove(int pos);

	int retrieve(int pos);
	int getLength();

	bool isEmpty();
	void draw();
};

void IntLinkedList::insert(int pos, int item) 
{
	if (pos > m_count + 1)
	{
		cout << "* invalid index *" << endl;
		return;
	}

	node* temp = m_head;

	for (int count = 1; count < pos; count++)
	{
		temp = temp->next;
	}

	node *p = new node(item);
	// p->data = item;
	// temp->next = p;

	if (temp && temp->next) // if temp has next data
	{
		p->next = temp->next;
	}
	temp->next = p;

	m_count++;
	cout << "IntLinkedList::insert :: " << p->data << endl;
}

void IntLinkedList::remove(int pos) 
{
	if (pos > m_count+1) 
	{
		cout << "* invalid index *" << endl;
		return;
	}

	node* temp = m_head;
	cout << "IntLinkedList::remove :: " << endl;

	for (int count = 1; count <= pos; count++)
	{
		temp = temp->next;
	}

	node *p = temp->next;
	if (temp->next)
	{
		temp->next = temp->next->next;
		m_count--;
	}
	cout << "IntLinkedList::remove :: " << temp->data << endl;

	delete p;
}

int IntLinkedList::retrieve(int pos) 
{
	node* temp = m_head;
	cout << "IntLinkedList::retrieve :: " << endl;

	for (int count = 1; count <= pos; count++)
	{
		temp = temp->next;
	}

	cout << pos << "번째 노드 : " << temp->data << endl;
	return temp->data;
}

int IntLinkedList::getLength()
{
	cout << "IntLinkedList::getLength :: " << m_count << endl;
	return m_count; 
};

bool IntLinkedList::isEmpty()
{
	bool result = false;
	(m_count == 0) ? result = true : result = false;
	cout << "IntLinkedList::isEmpty :: " << result << endl;

	return result;
}

void IntLinkedList::draw() 
{
	node* temp = m_head;
	cout << "IntLinkedList::draw :: " << endl;

	//while (temp->next != null) 
	//{
	//	cout << m_count << "번째 노드 : " << m_head->data << endl;
	//}

	for (int count = 0; count <= m_count; count++) 
	{
		cout << count << "번째 노드 : " << temp->data << endl;
		temp = temp->next;
	}
}


int main() 
{
	IntLinkedList* linkedList = new IntLinkedList();
	linkedList->isEmpty();
	linkedList->insert(1, 5);
	linkedList->getLength();

	linkedList->insert(2, 4);
	linkedList->insert(3, 3);
	linkedList->insert(4, 2);
	linkedList->insert(5, 1);
	linkedList->insert(3, 33);
	linkedList->getLength();

	linkedList->isEmpty();
	linkedList->remove(3);
	linkedList->remove(3);
	linkedList->retrieve(4);
	linkedList->draw();

	return 0;
}