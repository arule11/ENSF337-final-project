/*
 *  File Name: flight_main.cpp
 *  Completed by: Athena McNeil-Roberts
 *  Submission Date: June 15th, 2020
 */

#include "flight_main.h"

void display_header(){
  cout << "\n" << "Version: 1.0" << endl;
  cout << "Term Project – Flight Management Program in C++" << endl;
  cout << "Produced by: Athena McNeil-Roberts" << endl;
  press_enter();
}

void press_enter(){
  cout << "\n<<< Press Return to Continue>>>>\n";
  cin.get();
}

int menu(){
  int choice = 0;
  cout << "Please select one of the following operations: " << endl;
  cout << "  1. Display Flight Seat Map." << endl;
  cout << "  2. Display Passengers Information." << endl;
  cout << "  3. Add a New Passenger." << endl;
  cout << "  4. Remove an Existing Passenger." << endl;
  cout << "  5. Save data." << endl;
  cout << "  6. Quit" << "\n" <<endl;
  cout << "  Enter your choice (1, 2, 3, 4, 5, or 6): ";

  while(!(cin >> choice)){
    cerr << "\n Error: incorrect data type. Try again\n" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cout << "  Enter your choice (1, 2, 3, 4, 5, or 6): ";
  }
  cout << endl;
  return choice;
}

void display_Passengers(Flight& src){
  src.show_info();
}

int add_pass(Flight& src){
  Passenger p;
  char s;
  string phone, first, last;
  int r, id;

  do{
    cout << "Please enter the passenger id: ";
    while(!(cin >> id)){
      cerr << "\n Error: incorrect data type. Try again\n" << endl;
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Please enter the passenger id: ";
    }
  }while(!src.check_id(id));

  cout << "Please enter the passengers first name: ";
  cin.clear();
  cin.ignore(100, '\n');
  getline(cin, first);

  cout << "Please enter the passengers last name: ";
  getline(cin, last);

  cout << "Please enter the passengers phone number: ";
  getline(cin, phone);

  do{
    cout << "Please enter the passengers desired row: ";
    while(!(cin >> r)){
      cerr << "\n Error: incorrect data type. Try again\n" << endl;
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Please enter the passengers desired row: ";
    }
    cout << "Please enter the passengers desired seat: ";
    while(!(cin >> s)){
      cerr << "\n Error: incorrect data type. Try again\n" << endl;
      cin.clear();
      cin.ignore(100, '\n');
    }
  }while(!src.check_seat(r, s));

  p.set_first(first);
  p.set_last(last);
  p.set_phone(phone);
  p.set_seat(r, s);
  p.set_id(id);

  src.add_passenger(p);
  src.mark_seat(r, s);
  cout << "\n New Passenger successfully added\n" << endl;
  return 0;
}


int remove_pass(Flight& src){
  int target;
  cout << "Please enter the id of the passenger that needs to be removed: ";
  while(!(cin >> target)){
    cerr << "\n Error: incorrect data type. Try again\n" << endl;
    cin.clear();
    cin.ignore(100, '\n');
  }
  cout << endl;

  for(int i = 0; i < (src.get_people().size()); i++){
    if((src.get_people().at(i).get_id()) == target){
      src.remove_passenger(target);
      cout << " Passenger with ID# " << target << " has been removed. \n" << endl;
      return 0;
    }
  }
  cerr << " Error: Passenger with ID# " << target << " does not exist. \n" << endl;
  return 1;
}


void save_data(Flight& src, const string filename){
  char ans;
  do{
    cout << "Do you want to save the data to the file '" << filename << "'? Please answer <Y or N> ";
    while(!(cin >> ans)){
      cerr << "\n Error: incorrect data type. Try again\n" << endl;
      cin.clear();
      cin.ignore(100, '\n');
    }
    cerr << "\n Error: Please answer <Y or N>\n" << endl;
  }while(toupper(ans) != 'Y' && toupper(ans) != 'N');

  if(toupper(ans) == 'N'){
    cout << "\n Data in passenger list will not be saved.\n" << endl;
    return;
  }

  ofstream output;
  output.open(filename);
    output << setiosflags(ios::left) << setw(10) << src.get_flight_num() << setw(4) <<
      src.get_flight_rows() << setw(4) << src.get_flight_seats() << endl;
  for(int i = 0; i < src.get_people().size(); i++){
    output << setiosflags(ios::left) << setw(20) << src.get_people().at(i).get_first();
    output << setiosflags(ios::left) << setw(20) << src.get_people().at(i).get_last();
    output << setiosflags(ios::left) << setw(20) << src.get_people().at(i).get_phone();
    output << setiosflags(ios::left) << setw(2) << src.get_people().at(i).get_seat().get_row() <<
      setw(2) << src.get_people().at(i).get_seat().get_seat();
    output << setiosflags(ios::left) << setw(6) << src.get_people().at(i).get_id() << endl;
  }
  output.close();
  cout << "\n All the data in the passenger list was saved into " << filename << "\n" << endl;
}


Flight populate_flight(const string filename){
  Flight f;
  int rows, seats, r, id;
  char label[10], first[20], last[20], phone[20], s;
  Passenger p;

  ifstream file;
  file.open(filename);
  if(file.fail()){
    cerr << " Error reading file: " << filename << " \n Terminating program.. \n" << endl;
    exit(1);
  }

  file.get(label, 9);
  file >> rows >> seats;
  if(file.fail()){
    cerr << " Error1: reading input from file. Terminating program.. \n" << endl;
    exit(1);
  }

  f.set_flight_num(label);
  f.set_flight_rows(rows);
  f.set_flight_seats(seats);

  char clean[100];
  file.getline(clean, 100, '\n');

  f.build_map();

  while(1){
    file.get(first, 19);
    if(file.eof()){
      break;
    }else if(file.fail()){
      cerr << " Error2: reading input from file. Terminating program.. \n" << endl;
      exit(1);
    }

    file.get(last, 19);
    if(file.eof()){
      break;
    }else if(file.fail()){
      cerr << " Error3: reading input from file. Terminating program.. \n" << endl;
      exit(1);
    }
    file.get(phone, 19);
    if(file.eof()){
      break;
    }else if(file.fail()){
      cerr << " Error4: reading input from file. Terminating program.. \n" << endl;
      exit(1);
    }

    remove_leading(last);
    remove_leading(phone);

    file >> r >> s >> id;
    if(file.eof()){
      break;
    } else if(file.fail()){
      cerr << " Error5: reading input from file. Terminating program.. \n" << endl;
      exit(1);
    }

    p.set_first(first);
    p.set_last(last);
    p.set_phone(phone);
    p.set_seat(r,s);
    p.set_id(id);

    f.add_passenger(p);
    f.mark_seat(r, s);

    char junk[100];
    file.getline(junk, 100, '\n');
  }
  file.close();
  return f;
}

void remove_leading(char *str){
  if(str == nullptr){
    return;
  }
  int count = 0;
  for (int i = 0; str[i]; i++){
    if (str[i] != ' ' || str[i + 1] != ' '){
      str[count++] = str[i + 1];
    }
  }
  str[count] = '\0';
}
