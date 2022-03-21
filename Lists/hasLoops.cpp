

// Complete the has_cycle function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) {
    if (head == nullptr)
    {
        return false;
    }
    std::set<SinglyLinkedListNode*> set ;
    while( head != nullptr)
    {
        if(set.find(head )!= set.end())
        {
            return true;
        }
        set.emplace(head);
        head = head->next;
    }
    return false;
}


