/*
 *  File Name: run_flight.cpp
 *  Completed by: Athena McNeil-Roberts
 *  Submission Date: June 15th, 2020
 */

#include "Flight.h"
#include "Passenger.h"
#include "Seat.h"
#include "flight_main.h"
using namespace std;

int main(){
  Flight f;
  display_header();
  f = populate_flight("flight_info.txt");
  while(1){
    switch(menu()){
      case 1:
        f.show_seat_map();
        press_enter();
        break;
      case 2:
        display_Passengers(f);
        press_enter();
        break;
      case 3:
        add_pass(f);
        break;
      case 4:
        remove_pass(f);
        break;
      case 5:
        save_data(f, "flight_info.txt");
        break;
      case 6:
        cout << " Program Terminated!" << endl;
        exit(1);
        break;
      default:
        cerr << " Error: please enter a number 1-6\n" << endl;
    }
  }
  return 0;
}
