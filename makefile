run1: ej1/main1.cpp ej1/Time.cpp ej1/Time.h
	g++ -Wall -g ej1/main1.cpp ej1/Time.cpp -o 1
	./1

run2: ej2/main2.cpp ej2/CourseStudent.cpp ej2/CourseStudent.h
	g++ -Wall -g ej2/main2.cpp ej2/CourseStudent.cpp -o 2
	valgrind --leak-check=full ./2
run3: 
	g++ -Wall -g .cpp -o 3
	./3

clear:
	rm -f 1
	rm -f 2
	rm -f 3
	rm -f 4