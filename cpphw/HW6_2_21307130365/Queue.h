#include<memory>
#include<iostream>

template <class T>
class Queue
{
public:
	typedef size_t size_type;//�˴����size_type�����Ͷ���

	Queue() :head(NULL), rear(alloc.allocate(1)) { 
		std::cout << "\ndefault constructor called"; 
	}	//default constructor
	Queue(const Queue& q) :head(NULL) { copyLink(q.head); }	//copy constructor
	~Queue() { 
		freeLink(); 
		std::cout << "\ndestructor called.";
	}		//destructor

	Queue& operator=(const Queue&);		//��ֵ����������ض���

	bool enQueue(T);	//����
	bool deQueue();		//����

	T front()const { return head->val; }	//���ض���Ԫ�ص�ֵ
	T back()const { return rear->val; }	//���ض�βԪ�ص�ֵ

	size_type size()const;		//�˴�ʹ��ǰ�涨�������size_type
	bool isEmpty(void) const { return size() == 0; }	//�ж϶����Ƿ�Ϊ��
	bool isFull(void) const { return size() == 50; }	//�ж϶����Ƿ�����

	void output(void)const;		//�������
private:
	struct node{
		T val;
		node *next;
	}*head, *rear;	//������βԪ��ָ��

	std::allocator<node> alloc;//�ڴ������
	void copyLink(node *);	//������������
	void freeLink();		//�ͷ�����������ռ�ռ�
};

template <class T>
bool Queue<T>::enQueue(T t) {
	node newnode = { t, NULL };
	node* pnewnode = alloc.allocate(1);
	if (isEmpty()) {
		alloc.construct(rear, newnode);
		head = rear;
	}
	else {
		alloc.construct(pnewnode, newnode);
		rear->next = pnewnode;
		rear = pnewnode;
	}
	return isFull();
}
template <class T>
bool Queue<T>::deQueue() {
	node* newhead = head->next;
	alloc.destroy(head);
	alloc.deallocate(head, 1);
	head = newhead;
	return isEmpty();
}
template <class T>
void Queue<T>::output() const {
	node* p = head;
	std::cout << '\n';
	for (int i = 0; p; i++) {
		std::cout << (*p).val << ' ';
		if ((i + 1) % 10 == 0)
			std::cout << '\n';
		p = p->next;
	}
}
template <class T>
Queue<T>& Queue<T>::operator=(const Queue& qfrom) {
	std::cout << "\n\noperator =() called";
	if (&qfrom != this) {
		freeLink();
		//copyLink(qfrom.head);
		//���ֱ�ӵ���copy���ڿ���̨�ϴ�ӡcopy constructor called.
		//��ʾ����������control���ˡ�����
		node* newnode = qfrom.head;
		if (newnode != head) {
			while (newnode) {
				if (size() == 0)
					head = rear = alloc.allocate(1);
				alloc.construct(rear, *newnode);
				if (rear->next) {
					rear->next = alloc.allocate(1);
					rear = rear->next;
				}
				newnode = newnode->next;
			}
		}
	}
	return *this;
}
template <class T>
void Queue<T>::copyLink(node* newnode) {
	freeLink();
	std::cout << "\ncopy constructor called.";
	if (newnode != head) {
		while (newnode) {
			if (size() == 0)
				head = rear = alloc.allocate(1);
			alloc.construct(rear, *newnode);
			if (rear->next) {
				rear->next = alloc.allocate(1);
				rear = rear->next;
			}
			newnode = newnode->next;
		}
	}
}
template <class T>
void Queue<T>::freeLink() {
	node* it = head;
	//����ǿյ�queue����ôͷָ����ǿյģ�����itҲ�ǡ�
	while (it) {
		node* it_next = it->next;
		alloc.destroy(it);
		alloc.deallocate(it, 1);
		it = it_next;
	}
	head = rear = NULL;
}
template <class T>
size_t Queue<T>::size() const{
	if (!head)
		return 0;
	else {
		int s = 0;
		for (node* p = head; p != rear; s++)
			p = p->next;
		return s + 1;
	}
}
