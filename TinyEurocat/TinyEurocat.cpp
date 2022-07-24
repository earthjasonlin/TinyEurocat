#include "StdAfx.h"
#include "TinyEurocat.h"
#include <cstring>
#include "stdlib.h"
#include <cstdio>

TinyEurocat::TinyEurocat(void) : CPlugIn ( COMPATIBILITY_CODE,
	        "TinyEurocat",
	        "1.2.1",
	        "Future Sim Studio",
	        "Copr. 2022 Future Sim Studio" )
{
	RegisterTagItemType("Metric / Current Altitude", ITEM_MET_AFL);
	RegisterTagItemType("Metric / Cleared Altitude", ITEM_MET_CFL);
	RegisterTagItemType("Metric / Current Speed (Reported)", ITEM_MET_GS_R);
	RegisterTagItemType("Metric / Current Speed (Calculated)", ITEM_MET_GS_C);
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
	switch (ItemCode)
	{
		int maalt, mcalt, mcspd;
		char tmpstr[15];
		case ITEM_MET_CFL:
			maalt = FlightPlan.GetClearedAltitude() * 0.3048 / 10;
			if (maalt > 0)
			{
				itoa(maalt, tmpstr, 10);
				sprintf(sItemString, "%04s", tmpstr);
			}
			else
			{
				strcpy(sItemString, "    ");
			}
			break;
		case ITEM_MET_AFL:
			mcalt = RadarTarget.GetPosition().GetPressureAltitude() * 0.3048 / 10;
			itoa(mcalt, tmpstr, 10);
			sprintf(sItemString, "%04s", tmpstr);
			break;
		case ITEM_MET_GS_R:
			mcspd = RadarTarget.GetPosition().GetReportedGS() * 1.852;
			mcspd /= 10;
			itoa(mcspd, tmpstr, 10);
			sprintf(sItemString, "%03s", tmpstr);
			break;
		case ITEM_MET_GS_C:
			mcspd = RadarTarget.GetGS() * 1.852;
			mcspd /= 10;
			itoa(mcspd, tmpstr, 10);
			sprintf(sItemString, "%03s", tmpstr);
			break;
	}
}

TinyEurocat::~TinyEurocat(void)
{
}
