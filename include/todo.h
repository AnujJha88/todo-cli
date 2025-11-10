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
    //constructor
    TodoList();
    //creat+update+delete functions
    void add(const std::string &name, const std::string &desc="",Priority priority=Priority::MEDIUM,Status status=Status::TODO, const std::vector<std::string> tags={});
    void remove(int id);
    void update(int id, const std::string &name, const std::string &desc="", const std::vector<std::string> tags={});
    void set_status(int id,Status status);
    void set_priority(int id,Priority priority);
    void add_tags(int id,const std::vector<std::string> &tags);
    void set_due_date(int id,time_t due_date);
    //fetchers
    std::vector<Todo> get_all() const;
    std::vector<Todo> filter_by_status(Status status) const;
    std::vector<Todo> filter_by_priority(Priority priority) const;
    std::vector<Todo> filter_by_tags(std::vector<std::string> tags) const;
    std::vector<Todo> filter_by_date(time_t date) const;
    std::vector<Todo> search(const std::string &query) const;
    std::vector<Todo> get_overdue() const;
    Todo* find_by_id( int id);

    //sort
    void sort_priority();
    void sort_by_created();
    void sort_by_due();

    //QoL utils
    size_t size() const{return todos.size();}
    int get_next_id(){return next_id;}
};

#endif
