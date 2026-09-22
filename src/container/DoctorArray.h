#include <iostream>
#include <fstream>
#include <sstream>
#include "entity.h"

#define MAX_SIZE 256

using namespace std;

// 类定义
class DoctorArray
{
public:
    DoctorArray() : count_(0) {}
    int loadDoctors(const string &path);
    int getSize();
    Doctor *findById(string id);
    Doctor *findByDepartment(string dept);
    Doctor *findByTitle(string title);
    Doctor *findByGoodAt(string goodAt);
    int printDoctors();

private:
    Doctor data_[MAX_SIZE] = {};
    int count_ = 0;
};

// 加载医生列表
int DoctorArray::loadDoctors(const string &path)
{
    cout << "LOADING DOCTORS..." << endl;

    ifstream fin(path);
    if (!fin.is_open())
    {
        cout << "CAN NOT OPEN" << path << endl;
        return -1;
    }

    string line = "";

    while (getline(fin, line))
    {
        if (line.empty() || line[0] == '#')
        {
            continue;
        }
        if (count_ >= MAX_SIZE)
        {
            cout << "DOCTORS NUMBER OUT OF SIZE." << endl;
        }

        istringstream iss(line);

        getline(iss, data_[count_].id, '|');
        getline(iss, data_[count_].name, '|');
        getline(iss, data_[count_].dept, '|');
        getline(iss, data_[count_].title, '|');
        getline(iss, data_[count_].goodAt, '|');

        ++count_;
    }
    cout << count_ << "DOCTORS LOADED." << endl;
    return count_;
}

Doctor *DoctorArray::findById(string id)
{
    cout << "FINDING DOCTORS, ID = " << id << endl;
    for (int i = 0; i < count_; ++i)
    {
        if (data_[i].id == id)
        {
            cout << "DOCTORS HAS BEEN FOUND : " << data_[i].name << endl;
            return &data_[i];
        }
    }
    cout << "DOCTOR NOT FOUND." << endl;
    return nullptr;
}

Doctor *DoctorArray::findByDepartment(string department)
{
    cout << "FINDING DOCTORS, DEPARTMENT = " << department << endl;
    for (int i = 0; i < count_; ++i)
    {
        if (data_[i].dept == department)
        {
            cout << "DOCTORS HAS BEEN FOUND : " << data_[i].name << endl;
            return &data_[i];
        }
    }
    cout << "DOCTOR NOT FOUND." << endl;
    return nullptr;
}

Doctor *DoctorArray::findByTitle(string title)
{
    cout << "FINDING DOCTORS, TITLE = " << title << endl;
    for (int i = 0; i < count_; ++i)
    {
        if (data_[i].title == title)
        {
            cout << "DOCTORS HAS BEEN FOUND : " << data_[i].name << endl;
            return &data_[i];
        }
    }
    cout << "DOCTOR NOT FOUND." << endl;
    return nullptr;
}

Doctor *DoctorArray::findByGoodAt(string goodAt)
{
    cout << "FINDING DOCTORS GOOD AT : " << goodAt << endl;
    for (int i = 0; i < count_; ++i)
    {
        if (data_[i].goodAt == goodAt)
        {
            cout << "DOCTORS HAS BEEN FOUND : " << data_[i].name << endl;
            return &data_[i];
        }
    }
    cout << "DOCTOR NOT FOUND." << endl;
    return nullptr;
}
