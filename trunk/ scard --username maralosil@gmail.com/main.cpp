#include <iostream>
#include "scard.h"

using namespace std;


int main(){

	SCard card;
	
	
	try {

		card.setContext(SCARD_SCOPE_SYSTEM);
		
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



