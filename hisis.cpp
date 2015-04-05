/*
   HiSIS CCD Driver, based on Generic CCD Template for INDI Developers

   Copyright (C) 2015 Riccardo Stagni (unriccio@email.it)

 */

#include <memory>
#include "hisis.h"

std::auto_ptr<HiSIS> hisis(0);

void ISInit()
{
	static int isInit=0;
	if (isInit)
		return;
	if (hisis.get() == 0)
	{
		isInit = 1;
		hisis.reset(new HiSIS());
	}
}

void ISGetProperties (const char *dev)
{
	ISInit();
	hisis->ISGetProperties(dev);
}

void ISNewSwitch (const char *dev, const char *name, ISState *states, char *names[], int n)
{
	ISInit();
	hisis->ISNewSwitch(dev, name, states, names, n);
}

void ISNewText (const char *dev, const char *name, char *texts[], char *names[], int n)
{
	ISInit();
	hisis->ISNewText(dev, name, texts, names, n);
}

void ISNewNumber (const char *dev, const char *name, double values[], char *names[], int n)
{
	ISInit();
	hisis->ISNewNumber(dev, name, values, names, n);
}

void ISNewBLOB (const char *dev, const char *name, int sizes[], int blobsizes[], char *blobs[], char *formats[], char *names[], int n)
{
	INDI_UNUSED(dev);
	INDI_UNUSED(name);
	INDI_UNUSED(sizes);
	INDI_UNUSED(blobsizes);
	INDI_UNUSED(blobs);
	INDI_UNUSED(formats);
	INDI_UNUSED(names);
	INDI_UNUSED(n);
}

void ISSnoopDevice (XMLEle *root)
{
	ISInit();
	hisis->ISSnoopDevice(root);
}

HiSIS::HiSIS()
{
}

HiSIS::~HiSIS()
{
}

const char * HiSIS::getDefaultName()
{
	return "HiSIS CCD";
}

bool HiSIS::Connect()
{
	DEBUG(INDI::Logger::DBG_SESSION, "Attempting to find the CCD...");
	DEBUG(INDI::Logger::DBG_SESSION, "CCD found, retrieving data.");
	return true;
}

bool HiSIS::Disconnect()
{
	DEBUG(INDI::Logger::DBG_SESSION, "Disconnected successfully!");
	return true;
}

void HiSIS::ISGetProperties(const char *dev)
{
	INDI::CCD::ISGetProperties(dev);

	defineText(&PortTP);
}

bool HiSIS::initProperties() {
	// Init parent properties first
	INDI::CCD::initProperties();

	IUFillText(&PortT[0], "PORT", "Port", "0x378");
	IUFillTextVector(&PortTP, PortT, 1, getDeviceName(), "DEVICE_PORT", "Ports", MAIN_CONTROL_TAB, IP_RW, 0, IPS_IDLE);

	return true;
}

bool HiSIS::updateProperties() {
	INDI::CCD::updateProperties();

	if (isConnected())
	{
		// Let's get parameters now from CCD
		setupParams();
	}

	return true;
}

bool HiSIS::setupParams()
{
	return true;
}

