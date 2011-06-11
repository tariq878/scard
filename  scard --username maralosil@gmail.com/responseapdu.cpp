#include "responseapdu.h"

ResponseAPDU::ResponseAPDU()
{}

ResponseAPDU::ResponseAPDU(byte *buffer, int length)
	:APDU(buffer,length)
{}

ResponseAPDU::ResponseAPDU(String apdu)
	:APDU(apdu)
{}

std::vector<byte> ResponseAPDU::getData(){
	
	std::vector<byte> tmp = apduBuffer;

	tmp.pop_back();
	tmp.pop_back();

	return tmp;
}

byte ResponseAPDU::getSW1(){

	return apduBuffer.at(apduBuffer.size()-2);
}

byte ResponseAPDU::getSW2(){

	return apduBuffer.back();
}

int ResponseAPDU::getSW(){
	
	return (((getSW1()<<8)&0xFF00) | (getSW2()&0xFF));
}