/****************************************************************************
** ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─
** ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐
** ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴
** A Powerful General Purpose Framework
** More information in: https://aurora-fw.github.io/
**
** Copyright (C) 2017 Aurora Framework, All rights reserved.
**
** This file is part of the Aurora Framework. This framework is free
** software; you can redistribute it and/or modify it under the terms of
** the GNU General Public License version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE included in the
** packaging of this file. Please review the following information to
** ensure the GNU General Public License version 3 requirements will be
** met: https://www.gnu.org/licenses/gpl-3.0.html.
****************************************************************************/

#include <AuroraFW/Aurora.h>

using namespace AuroraFW;

Application *MyApp;

afwslot slot_MyApp_on_open()
{
	if(!Debug::getDebugStatus())
	{
		CLI::Log(CLI::Notice, "debug is disable");
	}
	if(Debug::getDebugStatus())
	{
		CLI::Log(CLI::Notice, "test the log");
		CLI::Log(CLI::Warning, "test the log");
		CLI::Log(CLI::Error, "test the log");
		CLI::Log(CLI::Notice,"test the log");
		Debug::Log("test the log");
	}
	#ifdef AURORAFW_
		CLI::Log(CLI::Notice, "Aurora Framework Macro detected!");
	#endif

	CLI::Log(CLI::Information, "Getting total virtual memory:\t\t", Info::RAM::getTotalVirtualMemory());
	CLI::Log(CLI::Information, "Getting used virtual memory:\t\t", Info::RAM::getUsedVirtualMemory());
	CLI::Log(CLI::Information, "Getting free virtual memory:\t\t", Info::RAM::getFreeVirtualMemory());
	CLI::Log(CLI::Information, "Getting total physical memory:\t\t", Info::RAM::getTotalPhysicalMemory());
	CLI::Log(CLI::Information, "Getting used physical memory:\t\t", Info::RAM::getUsedPhysicalMemory());
	CLI::Log(CLI::Information, "Getting free physical memory:\t\t", Info::RAM::getFreePhysicalMemory());
	CLI::Log(CLI::Information, "Getting Operation System Name:\t\t", Info::OS::getName());
	CLI::Log(CLI::Information, "Getting Operation System Architecture:\t", Info::OS::getArchitecture());
	CLI::Log(CLI::Information, "Getting Operation System Manufacturer:\t", Info::OS::getManufacturer());
	CLI::Log(CLI::Information, "Getting Operation System Version:\t\t", Info::OS::getVersion());
	CLI::Log(CLI::Information, "Getting User Computer Name:\t\t", Info::OS::getUserComputerName());

	//Input testing
	CLI::Output << "Insert something: ";
	int hello;
	CLI::Input >> hello;
	CLI::Output << hello << CLI::EndLine;
	Application::ExitSuccess();
}

int main(int argc, char * argv[])
{
	MyApp = new Application(slot_MyApp_on_open, argc, argv);
	delete MyApp;
	return 0;
}
