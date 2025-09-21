void rotate(int num)//take rotate number that will be positive always
{//in counter clock wise rotation we send  n nodes to the end of in reverse order 
	if (head == nullptr)
		return;
	Node<T>* temp = head;
	int size = 1;
	while (temp->next!=nullptr)//getting size
	{
		temp = temp->next;
		size++;
	}
	num = num % size;//num=3,size=3 num will be 0 means no rotattion is required
	if (num == 0)
		return;
	Node<T>* temp1 = head;
	for (int i = 1; i < num; i++)
	{
		temp1 = temp1->next;
	}
	if (temp1 == nullptr)
		return;
	Node<T>* after = temp1->next;
	temp1->next = nullptr;
	temp->next = head;
	head = after;
	tail = temp1;
}
