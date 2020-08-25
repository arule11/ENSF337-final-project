/*
 *  File Name: Seat.cpp
 *  Completed by: Athena McNeil-Roberts
 *  Submission Date: June 15th, 2020
 */

#include "Seat.h"

int Seat::get_row() const{
  return row;
}

char Seat::get_seat() const{
  return seat;
}

char Seat::get_label() const{
  return label;
}

void Seat::set_row(int r){
  row = r;
}

void Seat::set_seat(char s){
  seat = toupper(s);
}

void Seat::set_label(){
  label = EMPTY;
}

void Seat::mark_spot(){
  label = TAKEN;
}
