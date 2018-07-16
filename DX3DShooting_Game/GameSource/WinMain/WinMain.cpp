#include <d3d11.h>

#include "CKitEngine.h"

extern kit::Engine::KitEngine g_application;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpCmdLine, _In_ int nCmdShow) {
	
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	

	MSG msg = { 0 };
	while ( WM_QUIT != msg.message ) {
		if ( PeekMessage( &msg, nullptr, 0, 0, PM_REMOVE )) {
			TranslateMessage( &msg );
			DispatchMessage( &msg );
		}
		else {

		}
	}

	return static_cast< int >( msg.wParam );
}