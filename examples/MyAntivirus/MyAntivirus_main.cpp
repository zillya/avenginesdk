#include "zsdk_def.h"
#include "stdio.h"
void main()
{
	DWORD hScan = 0;
	DWORD res;
	zRPCAnswer answer;

	hScan = StartScan(L"c:\\WINDOWS\\notepad.exe");

	while(1)
	{
		res = GetScanData(hScan, answer);
		
		printf("");

		if(res == ZSDK_REQUEST_OK){
			printf("All scanned");
			break;
		}
		else if(res == ZSDK_REQUEST_MORE_DATA){
			printf("More data");
		}
		else if(res == ZSDK_REQUEST_ERROR){
			printf("Error in scan");
			break;
		}
	}
	system("pause");
}