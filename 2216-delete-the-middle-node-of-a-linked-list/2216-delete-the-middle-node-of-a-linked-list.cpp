class Solution {
public:
    // Helper function to find and delete the middle node
    int deleteMiddleHelper(ListNode* &current, int length, int count) {
        // Base case: If we reach the end of the list, return 0
        if (current == nullptr) {
            return 0;
        }

        // Recurse for the next node
        int index = deleteMiddleHelper(current->next, length, count + 1);

        // If the current node is the one before the middle node
        if (count == length / 2 - 1) {
            current->next = current->next->next; // Skip the middle node
        }

        return index + 1;
    }

    ListNode* deleteMiddle(ListNode* head) {
        // If the list is empty or has only one node, return NULL
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        // Find the length of the list by recursively traversing it
        int length = deleteMiddleHelper(head, 0, 0);

        // Delete the middle node in the second pass
        deleteMiddleHelper(head, length, 0);

        return head;
    }
};
