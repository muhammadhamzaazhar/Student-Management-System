#ifndef FACULTY_H
#define FACULTY_H

#include"Date.h"
#include"BioData.h"

class Faculty: public Date, public BioData {
  private:
      int id;
  public:
      Faculty * fhead = NULL;
      Faculty * next;
      int fcount = 0;
      void setdata(int d, int m, int y, string n, string fn, string add, string edu, int id);
      void save_fac_data(); //Prototype here only , method for saving data in file
      int retId();
      string getName() const;
      void setId(int i);
      void getAllFac(string & name, string & father_name, string & address, string & edu, int & d, int & m, int & y, string & cnic, int & id);
      void appCertFac();
      void addFac();
      void removeFaculty();
      void showFac();
      void Load_Faculty();
};

#endif // FACULTY_H
