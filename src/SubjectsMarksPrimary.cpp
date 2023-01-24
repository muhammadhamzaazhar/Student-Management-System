#include "SubjectsMarksPrimary.h"

void SubjectsMarksPrimary::setter(int eng, int urdu, int islam, int maths, int pst) {
  this -> eng = eng;
  this -> urdu = urdu;
  this -> islam = islam;
  this -> maths = maths;
  this -> pst = pst;
}

void SubjectsMarksPrimary::getter(int & eng, int & urdu, int & islam, int & maths, int & pst) {
  eng = this -> eng;
  urdu = this -> urdu;
  islam = this -> islam;
  maths = this -> maths;
  pst = this -> pst;
}
