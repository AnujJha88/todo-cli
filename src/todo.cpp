#include "todo.h"

Todo::Todo(){
    id=0;
    priority= Priority::MEDIUM;
    status=Status::TODO;
    created_at=time(nullptr);
    due_date=0;
    completed_at=0;
}

std::string Todo::priority_str() const{
    switch(priority){
        case Priority::LOW: return "Low";
        case Priority::MEDIUM: return "Medium";
        case Priority::HIGH: return "High";
        case Priority::URGENT: return "Urgent";
        default : return "unknown";
    }
}

std::string Todo::status_str() const{
    switch(status){
        case Status::TODO: return "TODO";
        case Status::DOING: return "DOING";
        case Status::DONE: return "DONE";
        case Status::ARCHIVED: return "ARCHIVED";
        default : return "unknown";
    }
}

bool  Todo::is_overdue() const{
    return due_date>0 && due_date<time(nullptr)&& status!=Status::DONE;
}

TodoList::TodoList(){
    next_id=1;

}
