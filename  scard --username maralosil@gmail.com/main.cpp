#include <iostream>
#include "scard.h"
#include "stringx.h"

using namespace std;

int main() {

	SCard card;
	
	try {

		card.setContext(SCARD_SCOPE_SYSTEM);

		card.connect();

		cout << card.getReader() << endl;

		
		char input[256];

		for (;;) {
		
			cout << "apdu> ";
		
			cin.getline(input, sizeof(input));

			String in(input);

			in = in.trim().toLower();

			if (in == "quit") {
				
				cout << "Bye" << endl;
				break;
			}

			APDU cmd(in,APDU::Separator::SPACE);
			
			APDU resp;

			try {

				card.transmit(cmd,resp);
				cout << resp.toString() << endl;	
				
			} catch (SCardException& e) {

				cerr << e.what() << endl;
			}

			
		}
		
	} catch (SCardException& e) {

		cerr << e.what() << endl;
	}
		
	return 0;
}

