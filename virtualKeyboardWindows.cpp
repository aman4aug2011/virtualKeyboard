#include "virtualKeyboardWindows.h"

int main()
{
	// Default message on launch
	cout<<"Virtual Keyboard session start..." << endl;
	
	// Create a smart unique ptr to VirtualKeyboard base class referring derived class object
	unique_ptr<virtualKeyboard> pVk (new virtualKeyboardWindows);
	
    // Run the virtual keyboard in loop	
	while(1)
	{
		pVk->execute();
	}
    
	return 0;
}
