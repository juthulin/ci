#pragma once
#include <windows.h>
#include <memory>

namespace Gdiplus {
	class Bitmap;
	class Graphics;
}

// Global forward declarations.
LRESULT CALLBACK WndProc( HWND, UINT, WPARAM, LPARAM );

class Capps
{
public:
	// Structors
	Capps( HINSTANCE hInstance, HWND hWnd );
	~Capps();

	// Public field
	HINSTANCE							m_hInstance;
	HWND								m_hWnd;

	std::unique_ptr<Gdiplus::Bitmap>	m_switchScreen;

	// Public methods


private:
};