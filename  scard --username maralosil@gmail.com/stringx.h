
#ifndef STRINGX_H
#define STRINGX_H

#include <cstring>
#include <cctype>
#include <string>
#include <list>

class String : public std::string {
	
	public:
		
		//Constructors
		String (char* s) : std::string(s) {};
		String (const std::string& s) : std::string(s) {};

				
		std::list<String> split(const char* delimiter) {
			
			std::list<String> tokens;
					
			char* data = new char [this->size()+1];
			::strcpy(data, this->c_str());
			
			
			char * pch = 0;
			pch = ::strtok (data,delimiter);
			
			while (pch != 0)
			{
				String s(pch);
				tokens.push_back(s);
				pch = strtok (0,delimiter);
			}
			
			delete data;
			
			return tokens;
		}
		
		String trim() {
			
			char* data = new char [this->size()+1];
			::strcpy(data, this->c_str());

			char* lch = data;

			while(isspace(*lch))
				lch++;

			char* rch = data +strlen(data); 

		    while(isspace(*--rch));
			
			*(rch+1) = '\0';
			
			String trimmed(lch);

			delete data;

			return trimmed;
	
		}
		
		long toLong(int base){

			return ::strtol( this->c_str(), 0, base);
								
		}
};

#endif //STRINGX_H