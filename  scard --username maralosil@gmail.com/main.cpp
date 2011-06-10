
#include <iostream>
#include <cstdio>
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

		//cout << setw(8) << hex << e.getId << endl;
		printf("Error: returned 0x%08X\n", e.getId());
		cout<< e.what() << endl;

		
	}
	
	return 0;
}



