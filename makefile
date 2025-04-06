run1: ej1/main1.cpp ej1/Time.cpp ej1/Time.h
	g++ -Wall -g ej1/main1.cpp ej1/Time.cpp -o 1
	./1
run2: ej2/main2.cpp ej2/Course.cpp ej2/Course.h ej2/Student.cpp ej2/Student.h
	g++ -Wall -g ej2/main2.cpp ej2/Course.cpp ej2/Student.cpp -o 2
	./2
run3:  ej3/main3.cpp  ej3/Numero.h ej3/Entero.h ej3/Complejo.h ej3/Real.h ej3/Entero.cpp ej3/Real.cpp ej3/Complejo.cpp
	g++ -Wall -g ej3/main3.cpp ej3/Entero.cpp ej3/Real.cpp ej3/Complejo.cpp -o 3
	./3
run4: ej4/main4.cpp ej4/Cuentas.cpp ej4/Cuentas.h
	g++ -Wall -g ej4/main4.cpp ej4/Cuentas.cpp -o 4
	./4
clear:
	rm -f 1
	rm -f 2
	rm -f 3
	rm -f 4