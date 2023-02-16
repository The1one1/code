// using priority queue

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<pair<int, ListNode *>> pq;
        int k = lists.size();

        for (int i = 0; i < k; i++)
        {
            if (lists[i] not_eq nullptr)
                pq.push({-1 * (lists[i]->val), lists[i]});
        }

        if (pq.size() == 0)
            return nullptr;

        ListNode *head = pq.top().second;
        ListNode *node = head;
        pq.pop();

        if (head->next != nullptr)
        {
            pq.push({-1 * (head->next->val), head->next});
        }

        while (not pq.empty())
        {

            ListNode *temp = pq.top().second;
            node = node->next = temp;
            pq.pop();

            if (temp->next not_eq nullptr)
            {
                temp = temp->next;
                pq.push({-1 * (temp->val), temp});
            }
        }
        node->next = nullptr;
        return head;
    }
};

// using sets

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        set<pair<int, ListNode *>> pq;
        int k = lists.size();

        for (int i = 0; i < k; i++)
        {
            if (lists[i] not_eq nullptr)
                pq.insert({-1 * (lists[i]->val), lists[i]});
        }

        if (pq.size() == 0)
            return nullptr;

        ListNode *head = (*--pq.end()).second;
        ListNode *node = head;
        pq.erase(--pq.end());

        if (head->next != nullptr) {
            pq.insert({-1 * (head->next->val), head->next});
        }

        while (not pq.empty())
        {
            auto it = --pq.end();
            ListNode *temp = (*it).second;
            node = node->next = temp;
            pq.erase(it);
            if (temp->next not_eq nullptr)
            {
                temp = temp->next;
                pq.insert({-1 * (temp->val), temp});
            }
        }
        node->next = nullptr;
        return head;
    }
};

// harsh

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<pair<int, ListNode *>> pq1, pq2;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                pq1.push({-1 * lists[i]->val, lists[i]});
            }
        }

        ListNode *h = NULL, *t = NULL;

        while (!pq1.empty()) {
            if (h == t && h == NULL) {
                ListNode *x = pq1.top().second;
                pq1.pop();
                if (x != NULL && x->next != NULL) {
                    pq1.push({-1 * (x->next->val), x->next});
                }
                h = x;
                t = h;
            }

            else {
                ListNode *x = pq1.top().second;
                pq1.pop();
                if (x != NULL && x->next != NULL) {
                    pq1.push({-1 * (x->next->val), x->next});
                }
                t->next = x;
                t = t->next;
            }
        }

        if (t != NULL) {
            t->next = NULL;
            t = NULL;
        }
        return h;
    }
};