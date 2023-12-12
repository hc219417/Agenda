#!/bin/bash
cp _TEST/sample-agenda.txt agenda.txt
echo '\033[0;33m' "###################################################################" '\033[m'
echo '\033[0;33m' "The following should produce errors" '\033[m'
echo '\033[0;33m' "###################################################################" '\033[m'
_TEST/a.out 
echo
_TEST/a.out 1
echo
_TEST/a.out 1 2 3 4
echo
echo '\033[0;33m' "Test: ./a.out -a ' Meeting with Bob | 2019 |-4 |29 |8:30 aM  |-15' | use default values" '\033[m'
_TEST/a.out -a " Meeting with Bob | 2019 |-4 |29 |8:30 aM  |-15 "
echo
echo '\033[0;33m' "###################################################################" '\033[m'
echo '\033[0;33m' "The following should produce the correct output" '\033[m'
echo '\033[0;33m' "###################################################################" '\033[m'

echo '\033[0;33m' "Test: ./a.out -ps" '\033[m'
echo '\033[0;33m' "-------------------------------------------------------------------" '\033[m'
_TEST/a.out -ps
echo
echo '\033[0;33m' "###################################################################" '\033[m'

echo '\033[0;33m' "Test: ./a.out -p 1230 " '\033[m'
echo '\033[0;33m' "-------------------------------------------------------------------" '\033[m'
_TEST/a.out -p 1230
echo
echo '\033[0;33m' "###################################################################" '\033[m'
echo '\033[0;33m' "Test: ./a.out -a 'Meeting with TEST | 2019 |4 |29 |8:30 aM  |15 '"
echo '\033[0;33m' "-------------------------------------------------------------------" '\033[m'
_TEST/a.out -a " Meeting with TEST | 2019 |4 |29 | 8:30 aM  |15 "
echo
echo '\033[0;33m' "Test: ./a.out -p 830 " '\033[m'
echo '\033[0;33m' "-------------------------------------------------------------------" '\033[m'
 _TEST/a.out -p 830
echo

echo '\033[0;33m' "Test: ./a.out -dt 'Lunch with the guys' | deletes 3 appts" '\033[m'
echo '\033[0;33m' "-------------------------------------------------------------------" '\033[m'
_TEST/a.out -dt "Lunch With The Guys"

echo
echo '\033[0;33m' "Test: ./a.out -ps" '\033[m'
echo '\033[0;33m' "-------------------------------------------------------------------" '\033[m'
_TEST/a.out -ps
echo

echo '\033[0;33m' "Test: ./a.out -dt 'Lunch with the guys' | deletes nothing" '\033[m'
echo '\033[0;33m' "-------------------------------------------------------------------" '\033[m'
_TEST/a.out -dt "Lunch With The Guys"

echo
echo '\033[0;33m' "Test: ./a.out -ps | nothing is deleted"  '\033[m'
echo '\033[0;33m' "-------------------------------------------------------------------" '\033[m'
_TEST/a.out -ps
echo

echo '\033[0;33m' "Test: ./a.out -dm 1445 | deletes 2 fishing appts" '\033[m'
echo '\033[0;33m' "-------------------------------------------------------------------" '\033[m'
_TEST/a.out -dm 1445
echo
echo '\033[0;33m' "Test: ./a.out -ps | fishing appts should be missing"  '\033[m'
echo '\033[0;33m' "-------------------------------------------------------------------" '\033[m'
_TEST/a.out -ps
echo
echo '\033[0;33m' "Test: ./a.out -p 1230 | no appointments '\033[m'"
echo '\033[0;33m' "-------------------------------------------------------------------" '\033[m'
_TEST/a.out -p 1230
echo
echo '\033[0;33m' "###################################################################" '\033[m'

