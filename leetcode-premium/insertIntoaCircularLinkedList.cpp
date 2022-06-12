class Solution {
public:
    ListNode* insertIntoCircularLinkedList(ListNode* head, int left, int right) {



        if(head == null){
                head = new Node(insertVal, null);
                head->next = head;
                return head;
            }

            Node* cur = head;

            while(true){
                if(cur->val < cur->next.val){
                    if(cur->val<=insertVal && insertVal<=cur->next->val){
                        cur->next = new Node(insertVal, cur->next);
                        break;
                    }
                }else if(cur->val > cur->next->val){
                    if(cur->val<=insertVal || insertVal<=cur->next->val){
                        cur->next = new Node(insertVal, cur->next);
                        break;
                    }
                }else{
                    if(cur->next == head){
                        cur->next = new Node(insertVal, head);
                        break;
                    }
                }

                cur = cur->next;
            }

            return head;



        
    }
};