/*
Node structure:

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
public:

    // Reverse a linked list
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;

        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    // Function to add two numbers represented by linked lists
    Node* addTwoLists(Node* num1, Node* num2) {

        // Remove leading zeros safely
        while (num1 && num1->data == 0) num1 = num1->next;
        while (num2 && num2->data == 0) num2 = num2->next;

        // If list becomes NULL, treat it as 0
        if (!num1) num1 = new Node(0);
        if (!num2) num2 = new Node(0);

        // Reverse both lists
        num1 = reverse(num1);
        num2 = reverse(num2);

        Node* dummy = new Node(-1);
        Node* curr = dummy;

        int carry = 0;

        // Add until both lists and carry are exhausted
        while (num1 || num2 || carry) {
            int sum = carry;

            if (num1) {
                sum += num1->data;
                num1 = num1->next;
            }

            if (num2) {
                sum += num2->data;
                num2 = num2->next;
            }

            curr->next = new Node(sum % 10);
            curr = curr->next;
            carry = sum / 10;
        }

        // Reverse result to restore correct order
        return reverse(dummy->next);
    }
};
