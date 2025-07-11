/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // Your code here
        // Node* rotate(Node* head, int k) {
    // Handle edge cases: empty list or no rotation needed
    if (head == NULL || k == 0) return head;

    // Step 1: Calculate the length of the list
    Node* tail = head;
    int len = 1;
    while (tail->next != NULL) {
        tail = tail->next;
        len++;
    }

    // Step 2: Optimize k (if k >= len)
    k = k % len;
    if (k == 0) return head;  // No rotation needed

    // Step 3: Link the tail to the head to make it circular
    tail->next = head;

    // Step 4: Find the new tail (kth node from the start)
    Node* newTail = head;
    for (int i = 1; i < k; i++) {
        newTail = newTail->next;
    }

    // Step 5: Update the head and break the cycle
    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}
};