

#ifndef APDU_H
#define APDU_H

#include <vector>
#include "scardtypes.h"
#include "stringx.h"

class APDU {

	protected:
		
		vector<byte> apduBuffer;
		
	public:
		
		//Contructors
		APDU();
		APDU(byte *buffer, int length);
		APDU(String apdu);

		//Destructor
		~APDU();

		//Methods
		vector<byte> getBuffer() const;
		void setBuffer(vector<byte> buffer);
		String toString();
				
};

#endif //APDU_H


