#include "oNativeLib.h"
#include "oUnmanaged_Reader.h"

using namespace System;

namespace oNativeLib {

	public ref class oManaged_Reader
	{
	private:
		oUnmanaged_Reader * m_Impl;

	internal:
		static char * oManagedStringToCharStar(String ^ m_String);
	public:
		// Allocate the native object on the C++ Heap via a constructor
		oManaged_Reader(String ^filePtr);
		// Deallocate the native object on a destructor
		~oManaged_Reader();

		String^ ReadAllLines();
		String^ ReadLine(int line);
	};
}