#include "DoctorArray.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

DoctorArray::DoctorArray() : count_(0) {}

int DoctorArray::loadDoctors(const string &path)
{
    cout << "LOADING DOCTORS..." << endl;

    ifstream fin(path);
    if (!fin.is_open())
    {
        cout << "CAN NOT OPEN " << path << endl;
        return -1;
    }

    string line;

    while (getline(fin, line))
    {
        if (line.empty() || line[0] == '#')
        {
            continue;
        }

        if (count_ >= kMaxDoctor)
        {
            cout << "DOCTORS NUMBER OUT OF SIZE." << endl;
            break;
        }

        istringstream iss(line);
        getline(iss, data_[count_].id, '|');
        getline(iss, data_[count_].name, '|');
        getline(iss, data_[count_].dept, '|');
        getline(iss, data_[count_].title, '|');
        getline(iss, data_[count_].goodAt, '|');

        ++count_;
    }

    cout << count_ << " DOCTORS LOADED." << endl;
    return count_;
}

int DoctorArray::getSize() const
{
    return count_;
}

int DoctorArray::findById(const string &id, Doctor *out, int cap)
{
    int found = 0;

    for (int i = 0; i < count_; ++i)
    {
        if (data_[i].id == id)
        {
            if (found >= cap)
                break;
            out[found] = data_[i];
            ++found;
        }
    }

    cout << found << " DOCTOR WAS FOUND." << endl;
    return found;
}

int DoctorArray::findByDepartment(const string &dept, Doctor *out, int cap)
{
    int found = 0;

    for (int i = 0; i < count_; ++i)
    {
        if (data_[i].dept == dept)
        {
            if (found >= cap)
                break;
            out[found] = data_[i];
            ++found;
        }
    }

    cout << found << " DOCTORS FOUND." << endl;
    return found;
}

int DoctorArray::findByTitle(const string &title, Doctor *out, int cap)
{
    int found = 0;

    for (int i = 0; i < count_; ++i)
    {
        if (data_[i].title == title)
        {
            if (found >= cap)
                break;
            out[found] = data_[i];
            ++found;
        }
    }

    cout << found << " DOCTORS FOUND." << endl;
    return found;
}

int DoctorArray::findByGoodAt(const string &goodAt, Doctor *out, int cap)
{
    int found = 0;

    for (int i = 0; i < count_; ++i)
    {
        if (data_[i].goodAt == goodAt)
        {
            if (found >= cap)
                break;
            out[found] = data_[i];
            ++found;
        }
    }

    cout << found << " DOCTORS FOUND." << endl;
    return found;
}

int DoctorArray::printDoctors() const
{
    for (int i = 0; i < count_; ++i)
    {
        cout << "  " << data_[i].id << "  "
             << data_[i].name << "  "
             << data_[i].dept << "  "
             << data_[i].title << "  "
             << data_[i].goodAt << endl;
    }
    return count_;
}
