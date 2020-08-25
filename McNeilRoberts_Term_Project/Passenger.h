/*
 *  File Name: Passenger.h
 *  Completed by: Athena McNeil-Roberts
 *  Submission Date: June 15th, 2020
 */

#ifndef final_passenger
#define final_passenger
/* The following class definition represents a passenger and contains five
 * private data members called first_name, last_name, phone_number, id_number,
 * passenger_seat.
 */

#include <string>
#include "Seat.h"
using namespace std;

class Passenger{
  public:

    string get_first() const;
    // PROMISES: returns passengers first_name

    string get_last() const;
    // PROMISES: returns passengers last_name

    string get_phone() const;
    // PROMISES: returns passengers phone_number

    int get_id() const;
    // PROMISES: returns passengers id_number

    Seat get_seat() const;
    // PROMISES: returns passengers assigned Seat

    void set_first(string first);
    // PROMISES: sets passengers first_name to the value of arg

    void set_last(string last);
    // PROMISES: sets passengers last_name to the value of arg

    void set_phone(string number);
    // PROMISES: sets passengers phone_number to the value of arg

    void set_id(int id);
    // REQUIRES: id be a new unique number
    // PROMISES: sets passengers id_number number to the value of arg

    void set_seat(int r, char c);
    // REQUIRES: 0 < r <= total rows on flight and 'A' <= c <= char value of total
    //    number seats on flight
    // PROMISES: sets passenger_seat to the seat corresponding to arg [r][c] on map

  private:
    string first_name;    // passengers first name
    string last_name;     // passengers last name
    string phone_number;  // passengers phone number
    int id_number;        // passengers ID number
    Seat passenger_seat;  // passengers assigned seat
};

#endif
