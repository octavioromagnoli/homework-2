#include "Time.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>
using namespace std;

// Constructor: Inicializa un objeto Time con horas, minutos, segundos y meridianos.
Time::Time(int hours, int minutes, int seconds, string meridiem) : hours(hours), minutes(minutes), seconds(seconds), meridiem(meridiem)
{
  if (hours < 0 || hours > 12)
    throw invalid_argument("La hora ingresada es inválida: debe estar entre 0 y 12");
  if (minutes < 0 || minutes > 59)
    throw invalid_argument("Los minutos ingresados son inválidos: deben estar entre 0 y 59");
  if (seconds < 0 || seconds > 59)
    throw invalid_argument("Los segundos ingresados son inválidos: deben estar entre 0 y 59");
  if (meridiem != "a.m." && meridiem != "p.m.")
    throw invalid_argument("Meridiano inválido: debe ser \"a.m.\" o \"p.m.\"");
}

// Establece la hora
void Time::sethour(int newhour)
{
  if (newhour < 0 || newhour > 12)
    throw invalid_argument("La hora ingresada es inválida: debe estar entre 0 y 12");
  hours = newhour;
}

// Establece los minutos.
void Time::setminutes(int newminutes)
{
  if (newminutes < 0 || newminutes > 59)
    throw invalid_argument("Los minutos ingresados son inválidos: deben estar entre 0 y 59");
  minutes = newminutes;
}

// Establece los segundos.
void Time::setseconds(int newseconds)
{
  if (newseconds < 0 || newseconds > 59)
    throw invalid_argument("Los segundos ingresados son inválidos: deben estar entre 0 y 59");
  seconds = newseconds;
}

// Establece el meridiano (a.m. o p.m.)
void Time::setmeridian(string newmeridian)
{
  if (newmeridian != "a.m." && newmeridian != "p.m.")
    throw invalid_argument("Meridiano inválido: debe ser \"a.m.\" o \"p.m.\"");
  meridiem = newmeridian;
}

// Establece toda la hora (horas, minutos, segundos y meridiano).
void Time::setTime(int newhour, int newseconds, int newminutes, string newmeridian)
{
  sethour(newhour);
  setminutes(newminutes);
  setseconds(newseconds);
  setmeridian(newmeridian);
}

// Devuelve la hora.
int Time::gethour() const
{
  return hours;
}

// Devuelve los minutos.
int Time::getminutes() const
{
  return minutes;
}

// Devuelve los segundos.
int Time::getseconds() const
{
  return seconds;
}

// Devuelve el meridiano (a.m. o p.m.).
string Time::getmeridiem() const
{
  return meridiem;
}

// Devuelve la hora como una cadena formateada.
string Time::getTime() const
{
  ostringstream out;
  out << setw(2) << setfill('0') << hours << "h, "
      << setw(2) << setfill('0') << minutes << "m, "
      << setw(2) << setfill('0') << seconds << "s "
      << meridiem;
  return out.str();
}

// Muestra la hora en formato de 24 horas (hh:mm:ss).
void Time::showTime() const
{
  cout << setfill('0');
  int hour24;

  if (meridiem == "a.m.")
  {
    hour24 = (hours == 12) ? 0 : hours;
  }
  else
  {
    hour24 = (hours == 12) ? 12 : hours + 12;
  }
  cout << setw(2) << hour24 << "h:" << setw(2) << minutes << "m:" << setw(2) << seconds << "s" << endl;
}
