#include "oNativeLib.h"

namespace oNativeLib 
{
	class oUnmanaged_Reader{
	private:
		char * fileName;

	public:
		oUnmanaged_Reader(char * filePtr);	//Constructor
		~oUnmanaged_Reader();

		string oReadAllLines();
		string oReadLine(int line);
	};
}