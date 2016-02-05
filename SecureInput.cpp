#include "SecureInput.h"

int SecureInput::Input(char *myString, int &resource)
{
	char chTemp[12], buff;
	int maxDigit(10), testdig(0), digit(0);
	bool sign(false);

	for (int i = 0; i < 12; i++)
	{
		chTemp[i] = '\0';
	}

	while (true)
	{
		system("cls");
		cout << myString << chTemp;
		buff = _getch();

		if ((digit == 1) && (atoi(chTemp) == 0) && buff == '0'); //Only one zero at the beginning.
		else
		{
			if (isdigit(buff) && (digit < maxDigit)) //If the number of digits in length within int.
			{
				if (digit == 9) //If current length smaller of max length on one element.
				{
					testdig = atoi(chTemp);
					if (((testdig < 0) && (testdig > PRE_MIN_SIGN_INT)) || ((testdig == PRE_MIN_SIGN_INT) && (buff < 57)))
						//write from buffer if number biggest of PRE_MIN_SIGN_INT & smaller 0 OR number == PRE_MIN_SIGN_INT & buffer char in range '0' - '8'.
					{
						chTemp[strlen(chTemp)] = buff;
						digit++;
					}
					else
					{
						if (((testdig < PRE_MAX_SIGN_INT) && (testdig >= 0)) || ((testdig == PRE_MAX_SIGN_INT) && (buff < 56)))
							//write from buffer if number smaller of PRE_MAX_SIGN_INT & >= 0 OR number == PRE_MAX_SIGN_INT & buffer char in range '0' - '7'.
						{
							chTemp[strlen(chTemp)] = buff;
							digit++;
						}
					}
				}
				else
				{
					if ((sign == true) && (chTemp[1] == '\0') && (buff == '0')); //don't write 0 if string have sign nd don't have digit.
					else
					{
						chTemp[strlen(chTemp)] = buff;
						digit++;
					}
				}
			}
			else
			{
				if ((sign == false && digit == 0) && (buff == '-')) //if string don't have sign, digit and buff is '-'.
				{
					chTemp[0] = buff;
					sign = true;
				}
				else
				{
					if (buff == ENTER && digit > 0) //if have digit in string and press ENTER.
					{
						resource = atoi(chTemp); // convert to int.
						break;                   // and break WHILE CYCLE.
					}
					else
					{
						if (buff == BACKSPACE && strlen(chTemp) > 0) //if press BACKSPACE & string != '\0'.
						{
							buff = chTemp[strlen(chTemp) - 1]; // cope erase symbol.
							chTemp[strlen(chTemp) - 1] = '\0';
							if (isdigit(buff)) //if erase digit.
							{
								digit--;
							}
							else //if erase sign.
							{
								sign = false;
							}
						}
					}
				}
			}
		}
	}

	return 1; //Return if succes and AND END FUNCTION.
};

int SecureInput::Input(char *myString, unsigned int &resource)
{
	char chTemp[11], buff;
	int maxDigit(10), testdig(0), digit(0);

	for (int i = 0; i < 11; i++)
	{
		chTemp[i] = '\0';
	}

	while (true)
	{
		system("cls");
		cout << myString << chTemp;
		buff = _getch();

		if ((digit == 1) && (strtoul(chTemp, NULL, 10) == 0) && buff == '0'); //Only one zero at the beginning.
		else
		{
			if (isdigit(buff) && (digit < maxDigit)) //If the number of digits in length within int.
			{
				if (digit == 9) //If current length smaller of max length on one element.
				{
					testdig = strtoul(chTemp, NULL, 10);
					if ((testdig < PRE_MAX_UNSIGN_INT) || ((testdig == PRE_MAX_UNSIGN_INT) && (buff < 54)))
						//write from buffer if number smaller of PRE_MAX_UNSIGN_INT || number == PRE_MAX_UNSIGN_INT & buffer char in range '0' - '5'.
					{
						chTemp[strlen(chTemp)] = buff;
						digit++;
					}
				}
				else
				{
					chTemp[strlen(chTemp)] = buff;
					digit++;
				}
			}
			else
			{
				if (buff == ENTER && digit > 0) //if have digit in string and press ENTER.
				{
					resource = strtoul(chTemp, NULL, 10); // convert to int.
					break;                   // break WHILE CYCLE.
				}
				else
				{
					if (buff == BACKSPACE && strlen(chTemp) > 0) //if press BACKSPACE & string != '\0'
					{
						chTemp[strlen(chTemp) - 1] = '\0';
						digit--;
					}
				}
			}
		}
	}

	return 1; //Return if succes and AND END FUNCTION.
}


int SecureInput::Input(char *myString, double &resource)
{
	char chTemp[24], buff, backBuff;
	bool dot(false), sign(false);
	int digitAfterPoint(0), digitBeforePoint(0), maxBeforeDig(19), maxAfterPoint(2), testDig(0);

	for (int i = 0; i < 24; i++)
	{
		chTemp[i] = '\0';
	}

	while (true)
	{
		system("cls");
		cout << myString << chTemp;
		buff = _getch();

		if (dot == false) //if string don't have dot.
		{
			if ((digitBeforePoint == 1) && (atof(chTemp) == 0) && isdigit(buff)); //NOTHIG if string have only 0 & buffer include digit symbol.
			else
			{
				if (isdigit(buff) && (digitBeforePoint < maxBeforeDig)) //if buffer is digit & current length smaller of max length before dot.
				{
					if ((atof(chTemp) < PRE_MAX_DOUBLE && (atof(chTemp) > -1)) || (atof(chTemp) == PRE_MAX_DOUBLE && buff < 56))
						//write from buffer if number smaller of PRE_MAX_DOUBLE & > -1 || number == PRE_MAX_DOUBLE & buffer char in range '0' - '7'.
					{
						chTemp[strlen(chTemp)] = buff;
						digitBeforePoint++;
					}
					else if (((atof(chTemp) > PRE_MIN_DOUBLE) && atof(chTemp) < 0) || (atof(chTemp) == PRE_MIN_DOUBLE && buff < 57))
						//write from buffer if number biggest of PRE_MIN_DOUBLE & < 0 || number == PRE_MIN_UNSIGN_DOUBLE & buffer char in range '0' - '8'.
					{
						chTemp[strlen(chTemp)] = buff;
						digitBeforePoint++;
					}
				}
				else if ((buff == '-' && sign == false && digitBeforePoint == 0) || ((buff == '.' && digitBeforePoint > 0)))
					//write from buffer if buff = '-' & string don't have sign & don't hav digit || buff is dot & and string have digit.
				{
					if (buff == '-') //if buff is sign.
					{
						chTemp[strlen(chTemp)] = buff;
						sign = true;
					}
					else if ((atof(chTemp) > MIN_DOUBLE && atof(chTemp) < 0) || (atof(chTemp) < MAX_DOUBLE && (atof(chTemp) > -1))) //if buff is dot.
						//write from buffer if number > MIN_DOUBLE & < 0 || buffer < MAX_DOUBLE & > -1.
					{
						chTemp[strlen(chTemp)] = buff;
						dot = true;
					}
				}
				else if (buff == BACKSPACE && strlen(chTemp) > 0) //if press backspace & length don't '\0'
				{
					backBuff = chTemp[strlen(chTemp) - 1];
					chTemp[strlen(chTemp) - 1] = '\0';
					if (isdigit(backBuff)) //erase digit
					{
						digitBeforePoint--;
					}
					else //erase sign
					{
						sign = false;
					}
				}
				else if (buff == ENTER && digitBeforePoint > 0) //if have digit in string and press ENTER.
				{
					resource = atof(chTemp); //convert to double.
					break; // break WHILE CYCLE.
				}
			}
		}
		else //DOT = TRUE
		{
			if (isdigit(buff) && (digitAfterPoint < maxAfterPoint))
			{
					chTemp[strlen(chTemp)] = buff;
					digitAfterPoint++;
			}
			else if (buff == BACKSPACE) //if press backspace
			{
				chTemp[strlen(chTemp) - 1] = '\0';
				if (digitAfterPoint > 0) //erase digit
				{
					digitAfterPoint--;
				}
				else //erase dot
				{
					dot = false;
				}
			}
			else if (buff == ENTER && digitAfterPoint > 0) //if have digit in string and press ENTER.
			{
				resource = atof(chTemp); //convert to double.
				break; // break WHILE CYCLE.
			}
		}
	}

	return 1; //Return if succes and AND END FUNCTION.
};

int SecureInput::Input(char *myString, char &resource)
{
	system("cls");
	cout << myString;
	resource = _getch();

	return 1; //Return if succes and AND END FUNCTION.
};

int SecureInput::Input(char *myString, char *resource, int resourceLen)
{	
	char buff('\0');
	char *chTemp = new char[resourceLen]; //Create dynamic temporary massive with resource size.
	int newLen(0);

	for (int i = 0; i < resourceLen; i++) //INITIALIZE ALL temporary string elements as '\0'! THENTS VERY IMPORTANT step.
	{
		chTemp[i] = '\0';
	}

	while (true)
	{
		system("cls");
		cout << myString << chTemp;
		buff = _getch();
		if ((buff > 31) && (buff < 127) && (newLen < (resourceLen - 1)))
			//if symbol in buff in ASCII range 32 - 126 (all ENG keyboard symbols and digit + SPACE) & in massive diapason. Least elements reserved from '\0'.
		{
			chTemp[newLen] = buff;
			newLen++;
		}
		else
		{
			if ((buff == BACKSPACE) && (newLen > 0)) //if press BACKSPACE & string != '\0'.
			{
				chTemp[newLen - 1] = '\0';
				newLen--;
			}
			else if ((buff == ENTER) && (newLen > 0)) //if press ENTER & string !='\0'. If you need empty string, change this: (newLen >= 0)!!!
			{
				strcpy_s(resource, resourceLen, chTemp); // copy from buffer in actual string.
				delete[] chTemp; //!!! Delete dynamic massive.
				break; //BREAK WHILE/
			}
		}
	}

	return 1; //Return if succes and AND END FUNCTION.
};
