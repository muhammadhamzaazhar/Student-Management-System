#include "Faculty.h"
#include<iostream>
#include<fstream>
#include<sstream>

void Faculty::setdata(int d, int m, int y, string n, string fn, string add, string edu, int id) {
  this -> day = d;
  this -> month = m;
  this -> year = y;
  this -> name = n;
  this -> father_name = fn;
  this -> address = add;
  this -> education = edu;
  this -> id = id;
}

int Faculty::retId() {
  return id;
}

string Faculty::getName() const {
  return this -> name; //concatenating the two strings
}

void Faculty::setId(int i) {
  this -> id = i;
}

void Faculty::getAllFac(string & name, string & father_name, string & address, string & edu, int & d, int & m, int & y, string & cnic, int & id) {
  name = this -> name;
  father_name = this -> father_name;
  address = this -> address;
  id = this -> id;
  edu = this -> education;
  d = this -> day;
  m = this -> month;
  y = this -> year;
  cnic = this -> cnice;
}

void Faculty::appCertFac() {
  fstream file;
  file.open("Appreciation_certificate_teacher.txt", ios::out);
  file << "Mr " << this -> name << " has taught very well in Bab-ul-Ilm school\nSo on their best performance, we are giving " <<
    "them the appreciation certificate\nFaculty name: " << this -> name << "\nProvided by Principal\n";
  file.close();
  cout << "\nIt is printed successfully\n";
}

void Faculty::save_fac_data() {
  Faculty * list = fhead;
  fstream file;
  file.open("Faculty_Record.txt", ios::out);
  while (list != NULL) {
    file << "Name:" << list -> name << endl;
    file << "Father Name:" << list -> father_name << endl;
    file << "Education:" << list -> education << endl;
    file << "Address:" << list -> address << endl;
    file << "CNIC:" << list -> cnice << endl;
    file << "Age:" << list -> age << endl;
    file << "ID:" << list -> id << endl;
    if (list -> next == NULL)
      file << "Day:" << list -> day << endl << "Month:" << list -> month << endl << "Year:" << list -> year;
    else
      file << "Day:" << list -> day << endl << "Month:" << list -> month << endl << "Year:" << list -> year << endl;
    list = list -> next;
  }
  file.close();
}
void Faculty::addFac() {
  Faculty f;
  Faculty * entry = new Faculty;
  int d, m, y, age, id;
  string n, fn, add, edu, cnic;
  cin.ignore();
  Name:
    cout << "Enter name: ";
  getline(cin, n);
  for (int i = 0; i < n.length(); i++) {
    if (n[i] >= 48 && n[i] <= 57) {
      cout << "Invalid, name should not contain any integer\n\n";
      goto Name;
    }
  }
  Fname:
    cout << "Enter father name: ";
  getline(cin, fn);
  for (int i = 0; i < fn.length(); i++) {
    if (fn[i] >= 48 && fn[i] <= 57) {
      cout << "Invalid, father name should not contain any integer\n\n";
      goto Fname;
    }
  }
  Edu:
    cout << "Enter education(only in string): ";
  getline(cin, edu);
  for (int i = 0; i < edu.length(); i++) {
    if (edu[i] >= 48 && edu[i] <= 57) {
      cout << "Invalid, education should not contain any integer\n\n";
      goto Edu;
    }
  }
  cout << "Enter Address: ";
  getline(cin, add);
  cout << "Enter CNIC(with dashes): ";
  getline(cin, cnic);
  Age:
    cout << "Enter age(less than or equal to 50): ";
  cin >> age;
  if (cin.fail() || age >= 50) {
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Please enter a valid integer value or age less than or equal to 50.\n" << endl;
    goto Age;
  }
  if (age == 0 || age < 0) {
    cout << "\nAge can't be 0 or negative\n";
    goto Age;
  }
  Id:
    cout << "Enter id(only integer): ";
  cin >> id;
  if (cin.fail()) {
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Please enter a valid integer value.\n" << endl;
    goto Id;
  }
  if (id == 0 || id < 0) {
    cout << "\nID can't be 0 or negative\n";
    goto Id;
  }
  if (fhead != NULL) {
    Faculty * check = fhead;
    while (check != NULL) {
      if (check -> retId() == id) {
        cout << "Id already exits,Try new one: ";
        cin >> id;

        check = fhead;
      } else
        check = check -> next;
    }
  }
  cout << "Enter date of Joining: " << endl;

  cout << "Month: ";
  cin >> m;
  if (m > 12 || m < 1) {
    while (m > 12 || m < 1) {
      cout << "Please enter the months in between 1 and 12: ";
      cin >> m;
    }
  }
  cout << "Day: ";
  cin >> d;
  if (d < 1 || d > 31) {
    while (d < 1 || d > 31) {
      cout << "\nDate lies between 1 and 31, so enter again: ";
      cin >> d;
    }
  } else {
    if (m == 2) {
      if (d > 28 || d > 29) {
        while (d > 28 || d > 29) {
          cout << "\nFebruary has 28 or 29 days so enter in between them: ";
          cin >> d;
        }
      }
    }
  }
  cout << "Year: ";
  cin >> y;
  if (y == 0 || y < 0) {
    while (y == 0 || y < 0) {
      cout << "\nYear cant be zero or less than that, so Enter again: ";
      cin >> y;
    }
  }
  entry -> setBioFac(n, fn, add, age, edu, cnic);
  entry -> setDate(d, m, y);
  entry -> setId(id);

  if (fhead == NULL) {
    fhead = entry;
    entry -> next = NULL; //fhead->>>Faculty node head
  } else {
    Faculty * cptr = fhead;
    while (cptr -> next != NULL) {
      cptr = cptr -> next;
    }
    cptr -> next = entry;
    entry -> next = NULL;
  }
  ++fcount;
  cout << "\nFaculty has been successfully added\n";
}

void Faculty::removeFaculty() {
  Faculty f;
  Faculty * cptr = fhead;
  Faculty * temp = NULL;
  int id, glad = 0;
  cout << "Enter the id of the member: ";
  cin >> id;
  if (id == fhead -> retId()) {
    temp = fhead;
    fhead = fhead -> next;
    delete temp;
    ++glad;
  } else {
    temp = NULL;
    while (cptr -> next != NULL) {
      if (id == cptr -> next -> retId()) {
        temp = cptr -> next;
        cptr -> next = cptr -> next -> next;
        delete temp;
        ++glad;
        break;
      }
      cptr = cptr -> next;
    }
  }
  if (glad == 0) {
    cout << "\nEntered ID does not match with the stored database\n";
  }
  if (glad > 0) {
    cout << "\nEmployee has been removed successfully\n";
    --fcount;
    f.save_fac_data();
  }

}

void Faculty::showFac() {
  string name, father_name, address, edu, cnic;
  int d, m, y, id;
  cout << "Following are the total faculty available: \n";
  Faculty * trav = fhead;

  while (trav != NULL) {
    trav -> getAllFac(name, father_name, address, edu, d, m, y, cnic, id);
    cout << "\n********************************\n";
    cout << "Name: " << name << endl;
    cout << "Father Name: " << father_name << endl;
    cout << "Education: " << edu << endl;
    cout << "Address: " << address << endl;
    cout << "ID: " << id << endl;
    cout << "CNIC: " << cnic << endl;
    cout << "Date of entrance: " << d << "/" << m << "/" << y << endl;
    cout << "***********************************\n";
    trav = trav -> next;
  }
}
//String to int conversion
int to_int1(string s) {
  int a;
  stringstream ss;
  ss << s;
  ss >> a;
  return a;
}
void Faculty::Load_Faculty() {
  int age, id, dd, mm, yy;
  string a, i, d, m, y, name, add, father_name, cnic, address, dummy, education, hug;
  fstream file;
  file.open("Faculty_Record.txt", ios::in);
  getline(file, dummy);
  file.close();
  file.open("Faculty_Record.txt", ios::in);
  if (dummy != "\0") {
    while (!file.eof()) {
      Faculty * ptr;
      ptr = new Faculty;
      file.ignore(30, ':');
      getline(file, name);
      file.ignore(30, ':');
      getline(file, father_name);
      file.ignore(30, ':');
      getline(file, education);
      file.ignore(30, ':');
      getline(file, add);
      file.ignore(30, ':');
      getline(file, cnic);
      file.ignore(30, ':');
      file >> a;
      file.ignore(30, ':');
      file >> i;
      file.ignore(30, ':');
      file >> d;
      file.ignore(30, ':');
      file >> m;
      file.ignore(30, ':');
      file >> y;
      getline(file, hug);
      age = to_int1(a);
      id = to_int1(i);
      dd = to_int1(d);
      mm = to_int1(m);
      yy = to_int1(y);
      ptr -> setBioFac(name, father_name, add, age, education, cnic);
      ptr -> setDate(dd, mm, yy);
      ptr -> setId(id);
      if (fhead == NULL) {
        fhead = ptr;
        ++fcount;
        ptr -> next = NULL;
      } else {
        Faculty * gptr = fhead;
        while (gptr -> next != NULL) {
          gptr = gptr -> next;
        }
        ++fcount;
        gptr -> next = ptr;
        ptr -> next = NULL;

      }
    }
  }

}
