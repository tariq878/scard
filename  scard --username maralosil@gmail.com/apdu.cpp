#include <sstream>
#include <iomanip>
#include "apdu.h"


APDU::APDU()
{} 

APDU::APDU(byte *buffer, int length) {
	
	for(int index =0; index < length; index++)
	{
		apduBuffer.push_back(buffer[index]);
	}

}
	
APDU::APDU(String apdu){
	
	list<String> tokens = apdu.split(":");
	list<String>::iterator it;

	for(it=tokens.begin(); it != tokens.end(); it++){
		
		String s = (*it).trim();

		apduBuffer.push_back(s.toLong(16));
	}


}

APDU::~APDU(){}


vector<byte> APDU::getBuffer() const{
	return apduBuffer;
}


void APDU::setBuffer(vector<byte> buffer){
	
	apduBuffer = buffer;

}

String APDU::toString(){

	stringstream apdu;

	vector<byte>:: iterator it;
	
	for(it=apduBuffer.begin(); it != apduBuffer.end(); it++){
		apdu << setfill('0') << setw(2) << hex << (int)*it << " "; 
	}

	return apdu.str();
}
