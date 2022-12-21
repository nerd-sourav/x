Node* curr=*head;
       while(curr!=NULL && curr->next!=NULL)
       {
           if(curr->next->data<0)
           {
               Node* temp=curr->next;
               curr->next=curr->next->next;
               temp->next=*head;
               *head=temp;
           }
           else
             curr=curr->next;
       }
       return *head;
//Driver code
