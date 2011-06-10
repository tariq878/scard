/*
 *
 *
 */


#include <string>
#include <iostream>
#include "scard.h"

using namespace std;

SCard::SCard()
	: context(SCARD_SCOPE_USER), card(0), reader(0), protocol(0) {}


SCard::~SCard(){
	
	if(context){
		
		if(reader){
			::SCardFreeMemory(context, reader);
			cout << "SCardFreeMemory" << endl;
		}
		::SCardReleaseContext(context);
		cout << "SCardReleaseContext" << endl;
	}

	cout << "end destructor" << endl;
	
}


void SCard::setContext(unsigned int scope) {
	
	int rv = ::SCardEstablishContext(scope,NULL,NULL,&context);

	if(rv != SCARD_S_SUCCESS)
		throw SCardException(rv);
}

/*
void SCard::listReaders(){

	::SCardListReaders(context, NULL,(LPTSTR)&readers, &dwReaders);
}
*/

char* SCard::getReader(){

	return reader;
	
}

void SCard::connect() throw (SCardException){

	unsigned long AUTO_ALLOC = SCARD_AUTOALLOCATE;
	long rv;
	

	rv = ::SCardListReaders(context, NULL, (LPTSTR)&reader, &AUTO_ALLOC);

	 
	if(rv != SCARD_S_SUCCESS)
		throw SCardException(rv);

	rv = ::SCardConnect(context, reader, SCARD_SHARE_SHARED,SCARD_PROTOCOL_T0 | SCARD_PROTOCOL_T1, &card, &protocol);

	if(rv != SCARD_S_SUCCESS)
		throw SCardException(rv);

	switch(protocol)
	{
		case SCARD_PROTOCOL_T0:
			pioSendPci = *SCARD_PCI_T0;
			break;

		case SCARD_PROTOCOL_T1:
			pioSendPci = *SCARD_PCI_T1;
			break;
					
	}

	pioRecvPci.dwProtocol = protocol;
	pioRecvPci.cbPciLength = 255;

}

void SCard::disconnect() throw (SCardException) {
	
	int rv = ::SCardDisconnect(card, SCARD_LEAVE_CARD);
	
	if(rv != SCARD_S_SUCCESS)
		throw SCardException(rv);

}

void SCard::transmit(const APDU &cmdApdu, APDU &respApdu) throw (SCardException) {

	vector<byte> cmdApduBuffer = cmdApdu.getBuffer();
	vector<byte>::iterator it;

	int cmdSize = cmdApduBuffer.size();
	byte* cmd = new byte[cmdSize];
	
	int index = 0;
	for(it = cmdApduBuffer.begin(); it < cmdApduBuffer.end(); it++){
	
		cmd[index] = *it;
		index++;
	}

	byte resp[255]; //buffer size maximum
	unsigned long respLength = sizeof(resp);

	int rv = ::SCardTransmit(card,&pioSendPci,cmd,cmdSize,&pioRecvPci,resp,&respLength);
	
	delete[] cmd;
	
	if(rv != SCARD_S_SUCCESS)
		throw SCardException(rv);

	vector<byte> respApduBuffer;

	for(int ct =0; ct < respLength; ct++){
	
		respApduBuffer.push_back(resp[ct]);
	}
		
	respApdu.setBuffer(respApduBuffer);

}