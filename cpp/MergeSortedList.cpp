
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = nullptr;
        ListNode* temp = nullptr;
        while(l1!=nullptr && l2!=nullptr){
            if (l1->val <= l2->val){
                if (res==nullptr){
                    res=l1;
                    temp=res;
                }
                else{
                    temp -> next = l1;
                    temp = temp -> next;
                }
                l1 = l1 -> next;
            }
            else{
                if (res==nullptr){
                    res=l2;
                    temp=res;
                }
                else{
                    temp -> next = l2;
                    temp = temp -> next;
                }
                l2 = l2 -> next;
            }
        }
        if(l1!=nullptr){
            if (res==nullptr){
                res=l1;
                temp=res;
            }
            else{
                temp -> next = l1;
                temp = temp->next;
                l1 = l1 -> next;
            }
            
        }
        
        if (l2!=nullptr){
            if (res==nullptr){
                res=l2;
                temp=res;
            }
            else{
                temp -> next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
            
        }
        return res;
    }
};
