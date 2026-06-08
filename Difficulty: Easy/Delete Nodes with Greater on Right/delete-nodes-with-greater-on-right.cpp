/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
    private:
    Node* reverseList(Node* head){
        Node* prev=nullptr;
        Node* curr=head;
        Node* next=nullptr;
        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
  public:
    Node *compute(Node *head) {
        if(!head || !head->next)
        return head;
        head=reverseList(head);
        Node* curr=head;
        Node* maxNode = head;
        while(curr!=nullptr && curr->next != nullptr){
            if(curr->next->data<maxNode->data){
                Node* temp=curr->next;
                curr->next=temp->next;
                delete temp;
            }
            else{
                curr=curr->next;
                maxNode=curr;
            }
        }
        return reverseList(head);
        
    }
};