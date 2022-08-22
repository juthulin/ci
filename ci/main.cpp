// main.cpp
// description of the class / app.

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <gdiplus.h>

#include "main.h"

/* todo - find out what this using namespace means.
* calling GetWidth() and GetHeight() doesn't work without it.
*/
using namespace Gdiplus;
#pragma comment( lib, "Gdiplus.lib" )

/*--------------------
	Global variables
--------------------*/
static TCHAR g_windowClass[] = _T( "capps" );					// The main window class name.
static TCHAR g_title[] = _T( "Capps Desktop Application" );		// The string that appears in the application's title bar.

HINSTANCE	g_hInstance;
HWND		g_hWnd;
std::unique_ptr<Capps> g_app;

/*
====================
WinMain
====================
*/
int WINAPI WinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow )
{
	if ( FindWindow( g_windowClass, g_windowClass ) != NULL )
	{
		MessageBox( 0, _T( "Capps is already running." ), 0l, MB_OK );
		return 0;
	}

	g_hInstance = hInstance;

	WNDCLASS wClass;
	wClass.lpszClassName = g_windowClass;
	wClass.hInstance = hInstance;
	wClass.lpfnWndProc = WndProc;
	wClass.hCursor = LoadCursor( NULL, IDC_ARROW );
	wClass.hIcon = 0;
	wClass.lpszMenuName = NULL;
	wClass.hbrBackground = 0;
	wClass.style = 0;
	wClass.cbClsExtra = 0;
	wClass.cbWndExtra = 0;
	if ( RegisterClass( &wClass ) == 0 )
	{
		MessageBox( 0, _T( "RegisterClass() failed!" ), 0, MB_OK );
		return 0;
	}

	// gdiplus struct?

	// assign g_overlay global variables.

	g_hWnd = CreateWindow( g_windowClass, g_windowClass, WS_OVERLAPPEDWINDOW, 0, 0, 400, 200, NULL, NULL, hInstance, NULL );
	if ( g_hWnd == NULL )
	{
		MessageBox( 0, _T( "CreateWindow() failed!" ), 0, MB_OK );
		return 0;
	}

	const int width = g_app->m_switchScreen->GetWidth();
	const int height = g_app->m_switchScreen->GetHeight();
	const int cx = ::GetSystemMetrics( SM_CXSCREEN );
	const int cy = ::GetSystemMetrics( SM_CYSCREEN );
	// create hWndAltTab...

	return 0;
}

/*
====================
WndProc
====================
*/
LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	return NULL;
}

/* Constructor
====================
Capps::Capps
====================
*/
Capps::Capps( HINSTANCE hInstance, HWND hWnd )
{
}

/* Destructor
====================
Capps::~Capps
====================
*/
Capps::~Capps()
{
}
