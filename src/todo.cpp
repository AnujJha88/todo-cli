#include "todo.h"

Todo::Todo(){
    id=0;
    priority= Priority::MEDIUM;
    status=Status::TODO;
    created_at=time(nullptr);
    due_date=0;
    completed_at=0;
}
