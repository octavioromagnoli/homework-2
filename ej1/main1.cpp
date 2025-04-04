#include <iostream>
#include <limits>
#include "Time.h" 
using namespace std;

/*
  Retorna 1 si el usuario quiere continuar y 0 si no.
  */
int wantToFollow(){
  int tryagain;
  cout<<"Queres intentar de nuevo? (1)SI (0)NO"<<endl;
  cin>>tryagain;
  if(tryagain != 1) tryagain = 0;
  if(tryagain) return 1;
  return 0;
};


int main() {
  /*
    Detecta cin.fail() y pregunta al usuario si quiere continuar
    Retorna 2 si no hubo error
    Retorna 1 si  hubo error pero el usuario quiere continuar.
    Retorna 0 si hubo error y no quiere continuar
    */
  auto handleInputError = [&]() -> int {
    if (cin.fail()) {
        cout << "Error, la entrada es de tipo inválido." << endl;
        cin.clear(); // Limpia el estado de error de cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto de la entrada
        return wantToFollow();
    }
    return 2; 
  };

  Time tobj;
  int selected;
  bool inputok = true;

  do{
    cout<<"Qué formato vas a querer ingresar?"<<endl<<
    "(1) Solo hora"<<endl<<
    "(2) Hora y minutos"<<endl<<
    "(3) Hora, minutos, segundos"<<endl<<
    "(4) Hora, minutos, segundos, meridiano"<<endl;
    cin >> selected;

    if(cin.fail()){
      cout << "Error, la entrada es de tipo inválido."<<endl;
      inputok = false;
      cin.clear();
      cin.ignore( numeric_limits<streamsize>::max(), '\n' );
      if(!wantToFollow()) return 0;
    }
    else if(selected < 1 || selected > 4){
      cout << "Error, se debe elegir una opcion válida."<<endl;
      inputok = false;
      if(!wantToFollow()) return 0;
    }
    else{
      inputok = true;
    }
  } while(!inputok);

  Time timeobj;
  int HH = 0, MM = 0, SS=0; 
  string MER = "";
  cout<<"Por default, el horario actual es " << timeobj.getTime() << endl;

  bool changed = false;
  switch(selected){

    case 1:
      do{
        cout<<"Ingrese la hora:"<<endl;
        cin >> HH;

        // Manejo en caso de valor de tipo inválido
        int stopOnError = handleInputError();
        if(!stopOnError) return 0;

        // Manejo en caso de valor int fuera de rango
        else if (stopOnError == 2){
          try {
            tobj.sethour(HH);
            changed = true;
          } catch (const invalid_argument& e) {
            cout << "Error, " << e.what() << endl;
            changed = false;
            if (!wantToFollow()) return 0;
          }

        }
      } while(!changed);
    break;

    case 2:
      do{
        cout<<"Ingrese la hora y los minutos separados por espacio"<<endl;
        cin >> HH >> MM;

        // Manejo en caso de valor de tipo inválido
        int stopOnError = handleInputError();
        if(!stopOnError) return 0;

        // Manejo en caso de valor int fuera de rango
        else if (stopOnError == 2){
          try {
            tobj.sethour(HH);
            tobj.setminutes(MM);
            changed = true;
          } catch (const invalid_argument& e) {
            cout << "Error, " << e.what() << endl;
            changed = false;
            if (!wantToFollow()) return 0;
          }
        }
      } while(!changed);
    break;
    
    case 3:
      do{
        cout<<"Ingrese la hora, los minutos y los segundos separados por espacio"<<endl;
        cin >> HH >> MM >> SS;

        // Manejo en caso de valor de tipo inválido
        int stopOnError = handleInputError();
        if(!stopOnError) return 0;

        // Manejo en caso de valor int fuera de rango
        else if (stopOnError == 2){
          try {
            tobj.sethour(HH);
            tobj.setminutes(MM);
            tobj.setseconds(SS);
            changed = true;
          } catch (const invalid_argument& e) {
            cout << "Error, " << e.what() << endl;
            changed = false;
            if (!wantToFollow()) return 0;
          }
        }
      } while(!changed);
    break;
    
    case 4:
      do{
        cout<<"Ingrese la hora, los minutos, los segundos y el meridiano (a.m. o p.m.) separados por espacio"<<endl;
        cin >> HH >> MM >> SS >> MER;

        // Manejo en caso de valor de tipo inválido
        int stopOnError = handleInputError();
        if(!stopOnError) return 0;

        // Manejo en caso de valor int fuera de rango
        else if (stopOnError == 2){
          try {
            tobj.setTime(HH, MM, SS, MER);
            changed = true;
          } catch (const invalid_argument& e) {
            cout << "Error, " << e.what() << endl;
            changed = false;
            if (!wantToFollow()) return 0;
          }
        }
      } while(!changed);
    break;
        

  }
  
  cout<<"Genial!";

  while(true){
  selected = 0;
  cout<<endl<<"La hora es "<< tobj.getTime() << endl 
    << "Qué operación queres hacer?"<<endl
    << "(1) Cambiar Horas"<< endl
    << "(2) Cambiar Minutos"<< endl
    << "(3) Cambiar Segundos"<< endl
    << "(4) Cambiar Meridiano"<< endl
    << "(5) Ver Horas"<< endl
    << "(6) Ver Minutos"<< endl
    << "(7) Ver Segundos"<< endl
    << "(8) Ver Meridiano"<< endl
    << "(9) Ver hora en tiempo a.m. o p.m."<< endl
    << "(10) Ver hora en tiempo 0 a 24"<< endl
    << "(11) Salir"<<endl;
    cout<<"Seleccion ---> "; cin >> selected;

    if (selected > 11 || selected < 0) selected = 11;

    switch (selected) {
      case 1:
        cout << "Ingrese la nueva hora:" << endl;
        cin >> HH;
        if (handleInputError() == 2) {
          try {
            tobj.sethour(HH);
            cout << "Hora actualizada a " << tobj.getTime() << endl;
          } catch (const invalid_argument& e) {
            cout << "Error, " << e.what() << endl;
          }
        }
        break;

      case 2:
        cout << "Ingrese los nuevos minutos:" << endl;
        cin >> MM;
        if (handleInputError() == 2) {
          try {
            tobj.setminutes(MM);
            cout << "Minutos actualizados a " << tobj.getTime() << endl;
          } catch (const invalid_argument& e) {
            cout << "Error, " << e.what() << endl;
          }
        }
        break;

      case 3:
        cout << "Ingrese los nuevos segundos:" << endl;
        cin >> SS;
        if (handleInputError() == 2) {
          try {
            tobj.setseconds(SS);
            cout << "Segundos actualizados a " << tobj.getTime() << endl;
          } catch (const invalid_argument& e) {
            cout << "Error, " << e.what() << endl;
          }
        }
        break;

      case 4:
        cout << "Ingrese el nuevo meridiano (a.m. o p.m.):" << endl;
        cin >> MER;
        if (handleInputError() == 2) {
          try {
            tobj.setmeridian(MER);
            cout << "Meridiano actualizado a " << tobj.getTime() << endl;
          } catch (const invalid_argument& e) {
            cout << "Error, " << e.what() << endl;
          }
        }
        break;

      case 5:
        cout << "La hora actual es: " << tobj.gethour() << endl;
        break;

      case 6:
        cout << "Los minutos actuales son: " << tobj.getminutes() << endl;
        break;

      case 7:
        cout << "Los segundos actuales son: " << tobj.getseconds() << endl;
        break;

      case 8:
        cout << "El meridiano actual es: " << tobj.getmeridiem() << endl;
        break;

      case 9:
        cout << "La hora en formato a.m./p.m. es: " << tobj.getTime() << endl;
        break;

      case 10:
        cout << "La hora en formato 24 horas es: "; tobj.showTime();
        break;

      case 11:
        cout << "Saliendo del programa." << endl;
        return 0;

      default:
        cout << "Opción inválida. Saliendo del programa." << endl;
        return 0;
    }
  }

    

}