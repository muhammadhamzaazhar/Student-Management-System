#ifndef STUDENT_H
#define STUDENT_H

#include"Date.h"
#include"BioData.h"
#include"SubjectsMarksPrimary.h"
#include"SubjectsMarksSecond.h"
#include<fstream>
#include<sstream>

class Student: public BioData, public SubjectsMarksPrimary, public Date, public SubjectsMarksSecond {
  private:
      string review;
  public:
      bool fee_status,teacher_review,markEn;
      Student * shead = NULL;
      Student * next;
      int count = 0;
      void save_data();
      void warning();
      void fee_chalan();
      void teacherReview();
      void setTeacherReview(string l);
      void getTeacherReview(string & l);
      int retStudentroll();
      void getAll(string & n, string & fn, string & add, string & cnic, int & age, int & roll_no, int & grade, int & d, int & m, int & y);
      string getName() const;
      int getGrade();
      void appCert();
      void leaveCert();
      /*
        Function for Adding Students to Linked List
      */
      void addStudent();
      //Sub Options in the student info
      void showStudent(int roll_no);
      void subMenuCase1();
      //Removes the student from the linked list
      void removeStd();
      void showStd();
      //Load Student Function into nodes
      void Load_student();
};
#endif // STUDENT_H
