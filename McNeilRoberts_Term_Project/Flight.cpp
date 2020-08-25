/*
 *  File Name: Flight.cpp
 *  Completed by: Athena McNeil-Roberts
 *  Submission Date: June 15th, 2020
 */

#include "Flight.h"

string Flight::get_flight_num() const{
  return flight_num;
}

int Flight::get_flight_rows() const{
  return flight_rows;
}

int Flight::get_flight_seats() const{
  return flight_seats;
}

vector<Passenger> Flight::get_people() const{
  return people;
}

vector< vector<Seat> > Flight::get_map() const{
  return map;
}

void Flight::set_flight_num(string s){
  flight_num = s;
}

void Flight::set_flight_rows(int r){
  flight_rows = r;
}

void Flight::set_flight_seats(int c){
  flight_seats = c;
}

void Flight::add_passenger(const Passenger& new_pass){
  people.push_back(new_pass);
}

void Flight::remove_passenger(int remove_id){
  for(int i = 0; i < people.size(); i++){
    if(people.at(i).get_id() == remove_id){
      int r = (people.at(i).get_seat().get_row() - 1);
      int c = int(people.at(i).get_seat().get_seat() - 'A');
      map.at(r).at(c).set_label();
      people.erase(people.begin() + i);
    }
  }
}

void Flight::mark_seat(int r,char s){
  s = toupper(s);
  map.at(r - 1).at((int)(s - 65)).mark_spot();
}

bool Flight::check_seat(int r, char s){
  s = toupper(s);
  if(r <= flight_rows && r > 0){
    if((int)(s - 65) <= flight_seats && (int)(s - 65) >= 0){
      for(int i = 0; i < people.size(); i++){
        if(people.at(i).get_seat().get_row() == r && people.at(i).get_seat().get_seat() == s){
          cerr << "\n Error: This seat is occupied.\n" << endl;
          return false;
        }
      }
      return true;
    }
    cerr << "\n Error: This seat does not exist.\n" << endl;
    return false;
  }
  cerr << "\n Error: This seat does not exist.\n" << endl;
  return false;
}

bool Flight::check_id(int id){
  for(int i = 0; i < people.size(); i++){
    if(people.at(i).get_id() == id){
      cout << "\n Error: Duplicate id number.\n" << endl;
      return false;
    }
  }
  return true;
}

void Flight::build_map(){
  map.resize(flight_rows, vector<Seat> (flight_seats));
  for( int row = 0; row < flight_rows; row++){
    for(int col = 0; col < flight_seats; col++){
      map.at(row).at(col).set_label();
      map.at(row).at(col).set_row(row);
      map.at(row).at(col).set_seat(col);
    }
  }
}

void Flight::show_seat_map(){
  cout << "Aircraft Seat Map for flight# " << get_flight_num() << "\n" << endl;

  for( int row = 0; row < flight_rows; row++){
      if(row == 0){
        for(int i = 0; i< flight_seats; i++){
          cout << setw(2) << "" << setw(2) << (char)('A' + i);
        }
        cout << "\n";
      }
      cout << "+";
      for(int i = 0; i< flight_seats ; i++){
        cout << "---+";
      }
    cout << endl;
    for(int col = 0; col < flight_seats + 1; col++){
      cout << setiosflags(ios::left) << setw(2) <<  "|";
      if (col == flight_seats){
        cout << setiosflags(ios::left) << row + 1;
      } else {
        cout << map[row][col].get_label() << " ";
      }
    }
    cout << "\n";
  }
  cout << "+";
  for(int i = 0; i< flight_seats ; i++){
    cout << "---+";
  }
  cout << "\n \n";
}

void Flight::show_info() const{
  cout << " " << setw(20) << setiosflags(ios::left) << "First Name" << setw(20) << "Last Name" <<
    setw(20) << "Phone" << setw(4) << "Row" << setw(5) << "Seat" << setw(7) << " ID" << endl;
  cout << "-----------------------------------------------------------------------------" << endl;

  for(int i = 0; i < people.size(); i++){
    cout << " " << setw(20) << setiosflags(ios::left) << people.at(i).get_first() << setw(20) <<
      people.at(i).get_last() << setw(20) << people.at(i).get_phone() << setw(4) <<
      people.at(i).get_seat().get_row() << setw(6) << people.at(i).get_seat().get_seat() <<
      setw(7) << people.at(i).get_id() << endl;
  cout << "-----------------------------------------------------------------------------" << endl;
  }
}
