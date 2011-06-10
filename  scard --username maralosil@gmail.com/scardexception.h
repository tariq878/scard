#ifndef SCARDEXCEPTION_H
#define SCARDEXCEPTION_H

#include "stringx.h"

class SCardException {

	private:
		
		long _id;

	public:
		
		SCardException(long id);

		long getId();
		String what();
		char* getMessage(); 
				
};

#endif //SCARDEXCEPTION_H