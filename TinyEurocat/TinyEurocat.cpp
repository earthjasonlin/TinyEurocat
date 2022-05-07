#include "StdAfx.h"
#include "TinyEurocat.h"
#include <cstring>
#include "stdlib.h"
#include <cstdio>

TinyEurocat::TinyEurocat(void) : CPlugIn ( COMPATIBILITY_CODE,
	        "TinyEurocat",
	        "1.0.0",
	        "Future Sim",
	        "Open-source" )
{
	RegisterTagItemType("Metric / Current Altitude", TAG_ITEM_MET_CURR_ALT);
	RegisterTagItemType("Metric / Cleared Altitude", TAG_ITEM_MET_ASS_ALT);
	RegisterTagItemType("Metric / Current Speed", TAG_ITEM_MET_CURR_SPD);
}

void TinyEurocat::OnGetTagItem( CFlightPlan FlightPlan,
                                CRadarTarget RadarTarget,
                                int ItemCode,
                                int TagData,
                                char sItemString [ 16 ],
                                int *pColorCode,
                                COLORREF *pRGB,
                                double *pFontSize )
{
	int maalt, mcalt, mcspd;
	switch (ItemCode)
	{
		case TAG_ITEM_MET_ASS_ALT:
			maalt = FlightPlan.GetClearedAltitude() * 0.3048;
			if(maalt != 0)
			{
				maalt /= 100;
				if(maalt % 3 == 1)
					maalt -= 1;
				else if(maalt % 3 == 2)
					maalt += 1;
				char tmpstr[15];
				itoa(maalt * 10, tmpstr, 10);
				sprintf(sItemString, "%04s", tmpstr);
			}
			else
			{
				strcpy(sItemString, "    ");
			}
			break;
		case TAG_ITEM_MET_CURR_ALT:
			mcalt = 1;
			itoa(mcalt, sItemString, 10);
			break;
		case TAG_ITEM_MET_CURR_SPD:
			mcspd = RadarTarget.GetGS() * 1.852;
			itoa(mcspd, sItemString, 10);
			break;
	}
}

TinyEurocat::~TinyEurocat(void)
{
}
