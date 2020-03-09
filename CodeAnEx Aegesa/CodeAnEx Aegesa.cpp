// CodeAnEx Aegesa.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Created by: Solomon Pattee

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <list>
#include <iterator>
#include "World.h"

using namespace std;

// templates
template <class printedT>
printedT output(string i)
{
	cout << setprecision(2) << fixed << endl;
	return i;
}

// globals

World d;

// function declarations
void menyu();
string dialougeInput(string);

int main()
{
	system("Color 0A");
	// formating
	// title screen
#pragma region Title

	cout 
		<< "####################################################################################################################\n"
		<< "#####################################################################################################################\n"
		<< "#####################################################################################################################\n"
		<< "   CCCCCCCCCCC        OOOOOOOOOO            DDDDDDDD              EEEEEEEEEEEEEEEEEEE   \n"
		<< "  CCCCC              OOO        OOO         DD       DD           EEEEEEEE    \n"
		<< " CC                 OO           OO         DD         DD          EE     \n"
		<< "CC                 OO              OO       DD         DD          EE   \n"
		<< "CC       =====  == OO              OO  ==  DD         DD   ==    EEEEEEEEE    === \n"
		<< "CC       =====  == OO             OO ==   DD         DD   ==    EEEEEEEEEE   === \n"
		<< " CC                OO            OO      DD        DD           EE                                       XXXXX    XXXXXXX\n"
		<< "  CC                OO          OO      DD       DD            EE                                    XXXX      XXXXXX\n"
		<< "   CCCCC             OO        OO      DD     DDD             EEEEEE                               XXXX    XXXXX\n"
		<< "    CCCCCCCCCCC       OOOOOOO         DDDDDDDDD              EEEEEEEEEEEEEEEEE                    XXX    XXXX\n"
		<< "                                                                     XXXXXX     XXXX          XXXXX  XXXXX\n"
		<< "   AAAAAAA                                     EEEEEEEEEEEEEEEE             XXX     XX      XXX   XXX\n"
		<< "   AA    AA                                   EEEEE                             XX   XX XXX      XXX\n"
		<< "  AAA    AAA                                 EEEE                                  X XXXXXXXX\n"
		<< "  AAAA     AAAA                              EEE                                   XXXXXXX \n"
		<< "  AA  AAAAAAAAAAA          NN    NNNNNN     EEEEEEEEE    ===   ==    =          XXXXXXXXX             == = == = \n"
		<< "   AA          AAAA         NNNN       NN   EEEEEEEEEEE   == ===   =         XXXXXXX  XXXXX XX = =   ===  = \n"
		<< "    AA           AAAAA       NN         NN   EEEE                        XXXXXX        XXXX    XXX   \n"
		<< "     AA            AAAAA      NN         NN     EEEE                  XXXXXX            XXXX    XXXXXX \n"
		<< "      AA              AAAAA     NN         NN      EEEEEEEEEE    XXXXXXXX                 XXXX    XXXXX\n"
		<< "       AA                AAAAA   NN          NN     EEEEEEEEEEEEEEEE                         XXX    XXXXXXXXX\n"
		<< "                                                                                                      XXXXXXXXXXXXXXXXX\n"
		<< "################################################################################################################################# = =     - - - -  + +  \n"
		<< "==========         ------           ------=-=-=-              ===   = -=--           =---==--  ===--            ========- -    --+ == +=+ = -\n"
		<< "==========  ==    ------    ----------=----          =-=---=     === = --    ----------=----==     = ===----====    =====  ==    -----  \n"
		<< "=========   ===   ------    -------=---==-      --= ========      -  = --    --=============== ==    ====================   ===   ----+   +    +  + + -  \n"
		<< "========   ======-------   ---------=------   =  -= =========   = -= -=-=-     --------=------=====     ==== ============   ======----*   *   **    * * --    \n"
		<< "=======           ------==            ---=-     ==== ===============  = --==          ---=-= ==========      ===========           --- + +   ++ + -+   + ++-    \n"
		<< "======    ======    --------   -----=------ --      --======-=        ===---==   -----=------=---- === ===       ======    ======    ---            \n"
		<< "=====    ========    =======    ====-=------ --       = = =====   -  = -======    ====-=----- ===========         ====    ========    == + +   + +     \n"
		<< "=====    ========     =======               -=-- -                -= -=========               ===              =======    ========     =   +  + +  + +   \n"
		<< "=================---------------------=--------========================-=- -  = -= -=-=- = ========---- === ========    \n"

		<< endl;
#pragma endregion

	cout << "Press Enter to Play" << endl;
	cin.get();

	// gamemenu

	menyu();

	system("PAUSE");
}

void menyu()
{
	system("CLS");
	int choice = 0;
	cout << "Main Menu\n"
		<< "\n"
		<< "New Game (n)\n"
		<< "Continue (c)\n"
		<< "Quit Game (q)" << endl;

	// choice goes here
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 'n':
		case 1:
		case 'N':

			choice = 0;
			d.beginningStory();
			choice = '4';
			break;

		case 'c':
		case 2:
		case 'C':
			choice = 0;

			break;

		case 'q':
		case 3:
		case 'Q':
			choice = 0;
			cout << endl;
			cout << "GoodBye!" << endl;
			choice = '4';
			break;

		default:
			choice = 0;
			cout << "Invalid option..." << endl; // infinite loop of death
			system("CLS");
			menyu();
			break;
		};
	} while (choice != '4');
}

string dialougeInput(string pvalue)
{
	getline(cin, pvalue);
	pvalue.erase(remove(pvalue.begin(), pvalue.end(), '\n'), pvalue.end());
	return pvalue;
}