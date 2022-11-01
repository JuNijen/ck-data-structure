#include <iostream>
using namespace std;


class InitList 
{
private:
	int *m_data;
	int m_count;
	int m_size;

public:
	InitList(int size) : m_size(size) { m_data = new int[size]; };	// �� ����Ʈ �����
	~InitList() { delete[] m_data; };	// ����Ʈ ���ֱ�

	void Insert(int pos, int item);	// �����͸� ����Ʈ�� �߰��ϱ�
	void Remove(int pos);			// ����Ʈ���� �����͸� �����ϱ�
	int Retrieve(int pos);				// ����Ʈ���� �����͸� �˻��ϱ�
	int GetLength() { return m_count;  };	// ����Ʈ�� ����Ǿ��ִ� ���� Ȯ���ϱ�
	bool isEmpty();						// ����Ʈ�� ����ִ��� �˻��ϱ�
	bool isFull();							// ����Ʈ�� �� á���� �˻��ϱ�
};

void InitList::Insert(int pos, int item) 
{
	if (isFull()) 
	{
		return;
	}
	else if (pos > m_count+1 || pos < 0) 
	{
		return;
	}
	else 
	{
		for (int repeat = m_count+1; repeat >= pos; repeat--) 
		{
			m_data[repeat + 1] = m_data[repeat];
		}
		m_data[pos] = item;
		m_count++;
	}
}

void InitList::Remove(int pos) 
{
	if (isEmpty()) 
	{
		return;
	}
	else if (pos > m_count-1 || pos < 0) 
	{
		return;
	}
	else 
	{
		for (int repeat = pos; repeat < m_count; repeat++)
		{
			m_data[repeat] = m_data[repeat + 1];
			m_count--;
		}
	}
}

int InitList::Retrieve(int pos) 
{
	int result = -1;

	if (!(pos > m_count + 1 || pos < 0))
	{
		result = -1;
	}
	else 
	{
		result = m_data[pos];
	}

	return result;
}

bool InitList::isEmpty() 
{
	bool isEmpty = false;

	if (m_count == 0)
	{
		isEmpty = true;
	}

	return isEmpty;
}

bool InitList::isFull() 
{
	bool isFull = false;

	if (m_count == m_size) 
	{
		isFull = true;
	}

	return isFull;
}


int main()
{
	InitList *list = new InitList(5);
	cout << "list->isEmpty() // count : 0 // " << list->isEmpty() << endl;
	cout << "list->isFull() // count : 0 // " << list->isFull() << endl;

	list->Insert(0, 3);
	list->Insert(1, 17);
	cout << "list->isEmpty() // count : 2 // " << list->isEmpty() << endl;
	list->Insert(2, 22);
	list->Insert(3, 31);
	list->Insert(4, 43);

	cout << "list->isFull() // count : 5 // " << list->isFull() << endl;

	list->Remove(2);
	cout << "list->Retrieve(3) " << list->Retrieve(3) << endl;
	cout << "list->GetLength() " << list->GetLength() << endl;

	return 0;
}