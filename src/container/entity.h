#pragma once
#define MAX_SIZE 256
#include <iostream>
#include <string>

using namespace std;

struct Department
{
    string id;
    string name;
    string location;
    string description;
    string symptoms;
};

struct Doctor
{
    string id;
    string name;
    string dept;
    string title;
    string goodAt;
};

struct Schedule
{
    int doctorsId[MAX_SIZE];
    int dayOfWeek;
    int period;
    int maxAppt;
    int booked;
};

struct Appointment
{
    string id;
    int patientId[MAX_SIZE];
    string doctorId;
    string date;
    int dayOfWeek;
    int period;
    int state;
};

struct Patient
{
    string id;
    string name;
    string phone;
    struct Appointment appt;
};

// 加权二部图
struct SymptomEdge
{
    int deptId;
    int weigh;
};

struct SymptomNode
{
    string name;
    SymptomEdge edges[MAX_SIZE];
};
