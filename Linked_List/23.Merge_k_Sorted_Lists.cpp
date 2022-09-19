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
// Linked List, Divide and ConquerHeap, (Priority Queue), Merge Sort

class Solution {
public:
    class my_data{    //My defined data
        public:
        ListNode *t;
        int size;
    };
    ListNode *mergeTwoList(ListNode *l1, ListNode *l2){ //merging two list
    
        if (l1 == NULL && l2 == NULL) return NULL;
        else if(l1 == NULL) return l2;
        else if(l2 == NULL) return l1;
        if (l1->val < l2->val){
            ListNode *temp = l1;
            temp->next = mergeTwoList(l1->next,l2);
            return temp;
        }
        else{
            ListNode *temp = l2;
            temp->next = mergeTwoList(l1,l2->next);
            return temp;
        }
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0){
            return NULL;
        }
        vector<int> list_length;  //store the size of each list
        for (auto list:lists){
            int cnt=0;
            while(list != NULL){
                cnt++;
                list = list->next;
            }
            list_length.push_back(cnt);
        }
        auto comp = [] (my_data &a, my_data &b) -> bool { return a.size > b.size; };   //lambda function for comapring size based queue
        std::priority_queue<my_data,std::vector<my_data>, decltype(comp) > pq (comp);
        
        int i=0;
        for(auto l:lists){
            pq.push({l,list_length[i]});  // pushing data into the priority queue (small size will merge first)
            i++;
        }
        while(!pq.empty() and pq.size() > 1){ 
            my_data t1 = pq.top();
            pq.pop();                   // poping top 2 element
            my_data t2 = pq.top();
            
            pq.pop();
            int x = t1.size + t2.size;  //  sum of their value 
            ListNode *srt = mergeTwoList(t1.t,t2.t); // merging 2 list having small size
            pq.push({srt, x}); // now pushing the merged list with size t1+t2
        }
        
        return pq.top().t;
    }
};
// https://leetcode.com/problems/merge-k-sorted-lists/
