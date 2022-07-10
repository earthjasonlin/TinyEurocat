#include "StdAfx.h"
#include "TinyEurocat.h"
#include <cstring>
#include "stdlib.h"
#include <cstdio>

TinyEurocat::TinyEurocat(void) : CPlugIn ( COMPATIBILITY_CODE,
	        "TinyEurocat",
	        "1.0.2",
	        "Future Sim Studio",
	        "Copr. 2022 Future Sim Studio" )
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
			char tmpstr[15];
		case TAG_ITEM_MET_ASS_ALT:
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
		case TAG_ITEM_MET_CURR_ALT:
			mcalt = RadarTarget.GetPosition().GetPressureAltitude() * 0.3048 / 10;
			itoa(mcalt, tmpstr, 10);
			sprintf(sItemString, "%04s", tmpstr);
			break;
		case TAG_ITEM_MET_CURR_SPD:
			mcspd = RadarTarget.GetPosition().GetReportedGS() * 1.852;
			mcspd /= 10;
			itoa(mcspd, tmpstr, 10);
			sprintf(sItemString, "%03s", tmpstr);
			break;
	}
}

TinyEurocat::~TinyEurocat(void)
{
}
