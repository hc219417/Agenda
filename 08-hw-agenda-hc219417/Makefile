# Created by: Nasseef Abukamail
# This Makefile will allow you to run tests for the appointment class
#
# Usage:
#    make run_tests
#    mingw32-make run_tests_win
#
#Variables
CC = g++
CFLAGS = -g -Wall -std=c++11

# Linking all the files and run the tests. Use your own header and
# object files.

a.exe: appointment.o appointment.h appointment_main.o
	$(CC) $(CFLAGS) _TEST/appointment.o _TEST/appointment_main.o -o a.exe

appointment.o: appointment.cc appointment.h
	$(CC) -c $(CFLAGS) appointment.cc -o _TEST/appointment.o

appointment_main.o: appointment_main.cc appointment.h
	$(CC) -c $(CFLAGS) appointment_main.cc -o _TEST/appointment_main.o

######################################## R U N   T E S T s ##################################################
run_tests: appointment.h appointment.o
	head appointment.cc
	$(CC) $(CFLAGS) _TEST/TEST_cases.cc appointment.cc -o _TEST/run_tests ; _TEST/run_tests -sr compact

run_tests_win: appointment.h appointment.o
	$(CC) $(CFLAGS) _TEST/TEST_cases.cc appointment.cc -o _TEST/run_tests
	_TEST/run_tests -sr compact
##############################################################################################################

clean:
	rm -rf _TEST/*.o _TEST/run_tests a.exe _TEST/a.exe

# ######################################### R U N   T E S T s ##################################################
# run_tests: appointment.h appointment.o
# 	head appointment.cc
# 	$(CC) $(CFLAGS) _TEST/TEST_cases.cc _TEST/appointment.o -o _TEST/a.exe && ./_TEST/a.exe -sr compact
# ##############################################################################################################
