#ifndef SUBJECTSMARKSPRIMARY_H
#define SUBJECTSMARKSPRIMARY_H

class SubjectsMarksPrimary {
  protected:
      int eng,urdu,islam,maths,pst;
  public:
       bool checkPri;
       void setter(int eng, int urdu, int islam, int maths, int pst);
       void getter(int & eng, int & urdu, int & islam, int & maths, int & pst);
};

#endif // SUBJECTSMARKSPRIMARY_H
