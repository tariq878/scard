#ifndef SCARDEXCEPTION_H
#define SCARDEXCEPTION_H

class SCardException {

	private:
		
		long _id;

	public:
		
		SCardException(long id);

		char* what();

				
};

#endif //SCARDEXCEPTION_H