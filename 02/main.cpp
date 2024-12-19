#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    if (head == nullptr) {
        return false; // Пустой список не содержит цикл
    }

    ListNode *slow = head; // Указатель черепахи
    ListNode *fast = head; // Указатель зайца

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next; // Перемещаем черепаху на один узел
        fast = fast->next->next; // Перемещаем зайца на два узла

        if (slow == fast) {
            return true; // Цикл найден
        }
    }

    return false; // Цикла нет
}

// Пример использования
int main() {
    // Создаем пример списка с циклом
    ListNode *head = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Создаем цикл

    if (hasCycle(head)) {
        std::cout << "The linked list has a cycle." << std::endl;
    } else {
        std::cout << "The linked list does not have a cycle." << std::endl;
    }

    // Освобождаем память (в данном случае не получится освободить память из-за цикла)
    // В реальных приложениях следует быть осторожным с освобождением памяти в циклических списках.

    return 0;
}
