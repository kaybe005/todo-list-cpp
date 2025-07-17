#include <iostream>
#include <list>
#include <string>
#include <ctime>


class TodoItem {
private:
    int id;
    std::string description;
    bool completed;

public:
    TodoItem() : id(0), description(""), completed(false) {}
    ~TodoItem() = default;

    bool create(std::string new_description) {
        id = rand() % 100 + 1;
        description = new_description;
        return true;
    }

    int getId() { return id; }
    std::string getDescription() { return description; }
    bool isCompleted() { return completed; }

    void setCompleted(bool val) {
        completed = val;
    }
};


int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    std::string input_description;
    char input_option;
    int input_id;
    std::string version = "v0.21.7";
    std::list<TodoItem> todoItems;
    std::list<TodoItem>::iterator it;

    todoItems.clear();


    while (1) {
        system("clear");
        std::cout << "Todo List-Maker - " << version << std::endl;
        std::cout << std::endl << std::endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++) {
            std::string completed = it->isCompleted() ? "done" : "not done";
            std::cout << it->getId() << " | " << it->getDescription() << " | " << completed << std::endl;
        }

        if (todoItems.empty()) {
            std::cout << "Add your first todo item!" << std::endl;
        }

        std::cout << std::endl << std::endl;

        std::cout << "[a]dd a new Todo" << std::endl;
        std::cout << "[c]omplete a Todo" << std::endl;
        std::cout << "[q]uit"  << std::endl;
        std::cout << "choice: ";

        std::cin >> input_option;

        if (input_option == 'q' ) {
            std::cout << "Have a nice day!" << std::endl;
            break;
        }
        else if (input_option == 'a')  {
            std::cout << "Add a new Todo item: " << std::endl;
            std::cin.clear();
            std::cin.ignore();

            std::getline(std::cin,  input_description);

            TodoItem newItem;
            newItem.create(input_description);
            todoItems.push_back(newItem);
        }
        else if (input_option == 'c') {
            std::cout << "Enter the ID of the Todo to complete: " << std::endl;
            std::cin >> input_id;

            for (it = todoItems.begin(); it != todoItems.end(); it++) {
                if (input_id == it->getId()) {
                    it->setCompleted(true);
                    break;
                }
            }
        }
    }
    return 0;
}