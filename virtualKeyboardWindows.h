#include <iostream>
#include <string>
using namespace std;
#include <bits/unique_ptr.h>
#include <conio.h>

class virtualKeyboard {

protected:
    // String to be read from stdin
	string key;

public:
    // Virtual function to execute virtual keyboard functionality
	virtual void execute()
	{
	}

};

class virtualKeyboardWindows : public virtualKeyboard
{
private:
		// Reads the input from stdin and stores in 'key'
		void readInput()
		{
            key.clear();
			
			// Loop to read characters from stdin
            while(1)
            {
                char ch = getch();
                
				// If input is ^q then release mutex and exit loop, the other thread will exit the program      
                if (ch == 17)
                {
                    exit(0);
                }
				
                // Don't append the character into the string if the character is 'ENTER (ASCII=13)'
                else if(ch != 13)
                {
                    key.append(1, ch);
                }
                else
                {
                    // Break out since now we have completed reading the string (till ENTER)
                    break;
                }
            }
		}
		
		// Prints the key to stdout
		void printOutput()
		{
			cout<<key<<endl;
		}

public:
		// Executes the virtual keyboard functionality
		void execute()
		{
			// Read the input from stdin
			readInput();
		
			// Print the output to stdout
			printOutput();			
		}	
};