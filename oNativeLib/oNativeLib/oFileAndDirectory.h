#include "oNativeLib.h"
#include "oManaged_Reader.h"

using namespace System;
namespace oNativeLib 
{
	class oFileAndDirectory{
	private:
		static int oMountDrive(string to, string user, string password);
		static int oDisMountDrive(string to);
	public:
		static int oFileCopy(char * from, char * to);
		static int oMoveFileNetwork(string from, string to, string user, string password);
		static int oMoveFolderNetwork(string from, string to, string user, string password);
	};



	public ref class oManaged_FileAndDirectory
	{
	public:
		static int FileCopy(String ^ from, String ^ to)
		{
			char * a = oManaged_Reader::oManagedStringToCharStar(from);
			char * b = oManaged_Reader::oManagedStringToCharStar(to);

			oFileAndDirectory::oFileCopy(a,b);
			delete a, b;
			return 0;
		}

		static int oMoveFileNetwork(String ^ from, String ^ to, String ^ user, String ^ password)
		{
			char * a = oManaged_Reader::oManagedStringToCharStar(from);
			char * b = oManaged_Reader::oManagedStringToCharStar(to);
			char * c = oManaged_Reader::oManagedStringToCharStar(user);
			char * d = oManaged_Reader::oManagedStringToCharStar(password);

			oFileAndDirectory::oMoveFileNetwork(a,b,c,d);
			getchar();
			delete a, b,c,d;
			return 0;
		}

		static int oMoveFolderNetwork(String ^ from, String ^ to, String ^ user, String ^ password)
		{
			char * a = oManaged_Reader::oManagedStringToCharStar(from);
			char * b = oManaged_Reader::oManagedStringToCharStar(to);
			char * c = oManaged_Reader::oManagedStringToCharStar(user);
			char * d = oManaged_Reader::oManagedStringToCharStar(password);

			oFileAndDirectory::oMoveFolderNetwork(a,b,c,d);
			getchar();
			delete a, b,c,d;
			return 0;
		}
	};
}