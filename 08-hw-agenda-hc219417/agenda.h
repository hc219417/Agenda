/**
 *   @file: agenda.h
 * @author: Hannah Culver
 *   @date: November 19, 2021
 *  @brief: contains the class definition
 */

#ifndef AGENDA_H
#define AGENDA_H
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>
using namespace std;

class Appointment{

public:

    //constructors
    Appointment(); //default constructor
    Appointment(string appData);

    //setters
    void setTitle(string newTitle);
    void setYear(int newYear);
    void setMonth(int newMonth);
    void setDay(int newDay);
    void setTime(int newTime); //military time
    void setDuration(int newDuration);
    void setDate(int newYear, int newMonth, int newDay);

    //getters
    string getTitle() const;
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getTime() const; //military time
    int getDuration() const;
    string getDate() const; //return a date in the format yyyy-mm-dd
    string getStandardTime();

    //helper functions
    string militaryToStandard(int time);
    int standardToMilitary(string time);
    string convertUppercase(string time);
    string trimString(string trim);
    void output(); //simple output function
    friend bool operator == (const Appointment &first, const Appointment &second);

private:

    //member variables
    string title;
    int year;
    int month;
    int day;
    int time;
    int duration;

};

#endif