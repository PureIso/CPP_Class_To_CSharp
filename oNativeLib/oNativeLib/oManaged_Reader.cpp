#include "stdafx.h"
#include "oManaged_Reader.h"

namespace oNativeLib 
{
	char * oManaged_Reader::oManagedStringToCharStar(String ^ m_String)
	{
			pin_ptr<const wchar_t> wch = PtrToStringChars(m_String);
			size_t convertedChars = 0;
			size_t  sizeInBytes = ((m_String->Length + 1) * 2);
			char    *ch = (char *)malloc(sizeInBytes);
			errno_t err = 0;
			err = wcstombs_s(&convertedChars, ch, sizeInBytes,wch, sizeInBytes);
			return ch;
	};

	// Allocate the native object on the C++ Heap via a constructor
	oManaged_Reader::oManaged_Reader(String ^filePtr)
	{
		m_Impl = new oUnmanaged_Reader(oManagedStringToCharStar(filePtr));
	};

		// Deallocate the native object on a destructor
	oManaged_Reader::~oManaged_Reader() 
	{
		delete m_Impl;
	};

	String^ oManaged_Reader::ReadAllLines()
	{
		return gcnew String(m_Impl->oReadAllLines().c_str());
	}

	String^ oManaged_Reader::ReadLine(int line)
	{
		return gcnew String(m_Impl->oReadLine(line).c_str());
	}
}
