#ifndef _INC_EMPLOYEE_IMPORTANCE_
#define _INC_EMPLOYEE_IMPORTANCE_

#include "_common_all.h"

class EmployeeImportance {
private:
    // Employee info
    class Employee {
    public:
        // It's the unique ID of each node.
        // unique id of this employee
        int id;
        // the importance value of this employee
        int importance;
        // the id of direct subordinates
        vector<int> subordinates;
    };

public:
    static int main(vector<Employee*> employees, int id) {
        int importance = 0;
        Employee *root = nullptr;
        unordered_map<int, Employee*> emap;
        for (auto e : employees) {
            if (e->id == id) {
                root = e;
            }
            emap.insert(std::make_pair(e->id, e));
        }
        if (nullptr == root) {
            return 0;
        }
        walk(root, emap, importance);
        return importance;
    }

    void walk(Employee *e, unordered_map<int, Employee*> &emap, int &importance) {
        if (nullptr == e) {
            return;
        }
        importance += e->importance;
        for (auto eid : e->subordinates) {
            auto fnd = emap.find(eid);
            walk(fnd->second, emap, importance);
        }
    }
};

#endif
