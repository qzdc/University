#include<memory>
#include<iostream>

template <class T>
class Queue
{
public:
	typedef size_t size_type;//此处添加size_type的类型定义

	Queue() :head(NULL), rear(alloc.allocate(1)) { 
		std::cout << "\ndefault constructor called"; 
	}	//default constructor
	Queue(const Queue& q) :head(NULL) { copyLink(q.head); }	//copy constructor
	~Queue() { 
		freeLink(); 
		std::cout << "\ndestructor called.";
	}		//destructor

	Queue& operator=(const Queue&);		//赋值运算符的重载定义

	bool enQueue(T);	//进队
	bool deQueue();		//出队

	T front()const { return head->val; }	//返回队首元素的值
	T back()const { return rear->val; }	//返回队尾元素的值

	size_type size()const;		//此处使用前面定义的类型size_type
	bool isEmpty(void) const { return size() == 0; }	//判断队列是否为空
	bool isFull(void) const { return size() == 50; }	//判断队列是否已满

	void output(void)const;		//输出队列
private:
	struct node{
		T val;
		node *next;
	}*head, *rear;	//队列首尾元素指针

	std::allocator<node> alloc;//内存管理函数
	void copyLink(node *);	//复制已有链表
	void freeLink();		//释放已有链表所占空间
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
		//如果直接调用copy会在控制台上打印copy constructor called.
		//与示例不符，就control大法了。。。
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
	//如果是空的queue，那么头指针就是空的，所以it也是。
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
