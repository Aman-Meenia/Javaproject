    Node* BubbleSort(Node* head) {
        // your code here
Node * temp = head;
        while(temp!=NULL){
            Node * t = head;
            while(t->next!=NULL){
                if(t->data>t->next->data){
                    int k = t->data;
                 t->data=t->next->data;
                 t->next->data=k;
                }
                t=t->next;
            }
            temp=temp->next;
            
        }
        return head;
        
        
        
    }
