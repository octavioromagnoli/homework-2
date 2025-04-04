run1: ej1/main1.cpp ej1/Time.cpp ej1/Time.h
	g++ -Wall -g ej1/main1.cpp ej1/Time.cpp -o 1
	./1

clear:
	rm -f 1
	rm -f 2
	rm -f 3
	rm -f 4