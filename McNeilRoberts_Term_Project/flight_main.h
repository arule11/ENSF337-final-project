/*
 *  File Name: flight_main.h
 *  Completed by: Athena McNeil-Roberts
 *  Submission Date: June 15th, 2020
 */

#ifndef final_flight_main
#define final_flight_main

#include <fstream>

#include "Flight.h"
#include "Passenger.h"
#include "Seat.h"
using namespace std;

void display_header();
// PROMISES: displays intro header

void press_enter();
// PROMISES: prompts user to press enter to continue when starting program (grabbing
//   next char)

int menu();
// PROMISES: display menu and prompt user to choose task.
//    returns int value corresponding to menu task.

void display_Passengers(Flight& src);
// REQIRES: src refernce a valid flight
// PROMISES: display each passengers information within flight

int add_pass(Flight& src);
// REQIRES: src refernce a valid flight
// PROMISES: add a new passenger to flight, prompting user for values

int remove_pass(Flight& src);
// REQIRES: src refernce a valid flight
// PROMISES: remove a target passenger from the flight

void save_data(Flight& src, const string filename);
// REQIRES: src refernce a valid flight and filename be a valid existing file
//    within the same directory
// PROMISES: save updated passenger data to file entered, if users seeks to do so

Flight populate_flight(const string file_name);
// REQIRES: filename be a valid existing file within the same directory as program
// PROMISES: read passenger data from file and add each passenger to passenger list

void remove_leading(char *str);
// REQIRES: str point to value char array
// PROMISES: remove leading space characters from char array

#endif
