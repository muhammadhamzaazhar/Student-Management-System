#ifndef SUBJECTSMARKSSECOND_H
#define SUBJECTSMARKSSECOND_H

class SubjectsMarksSecond {
  protected:
      int eng,urdu,islam,maths,pst,physics,chemistry;
  public:
       bool checkSec;
       void setMS(int eng, int urdu, int islam, int maths, int pst, int physics, int chemistry);
       void getMS(int & eng, int & urdu, int & islam, int & maths, int & pst, int & physics, int & chemistry);
};

#endif // SUBJECTSMARKSSECOND_H
