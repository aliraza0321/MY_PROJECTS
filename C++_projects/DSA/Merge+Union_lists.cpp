 void unionSet(SortedSet<T>* obj)
{
	

	Node<T>* temp1, * temp2;
	temp1 = head;
	temp2 = obj->head;
	while (temp2 != nullptr)
	{
		insert(temp2->data);
		temp2 = temp2->next;
	}
}
void insert(T d)
{
	//insert  in case of empty 
	Node<T>* newNode = new Node<T>(d);
	if (head == nullptr)
	{
		head = tail = newNode;
			return;
	}
	if (d <= head->data)//insert at start
	{
		if (d == head->data)
		{
			return;//duplicate value
		}
		newNode->next = head;
		head = newNode;
		return;
	}
	if (d >= tail->data)//insert at last
	{
		if (d == tail->data)//same value at last
			return;
		tail->next = newNode;
		tail = newNode;
		return;
	}
	//in middle insertion
	Node<T>* temp = head;
	while (temp->next != nullptr && temp->next->data < d)
	{
		temp = temp->next;
	}
	if (temp->next != nullptr && temp->next->data == d)
		return;
	newNode->next = temp->next;
	temp->next = newNode;
	
}
