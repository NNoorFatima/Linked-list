void findloop(Node* ptr)
{
  Node* slow=ptr;
  Node* fast=ptr;
  while(slow!=nullptr && fast!=nullptr && fast->next !=nullptr)
  {
    if(slow==fast)
      break;
    slow=slow->next;
    fast= fast->next->next;
  }
  if(fast==slow)
  {
    fast=head;    
    while(fast!=slow)
    {
      fast=fast->next;
      slow=slow->next;
    }
      slow->next=nullptr;

  }


}
