// header files
#include "StandardConstants.h"
#include "Console_IO_Utility.h"
#include "File_Input_Utility.h"
#include "File_Output_Utility.h"
#include "Arizona_Tax_Utility.h" 

// TODO

// constants
    // none 

// function prototypes

/*
Name: createOutputString
Process: creates string to be displayed and output to file;
         only one string can be assembled in the function
Function input/parameters:  the output string pointer, tax year and income
Function output/parameters: the generated output string (char *)
Function output/returned: none
Function input/keyboard: none
Device output/file: none
Dependencies: sprintf
*/
// TODO
void createOutputString(char *outString, int taxYear, double azTax);

/*
Name: outputResultsToFile
Process: opens file for output, writes string to file with endline,
         closes file
Function input/parameters: file name (const char *), 
                           output string (const char *)
Function output/parameters: none
Function output/returned: none
Function input/keyboard: none
Device output/file: none
Dependencies: File Output Utility tools
*/
// TODO
void outputResultsToFile( const char* filename, const char* outString );



// main program
int main()
    {
        
     // TODO
        
     // initialize variables
	 //Input file array
     char taxFile[ STD_STR_LEN ];
	 //Calculation variables
	 int taxYear;
	 double azTax, adjustedIncome;
	 //Year count variable initialized
	 int yearCount = 0;
	 //Output string array
	 char outString[STD_STR_LEN];
	 //Output file array
	 char filename[STD_STR_LEN];
	 
	 
        
     // show title
         // function: printf
     printf( "\nDUMMY TAX CALCULATOR V0.4\n" );
     printf( "===========================\n\n" ); 
	 
	 // get input

     // get file name
         // function: promptForString
     promptForString( "Enter file name containing income information: ",
                                                        taxFile );
	
	// processing
    // open data stream, check for successful access
        // function: openInputFile
    if( openInputFile( taxFile ) )
{
	//Get tax year to prime loop:
		//function: readIntegerFromFile
		taxYear = readIntegerFromFile(taxFile);
	
	//While loop reading input file
	//	functions: readDoubleFromFile, while, checkForEndOfInputFile,
	//			sprintf;
	while ( !checkForEndOfInputFile() )
{
	 //Get adjusted income:
		//function: readDoubleFromFile
		adjustedIncome = readDoubleFromFile(taxFile);
	 //Calculate AZ taxes
		// function: calculateAZTax
		azTax = calculateArizonaTax(adjustedIncome);
	//Increment Year Count:
		yearCount += 1;
	 
     // creat output string
        // function: createOutputString
        createOutputString(outString, taxYear, azTax);
		
	// name outputfile:
		//function sprintf
		sprintf(filename, "Tax_Report_%d.txt", taxYear);

     // call to output file
        // function: outputResultsToFile
        outputResultsToFile(filename, outString);
	//Get next tax year:
		//function: readIntegerFromFile
		taxYear = readIntegerFromFile(taxFile);
	
	//End while loop
	
}

	//Close input file
		//Function: closeInputFile
		closeInputFile();

    // display results
       // function: printf
       printf( "\nArizona Tax for %d years has been calculated.\n", yearCount );
       printf( "\nThe results can be viewed in the report files.\n" );
	   
	//End if statement
}
     // else: if file does not open print error message 
     else
{
	//Tell user that file doesn't exist
		//function: printf
		printf( "\nThat file does not exist.\n" );
		//End else
}
    
    // end program
    
    // show program end
        // function: printf
    printf( "\nProgram End\n" );

    // return successful program
    return 0;
    
    }


// supporting functions

// TODO
//Create Output String function
//Dependencies: sprintf
void createOutputString(char *outString, int taxYear, double azTax)
{

	//Create string with tax year and tax amount. 
	//	Function: sprintf
	sprintf(outString, "For the tax year %d total AZ tax to be payed is %f $", taxYear, azTax);

	//End function
}

//Write output string to file
//Dependencies: openOutputFile, writeStringToFile, closeOutputFile
void outputResultsToFile( const char *filename, const char *outString )
{
	
	//Write string to output file
	//	functions: writeDoubleToFile, openOutputFile, closeOutputFile
	//		writeStringToFile
	
	//Open the output file
		//Function: openOutputFile
	openOutputFile(filename);
	
	//Save string in output file
		//Function: writeStringToFile
	writeStringToFile( outString);
	
	//Close output file
		//Function: closeOutputFile
	closeOutputFile();
	
	//End function
}

