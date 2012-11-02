// test.cpp : Defines the entry point for the console application.
//

#include "../zslib/zsdk_def.h"


int main(int argc, char* argv[])
{
	DWORD hScan = 0, res;
	zRPCAnswer answer;


	wchar_t buffer[1024];
	GetEnvironmentVariable(L"ZSDK_BASES",(wchar_t*)&buffer, 1024);

	hScan = StartScan(L"c:\\WINDOWS\\notepad.exe");

	while(1)
	{
		res = GetScanData(hScan, answer);

		if(res != ZSDK_REQUEST_MORE_DATA)
			break;
	}

	return 0;
}

