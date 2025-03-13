// TemplateDialog.cpp

#include "TemplateDialog.h"

// Global variables
LPTSTR g_lpszInputText;

INT_PTR CALLBACK TemplateDialogProcedure( HWND hWndDialog, UINT uMessage, WPARAM wParam, LPARAM )
{
	BOOL bResult = FALSE;

	// Select message
	switch( uMessage )
	{
		case WM_INITDIALOG:
		{
			// An init dialog message

			// Set edit text
			SetDlgItemText( hWndDialog, IDC_EDITTEXT, g_lpszInputText );

			// Select edit text
			SendDlgItemMessage( hWndDialog, IDC_EDITTEXT, EM_SETSEL, ( WPARAM )0, ( LPARAM )-1 );

			// Update return value
			bResult = TRUE;

			// Break out of switch
			break;

		} // End of an init dialog message
		case WM_COMMAND:
		{
			// A command message

			// Select command
			switch( LOWORD( wParam ) )
			{
				case IDOK:
				{
					// An ok command

					// Get edit text
					GetDlgItemText( hWndDialog, IDC_EDITTEXT, g_lpszInputText, STRING_LENGTH );

					// End dialog with ok
					EndDialog( hWndDialog, IDOK );

					// Break out of switch
					break;

				} // End of an ok command
				case IDCANCEL:
				{
					// A cancel command

					// End dialog with cancel
					EndDialog( hWndDialog, IDCANCEL );

					// Break out of switch
					break;

				} // End of a cancel command

			}; // End of selection for command

			// Update return value
			bResult = TRUE;

			// Break out of switch
			break;

		} // End of an init dialog message

	}; // End of selection for message

	return bResult;

} // End of function TemplateDialogProcedure

BOOL ShowTemplateDialog( HWND hWndParent, HINSTANCE hInstance, LPTSTR lpszInputText )
{
	BOOL bResult = FALSE;

	// Allocate string memory
	g_lpszInputText = new char[ STRING_LENGTH + sizeof( char ) ];

	// Copy input text to global
	lstrcpy( g_lpszInputText, lpszInputText );

	// Show template dialog
	if( DialogBox( hInstance, MAKEINTRESOURCE( IDD_TEMPLATE_DIALOG ), hWndParent, TemplateDialogProcedure ) == IDOK )
	{
		// Dialog box was shown and ok button was pressed

		// Get input text from global
		lstrcpy( lpszInputText, g_lpszInputText );

		// Update return value
		bResult = TRUE;

	} // End of dialog box was shown and ok button was pressed

	// Free string memory
	delete [] g_lpszInputText;

	return bResult;

} // End of function ShowTemplateDialog
