#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = nullptr;
    }

    void append(int val)
    {
        Node *newnode = new Node(val);
        if (!head)
        {
            head = newnode;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void Display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node *Reverse_list()
    {
        Node *current = head, *prev = nullptr, *next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }

    void Modify(int pos, int val)
    {
        if (!head)
            return;

        Node *temp = head;
        int index = 0;
        while (temp != nullptr && index != pos)
        {
            temp = temp->next;
            index++;
        }

        if (temp)
            temp->data = val;
    }

    int Middle_list()
    {
        Node *temp = head;
        int count = 0;

        while (temp != nullptr)
        {
            temp = temp->next;
            count++;
        }

        int var = count / 2;
        temp = head;

        while (var--)
        {
            temp = temp->next;
        }

        return temp->data;
    }

    void Delete_AT_end()
    {
        if (head == nullptr)
            return;

        if (!head->next)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    void Delete_at_begin()
    {
        if (!head)
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void Search_key(int val)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                cout << "Node is Present in it" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Node not Found" << endl;
    }

    void Delete_at_pos(int pos)
    {
        if (!head)
            return;

        if (pos == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        int index = 0;
        Node *temp = head;
        while (temp->next != nullptr && index < pos - 1)
        {
            temp = temp->next;
            index++;
        }

        if (temp->next == nullptr)
            return;

        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void insert_at_Index(int pos, int val)
    {
        Node *newnode = new Node(val);
        if (!head || pos == 0)
        {
            newnode->next = head;
            head = newnode;
            return;
        }

        Node *temp = head;
        int index = 0;
        while (temp->next != nullptr && index < pos - 1)
        {
            temp = temp->next;
            index++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    int Sum_link_list(LinkedList *l1, LinkedList *l2)
    {
        int sum1 = 0, sum2 = 0;
        for (Node *temp = l1->head; temp != nullptr; temp = temp->next)
        {
            sum1 += temp->data;
        }
        for (Node *temp = l2->head; temp != nullptr; temp = temp->next)
        {
            sum2 += temp->data;
        }
        if (sum1 == sum2)
            return 0;
        else if (sum1 > sum2)
            return 1;
        else
            return -1;
    }

    void Alternative_nodes()
    {
        if (!head)
            return;
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << endl;
            if (!temp->next)
                break;
            temp = temp->next->next;
        }
    }

    void Even_Nodes()
    {
        if (!head)
            return;

        Node *temp = head;
        bool found = false;

        while (temp)
        {
            if (temp->data % 2 == 0)
            {
                cout << temp->data << endl;
                found = true;
            }
            temp = temp->next;
        }

        if (!found)
            cout << "No even numbers found." << endl;
    }

    void Second_to_second_last()
    {
        if (!head || !head->next)
            return;
        Node *temp = head;

        while (temp->next->next != nullptr)
        {
            cout << temp->next->data << endl;
            temp = temp->next;
        }
    }

    void add_if_500(int val)
    {
        if (!head)
            return;
        Node *newnode = new Node(val);
        Node *temp = head;
        int count = 0;
        while (temp != nullptr)
        {
            count += temp->data;
            if (temp->next == nullptr)
                break;
            temp = temp->next;
        }
        if (count > 500)
        {
            temp->next = newnode;
        }
    }

    void Add_even(int val)
    {
        if (!head)
            return;

        if (val % 2 == 0)
        {
            Node *temp = head;
            while (temp != nullptr)
            {
                if (temp->data % 2 == 0)
                {
                    Node *newnode = new Node(val);
                    newnode->next = temp->next;
                    temp->next = newnode;
                    temp = newnode->next;
                }
                else
                {
                    temp = temp->next;
                }
            }
        }
    }

    void Remove_if_greater()
    {
        if (!head)
            return;

        Reverse_list();

        Node *temp = head;
        Node *max_node = head;

        while (temp && temp->next)
        {
            if (temp->next->data < max_node->data)
            {
                Node *to_delete = temp->next;
                temp->next = temp->next->next;
                delete to_delete;
            }
            else
            {
                max_node = temp->next;
                temp = temp->next;
            }
        }

        Reverse_list();
    }
};

int main()
{
    LinkedList l1;
    l1.append(2);
    l1.append(12);
    l1.append(23);
    l1.append(21);
    l1.append(211);
    l1.append(2);

    cout << "Original list: ";
    l1.Display();

    l1.Remove_if_greater();

    cout << "After Remove_if_greater: ";
    l1.Display();

    return 0;
}
