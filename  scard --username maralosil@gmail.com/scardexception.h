#ifndef SCARDEXCEPTION_H
#define SCARDEXCEPTION_H

class SCardException {

	private:
		
		long _id;

	public:
		
		
		SCardException(long id);

		long getId();
		char* what();

				
};

#endif //SCARDEXCEPTION_H