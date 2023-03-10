#pragma once
#include "bEngine.h"

namespace b
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hWnd);
		void Run();
		void Update();
		void Render();

		HWND GetHwnd() { return mHwnd; }
		HDC GetHdc() { return mHdc; }

	private:
		HWND mHwnd;
		HDC mHdc;

		// back buffer
		HBITMAP mBackBuffer;
		HDC mBackHdc;

		UINT mWidth;
		UINT mHeight;

		Vector2 mPos;
	};
}

