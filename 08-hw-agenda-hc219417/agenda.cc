/**
 *   @file: agenda.cc
 * @author: Hannah Culver
 *   @date: November 19, 2021
 *  @brief: contains the class implementation (all the functions)
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>
#include "agenda.h"
using namespace std;

/**
 * bool operator == checks if two appointments are the same
 * @param first first appointment
 * @param second second appointment
 * @return true if the appointments are the same
 */
bool operator == (const Appointment &first, const Appointment &second);

/**
 * convertUppercase - converts a string to uppercase
 * @param time string to be converted to uppercase
 * @return uppercase string
 */
string convertUppercase(string time);

/**
 * trimString - trim a string by removing the leading and trailing white spaces
 * @param trim string to be trimmed
 * @return trimmed string
 */
string trimString(string trim);

Appointment::Appointment() //default constructor
{
    title = "N/A";
    year = 1;
    month = 1;
    day = 1;
    time = 0;
    duration = 1;
}

Appointment::Appointment(string appData)
{
    int first_vertical_bar_location = appData.find("|");
    int second_vertical_bar_location = appData.find("|",first_vertical_bar_location + 1);
    int third_vertical_bar_location = appData.find("|",second_vertical_bar_location + 1);
    int fourth_vertical_bar_location = appData.find("|",third_vertical_bar_location + 1);
    int fifth_vertical_bar_location = appData.find("|",fourth_vertical_bar_location + 1);

    title = appData.substr(0,first_vertical_bar_location);
    string string_year = appData.substr(first_vertical_bar_location + 1,second_vertical_bar_location - (first_vertical_bar_location + 1));
    string string_month = appData.substr(second_vertical_bar_location + 1,third_vertical_bar_location - (second_vertical_bar_location + 1));
    string string_day = appData.substr(third_vertical_bar_location + 1,fourth_vertical_bar_location - (third_vertical_bar_location + 1));
    string standard_time = appData.substr(fourth_vertical_bar_location + 1,fifth_vertical_bar_location - (fourth_vertical_bar_location + 1));
    string string_duration = appData.substr(fifth_vertical_bar_location + 1);

    title = trimString(title);

    string_year = trimString(string_year);
    year = stoi(string_year);

    string_month = trimString(string_month);
    month = stoi(string_month);
    
    string_day = trimString(string_day);
    day = stoi(string_day);
    
    standard_time = trimString(standard_time);
    time = standardToMilitary(standard_time);
    
    string_duration = trimString(string_duration);
    duration = stoi(string_duration);
}

void Appointment::setTitle(string newTitle)
{
    if (newTitle != "")
    {
        title = newTitle;
    }
}

void Appointment::setYear(int newYear)
{
    if (newYear >= 0)
    {
        year = newYear;
    }
}

void Appointment::setMonth(int newMonth)
{
    if (newMonth >= 1 && newMonth <= 12)
    {
        month = newMonth;
    }
}

void Appointment::setDay(int newDay)
{
    if (newDay >= 1 && newDay <= 31)
    {
        day = newDay;
    }
}

void Appointment::setTime(int newTime)
{
    if ((newTime >= 0 && newTime < 2400) && (((newTime % 100) >= 0) && ((newTime % 100) < 60)))
    {
        time = newTime;
    }
}

void Appointment::setDuration(int newDuration)
{
    if (newDuration >= 0)
    {
        duration = newDuration;
    }
}

void Appointment::setDate(int newYear, int newMonth, int newDay)
{
    if (newYear >= 0)
    {
        year = newYear;
    }
    if (newMonth >= 1 && newMonth <= 12)
    {
        month = newMonth;
    }
    if (newDay >= 1 && newDay <= 31)
    {
        day = newDay;
    }
}

string Appointment::getTitle() const
{
    return title;
}

int Appointment::getYear() const
{
    return year;
}

int Appointment::getMonth() const
{
    return month;
}

int Appointment::getDay() const
{
    return day;
}

int Appointment::getTime() const
{
    return time;
}

int Appointment::getDuration() const
{
    return duration;
}

 string Appointment::getDate() const
{
    string date;
    string y = to_string(year);
    string m;
    if (month >= 1 && month <= 9)
    {
        m = "0" + to_string(month);
    }
    else if (month >= 10 && month <= 12)
    {
        m = to_string(month);
    }
    string d = to_string(day);
    date = y + "-" + m + "-" + d;
    return date;
}

string Appointment::getStandardTime()
{
    string standard_time = militaryToStandard(time);
    return standard_time;
}

string Appointment::militaryToStandard(int time)
{
    string standard_time;
    string am_pm;
    int hours = (time - (time % 100)) / 100;
    int minutes = time % 100;
    string h = to_string(hours);
    string m = to_string(minutes);
    if (hours >= 0 && hours < 12)
    {
        if (hours == 0)
        {
            h = "12";
        }
        am_pm = "AM";
    }
    else if (hours >= 12 && hours < 24)
    {
        if (hours > 12 && hours < 24)
        {
            hours -= 12;
            h = to_string(hours);
        }
        am_pm = "PM";
    }
    if (minutes >= 0 && minutes < 10)
    {
        m = "0" + m;
    }
    standard_time = h + ":" + m + am_pm;
    return standard_time;
}

int Appointment::standardToMilitary(string time)
{
    int military_time;
    string standard_time = convertUppercase(time);
    int colon_location = standard_time.find(":");
    string string_hour = standard_time.substr(0,colon_location);
    int int_hour = stoi(string_hour);
    string string_minute = standard_time.substr(colon_location + 1,2);
    int int_minute = stoi(string_minute);
    int am_pm_location = standard_time.length() - 1;
    string am_pm = standard_time.substr(am_pm_location - 1);

    if (am_pm == "AM")
    {
        if (int_hour == 12)
        {
            int_hour = 0;
        }
        int_hour = int_hour;
    }
    else if (am_pm == "PM")
    {
        if (int_hour != 12)
        {
            int_hour += 12;
        }
        int_hour = int_hour;
    }

    int_hour *= 100;

    if (int_minute == 0)
    {
        military_time = int_hour;
    }
    else if (int_minute != 0)
    {
        military_time = int_hour + int_minute;
    }

    return military_time;
}

void Appointment::output()
{
    cout << "Title: " << title << endl;
    cout << "Year: " << year << endl;
    cout << "Month: " << month << endl;
    cout << "Day: " << day << endl;
    cout << "Time: " << time << endl;
    cout << "Duration: " << duration << endl;
}

bool operator == (const Appointment &first, const Appointment &second)
{
    if ((first.getTitle() == second.getTitle()) && (first.getYear() == second.getYear()) && (first.getMonth() == second.getMonth()) && (first.getDay() == second.getDay()) && (first.getTime() == second.getTime()) && (first.getDuration() == second.getDuration()))
    {
        return true;
    }
    return false;
}

string Appointment::convertUppercase(string time)
{
    string uppercase = time;
    for (size_t i = 0; i < uppercase.length(); i++)
    {
        uppercase.at(i) = toupper(uppercase.at(i));
    }
    return uppercase;
}

string Appointment::trimString(string trim)
{
    while(trim.find(" ") == 0)
    {
        trim.erase(0,1);
    }
    size_t length = trim.size();
    while(trim.rfind(" ") == --length)
    {
        trim.erase(length,length + 1);
    }
    return trim;
}