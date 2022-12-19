#include <iostream>
#include <memory>
#include <string>
#include <cstdlib>

namespace data_structures
{
    namespace linked_list
    {
        bool isDigit(const std::string &s)
        {
            for (char i : s)
            {
                if (!isdigit(i))
                {
                    return false;
                }
            }

            return true;
        }

        class link
        {
        private:
            int linkValue;
            std::shared_ptr<link> next;

        public:
            // Getter
            int val()
            {
                return linkValue;
            }
            // Getter
            std::shared_ptr<link> &nextLink()
            {
                return next;
            }

            explicit link(int value = 0) : linkValue(value), next(nullptr) {}
        };

        class list
        {
        private:
            std::shared_ptr<link> head;
            std::shared_ptr<link> tail;

        public:
            list()
            {
                head = std::make_shared<link>();
                tail = nullptr;
            }

            bool isEmpty();

            void push_back(int new_elem);
            void push_front(int new_elem);
            void erase(int old_elem);
            void display();
            std::shared_ptr<link> search(int find_elem);
        };

        bool list::isEmpty()
        {
            if (tail == nullptr)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        void list::push_back(int new_elem)
        {
            if (isEmpty())
            {
                (*head).nextLink() = std::make_shared<link>(new_elem);
                tail = (*head).nextLink();
            }
            else
            {
                (*tail).nextLink() = std::make_shared<link>(new_elem);
                tail = (*tail).nextLink();
            }
        }

        void list::push_front(int new_elem)
        {
            if (isEmpty())
            {
                (*head).nextLink() = std::make_shared<link>(new_elem);
                tail = (*head).nextLink();
            }
            else
            {
                std::shared_ptr<link> temp = std::make_shared<link>(new_elem);
                (*temp).nextLink() = (*head).nextLink();
                (*head).nextLink() = temp;
            }
        }

        void list::erase(int old_elem)
        {
            if (isEmpty())
            {
                std::cout << "List is Empty!";
                return;
            }

            std::shared_ptr<link> temp = head;
            std::shared_ptr<link> tempRemove = nullptr;

            while (temp != tail && (*temp).nextLink()->val() != old_elem)
            {
                temp = (*temp).nextLink();
            }

            if (temp == tail)
            {
                std::cout << "Element not found\n";
                return;
            }

            tempRemove = (*temp).nextLink();
            (*temp).nextLink() = (*temp).nextLink()->nextLink();
            tempRemove.reset();

            if ((*temp).nextLink() == nullptr)
            {
                tail = temp;
            }

            if (head == tail)
            {
                tail = nullptr;
            }
        }

        void list::display()
        {
            if (isEmpty())
            {
                std::cout << "List is Empty!";
                return;
            }

            std::shared_ptr<link> temp = head;

            while ((*temp).nextLink() != nullptr)
            {
                std::cout << (*temp).nextLink()->val() << "\t";
                temp = (*temp).nextLink();
            }
        }

        std::shared_ptr<link> list::search(int find_elem)
        {
            if (isEmpty())
            {
                std::cout << "List is Empty!";
                return nullptr;
            }

            std::shared_ptr<link> temp = head;

            while (temp != tail && (*temp).nextLink()->val() != find_elem)
            {
                temp = (*temp).nextLink();
            }

            if (temp == tail)
            {
                std::cout << "Element not found\n";
                return nullptr;
            }

            std::cout << "Element was found\n";

            return (*temp).nextLink();
        }
    }
}

int main()
{
    data_structures::linked_list::list l;
    int choice = 0;
    int x = 0;
    std::string s;
    do
    {
        std::cout << "\n1. Insert";
        std::cout << "\n2. Delete";
        std::cout << "\n3. Search";
        std::cout << "\n4. Print";
        std::cout << "\n0. Exit";
        std::cout << "\n\nEnter you choice : ";
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            std::cout << "\nQuitting the program...\n";
            break;
        case 1:
            std::cout << "\nEnter the element to be inserted : ";
            std::cin >> s;

            if (data_structures::linked_list::isDigit(s))
            {
                x = std::stoi(s);
                l.push_back(x);
            }
            else
            {
                std::cout << "Wrong Input!\n";
            }
            break;
        case 2:
            std::cout << "\nEnter the element to be removed : ";
            std::cin >> s;
            if (data_structures::linked_list::isDigit(s))
            {
                x = std::stoi(s);
                l.erase(x);
            }
            else
            {
                std::cout << "Wrong Input!\n";
            }
            break;
        case 3:
            std::cout << "\nEnter the element to be searched : ";
            std::cin >> s;
            if (data_structures::linked_list::isDigit(s))
            {
                x = std::stoi(s);
                std::shared_ptr<data_structures::linked_list::link> found =
                    l.search(x);
            }
            else
            {
                std::cout << "Wrong Input!\n";
            }
            break;
        case 4:
            l.display();
            std::cout << "\n";
            break;
        default:
            std::cout << "Invalid Input\n"
                      << std::endl;
            break;
        }
    } while (choice != 0);
    return 0;
}