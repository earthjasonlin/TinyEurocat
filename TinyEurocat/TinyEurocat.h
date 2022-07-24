#pragma once
#include "..\lib\EuroScopePlugIn.h"

using namespace EuroScopePlugIn;

const int ITEM_MET_AFL  =	1;
const int ITEM_MET_CFL	=	2;
const int ITEM_MET_GS	=	3;

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

