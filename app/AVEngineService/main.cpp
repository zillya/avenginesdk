#include "RpcServer.h"
#include "ServiceDefault.h"
#include <iostream>
using namespace Zillya;

//Service name and display name defines
#define SERVICE_NAME				L"ZillyaAVEngine"
#define SERIVCE_DISPLAY_NAME		L"Zillya AVEngine Service"

int main(int argc, char **argv)
{
	//Create service
	ServiceDefault *service = ServiceDefault::getInstance();

	if(argc == 2)
	{
		if(strcmp(argv[1], "-i") == 0)
		{
			TCHAR szCurrentDirectory[MAX_PATH];
			GetCurrentDirectory(MAX_PATH, szCurrentDirectory);

			std::string		name	= argv[0];
			std::wstring	wname	= std::wstring(name.begin(), name.end());
			std::wstring	wpath	= szCurrentDirectory;

			wpath += L"\\";
			wpath += wname;

			DWORD dwInstall		= service->Install(SERVICE_NAME, SERIVCE_DISPLAY_NAME, wpath.data());
			if(dwInstall != 0)
			{
				std::cout << "Error: cannot install service" << std::endl;
				return -1;
			}
			return 0;
		}
		else if(strcmp(argv[1], "-u") == 0)
		{
			DWORD dwUninstall = service->Uninstall(SERVICE_NAME);
			if(dwUninstall != 0)
			{
				std::cout << "Error: cannot uninstall service" << std::endl;
				return -1;
			}
			return 0;
		}
		else
		{
			std::cout << "Wrong parameter: usage \"-i\" for install and \"-u\" for uninstall" << std::endl;
			return -1;
		}
	}

	//Create RpcServer
	RpcServer server;
	server.Start();
	
	//Run service
	service->Run(SERVICE_NAME);

	std::cin.get();

	return 0;
}