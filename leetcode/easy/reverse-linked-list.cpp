#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ListNode* reverseList(ListNode* head) {
    if (head == nullptr) return head;
    stack<int> tmp;
    while (head != nullptr) {
        tmp.push(head->val);
        head = head->next;
    }
    ListNode *ans_head = new ListNode();
    ListNode *ans = ans_head;
    while (tmp.size() > 1) {
        ans->val = tmp.top();
        tmp.pop();
        ans->next = new ListNode();
        ans = ans->next;
    }
    ans->val = tmp.top();
    return ans_head;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ListNode *head;
	cout << reserveList(head) << endl;

	return 0;
}

