#include "stdafx.h"
#include "oFileAndDirectory.h"

namespace oNativeLib
{
	int oFileAndDirectory::oMountDrive(string to, string user, string password)
	{
		if(system(NULL)) puts("ok");
		else exit (EXIT_FAILURE);
		//string that mounts network folder to an anonymous drive
		string mount = "net use "+to+" /user:"+user+" "+password;
		// system call that mounts folder
		system(mount.c_str()); 
		return 0;
	};

	int oFileAndDirectory::oDisMountDrive(string to)
	{
		if(system(NULL)) puts("ok");
		else exit (EXIT_FAILURE);
		// unmount shared folder
		string unmount = "net use "+to+" /delete";
		system( unmount.c_str());
		return 0;
	};

	int oFileAndDirectory::oFileCopy(char* from, char* to)
	{
		ifstream  src(from, ios::binary);
		ofstream  dst(to,   ios::binary);
		dst << src.rdbuf();

		src.close();
		dst.close();
		return 0;
	};

	int oFileAndDirectory::oMoveFileNetwork(string from, string to, string user, string password)
	{
		string copyCmd;
		oFileAndDirectory::oMountDrive(to,user,password);
		copyCmd = "copy /b " + from + " " + to;
		system(copyCmd.c_str());
		oFileAndDirectory::oDisMountDrive(to);
		return 0;
    }

	int oFileAndDirectory::oMoveFolderNetwork(string from, string to, string user, string password)
	{
		string copyCmd;
		oFileAndDirectory::oMountDrive(to,user,password);
		copyCmd = "xcopy " + from + " " + to+" /e /i /h ";
		system(copyCmd.c_str());
		oFileAndDirectory::oDisMountDrive(to);
		return 0;
    }
}