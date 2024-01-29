CC=gcc
CFLAGS=-c -Wall  -Werror -Wextra -g -std=c11
CCTEST=gcc -fprofile-arcs -ftest-coverage

all: s21_string.a

s21_string.a: s21_*.o  functions_for_*.o  general_helper_functions.o 
	ar rc s21_string.a s21_*.o  functions_for_*.o  general_helper_functions.o 

test: unit_tests.o tests_*.o s21_string.a
ifeq ($(shell uname),Linux)   
	$(CC)  unit_tests.o tests_*.o s21_string.a -o unit_tests -lcheck -lm -lsubunit   
else   
	$(CC)  unit_tests.o tests_*.o s21_string.a -o unit_tests -lcheck   
endif   
	 

html_s21_string.a: html_s21_*.o  html_functions_for_*.o  html_general_helper_functions.o 
	ar rc html_s21_string.a s21_*.o  functions_for_*.o  general_helper_functions.o

html_test: unit_tests.o tests_*.o html_s21_string.a
ifeq ($(shell uname),Linux)   
	$(CCTEST)  unit_tests.o tests_*.o  html_s21_string.a -o unit_tests -lcheck -lm -lsubunit   
else   
	$(CCTEST)  unit_tests.o tests_*.o  html_s21_string.a -o unit_tests -lcheck    
endif  
	

gcov_report:clean html_test
	./unit_tests
	lcov -t "unit_tests" -o fizzbuzz.info -c -d .
	genhtml -o report fizzbuzz.info




unit_tests.o: unit_tests.c 
	$(CC)  $(CFLAGS)  unit_tests.c

tests_*.o: test_suite_creation_functions/tests_*.c 
	$(CC) $(CFLAGS) test_suite_creation_functions/tests_*.c




html_s21_*.o: string_processing_functions/s21_*.c functions_string/s21_*.c s21_string.c
	$(CCTEST) $(CFLAGS) string_processing_functions/s21_*.c functions_string/s21_*.c s21_string.c

html_functions_for_*.o: functions_for_sprintf/functions_for_*.c 
	$(CCTEST) $(CFLAGS) functions_for_sprintf/functions_for_*.c 

html_general_helper_functions.o: functions_for_sprintf/general_helper_functions.c
	$(CCTEST) $(CFLAGS) functions_for_sprintf/general_helper_functions.c

s21_*.o: string_processing_functions/s21_*.c functions_string/s21_*.c s21_string.c
	$(CC) $(CFLAGS) string_processing_functions/s21_*.c functions_string/s21_*.c s21_string.c

functions_for_*.o: functions_for_sprintf/functions_for_*.c 
	$(CC) $(CFLAGS)  functions_for_sprintf/functions_for_*.c

general_helper_functions.o: functions_for_sprintf/general_helper_functions.c
	$(CC) $(CFLAGS) functions_for_sprintf/general_helper_functions.c


clean:
	rm -rf *.o *.a *.gcno *.gcda *.info *.gcov
