#ifndef __cNewMod__
#define __cNewMod__

/**
@file
Subclass of cNewMod, which is generated by wxFormBuilder.
*/

#include "cGUI.h"
#include <iostream>
#include <fstream>
//// end generated include

/** Implementing cNewMod */
class cNewMod : public cNewModDialog
{
	protected:
		// Handlers for cNewMod events.
		void Close( wxCommandEvent& event );
		void createMod( wxCommandEvent& event );
	public:
		/** Constructor */
		cNewMod( wxWindow* parent );
	//// end generated class members

};

#endif // __cNewMod__
