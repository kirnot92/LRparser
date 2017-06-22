#ifndef _TABLE_
#define _TABLE_

#include <iostream>


using namespace std;

enum V {
	ID, PLUS, MULTI, LEFT, RIGHT, END, E, T, F
};


string table[12][9] = {

	//		 ID		PLUS	MULTI	LEFT	RIGHT	END		E		T		F
	/*0*/{  "s5",	"",		"",		"s4",	"",		"",		"g1",	"g2",	"g3" },
	/*1*/{  "",		"s6",	"",		"",		"",		"$0",	"",		"",		""   },
	/*2*/{  "",		"r2",	"s7",	"",		"r2",	"r2",	"",		"",		""   },
	/*3*/{  "",		"r4",	"r4",	"",		"r4",	"r4",	"",		"",		""   },
	/*4*/{  "s5",	"",		"",		"s4",	"",		"",		"g8",	"g2",	"g3" },
	/*5*/{  "",		"r6",	"r6",	"",		"r6",	"r6",	"",		"",		""   },
	/*6*/{  "s5",	"",		"",		"s4",	"",		"",		"",		"g9",	"g3" },
	/*7*/{  "s5",	"",		"",		"s4",	"",		"",		"",		"",		"g10"},
	/*8*/{  "",		"s6",	"",		"",		"s11",	"",		"",		"",		""   },
	/*9*/{  "",		"r1",	"s7",	"",		"r1",	"r1",	"",		"",		""   },
	/*10*/{ "",		"r3",	"r3",	"",		"r3",	"r3",	"",		"",		""   },
	/*11*/{ "",		"r5",	"r5",	"",		"r5",	"r5",	"",		"",		""   }

};

int v_to_num(char a) {
	if (a == 'a') return V::ID;
	else if (a == '+') return V::PLUS;
	else if (a == '*') return V::MULTI;
	else if (a == '(') return V::LEFT;
	else if (a == ')') return V::RIGHT;
	else if (a == '$') return V::END;
	else if (a == 'E') return V::E;
	else if (a == 'T') return V::T;
	else /*if (a == 'F')*/ return V::F;

}


#endif


