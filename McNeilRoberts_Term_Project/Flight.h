/*
 *  File Name: Flight.h
 *  Completed by: Athena McNeil-Roberts
 *  Submission Date: June 15th, 2020
 */

#ifndef final_flight
#define final_flight
/* The following class definition represents a flight and contains five
 * private data members called people, flight_num, flight_rows, flight_seats,
 * and map.
 */

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

#include "Passenger.h"
#include "Seat.h"

using namespace std;

class Flight{
  public:

    string get_flight_num() const;
    // PROMISES: returns unique flight number associated with flight

    int get_flight_rows() const;
    // PROMISES: returns number of rows of associated flight

    int get_flight_seats() const;
    // PROMISES: returns number of columns of associated flight

    vector<Passenger> get_people() const;
    // PROMISES: returns vector list of passengers on flight

    vector< vector<Seat> > get_map() const;
    // PROMISES: returns seat map of associated flight

    void set_flight_num(string s);
    // REQUIRES: s be a combination of letters and numbers
    // PROMISES: set data member flight_num to arg

    void set_flight_rows(int r);
    // REQUIRES: r > 0
    // PROMISES: set data member flight_rows to arg

    void set_flight_seats(int c);
    // REQUIRES: c > 0
    // PROMISES: set data member flight_seats to arg

    void add_passenger(const Passenger& new_pass);
    // REQUIRES: new_pass refernce a valid passenger
    // PROMISES: adds passenger arg to list of passengers

    void remove_passenger(int remove_id);
    // REQUIRES: remove_id be a valid id number
    // PROMISES: remove passenger with target id from list of passengers aswell
    //    as free up their seat on the seat map.

    void build_map();
    // PROMISES: create an empty map with rows of size flight_rows and columns
    //    of size flight_seats

    void mark_seat(int r,char s);
    // REQUIRES: 0 < r <= flight_rows and 'A' <= s <= char value of flight_seats
    // PROMISES: change the corresponding spot on the seat map to taken

    void show_info() const;
    // PROMISES: display each passengers information within list

    void show_seat_map();
    // PROMISES: display current seat map, indicating which seats are occupied

    bool check_seat(int r, char s);
    // PROMISES: check that the seat at location [r][s] exists and is not
    //    already occupied

    bool check_id(int id);
    // PROMISES: check that the id arg is not already being used

  private:
    vector<Passenger> people;   // list of passengers on flight
    string flight_num;          // associated flight number
    int flight_rows;            // number of rows on flight
    int flight_seats;           // number of columns on flight
    vector< vector<Seat> > map; // 2D list of all seats on flight
};

#endif
