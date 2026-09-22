#include <iostream>
#include <fstream>
#include <sstream>
#include "entity.h"

#define MAX_SIZE 256

using namespace std;

class DoctorArray
{
public:
    DoctorArray() : count_(0) {}
    int loadDoctors(const string &path);
    int getSize();
    Doctor *findById();
    Doctor *findByDepartment();
    Doctor *findByTitle();
    Doctor *findByGoodAt();
    bool printDoctors();

private:
    Doctor data_[MAX_SIZE] = {};
    int count_ = 0;
};

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

        istringstream iss(line);

        getline(iss, data_[count_].id, '|');
        getline(iss, data_[count_].name, '|');
        getline(iss, data_[count_].dept, '|');
        getline(iss, data_[count_].title, '|');
        getline(iss, data_[count_].goodAt, '|');

        if (count_ >= MAX_SIZE)
        {
            cout << "DOCTORS NUMBER OUT OF SIZE." << endl;
        }
        else
        {
            ++count_;
        }
    }
    cout << count_ << "DOCTORS LOADED." << endl;
}