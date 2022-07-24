#pragma once
#include "..\lib\EuroScopePlugIn.h"

using namespace EuroScopePlugIn;

const int ITEM_MET_AFL  =	1;	// AFL in metric
const int ITEM_MET_CFL	=	2;	// CFL in metric
const int ITEM_MET_GS_R	=	3;	// Reported GS in metric
const int ITEM_MET_GS_C =	4;	// Calculated GS in metric

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

