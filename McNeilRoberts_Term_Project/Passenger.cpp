/*
 *  File Name: Passenger.cpp
 *  Completed by: Athena McNeil-Roberts
 *  Submission Date: June 15th, 2020
 */

#include "Passenger.h"

string Passenger::get_first() const{
  return first_name;
}

string Passenger::get_last() const{
  return last_name;
}

string Passenger::get_phone() const{
  return phone_number;
}

int Passenger::get_id() const{
  return id_number;
}

Seat Passenger::get_seat() const{
  return passenger_seat;
}

void Passenger::set_first(string first){
  first_name = first;
}

void Passenger::set_last(string last){
  last_name = last;
}

void Passenger::set_phone(string number){
  phone_number = number;
}

void Passenger::set_id(int id){
  id_number = id;
}

void Passenger::set_seat(int r,char c){
  passenger_seat.set_row(r);
  passenger_seat.set_seat(c);
  passenger_seat.mark_spot();
}
