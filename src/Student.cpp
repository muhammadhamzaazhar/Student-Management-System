#include "Student.h"
#include<iostream>
#include<fstream>
#include<ctime>
#include<sstream>

void Student::warning() {
  int grade;
  fstream file;
  file.open("warning_letter.txt", ios::out);
  file << "Respected Parents ! The behaviour of your child is not good in class and as well as in school so ," << endl <<
    "in the presence of Principal the warning letter has been isssued to your child " << this -> name << " of " << endl <<
    "Grade " << this -> grade << " if 2 more warning letters are issued then your child will be expelled from the school" << endl <<
    endl << "Regards from Principal" << endl;
  cout << "Your Letter is ready to print,file is saved in warning_letter.txt";
  file.close();
}

void Student::fee_chalan() {
  fstream file;
  time_t now = time(0);
  char * dt = ctime( & now);
  if (this -> grade >= 1 && this -> grade <= 4) {
    file.open("Fee_Chalan.txt", ios::out);
    file << "--------------------------Babul Ilm School-------------------------------" << endl << endl <<
      "This fee chalan is issued to student " << this -> name << " of Grade " << this -> grade << " and the fee Rs 1200/- " << endl <<
      "should be submitted before the deadline in the nearest HBL Bank branch " << endl << endl << "Chalan Issued Date: " << dt;
    file.close();
  } else if (this -> grade >= 5 && this -> grade <= 8) {
    file.open("Fee_Chalan.txt", ios::out);
    file << "--------------------------Babul Ilm School-------------------------------" << endl << endl <<
      "This fee chalan is issued to student " << this -> name << " of Grade " << this -> grade << " and the fee Rs 1500/- " << endl <<
      "should be submitted before the deadline in the nearest HBL Bank branch " << endl << endl << "Chalan Issued Date: " << dt;
    file.close();
  } else if (this -> grade == 9 || this -> grade == 10) {
    file.open("Fee_Chalan.txt", ios::out);
    file << "--------------------------Babul Ilm School-------------------------------" << endl << endl <<
      "This fee chalan is issued to student " << this -> name << " of Grade " << this -> grade << " and the fee Rs 2000/- " << endl <<
      "should be submitted before the deadline in the nearest HBL Bank branch " << endl << endl << "Chalan Issued Date: " << dt;
    file.close();
  }
}

void Student::teacherReview() {
  cout << this -> review;
  //Remember to ask for print
}

void Student::setTeacherReview(string l) {
  this -> review = l;
}

void Student::getTeacherReview(string & l) {
  l = this -> review;
}

int Student::retStudentroll() {
  return this -> roll_no;
}

void Student::getAll(string & n, string & fn, string & add, string & cnic, int & age, int & roll_no, int & grade, int & d, int & m, int & y) {
  n = this -> name;
  fn = this -> father_name;
  add = this -> address;
  cnic = this -> cnice;
  age = this -> age;
  roll_no = this -> roll_no;
  grade = this -> grade;
  d = this -> day;
  m = this -> month;
  y = this -> year;
}

string Student::getName() const {
  return this -> name; //concatenating the two strings
}

int Student::getGrade() {
  return this -> grade;
}

void Student::appCert() {
  fstream file;
  file.open("Appreciation_certificate.txt", ios::out);
  file << "Mr " << this -> name << " has performed well in the sportics and as well as" <<
    "in academics\nso on their best performance in both we are giving them the appreciation certificate\nStudent name: " <<
    this -> name << "\nGrade: " << this -> grade << "\nProvided by Principal\n";
  file.close();
}

void Student::leaveCert() {
  fstream file;
  file.open("School_leaving_certificate.txt", ios::out);
  file << "Mr " << this -> name << " has performed well in the studies but due to some conditions he is leaving the school\nwe are " <<
    "giving them the school leaving certificate\nStudent name: " << this -> name << "\nGrade: " << this -> grade <<
    "\nProvided by Principal\n";
  file.close();
}

void Student::save_data() {
  Student * list = shead;
  fstream file;
  file.open("Student_Record.txt", ios::out);
  while (list != NULL) {
    file << "Student Name:" << list -> name << endl;
    file << "Father Name:" << list -> father_name << endl;
    file << "Student Age:" << list -> age << endl;
    file << "Student CNIC:" << list -> cnice << endl;
    file << "Student Grade:" << list -> grade << endl;
    file << "Student Roll_No:" << list -> roll_no << endl;
    file << "Student Address:" << list -> address << endl;
    file << "Day:" << list -> day << endl << "Month:" << list -> month << endl << "Year:" << list -> year << endl;
    if (list -> next == NULL)
      file << "Student Fee_Status:" << list -> fee_status;
    else
      file << "Student Fee_Status:" << list -> fee_status << endl;
    list = list -> next;
  }
  file.close();
}

/*
Function for Adding Students to Linked List
*/
void Student::addStudent() {
  string name, fn, cnic, address, num;
  int roll, age, grade, d, y, m;
  Student * ptr = new Student;
  cin.ignore();
  Name:
    cout << "Enter the Name: ";
  getline(cin, name);
  for (int i = 0; i < name.length(); i++) {
    if (name[i] >= 48 && name[i] <= 57) {
      cout << "Invalid, name should not contain any integer\n\n";
      goto Name;
    }
  }
  Fname:
    cout << "Enter the father name: ";
  getline(cin, fn);
  for (int i = 0; i < fn.length(); i++) {
    if (fn[i] >= 48 && fn[i] <= 57) {
      cout << "Invalid, father name should not contain any integer\n\n";
      goto Fname;
    }
  }
  Age:
    cout << "Enter the age: ";
  cin >> age;
  if (cin.fail()) {
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Please enter a valid integer value.\n" << endl;
    goto Age;
  }
  if (age == 0 || age < 0 || age >= 20) {
    cout << "Age cant be zero or negative or greater than 20\n";
    goto Age;
  }
  ptr -> teacher_review = false;
  ptr -> checkSec = false;
  ptr -> checkPri = false;
  ptr -> markEn = false;
  cout << "Enter the CNIC/B-Form(with dashes): ";
  getline(cin.ignore(), cnic);
  cout << "Enter the grade: ";
  cin >> grade;
  if (grade >= 1 && grade <= 10) {
    if (grade >= 1 && grade <= 8)
      ptr -> checkPri = true;
    else
      ptr -> checkSec = true;
  } else if (grade <= 0 || grade > 10) {
    while (grade <= 0 || grade > 10) {
      cout << "\nInvalid Grade !!! We have grades from 1 to 10 only\n";
      cin >> grade;

    }
  }
  Roll:
  cout << "Enter the roll #(only integer): ";
  cin >> roll;
  if (cin.fail()) {
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Please enter a valid integer value.\n" << endl;
    goto Roll;
  }
  if (roll == 0 || roll < 0) {
    while (roll == 0 || roll < 0) {
      cout << "\nRoll no cant be 0 or negative\n";
      cin >> roll;
    }
  }
  if (shead != NULL) {
    Student * check = shead;
    while (check != NULL) {
      if (check -> retStudentroll() == roll) {
        //			while(check->retStudentroll()==roll)
        //			cout<<"Student of grade "<<check->getGrade()<<" Mr "<<check->getName()<<" has this roll no \n";

        cout << "Roll no already exits,Try new one: ";
        cin >> roll;

        check = shead;
      } else
        check = check -> next;
    }
  }
  cout << "Enter the permanent address: ";
  getline(cin.ignore(), address);
  cout << "Enter date of Birth: " << endl;
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
  ptr -> setDate(d, m, y);
  cout << "Has the student submitted the fee: ";
  cin >> num;
  if (num == "yes")
    ptr -> fee_status = true;
  else
    ptr -> fee_status = false;
  ptr -> setBioStudent(name, fn, address, age, roll, grade, cnic);
  if (shead == NULL) {
    shead = ptr;
    ptr -> next = NULL;
  } else {
    Student * cptr = shead;
    while (cptr -> next != NULL) {
      cptr = cptr -> next;
    }
    cptr -> next = ptr;
    ptr -> next = NULL;
  }
  cout << "The Student has been successfully entered in the database " << endl;
  ++count;
}

void Student::showStudent(int roll_no) {
  Student * show = shead;
  int supercount = count;
  int ans, flag, glaf, fake = supercount;
  while (show != NULL) {
    --fake;
    if (show -> retStudentroll() == roll_no) {
      glaf = 0;
      labelInner: //Label is defined to return back
        string n, fn, add, cnic;
      int age, roll_no, grade, d, m, y;
      system("CLS");
      cout << "1) General Information\n2) Marks Status\n3) Fee Status\n4) Show Teacher Review\n5) Entry of Marks\n6) Write Teacher Review\n7) Warning Letter\n8) Fee Chalan\n9) Update Student Information\n10) Certificate\n11)Main Menu" << endl;
      cin >> ans;
      show -> getAll(n, fn, add, cnic, age, roll_no, grade, d, m, y);
      if (ans == 1) {
        cout << "Name: " << n << endl;
        cout << "Father name: " << fn << endl;
        cout << "CNIC/B-Form: " << cnic << endl;
        cout << "Address: " << add << endl;
        cout << "Roll no: " << roll_no << endl;
        cout << "Grade: " << grade << endl;
        cout << "DOB: " << d << "/" << m << "/" << y << endl;
      } else if (ans == 2) {
        if (show -> checkSec == true && show -> markEn == true) {
          int eng, urdu, islam, maths, pst, physics, chemistry;
          show -> getMS(eng, urdu, islam, maths, pst, physics, chemistry);
          //Must perform a check in order to show this
          cout << "The marks of the student are: " << endl;
          cout << "English: " << eng << endl;
          cout << "Urdu: " << urdu << endl;
          cout << "Islamiyat: " << islam << endl;
          cout << "Maths: " << maths << endl;
          cout << "Pak-Studies: " << pst << endl;
          cout << "Physics: " << physics << endl;
          cout << "Chemistry: " << chemistry << endl;
        } else if (show -> checkPri == true && show -> markEn == true) {
          //continued here
          int eng, urdu, islam, maths, pst;
          show -> getter(eng, urdu, islam, maths, pst);
          cout << "The marks of the student are: " << endl;
          cout << "English: " << eng << endl;
          cout << "Urdu: " << urdu << endl;
          cout << "Islamiyat: " << islam << endl;
          cout << "Maths: " << maths << endl;
          cout << "Pak-Studies: " << pst << endl;
        } else {
          cout << "No record of marks found regarding student Mr " << show -> getName() << endl;
        }
      } else if (ans == 3) {
        if (show -> fee_status == true)
          cout << "Fee is submitted " << endl;
        else
          cout << "Fee is not submitted " << endl;

      } //end of else if
      else if (ans == 4) {
        string line;
        if (show -> teacher_review == true) {
          cout << "Teacher Overall Review about Mr " << show -> getName() << endl;
          cout << "**************************************************\n";
          show -> getTeacherReview(line);
          cout << line;
          cout << "\n**************************************************\n";
        } else
          cout << "No record found related to Mr " << show -> getName() << endl;
      } //end of condition
      else if (ans == 5) {
        int eng, urdu, islam, maths, pst, chem, phy;
        if (show -> checkPri == true) { //Entered at the time of the entry
          cout << "Enter the marks of the student: " << endl;
          cout << "English :";
          cin >> eng;
          cout << "Urdu :";
          cin >> urdu;
          cout << "Islamiyat: ";
          cin >> islam;
          cout << "Maths: ";
          cin >> maths;
          cout << "Pak studies: ";
          cin >> pst;
          show -> setter(eng, urdu, islam, maths, pst);
          cout << "Your Marks has been successfully entered" << endl;
          show -> markEn = true;
        } else if (show -> checkSec == true) {
          cout << "Enter the marks of the student: " << endl;
          cout << "English :";
          cin >> eng;
          cout << "Urdu :";
          cin >> urdu;
          cout << "Maths: ";
          cin >> maths;
          cout << "PakStudies: ";
          cin >> pst;
          cout << "Islamiyat: ";
          cin >> islam;
          cout << "Chemistry: ";
          cin >> chem;
          cout << "Physics: ";
          cin >> phy;
          show -> setMS(eng, urdu, islam, maths, pst, phy, chem);
          cout << "Your Marks has been successfully entered" << endl;
          show -> markEn = true;
        } //end of internal else if

      } //end of condition
      else if (ans == 6) {
        string line;
        cout << "Write your review about " << show -> getName() << endl;
        getline(cin.ignore(), line);
        show -> teacher_review = true;
        show -> setTeacherReview(line);
        cout << "\nYour review has been submitted about Mr " << show -> getName() << endl;
      } else if (ans == 7) {
        //Warning Letter
        show -> warning();
        cout << "\nWarning Letter is ready for printing\n";
      } //end of else if
      else if (ans == 8) {
        //Fee Chalan
        show -> fee_chalan();
        cout << "\nFee Chalan is ready for printing\n";
      } else if (ans == 9) {
        int o;
        //Edit Student Information
        system("CLS");
        cout << "What you want to modify of Mr " << show -> getName() << endl;
        cout << "\n1) Name\n2) Grade\n3) Teacher Review\n";
        cin >> o;
        if (o == 1) {
          string name;
          cout << "Enter the name: ";
          getline(cin.ignore(), name);
          show -> setName(name);
          cout << "Enter the father name: ";
          getline(cin, name);
          show -> setFatherName(name); //Name variable again used
        } else if (o == 2) {
          int grade;
          cout << "enter the new grade: ";
          cin >> grade;
          if (grade >= 1 || grade <= 10) {
            if (grade >= 1 || grade <= 8)
              show -> checkPri = true;
            else
              show -> checkSec = true;
          } else if (grade <= 0 || grade > 10) {
            cout << "\nInvalid Grade !!! We have grades from 1 to 10 only\n";
            while (grade <= 0 || grade > 10) {
              cout << "\nInvalid Grade !!! We have grades from 1 to 10 only\n";
              cin >> grade;

            }
            show -> setGrade(grade);
          }
          cout << "\nYour information has been updated successfully\n";
        } //end of main else if o==2
        else if (o == 3) //o==3 DOB CHANGE
        {
          string line;
          cout << "\nEnter the new review: ";
          getline(cin.ignore(), line);
          show -> setTeacherReview(line);
          cout << "\nReview has been successfully updated\n";

        } //end of Review o==3
      } //end of 9
      else if (ans == 10) {
        int opt;
        cout << "Which certificate do you want to print: ";
        cout << "\n1) Appreciation Certificate\n2) School Leaving Certificate\n";
        cin >> opt;
        if (opt == 1) {
          show -> appCert();
          cout << "\nYour file of certificate is ready \n";
        } else {
          show -> leaveCert();
          cout << "\nYour file of certificate is ready \n";
        }

      } //Last Else if
      else if (ans == 11) {
        break;
      }
    } else {
      show = show -> next;
      glaf = 1;
    }
    int input;
    labelOuter:
      if (glaf == 1 && fake == 0) {
        int jok;
        cout << "\nNo roll found as you entered\n";
        cout << "Press 1 to return to main menu";
        cin >> jok;
        if (jok == 1)
          break;
      }
    labelkill:
      if (glaf == 0) {
        cout << "\nPress 1 to go to student menu and 2 to main menu: ";
        cin >> input;
        if (input == 1)
          goto labelInner;
        else
          break;
      }
  }

}
void Student::subMenuCase1() {
  cout << "\nEnter Option: \n1) Add Student\n2) Student Info\n3) Remove Student\n4) Show Students List\n" << endl;
}

void Student::removeStd() {
  Student s;
  Student * cptr = shead;
  Student * temp = NULL;
  int id, glad = 0;
  cout << "Enter the Roll no of the student: ";
  cin >> id;
  if (id == shead -> retStudentroll()) {
    temp = shead;
    shead = shead -> next;
    delete temp;
    ++glad;
  } else {
    temp = NULL;
    while (cptr -> next != NULL) {
      if (id == cptr -> next -> retStudentroll()) {
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
    cout << "\nEntered ID does not match with the strored database\n";
  }
  if (glad > 0) {
    cout << "\nStudent has been removed successfully\n";
    --count;
    s.save_data();
  }

}
void Student::showStd() {
  string name, father_name, add, cnic;
  int d, m, y, roll, grade, age;
  cout << "Following are the total students available: \n";
  Student * trav = shead;

  while (trav != NULL) {
    trav -> getAll(name, father_name, add, cnic, age, roll, grade, d, m, y);
    cout << "\n********************************\n";
    cout << "Name: " << name << endl;
    cout << "Father Name: " << father_name << endl;
    cout << "Address: " << add << endl;
    cout << "Roll No: " << roll << endl;
    cout << "CNIC: " << cnic << endl;
    cout << "DOB: " << d << "/" << m << "/" << y << endl;
    cout << "***********************************\n";
    trav = trav -> next;
  }
}
//String to int conversion
int to_int(string s) {
  int a;
  stringstream ss;
  ss << s;
  ss >> a;
  return a;
}
void Student::Load_student() {
  int age, grade, roll, dd, mm, yy, status;
  string a, g, r, d, m, y, name, father_name, cnic, address, dummy, yut, hug;
  fstream file;
  file.open("Student_Record.txt", ios::in);
  getline(file, dummy);
  file.close();
  file.open("Student_Record.txt", ios::in);
  if (dummy != "\0") {
    while (!file.eof()) {
      Student * ptr;
      ptr = new Student;
      file.ignore(30, ':');
      getline(file, name);
      file.ignore(30, ':');
      getline(file, father_name);
      file.ignore(30, ':');
      file >> a;
      file.ignore(30, ':');
      getline(file, cnic);
      file.ignore(30, ':');
      file >> g;
      file.ignore(30, ':');
      file >> r;
      file.ignore(30, ':');
      getline(file, address);
      file.ignore(30, ':');
      file >> d;
      file.ignore(30, ':');
      file >> m;
      file.ignore(30, ':');
      file >> y;
      file.ignore(30, ':');
      file >> yut;
      getline(file, hug);
      status = to_int(yut);
      if (status == 1)
        ptr -> fee_status = true;
      else
        ptr -> fee_status = false;
      dd = to_int(d);
      mm = to_int(m);
      yy = to_int(y);
      age = to_int(a);
      grade = to_int(g);
      roll = to_int(r);
      ptr -> setBioStudent(name, father_name, address, age, roll, grade, cnic);
      ptr -> setDate(dd, mm, yy);
      if (shead == NULL) {
        shead = ptr;
        ++count;
        ptr -> next = NULL;
      } else {
        Student * gptr = shead;
        while (gptr -> next != NULL) {
          gptr = gptr -> next;
        }
        gptr -> next = ptr;
        ptr -> next = NULL;
        ++count;
      }
    }
  }
  file.close();

}
