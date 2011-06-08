/*
 *
 *
 */

#ifndef SCARD_H
#define SCARD_H

#include <winscard.h>
#include "apdu.h"

class SCard {

	private:

		SCARDCONTEXT context;
		SCARDHANDLE card;
		LPTSTR reader;
		DWORD protocol;
		SCARD_IO_REQUEST pioSendPci;
		SCARD_IO_REQUEST pioRecvPci;
					
	public:
		
		SCard();
		~SCard();
		void setContext(unsigned int scope);
		//void listReaders();
		
		char*  getReader();
		void connect();
		void transmit(const APDU &cdmApdu, APDU &respApdu);
		void disconnect();
		
};

#endif //SCARD_H