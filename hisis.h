/*
   HiSIS CCD Driver, based on Generic CCD Template for INDI Developers

   Copyright (C) 2015 Riccardo Stagni (unriccio@email.it)

 */

#ifndef HISIS_H
#define HISIS_H

#include <indiccd.h>

class HiSIS : public INDI::CCD
{
	public:
		HiSIS();
		~HiSIS();

		void ISGetProperties(const char *dev);

	protected:
		const char *getDefaultName();

		bool Connect();
		bool Disconnect();

		bool initProperties();
		bool updateProperties();

	private:
		ISwitch ConnS[2];
		ISwitchVectorProperty ConnSP;
		ISwitch PortS[3];
		ISwitchVectorProperty PortSP;

		bool setupParams();
};

#endif // HISIS_H
