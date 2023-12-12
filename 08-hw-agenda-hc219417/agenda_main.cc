/**
 *   @file: agenda_main.cc
 * @author: Hannah Culver
 *   @date: November 19, 2021
 *  @brief: homework 8 (agenda)
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>
#include <fstream>
#include <vector>
#include <algorithm> //not sure if we've talked about this library in class, but I found it in the textbook (pg 192)
#include "agenda.h"
#include "agenda.cc"

using namespace std;

/**
 * ps - print daily schedule in order by starting time (using standard time format)
 * @param appointments vector of appointments
 * @return appointments displayed in table format with proper labels
 */
void ps(vector <string> appointments);

/**
 * p - print all appointments at specified military time
 * @param appointments vector of appointments
 * @param argv argument vector
 * @return display of appointments
 */
void p(vector <string> appointments, const char *argv[]);

/**
 * a - add an appointment given in the string format
 * @param appointments vector of appointments
 * @param argv argument vector
 * @return updated daily schedule and vector of appointments
 */
void a(vector <string> &appointments, const char *argv[]);

/**
 * convertLowercase - converts a string to lowercase for comparison
 * @param title string to be converted to lowercase
 * @return lowercase string
 */
string convertLowercase(string title);

/**
 * dt - delete all appointments that match a title exactly
 * @param appointments vector of appointments
 * @param argv argument vector
 * @return updated daily schedule and vector of appointments
 */
void dt(vector <string> &appointments, const char *argv[]);

/**
 * dm - delete all appointments that match the starting military time exactly
 * @param appointments vector of appointments
 * @param argv argument vector
 * @return updated daily schedule and vector of appointments
 */
void dm(vector <string> &appointments, const char *argv[]);

int main(int argc, char const *argv[]) {

    ifstream inStream;
    inStream.open("agenda_copy.txt");
    if(inStream.fail())
    {
        cout << "Error: file not found" << endl;
        exit(0);
    }

    size_t white_space_count = 0;
    string appointment;
    vector <string> appointments;

    while(!inStream.eof())
    {
        getline(inStream,appointment);
        while(appointment.length() != 0) //while length isn't zero...
        {
            appointments.push_back(appointment); //...load into vector
            getline(inStream,appointment);
        }
    }

    for (size_t i = 0; i < appointments.size(); i++)
    {
        for (size_t j = 0; j < appointments.at(i).size(); j++)
        {
            if (isspace(appointments.at(i).at(j)))
            {
                white_space_count++;
            }
        }
        if (white_space_count == appointments.at(i).size())
        {
            appointments.erase(appointments.begin() + i);
        }
        white_space_count = 0; //reset the white space count
    }

    if (argc < 2 || argc > 3) //check for argument count, must equal 2 or 3 (./a.exe -whatever +string)
	{
		cout << "Error: invalid command line argument" << endl;
		exit(0);
	}

    if (argc == 2) //argument count equals 2
    {
        if (std::string(argv[1]) == "-ps") //print daily schedule in order by starting time (using standard time format)
        {
            ps(appointments);
        }
        else
        {
            cout << "Error: invalid command line argument" << endl;
		    exit(0);
        }
    }

    else if (argc == 3) //argument count equals 3
    {
        if (std::string(argv[1]) == "-p") //print all appointments at specified military time
        {
            p(appointments,argv);
        }
        else if (std::string(argv[1]) == "-a") //add an appointment given in the string format
        {
            ofstream outStream;
            outStream.open("agenda_copy.txt");
            if(outStream.fail())
            {
                cout << "Error: failed to create file" << endl;
                exit(0);
            }

            a(appointments,argv);
            for (size_t i = 0; i < appointments.size(); i++)
            {
                Appointment a(appointments.at(i));
                outStream << a.getTitle() << " | " << a.getYear() << " | " << a.getMonth() << " | " << a.getDay() << " | " << a.getStandardTime() << " | " << a.getDuration() << endl;
            }

            outStream.close();
        }
        else if (std::string(argv[1]) == "-dt") //delete all appointments that match a title exactly
        {
            ofstream outStream;
            outStream.open("agenda_copy.txt");
            if(outStream.fail())
            {
                cout << "Error: failed to create file" << endl;
                exit(0);
            }

            dt(appointments,argv);
            for (size_t i = 0; i < appointments.size(); i++)
            {
                Appointment a(appointments.at(i));
                outStream << a.getTitle() << " | " << a.getYear() << " | " << a.getMonth() << " | " << a.getDay() << " | " << a.getStandardTime() << " | " << a.getDuration() << endl;
            }

            outStream.close();
        }
        else if (std::string(argv[1]) == "-dm") //delete all appointments that match the starting military time exactly
        {
            ofstream outStream;
            outStream.open("agenda_copy.txt");
            if(outStream.fail())
            {
                cout << "Error: failed to create file" << endl;
                exit(0);
            }

            dm(appointments,argv);
            for (size_t i = 0; i < appointments.size(); i++)
            {
                Appointment a(appointments.at(i));
                outStream << a.getTitle() << " | " << a.getYear() << " | " << a.getMonth() << " | " << a.getDay() << " | " << a.getStandardTime() << " | " << a.getDuration() << endl;
            }

            outStream.close();
        }
        else
        {
            cout << "Error: invalid command line argument" << endl;
		    exit(0);
        }
    }

    inStream.close();
    
    return 0;
}// main

bool comp(const Appointment &a, const Appointment &b)
{
    return a.getTime() < b.getTime(); //return true if appointment a time comes before appointment b time
}

//ok so this function kinda works, it puts all of them in order except
//for the very first one and instead deletes a random one, I think it
//might have something to do with it not knowing what to do with the
//first appointment it reads since it has nothing to compare it to yet

void ps(vector <string> appointments)
{
    cout << "======================================================================" << endl;
    cout << left << setw(35) << "Title" << setw(15) << "Date" << setw(10) << "Time" << setw(10) << "Duration" << endl;
    cout << "======================================================================" << endl;
    for (size_t i = 0; i < appointments.size(); i++)
    {
        Appointment a(appointments.at(i));
        sort(appointments.begin(),appointments.end(),comp); //see above bool comp function
        cout << left << setw(35) << a.getTitle() << setw(15) << a.getDate() << setw(10) << a.getStandardTime() << setw(10) << a.getDuration() << endl;
    }
    cout << "======================================================================" << endl;
}

void p(vector <string> appointments, const char *argv[])
{
    int int_time = stoi(argv[2]); //convert string to int
    for (size_t i = 0; i < appointments.size(); i++)
    {
        Appointment a(appointments.at(i));
        if (int_time == a.getTime())
        {
            cout << "-------------------------------------------------------------------------------------" << endl;
            cout << left << setw(35) << "Title" << setw(10) << "Year" << setw(10) << "Month" << setw(10) << "Day" << setw(10) << "Time" << setw(10) << "Duration" << endl;
            cout << left << setw(35) << a.getTitle() << setw(10) << a.getYear() << setw(10) << a.getMonth() << setw(10) << a.getDay() << setw(10) << a.getStandardTime() << setw(10) << a.getDuration() << endl;
            cout << "-------------------------------------------------------------------------------------" << endl;
        }
    }
}

void a(vector <string> &appointments, const char *argv[]) //send appointment vector by reference
{
    appointments.push_back(argv[2]); //simple enough
}

string convertLowercase(string title)
{
    string lowercase = title;
    for (size_t i = 0; i < lowercase.length(); i++)
    {
        lowercase.at(i) = tolower(lowercase.at(i));
    }
    return lowercase;
}

void dt(vector <string> &appointments, const char *argv[]) //send appointment vector by reference
{
    string string_title = convertLowercase(argv[2]); //convert string to lowercase
    for (size_t i = 0; i < appointments.size(); i++)
    {
        Appointment a(appointments.at(i));
        if (string_title == convertLowercase(a.getTitle())) //if titles match...
        {
            appointments.erase(appointments.begin() + i); //...delete appointment
        }
    }
}

void dm(vector <string> &appointments, const char *argv[]) //send appointment vector by reference
{
    int int_time = stoi(argv[2]); //convert string to int
    for (size_t i = 0; i < appointments.size(); i++)
    {
        Appointment a(appointments.at(i));
        if (int_time == a.getTime()) //if times match...
        {
            appointments.erase(appointments.begin() + i); //...delete appointment
        }
    }
}