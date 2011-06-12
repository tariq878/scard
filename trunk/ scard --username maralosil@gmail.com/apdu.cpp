#include <sstream>
#include <iomanip>
#include "apdu.h"

APDU::APDU()
{} 

APDU::APDU(byte *buffer, int length) {
	
	for(int i=0; i < length; i++)
	{
		apduBuffer.push_back(buffer[i]);
	}
}
	
APDU::APDU(String apdu, Separator sep){
	
	const char* dlmter;
	
	switch(sep){
		
		default:
		case COLON:
			dlmter = ":";
			break;

		case SEMICOLON:
			dlmter = ";";
			break;

		case COMMA:
			dlmter = ",";
			break;

		case SPACE:
			dlmter = " ";
			break;

	}
	
	std::list<String> tokens = apdu.split(dlmter);
	std::list<String>::iterator it;

	for(it=tokens.begin(); it != tokens.end(); it++){
		
		String s = (*it).trim();

		apduBuffer.push_back(s.toLong(16));
	}
}

APDU::~APDU(){}

std::vector<byte> APDU::getBuffer() const{
	
	return apduBuffer;
}

void APDU::setBuffer(std::vector<byte> buffer){
	
	apduBuffer = buffer;
}

String APDU::toString(){

	std::stringstream apdu;

	std::vector<byte>:: iterator it = apduBuffer.begin();

	for(int j=1; it!=apduBuffer.end(); it++,j++){

		apdu << std::setfill('0') << std::setw(2)
			<< std::hex << (int)*it; 
		
		if(j < apduBuffer.size())
			apdu << " ";
	}
			
	return apdu.str();
}
