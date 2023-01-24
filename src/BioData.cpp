#include "BioData.h"

void BioData::setBioFac(string name, string f_n, string address, int age, string education, string cnic) {
  this -> name = name;
  this -> father_name = f_n;
  this -> address = address;
  this -> age = age;
  this -> education = education;
  this -> cnice = cnic;
}

void BioData::setBioStudent(string name, string f_n, string address, int age, int roll_no, int grade, string cnic) {
  this -> name = name;
  this -> father_name = f_n;
  this -> address = address;
  this -> age = age;
  this -> roll_no = roll_no;
  this -> grade = grade;
  this -> cnice = cnic;
}

void BioData::setName(string n) {
  this -> name = n;
}

void BioData::setFatherName(string n) {
  this -> father_name = n;
}

void BioData::setAdd(string add) {
  this -> address = add;
}

void BioData::setGrade(int grade) {
  this -> grade = grade;
}

void BioData::setAge(int age) {
  this -> age = age;
}
