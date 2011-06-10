
#include <iostream>
#include <cstdio>
#include <iomanip>
#include "scard.h"
#include "stringx.h"

using namespace std;


int main(){

	SCard card;
	
	card.setContext(SCARD_SCOPE_SYSTEM);
	
	try {

		card.connect();
	
		cout << card.getReader() << endl;

		APDU cmd("A0:A4:00:00:02:3F:00");

		APDU resp;

		card.transmit(cmd,resp);

		cout << cmd.toString() << endl;
		cout << resp.toString() << endl;
	
	} catch(SCardException& e) {

		cerr << e.what() << endl;
		
	}
	
	return 0;
}



