#include "Time.h"
#include<iostream>
#include<stdexcept>
#include<iomanip>
using namespace std;

Time::Time(): hours(0), minutes(0), seconds(0), meridiem("a.m."){
}

Time::Time(int hours): hours(hours), minutes(0), seconds(0), meridiem("a.m."){
  if(hours < 1 || hours > 12) 
    throw invalid_argument("La hora ingresada es inválida: debe estar entre 1 y 12");
}

Time::Time(int hours, int minutes): hours(hours), minutes(minutes), seconds(0), meridiem("a.m."){
  if(hours < 1 || hours > 12) 
    throw invalid_argument("La hora ingresada es inválida: debe estar entre 1 y 12");
  if(minutes < 0 || minutes > 59) 
    throw invalid_argument("Los minutos ingresados son inválidos: deben estar entre 0 y 59");
}

Time::Time(int hours, int minutes, int seconds): hours(hours), minutes(minutes), seconds(seconds), meridiem("a.m."){
  if(hours < 1 || hours > 12) 
    throw invalid_argument("La hora ingresada es inválida: debe estar entre 1 y 12");
  if(minutes < 0 || minutes > 59) 
    throw invalid_argument("Los minutos ingresados son inválidos: deben estar entre 0 y 59");
  if(seconds < 0 || seconds > 59) 
    throw invalid_argument("Los segundos ingresados son inválidos: deben estar entre 0 y 59");
}

Time::Time(int hours, int minutes, int seconds, string meridiem): hours(hours), minutes(minutes), seconds(seconds), meridiem(meridiem){
  if(hours < 1 || hours > 12) 
    throw invalid_argument("La hora ingresada es inválida: debe estar entre 1 y 12");
  if(minutes < 0 || minutes > 59) 
    throw invalid_argument("Los minutos ingresados son inválidos: deben estar entre 0 y 59");
  if(seconds < 0 || seconds > 59) 
    throw invalid_argument("Los segundos ingresados son inválidos: deben estar entre 0 y 59");
  if(meridiem != "a.m." && meridiem != "p.m.") 
    throw invalid_argument("Meridiano inválido: debe ser \"a.m.\" o \"p.m.\"");
  
}
  
void Time::sethour(int newhour) {
  if(newhour < 1 || newhour > 12)
    throw invalid_argument("La hora ingresada es inválida: debe estar entre 1 y 12");
  hours = newhour;
}

void Time::setminutes(int newminutes) {
  if(newminutes < 0 || newminutes > 59)
    throw invalid_argument("Los minutos ingresados son inválidos: deben estar entre 0 y 59");
  minutes = newminutes;
}

void Time::setseconds(int newseconds) {
  if(newseconds < 0 || newseconds > 59)
    throw invalid_argument("Los segundos ingresados son inválidos: deben estar entre 0 y 59");
  seconds = newseconds;
}

void Time::setmeridian(string newmeridian) {
  if(newmeridian != "a.m." && newmeridian != "p.m.")
  throw invalid_argument("Meridiano inválido: debe ser \"a.m.\" o \"p.m.\"");
  meridiem = newmeridian;
}


void Time::setTime(int newhour, int newseconds, int newminutes, string newmeridian){
  sethour(newhour);       
  setminutes(newminutes); 
  setseconds(newseconds); 
  setmeridian(newmeridian); 
}

int Time::gethour() const{
  return hours;
}

int Time::getminutes() const{
  return minutes;
}

int Time::getseconds() const{
  return seconds;
}

string Time::getmeridiem() const{
  return meridiem;
}

string Time::getTime() const {
  ostringstream out;
  out << setw(2) << setfill('0') << hours << "h, "
      << setw(2) << setfill('0') << minutes << "m, "
      << setw(2) << setfill('0') << seconds << "s "
      << meridiem;
  return out.str();
}

void Time::showTime() const{
  cout << setfill('0');
  cout << setw(2) << (hours + 12) % 24 << ":" << setw(2) << minutes << ":" << setw(2) << seconds << " " << meridiem << endl;
}
