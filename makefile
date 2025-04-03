run1: ej1/main1.cpp ej1/Time.cpp ej1/Time.h
	g++ -Wall -g ej1/main1.cpp ej1/Time.cpp -o 1
	./1

clear:
	rm 1
	rm 2
	rm 3
	rm 4