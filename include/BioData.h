#ifndef BIODATA_H
#define BIODATA_H

#include<string>

using namespace std;

class BioData {
  protected:
      string cnice,name,father_name,address,education;
    int age,roll_no,grade;
  public:
    /*Both of the Bio_Functions are overloaded for the purpose of different data for
		 both faculty and student*/
    void setBioFac(string name, string f_n, string address, int age, string education, string cnic);
    void setBioStudent(string name, string f_n, string address, int age, int roll_no, int grade, string cnic);
    void setName(string n);
    void setFatherName(string n);
    void setAdd(string add);
    void setGrade(int grade);
    void setAge(int age);
};

#endif // BIODATA_H
