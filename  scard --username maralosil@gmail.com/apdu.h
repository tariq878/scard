#ifndef APDU_H
#define APDU_H

#include <vector>
#include "scardtypes.h"
#include "stringx.h"

class APDU {

	protected:
		
		std::vector<byte> apduBuffer;
		
	public:
		
		//TODO
		static enum Separator {
			COLON,
			SEMICOLON,
			COMMA,
			SPACE
		};

		//Contructors
		APDU();
		APDU(byte *buffer, int length);
		APDU(String apdu, Separator sep = Separator::COLON);

		//Destructor
		~APDU();

		//Methods
		std::vector<byte> getBuffer() const;
		void setBuffer(std::vector<byte> buffer);
		String toString();
				
};

#endif //APDU_H


