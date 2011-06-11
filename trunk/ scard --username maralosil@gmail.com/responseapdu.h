#ifndef RESPONSEAPDU_H
#define RESPONSEAPDU_H

#include "apdu.h"

class ResponseAPDU : public APDU {

	public:
		
		ResponseAPDU();
		ResponseAPDU(byte *buffer, int length);
		ResponseAPDU(String apdu);
		
		std::vector<byte> getData();
		byte getSW1();
		byte getSW2();
		int getSW();

};

#endif //RESPONSEAPDU_H
