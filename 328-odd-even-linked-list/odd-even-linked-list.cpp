class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL || head->next == NULL)   
            return head;

        ListNode* Evenhead = head->next;
        ListNode* even = head->next;
        ListNode* odd = head;

        while((even != NULL && even->next != NULL) &&
              (odd != NULL && odd->next != NULL)){
                   odd->next = even->next;
                   odd = odd->next;
                   even->next = odd->next;
                   even = even->next;;
        }


        odd->next = Evenhead;

        return head;
    }
};