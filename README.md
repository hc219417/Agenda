# Agenda
Write a C++ program to manage a single day agenda using the Appointment class. Appointments for the day are stored in a file called "**agenda.txt**". The appointment data is stored in the file using the following format:

"`title|year|month|day|time(standard)|duration`"

Example: "`Meeting with Bob | 2019 |4 |29 |8:30 aM |15`"
 
The file might contain empty lines or no lines at all (no appointments). See the supplied sample file in the assignment's repository.

Write a C++ program that uses the Appointment class to manage the daily calendar. Your program should start by reading all the appointments from the data file and process command line arguments as follows:

- `./a.out -ps`

Print my daily schedule in **order** by starting time using standard time format. The appointments must be displayed in a table format with proper labels.

- `./a.out -p "time"`

Print all appointments at specified military time

- `./a.out -a "Appointment data"`

Add an appointment given in the format:

"`title|year|month|day|time|duration`"
 
Time is given in standard time and duration is given in minutes. Leading and trailing spaces must be removed.

**Example:** "`Meeting with Bob | 2019 |4 |29 |8:30 aM |15`"

- `./a.out -dt "title"`

Delete all appointments that match a title exactly. It should work for both upper and lower-case characters with leading and trailing spaces removed.

- `./a.out -dm "time"`

Delete all appointments that match the starting military time exactly.

If the daily calendar data is updated (add, delete) then all the data must be stored back in the same data file using the same format. You should be able to run the program again and see the changes reflected in the new daily agenda.

**Error checking:**

- Your program must handle data files that include empty lines or no lines at all.
- Report an error if the number of arguments is invalid.
- Report an error if the option is not valid.
