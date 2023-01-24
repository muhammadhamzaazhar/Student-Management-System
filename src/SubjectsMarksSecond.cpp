#include "SubjectsMarksSecond.h"

void SubjectsMarksSecond::setMS(int eng, int urdu, int islam, int maths, int pst, int physics, int chemistry) {
  this -> eng = eng;
  this -> urdu = urdu;
  this -> islam = islam;
  this -> maths = maths;
  this -> pst = pst;
  this -> physics = physics;
  this -> chemistry = chemistry;
}

void SubjectsMarksSecond::getMS(int & eng, int & urdu, int & islam, int & maths, int & pst, int & physics, int & chemistry) {
  eng = this -> eng;
  urdu = this -> urdu;
  islam = this -> islam;
  maths = this -> maths;
  pst = this -> pst;
  physics = this -> physics;
  chemistry = this -> chemistry;
}
