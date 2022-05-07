#include "stdafx.h"
#include "TinyEurocat.h"

TinyEurocat *pMyPlugIn = NULL;

void __declspec ( dllexport ) EuroScopePlugInInit ( EuroScopePlugIn :: CPlugIn **ppPlugInInstance )
{
	// allocate
	* ppPlugInInstance = pMyPlugIn = new TinyEurocat ;
}

void __declspec ( dllexport ) EuroScopePlugInExit ( void )
{
	delete pMyPlugIn ;
}
