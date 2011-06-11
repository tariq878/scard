#include "responseapdu.h"

ResponseAPDU::ResponseAPDU()
{}

ResponseAPDU::ResponseAPDU(byte *buffer, int length)
	:APDU(buffer,length)
{}

ResponseAPDU::ResponseAPDU(String apdu)
	:APDU(apdu)
{}
		
byte ResponseAPDU::getSW1(){

	return apduBuffer.at(apduBuffer.size()-2);
}

byte ResponseAPDU::getSW2(){

	return apduBuffer.back();
}

int ResponseAPDU::getSW(){
	
	return 0;
}