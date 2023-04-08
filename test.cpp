#include <iostream>
using namespace std; 

struct Node  //链表节点
{
	int data;
	Node* next;
};

Node* head = nullptr;  //头结点 全局变量

// 反转链表
void Reverse(Node* p) {
	if(p->next == nullptr) {
		head = p;
		return;
	}
	Reverse(p->next);
	Node* q = p->next;
	q->next = p;
	p->next = nullptr;
}
Node* Insert(Node* head, int data) {  //尾部插入
	Node* temp = new Node();
	temp->data = data;
	temp->next = nullptr;
	if (head == nullptr) head = temp;
	else {
		Node* temp1 = head;
		while (temp1->next != nullptr) temp1 = temp1->next;
		temp1->next = temp; 
	}
	return head;
}

//正序打印
void Print(Node* head) {        
	if(head == nullptr) return;
	cout << head->data << '\t';
	Print(head->next); 
}
//逆序打印
void ReversePrint(Node* head) {
	if(head == nullptr) return;
	ReversePrint(head->next);
	cout << head->data << '\t';
}
int main()
{
	//Node* head = nullptr;   //链表头节点
	head = Insert(head, 1);
	head = Insert(head, 2);
	head = Insert(head, 3);
	head = Insert(head, 4);

	Reverse(head);
	Print(head);
	ReversePrint(head);

    cout << "--------------------------------" << endl;
    system("pause");
    return 0;
}