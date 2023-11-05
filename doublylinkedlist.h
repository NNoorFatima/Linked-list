//q1
class DoublyNode
{
	int data;
	DoublyNode* prev;
	DoublyNode* next;
public:
	DoublyNode()
	{
		data = 0;
		prev = nullptr;
		next = nullptr;
	}
	DoublyNode(int x, DoublyNode* n, DoublyNode* p)
	{
		data = x;
		next = n;
		prev = p;
	}
	int getData()
	{
		return data;
	}
	void setData(int s)
	{
		data = s;
	}
	DoublyNode* getNext()
	{
		return next;
	}
	void setNext(DoublyNode* n)
	{
		next = n;
	}
	void setPrev(DoublyNode* p)
	{
		prev = p;
	}
	DoublyNode* getPrev()
	{
		return prev;
	}
};

class DoublyLinkedList
{
	DoublyNode* head;
public:
	DoublyNode* getHead()
	{
		return head;
	}
	void setHead(DoublyNode* s)
	{
		head = s;
	}
	DoublyLinkedList()
	{
		head = nullptr;
	}
	void insert(int s)
	{
		DoublyNode* n_node = new DoublyNode(s, nullptr, nullptr);
		if (head == nullptr)
		{
			setHead(n_node);
		}
		else
		{
			DoublyNode* current = getHead();
			DoublyNode* prev = getHead();;
			while (current->getNext() != NULL)
			{
				prev = current;
				current = current->getNext();
			}
			current->setNext(n_node);
			current->getNext()->setPrev(prev);
		}
	}
	bool isEmpty()
	{
		if (getHead() == nullptr)
			return 1;
		return 0;
	}
	void insertToHead(int s)
	{
		DoublyNode* n_node = new DoublyNode(s, nullptr, nullptr);
		if (getHead() == NULL)
			setHead(n_node);
		else
		{
			n_node->setNext(head);
			getHead()->setPrev(n_node);
			setHead(n_node);
		}
	}
	//implementation is based on a liked list which has unlimited size so size can be changed
	//list can never be full
	bool search(int s)
	{
		if (head == NULL)		//head has no value list is empty 
			return 0;
		if (head->getNext() == nullptr)	//only one value 
		{
			if (head->getData() == s)
				return 1;
		}
		else
		{
			DoublyNode* c = head;
			while (c->getNext() != nullptr)
			{
				c = c->getNext();
				if (c->getData() == s)
					return 1;
			}
		}
		return 0;

	}
	void update(int x, int s)
	{
		DoublyNode* c = head;
		if (search(x) == 1)		//value is in the list
		{
			if (head->getNext() == NULL)
			{
				if (head->getData() == x)
				{
					head->setData(s);
				}
			}
			else
			{
				while (c->getNext() != NULL)
				{
					c = c->getNext();
					if (c->getData() == x)		//if value found change the val
					{
						c->setData(s);
					}
				}
			}

		}
	}
	void insertAtIndex(int s, int index)
	{
		int count = 0;
		DoublyNode* n_node = new DoublyNode(s, nullptr, nullptr);
		if (index == 0)
		{
			if (head == nullptr)
			{
				n_node->setNext(head);
				head->setPrev(n_node);
				head = n_node;
			}
		}
		else
		{
			DoublyNode* c = head;
			DoublyNode* p = head;
			while (count != index)		//loops till the count doesnt reach index
			{
				p = c;
				c = c->getNext();	//if index is not equal to count move c to next point
				count++;
			}
			p->setNext(n_node);
			n_node->setPrev(p);
			n_node->setNext(c);
		}
	}
	void print()
	{
		DoublyNode* c = head;
		while (c != NULL)
		{
			cout << c->getData() << " ";
			c = c->getNext();
		}
	}
	void deleteData(int x)
	{
		if (search(x) == 1)
		{
			if (head->getNext() == NULL)
			{
				if (head->getData() == x)
				{
					head = NULL;
				}
			}
			DoublyNode* c = head;
			DoublyNode* p = head;
			while (c->getNext() != nullptr)
			{
				p = c;
				c = c->getNext();
				if (c->getData() == x)
				{
					p->setNext(c->getNext());
					c->setPrev(p);		//10 20 30 
				}


			}

		}
	}
};

//q2 + q3
class Node
{
	int data;
	Node* next;
public:
	Node()
	{
		data = 0;
		next = nullptr;
	}
	Node(int x, Node* s)
	{
		data = x;
		next = s;
	}
	void setData(int s)
	{
		data = s;
	}
	int getData()
	{
		return data;
	}
	void setNext(Node* s)
	{
		next = s;
	}
	Node* getNext()
	{
		return next;
	}
};

class CircularLinkedList
{
	Node* head;
public:
	Node* getHead()
	{
		return head;
	}
	void setHead(Node* s)
	{
		head = s;
	}
	CircularLinkedList()
	{
		head = nullptr;
	}
	void insert(int s)
	{
		Node* n_node = new Node(s, nullptr);
		if (head == nullptr)
		{
			head = n_node;
			n_node->setNext(head);
		}
		else
		{
			Node* c = head;
			while (c->getNext() != head)
			{
				c = c->getNext();
			}
			c->setNext(n_node);
			n_node->setNext(head);
		}
	}
	bool isEmpty()
	{
		if (head == nullptr)
			return 1;
		return 0;
	}
	//size of a linked list can always be changed as we created this using pointer
	//so size is unlimited and therefore linkedlist can never be full
	bool search(int s)
	{
		Node* c = head;
		if (head != NULL && head->getData() == s)
			return 1;
		while (c->getNext() != head)
		{
			if (c->getData() == s)
				return 1;
			c = c->getNext();
		}
		return 0;
	}
	void update(int val, int n_val)
	{
		if (search(val) == 1)
		{
			Node* c = head;
			while (c->getNext() != head)
			{
				if (c->getData() == val)
				{
					c->setData(n_val);
					break;
				}
				c = c->getNext();
			}
		}
	}
	void insertAtIndex(int s, int index)
	{
		int count = 0;
		Node* c = head;
		Node* prev = head;
		Node* n_node = new Node(s, nullptr);
		if (index == 0 && head == NULL)
		{
			head = n_node;
			n_node->setNext(head);
		}
		else if (index == 0 && head != nullptr)
		{
			n_node->setNext(head);
			head = n_node;
		}
		else
		{
			while (c->getNext() != NULL && count != index)
			{
				count++;
				prev = c;
				c = c->getNext();
			}
			prev->setNext(n_node);
			n_node->setNext(c);
		}
	}
	void print()
	{
		Node* c = head->getNext();
		cout << head->getData() << " ";
		while (c != head)
		{
			cout << c->getData() << " ";
			c = c->getNext();
		}
		cout << endl;
	}
	void deleteData(int x)
	{
		Node* c = head->getNext();
		Node* p = head;
		if (search(x) == 1) // value in list
		{
			Node* tail = head;
			while (tail != head)
				tail->getNext();
			if (head->getData() == x)
			{
				head = head->getNext();
				tail->setNext(head);
			}
			while (c != head)
			{
				if (c->getData() == x)
				{
					p->setNext(c->getNext());
					break;
				}
				p = c;
				c = c->getNext();
			}
		}
	}
