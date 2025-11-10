#ifndef TODO_H
#define TODO_H

#include<string>
#include<vector>
#include<ctime>

enum class Priority {LOW,MEDIUM,HIGH,URGENT};
enum class Status {TODO,DOING,DONE,ARCHIVED};

struct Todo{
int id;
    std::string task;
    std::string desc;
    Priority priority;
    Status status;
    std::vector<std::string> tags;
    time_t created_at;
    time_t due;
    time_t completed_at;

    Todo();
    std::string priority_str() const;
    std::string status_str() const;
    bool is_overdue() const;

};


class TodoList{
private:
    std::vector<Todo> todos;
    int next_id;
public:
    TodoList();
    void add();
    void remove();
    void update();
    void set_status();
    void set_priority();
    void add_tags();
    void set_due_date();

    std::vector<Todo> get_all() const;
    std::vector<Todo> filter_by_status(Status status) const;

};

#endif
