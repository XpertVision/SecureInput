#ifndef _SECURE_INPUT_H_
#define _SECURE_INPUT_H_

//LICENSE GNU GPL 3.0 
//CLASS FROM SACERU INPUT DOUBLE, INT, UNSIGNED INT, CHAR AND CHAR[] FROM WINDOWS CONSOLE. FROM 32-BIT APPLICATION.
//FUNCTIONS NEED STRING WITH TEXT FROM APPLICATION USERS AND VARIABLE FOR INPUT FROM CONSOLE.
//ALL FUNCTIONS RETURN 1 IF SUCCED.

//Сlass written not a professional programmer. Performance may be low for this task. Oriented more to learning. Enjoy using.

//AUTHOR: MAXYM BEZUGLYY EMAIL: maxim.bez.1990@gmail.com


#include <iostream>

#define BACKSPACE 8
#define ENTER 13

#define PRE_MAX_SIGN_INT 214748364
#define PRE_MIN_SIGN_INT -214748364

#define PRE_MAX_UNSIGN_INT 429496729

#define PRE_MAX_DOUBLE 922337203685477580.0
#define MAX_DOUBLE 9223372036854775807.0
#define PRE_MIN_DOUBLE -922337203685477580.0
#define MIN_DOUBLE -9223372036854775808.0

using namespace std;

class SecureInput {
public:
	int Input(char *myString, int &resource);
	int Input(char *myString, unsigned int &resource);
	int Input(char *myString, double &resource);
	int Input(char *myString, char &resource);
	int Input(char *myString, char *resource, int resourceLen);
};

#endif
