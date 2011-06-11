#include <iostream>
#include "scard.h"
#include "responseapdu.h"

using namespace std;


int main(){

	ResponseAPDU resp("A0:A4:00:00:02:90:00");
	cout << resp.toString() << endl;

	cout << resp.getSW1() << endl;
	cout << resp.getSW2() << endl;
	cout << resp.getSW() << endl;

	if(resp.getSW() == 0x9000)
		cout << "funfa!" << endl;


#if 0
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
#endif

	
	return 0;
}



