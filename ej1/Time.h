#ifndef TIME_H
#define TIME_H

#include <string>
using std::string;

class Time
{
private:
  int hours;
  int minutes;
  int seconds;
  string meridiem;

public:
  Time(int hours = 0, int minutes = 0, int seconds = 0, string meridiem = "a.m.");

  void sethour(int newhour);
  void setminutes(int newminutes);
  void setseconds(int newseconds);
  void setmeridian(string newmeridian);
  void setTime(int newhour, int newminutes, int newseconds, string newmeridian);

  int gethour() const;
  int getminutes() const;
  int getseconds() const;
  string getmeridiem() const;
  string getTime() const;

  void showTime() const;
};

#endif // TIME_H