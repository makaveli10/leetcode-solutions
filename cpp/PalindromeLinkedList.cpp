#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head==nullptr || head-> next == nullptr)
            return true;
        
        // Reach the midpoint also reverse half of the list
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            
            ListNode* temp = slow->next;
            slow -> next = prev;
            prev = slow;
            slow = temp;
        }
        ListNode* t = prev;
        while(t !=nullptr){
            std::cout << t->val << " ";
            t = t -> next;
        }
        if (fast == nullptr){
            //even
            while(slow != nullptr && prev != nullptr){
                if (slow-> val != prev -> val)
                    return false;
                slow = slow -> next;
                prev = prev -> next;
            }
            return true;
        }
        else{
            slow = slow -> next;
             while(slow != nullptr && prev != nullptr){
                if (slow-> val != prev -> val)
                    return false;
                slow = slow -> next;
                prev = prev -> next;
            }
            return true;
            
        }
    }
};
