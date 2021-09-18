//link: https://leetcode.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


int getCount(ListNode* l){
    
    int count = 0;
    
    ListNode* temp = l;
    
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    
    return count;
}


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        int carry = 0;

         ListNode* lgList = l1;
         ListNode* smList = l2;
        
        if(getCount(l2) > getCount(l1)){
            lgList = l2;
            smList = l1;
        }
        
        ListNode* sumHead = new ListNode();
        ListNode* currentDigit = sumHead;
               
        while(lgList != NULL){   
            
           int n1 = lgList->val;
           int n2 = 0;
            
            if(smList != NULL){
                n2 = smList->val;
                smList = smList->next;
            }
            
            int sm = n1 + n2 + carry;
            
            if(sm > 9){
                
             carry = sm / 10;
             int val = sm % 10;
             currentDigit->val = val;
 
            } else {        
              currentDigit->val = sm;   
                carry = 0;
            }
            
    
            lgList = lgList->next;
            
            if(lgList != NULL){
               ListNode* temp =  new ListNode();
               currentDigit->next = temp;
               currentDigit = currentDigit->next;
            } else {
                if(carry > 0){
                 ListNode* temp =  new ListNode();
                 temp->val = carry;
                 currentDigit->next = temp;
                 currentDigit = currentDigit->next;
                }
            }
               
        }
        return sumHead;
          
    }
};

