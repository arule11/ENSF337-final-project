/*
 *  File Name: Seat.h
 *  Completed by: Athena McNeil-Roberts
 *  Submission Date: June 15th, 2020
 */

#ifndef final_seat
#define final_seat
/* The following class definition represents a seat and contains three
 * private data members called row, seat, label.
 */

#include <string>
#include <vector>
using namespace std;

#define EMPTY ' '
#define TAKEN 'X'

class Seat{
  public:

    int get_row() const;
    // PROMISES: returns passengers assigned seat row

    char get_seat() const;
    // PROMISES: returns passengers assigned seat letter

    char get_label() const;
    // PROMISES: returns label associated with passengers assigned seat

    void set_row(int r);
    // REQUIRES: r > 0 and r <= total rows on flight
    // PROMISES: set data member row to arg

    void set_seat(char s);
    // REQUIRES: 'A' <= s <= char value of total number seats on flight
    // PROMISES: set data member seat to arg

    void set_label();
    // PROMISES: set data member label to empty

    void mark_spot();
    // PROMISES: set data member label to taken

  private:
    int row;      // row of assigned seat
    char seat;    // seat letter of assigned seat
    char label;   // status of assigned seat
};

#endif
