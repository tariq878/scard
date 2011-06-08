
#ifndef STRINGX_H
#define STRINGX_H

#include <cstring>
#include <cctype>
#include <string>
#include <list>


using namespace std;

class String : public string {
	
	public:
		
		//Constructors
		String (char* s) : string(s) {};
		String (const std::string& s) : string(s) {};

				
		list<String> split(const char* delimiter) {
			
			list<String> tokens;
					
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