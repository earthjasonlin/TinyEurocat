#pragma once
#include "..\lib\EuroScopePlugIn.h"

using namespace EuroScopePlugIn;

const int TAG_ITEM_MET_CURR_ALT =	1;
const int TAG_ITEM_MET_ASS_ALT	=	2;
const int TAG_ITEM_MET_CURR_SPD	=	3;

class TinyEurocat : public CPlugIn
{
	public:
		TinyEurocat(void);
		~TinyEurocat(void);
		void OnGetTagItem( CFlightPlan FlightPlan,
		              CRadarTarget RadarTarget,
		              int ItemCode,
		              int TagData,
		              char sItemString [ 16 ],
		              int *pColorCode,
		              COLORREF *pRGB,
		              double *pFontSize );

};

