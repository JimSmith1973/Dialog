// Dialog.cpp

#include "Dialog.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE, LPTSTR, int )
{
	// Allocate string memory
	LPTSTR lpszInputText = new char[ STRING_LENGTH + sizeof( char ) ];

	// Set initial input text
	lstrcpy( lpszInputText, "Input some text" );

	// Show template dialog box
	if( TemplateDialogShow( NULL, hInstance, lpszInputText ) )
	{
		// Successfully shown template dialog box

		// Display input text
		MessageBox( NULL, lpszInputText, INFORMATION_MESSAGE_CAPTION, ( MB_OK | MB_ICONINFORMATION ) );

	} // End of successfully shown template dialog box

	return 0;

} // End of function WinMain
