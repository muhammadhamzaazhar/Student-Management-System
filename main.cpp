#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "Student.h"
#include "Faculty.h"

void menuMain();
void printData();
void authen();
int flag = 1;

using namespace std;
int main() {
  system("Color 0A");
  authen();
  Student s;
  Faculty f;

  int option, flag = 1, opt;
  s.Load_student(); // Functions for populating the linked list
  f.Load_Faculty();
  while (flag == 1) {
    main: menuMain();
    Option:
    cin >> option;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\nPlease enter a valid integer value.\nProceed with your choice:";
        goto Option;
    }
    switch (option) {
    case 1:
      system("CLS");
      s.save_data();
      f.save_fac_data();
      s.subMenuCase1();
      cin >> opt;
      switch (opt) {
      case 1:
        s.addStudent();
        s.save_data();
        cout << "Press 1 to return to main menu: ";
        cin >> flag;
        break;
      case 2:
        if (s.count > 0) {
          int roll;
          cout << "Enter the roll no of the student: ";
          cin >> roll;
          s.showStudent(roll);
        } else {
          cout << "No record found , first enter the student\n";
          cout << "\nPress 1 to return to main menu: ";
          cin >> flag;
        }

        flag = 1;
        break;
      case 3:
        if (s.count > 0) {
          s.removeStd();
        } else
          cout << "No record found , first enter the student\n";
        cout << "\nPress 1 to return to main menu: ";
        cin >> flag;
        break;
      case 4:
        if (s.count > 0) {
          s.showStd();
        } else
          cout << "No record found , first enter the student\n";
        cout << "\nPress 1 to return to main menu: ";
        cin >> flag;
        break;

      default:
        cout << "Invalid Input,Press 1 to return to main menu or any other to exit: ";
        cin >> flag;
        break;
      }
      break;
    case 2: // Main Cases Part 2

      int fac;
      labelFac:
        system("CLS");
        f.save_fac_data();
      cout << "1) List of All faculty\n2) Entry of Faculty\n3) Appreciation Certificate\n4) Remove Faculty Member\n5) Main Menu\nEnter option: ";
      cin >> fac;
      if (fac == 1) {
        if (f.fcount > 0)
          f.showFac();
        else {
          int ox;
          cout << "\nWe have no data to show,First Enter the data\n";
          cout << "Press 1 to return to faculty menu and 2 to return to main menu\n";
          cin >> ox;
          if (ox == 1)
            goto labelFac;
          else
            goto main;
        }
      } else if (fac == 2) {
        f.addFac();
        f.save_fac_data();
      } else if (fac == 3) {
        if (f.fcount > 0) {
          int id, king = 0;
          cout << "Enter the id: ";
          cin >> id;
          Faculty * ptr = f.fhead;
          if (id == f.fhead -> retId()) {
            f.fhead -> appCertFac();
            ++king;
          } else {
            while (ptr != NULL) {
              if (ptr -> retId() == id) {
                ++king;
                ptr -> appCertFac();

                break;
              }
              ptr = ptr -> next;
            }
          }
          if (king == 0) {
            cout << "Id id not found \n";
          }
        } else {
          int ox;
          cout << "\nWe have no data to show,First Enter the data\n";
          cout << "Press 1 to return to faculty menu and 2 to return to main menu\n";
          cin >> ox;
          if (ox == 1)
            goto labelFac;
          else
            goto main;
        }
      } else if (fac == 4) {
        if (f.fcount > 0)
          f.removeFaculty();
        else {
          int ox;
          cout << "\nWe have no data to show,First Enter the data\n";
          cout << "Press 1 to return to faculty menu and 2 to return to main menu\n";
          cin >> ox;
          if (ox == 1)
            goto labelFac;
          else
            goto main;
        }
      } else if (fac == 5)
        goto main;
      else {
        cout << "Invalid option\n";
      }
      cout << "\nPress 1 to return to main menu: ";
      cin >> flag;
      break;
    case 3: // Main Cases Part 3
      printData();
      cout << "\nPress 1 to return to main menu\n";
      cin >> flag;
      break;
    case 4: // Main Cases Part 4
      cout << "\nThank You for using our services\n";
      flag = 0;
      break;
    default:
      cout << "Invalid Input,Press 1 to return to main menu or any other to exit: ";
      cin >> flag;
    }
  }
  return 0;
}

void menuMain() {
  system("CLS");
  cout << "--------------------------------------------------------------\n";
  cout << "             WELCOME TO STUDENT MANAGENMENT SYSTEM              " << endl;
  cout << "--------------------------------------------------------------\n";
  cout << "1)Student Information\n2)Faculty Information\n3)Print Data\n4)Exit\n-----------------------------\n-----------------------------\n";
  cout << "Please proceed with your choice:";
}

// Option 3 in main
void printData() {
  string line;
  cout << "Write the document\n";
  getline(cin.ignore(), line);
  fstream file;
  file.open("Document.txt", ios::out);
  file << line;
  file.close();
  cout << "Your data has been successfully written in a document in file you can check\n";
}

void authen() {
  int check = 3;
  string e_pass, user, line1, line;
  labelCheck:
    system("CLS");
  if (check > 0) {
    cout << "\n------------------------------------------------------\n";
    cout << "                   Kindly Log in to system\n";
    cout << "\n------------------------------------------------------\n";
    cout << "                   Enter Username:  ";
    cin >> line;
    cout << "                   Enter Password:  ";
    cin >> e_pass;
    cout << "\n------------------------------------------------------\n";
    cout << "\n------------------------------------------------------\n";
    /*fstream file;
    file.open("authen.txt", ios::in);
    while (!file.eof())
    {
    	file >> user;
    	file >> line1;
    }
    file.close();*/
    //if (e_pass == line1 && line == user)
    if (e_pass == "12345" && line == "pieas123") {
      cout << "You have logged in successfully\n";
      cout << "Redirecting to the menu.......\n";
      Sleep(2000); // Will stop the execution for 2 sec or  2000 miliseconds
      system("CLS");
    } else {
      int reply;
      cout << "\nYour credentials doesn't match,you have " << --check << " tries left" << endl;
      if (check == 0) {
        cout << "Your tries are over , Kindly log in to system after some time\n";
        exit(0);
      }
      cout << "\nPress 1 to enter again and 2 to exit: ";
      cin >> reply;
      if (reply == 1)
        goto labelCheck;
      else {
        cout << "\nThank you for using our services\n";
        exit(0);
      }
    }
  }
}
