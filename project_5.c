// header files
#include "Console_IO_Utility.h"

// global constants
    //AZ taxes
        // AZ tax Baseline RATE
const double AZ_TAX_BASELINE_RATE = 0.0259;
        // AZ tax Baseline LIMIT
const double AZ_TAX_BASELINE_LIMIT = 27808.5; 
        // AZ tax First bracket RATE
const double AZ_TAX_FIRST_BRACKET_RATE = 0.0334;   
        // AZ tax First bracket LIMIT 
const double AZ_TAX_FIRST_BRACKET_LIMIT = 55615.5;
        // AZ tax Second bracket RATE
const double AZ_TAX_SECOND_BRACKET_RATE = 0.0417; 
        // AZ tax Second bracket LIMIT
const double AZ_TAX_SECOND_BRACKET_LIMIT = 166843.5;
        // AZ tax MAX bracket RATE
const double AZ_TAX_MAX_RATE = 0.045;

    // Federal taxes
        // Minimum FED Tax RATE
const double FED_TAX_BASELINE_RATE = 0.1000;   
        // FED tax Baseline LIMIT
const double FED_TAX_BASELINE_LIMIT = 10275.5; 
        // FED tax First bracket RATE
const double FED_TAX_FIRST_BRACKET_RATE = 0.1200;   
        // FED tax First bracket LIMIT 
const double FED_TAX_FIRST_BRACKET_LIMIT = 41775.5;
        // FED tax Second bracket RATE
const double FED_TAX_SECOND_BRACKET_RATE = 0.2200; 
        // FED tax Second bracket LIMIT
const double FED_TAX_SECOND_BRACKET_LIMIT = 89075.5;
        // FED tax Third bracket RATE
const double FED_TAX_THIRD_BRACKET_RATE = 0.2400;  
        // FED tax Third bracket LIMIT 
const double FED_TAX_THIRD_BRACKET_LIMIT = 170050.5;
        // FED tax Fourth bracket RATE
const double FED_TAX_FOURTH_BRACKET_RATE = 0.3200;   
        // FED tax Fourth bracket LIMIT 
const double FED_TAX_FOURTH_BRACKET_LIMIT = 215950.5;
        // FED tax Fifth bracket RATE
const double FED_TAX_FIFTH_BRACKET_RATE = 0.3500; 
        // FED tax Fifth bracket LIMIT
const double FED_TAX_FIFTH_BRACKET_LIMIT = 539900.5;
        // AZ tax MAX bracket RATE
const double FED_TAX_MAX_RATE = 0.3700;

    // Other Taxes
        // SSN Tax RATE
const double TAX_SSN = 0.0620;
        // MC Tax RATE
const double TAX_MC = 0.0145;
    
    
    // Percent Conversion, ratio
const double PERCENTAGE_CONVERSION = 100;

    // printing related constants
const int TWO_ENDLINES = 2;
    // constants for table
const int TABLE_WIDTH = 45;
const int DATA_NAME_WIDTH = 20;
const int UNIT_WIDTH = 7;
const int VALUE_WIDTH = 14;
const int TABLE_CORRECTION = 1;
const char TOP_LINE[]
                = "==============================================";
const char THICK_LINE_DIVIDER[]
                = "|============================================|";
const char THIN_LINE_DIVIDER[]
                = "|--------------------------------------------|";
const char PIPE_SPACE[] = "| ";
const char SPACE_PIPE[] = " |";

// function prototypes
double calculateFederalTax( double adjustedIncome );
double calculateArizonaTax( double adjustedIncome );
                           
void displayResultsTable( double taxArizona, double taxFederal,
                          double incomeAfterTaxes, double effectiveTax,
                          double taxTotal, double incomeLocked);

// main program
int main()
    {
        // TODO: Write program as specified    
        // show title
                // function: printString, printEndline(s)
        printEndline();
        printString( "Dummy tax calculator V0.3" );
        printEndline();
        printString( TOP_LINE );
        printEndlines( TWO_ENDLINES );
        
        // initialize variables/functions
        double totalIncome, contributionToIRA, adjustedIncome;
        double taxFederal, taxArizona;
        double taxSSN, taxMC, taxTotal;
        double incomeAfterTaxes;
        double effectiveTax, incomeLocked;
        
        // get user input
        // section title
                // function: printString, printEndline
        printString( "Provide your Tax information below." );
        printEndline();
        
                // total income $
                // function: promptForDouble
        totalIncome = promptForDouble("Total income $: ");
        
                // IRA contributions $
                // function: promptForDouble
        contributionToIRA = promptForDouble("Your IRA contributions $: ");
        
        // conduct computations
                // adjust income by IRA contributions, $
        adjustedIncome = totalIncome - contributionToIRA;

                // calculate federal tax, $
        taxFederal = calculateFederalTax(adjustedIncome);
        
                // calculate AZ tax, $
        taxArizona = calculateArizonaTax(adjustedIncome);
        
                // calculate SSN tax, $
        taxSSN = adjustedIncome * TAX_SSN;
        
                // calculate MC tax, $
        taxMC =  adjustedIncome * TAX_MC;
        
                // calculate Total tax to be payed, $
        taxTotal = taxFederal + taxArizona + taxSSN + taxMC; 
        
                // calculate Income after Tax, $
        incomeAfterTaxes = totalIncome - taxTotal;
        
                // calculate effective tax rate, %
        effectiveTax = taxTotal / totalIncome;
        
                // calculate % of income locked in IRA, %
        incomeLocked = (contributionToIRA / totalIncome) * PERCENTAGE_CONVERSION;
        
        // display results
        displayResultsTable( taxArizona, taxFederal,
                                incomeAfterTaxes, effectiveTax,
                                taxTotal, incomeLocked);
        
        // end program / return program success
        return 0;
    }

// supporting functions
    // TODO


/*
Name: calculateArizonaTax
Process: calculates total marginal Arizona tax based on adjusted income
Function Input/Parameters: adjustedIncome
Function Output/Parameters: none
Function Output/Returned: total arizona tax
Device Input/Keyboard: none
Device Output/Monitor: none
Dependencies: none
*/
double calculateArizonaTax( double adjustedIncome )
{
//Initialize Variables
double taxRateAZ, marginTax, AZtax, IncomeOverMargin;
double firMargin, secMargin, thirMargin;

//Calculate Margins

	//first Margin taxed amount (amount * taxRate)
	firMargin = AZ_TAX_BASELINE_LIMIT * AZ_TAX_BASELINE_RATE;
	
	//Second Margin untaxed amount
	secMargin = (AZ_TAX_FIRST_BRACKET_LIMIT - AZ_TAX_BASELINE_LIMIT);
	//Second Margin taxed amount + first margin taxed amount
	secMargin = secMargin * AZ_TAX_FIRST_BRACKET_RATE + firMargin;
	
	//Third Margin untaxed amount
	thirMargin = (AZ_TAX_SECOND_BRACKET_LIMIT - AZ_TAX_FIRST_BRACKET_LIMIT);
	//Third Margin taxed amount + second margin taxed amount
	thirMargin = thirMargin * AZ_TAX_SECOND_BRACKET_RATE + secMargin;
	
	
//Check AZ tax bracket
//	Functions: if, else if, else

//Check if user is in top bracket ( >166843.5)
if (adjustedIncome > AZ_TAX_SECOND_BRACKET_LIMIT)
{
	//Assign Max tax Rate
	taxRateAZ = AZ_TAX_MAX_RATE;
	//Assign margin taxes to third margin tax amount
	marginTax = thirMargin;
	//Calculate income above limit for taxing outside of margin
	IncomeOverMargin = adjustedIncome - AZ_TAX_SECOND_BRACKET_LIMIT;
	
}
//Check if user is in second bracket ( >55615.5)
else if (adjustedIncome > AZ_TAX_FIRST_BRACKET_LIMIT)
{
	//Assign Second Bracket tax Rate
	taxRateAZ = AZ_TAX_SECOND_BRACKET_RATE;
	//Assign margin taxes to second margin amount
	marginTax = secMargin;
	//Calculate income above limit for taxing outside of margin
	IncomeOverMargin = adjustedIncome - AZ_TAX_FIRST_BRACKET_LIMIT;
	
}
//Check if user is in first bracket ( >27808.5)
else if (adjustedIncome > AZ_TAX_BASELINE_LIMIT)
{
	//Assign first Bracket tax Rate
	taxRateAZ = AZ_TAX_FIRST_BRACKET_RATE;
	//Assign margin taxes to first margin amount
	marginTax = firMargin;
	//Calculate income above limit for taxing outside of margin
	IncomeOverMargin = adjustedIncome - AZ_TAX_BASELINE_LIMIT;
	
}
//User is in baseline bracket ( <27808.5)
else
{
	//Assign Baseline tax rate
	taxRateAZ = AZ_TAX_BASELINE_RATE;
	//No margin tax amount, user is in baseline
	marginTax = 0;
	//No income above margin, user is in baseline
	IncomeOverMargin = adjustedIncome;
	
}

//Compute total AZ taxes:
AZtax = IncomeOverMargin * taxRateAZ + marginTax;

//Output total AZ taxes back to main function
return AZtax;
}


/*
Name: calculateFederalTax
Process: calculates total marginal federal tax based on adjusted income
Function Input/Parameters: adjustedIncome
Function Output/Parameters: none
Function Output/Returned: total federal tax
Device Input/Keyboard: none
Device Output/Monitor: none
Dependencies: none
*/
double calculateFederalTax( double adjustedIncome )
{
	//Initialize Variables
	double taxRateFed, marginTax, FedTax, IncomeOverMargin;
	double firMargin, secMargin, thirMargin;
	double fourMargin, fifMargin, sixMargin;
		
	//Calculate Margins
	
	//First margin taxed amount (amount * tax rate)
	firMargin = FED_TAX_BASELINE_LIMIT * FED_TAX_BASELINE_RATE;
	
	//Second margin untaxed amount
	secMargin = (FED_TAX_FIRST_BRACKET_LIMIT - FED_TAX_BASELINE_LIMIT);
	//Second margin taxed amount + first margin taxed amount
	secMargin = secMargin * FED_TAX_FIRST_BRACKET_RATE + firMargin;

	//Third margin untaxed amount
	thirMargin = (FED_TAX_SECOND_BRACKET_LIMIT - FED_TAX_FIRST_BRACKET_LIMIT); 
	//Third Margin taxed amount + second margin taxed amount
	thirMargin = thirMargin * FED_TAX_SECOND_BRACKET_RATE + secMargin;

	//Fourth Margin untaxed amount
	fourMargin = (FED_TAX_THIRD_BRACKET_LIMIT - FED_TAX_SECOND_BRACKET_LIMIT); 
	//Fourth Margin taxed amount + third margin taxed amount
	fourMargin = fourMargin * FED_TAX_THIRD_BRACKET_RATE + thirMargin;

	//Fifth Margin untaxed amount
	fifMargin = (FED_TAX_FOURTH_BRACKET_LIMIT - FED_TAX_THIRD_BRACKET_LIMIT); 
	//Fifth Margin taxed amount + fourth margin taxed amount
	fifMargin = fifMargin * FED_TAX_FOURTH_BRACKET_RATE + fourMargin;

	//Sixth Margin untaxed amount
	sixMargin = (FED_TAX_FIFTH_BRACKET_LIMIT - FED_TAX_FOURTH_BRACKET_LIMIT);
	//Sixth Margin taxed amount + fifth margin taxed amount
	sixMargin = sixMargin * FED_TAX_FIFTH_BRACKET_RATE + fifMargin;

	
//Check Federal Tax Bracket
//	Functions: if, else if, if

//Check if user is in top bracket ( >539900.5)
if (adjustedIncome > FED_TAX_FIFTH_BRACKET_LIMIT)
{
	//Assign Top earners' tax rate
	taxRateFed = FED_TAX_MAX_RATE;
	//Assign margin taxes to sixth margin amount
	marginTax = sixMargin;
	//Calculate income above limit for taxing outside of margin
	IncomeOverMargin = adjustedIncome - FED_TAX_FIFTH_BRACKET_LIMIT;
	
}
//Check if user is in fifth bracket ( >215950.5)
else if (adjustedIncome > FED_TAX_FOURTH_BRACKET_LIMIT)
{
	//Assign fifth bracket tax rate
	taxRateFed = FED_TAX_FIFTH_BRACKET_RATE;
	//Assign margin taxes to fifth margin amount
	marginTax = fifMargin;
	//Calculate income above limit for taxing outside of margin
	IncomeOverMargin = adjustedIncome - FED_TAX_FOURTH_BRACKET_LIMIT;

}
//Check if user is in fourth bracket ( >170050.5)
else if (adjustedIncome > FED_TAX_THIRD_BRACKET_LIMIT)
{
	//Assign fourth bracket tax rate
	taxRateFed = FED_TAX_FOURTH_BRACKET_RATE;
	//Assign margin taxes to fourth margin amount
	marginTax = fourMargin;
	//Calculate income above limit for taxing outside of margin
	IncomeOverMargin = adjustedIncome - FED_TAX_THIRD_BRACKET_LIMIT;
}
//Check if user is in third bracket ( >89075.5)
else if (adjustedIncome > FED_TAX_SECOND_BRACKET_LIMIT)
{
	//Assign third bracket tax rate
	taxRateFed = FED_TAX_THIRD_BRACKET_RATE;
	//Assign margin taxes to third margin amount
	marginTax = thirMargin;
	//Calculate income above limit for taxing outside of margin
	IncomeOverMargin = adjustedIncome - FED_TAX_SECOND_BRACKET_LIMIT;
}
//Check if user is in second bracket ( >41775.5)
else if (adjustedIncome > FED_TAX_FIRST_BRACKET_LIMIT)
{
	//Assign second bracket tax rate
	taxRateFed = FED_TAX_SECOND_BRACKET_RATE;
	//Assign margin taxes to second margin amount
	marginTax = secMargin;
	//Calculate income above limit for taxing outside of margin
	IncomeOverMargin = adjustedIncome - FED_TAX_FIRST_BRACKET_LIMIT;
}
//Check if user is in first bracket ( >10275.5)
else if (adjustedIncome > FED_TAX_BASELINE_LIMIT)
{
	//Assign first bracket tax rate
	taxRateFed = FED_TAX_FIRST_BRACKET_RATE;
	//Assign margin taxes to first margin amount
	marginTax = firMargin;
	//Calculate income above limit for taxing outside of margin
	IncomeOverMargin = adjustedIncome - FED_TAX_BASELINE_LIMIT;
}
//User is in baseline bracket ( <10275.5)
else
{
	//Assign baseline tax rate
	taxRateFed = FED_TAX_BASELINE_RATE;
	//No margin taxes, user is in baseline
	marginTax = 0;
	//No income above margin, user is in baseline
	IncomeOverMargin = adjustedIncome;
	
}

//Calculate total Federal Taxes
FedTax = IncomeOverMargin * taxRateFed + marginTax;

//Output total federal taxes back to main function
return FedTax;
}
/*
Name: displayResultsTable
Process: displays (prints) table for tax calculator V0.3
Function Input/Parameters: income after tax, effective tax rate, 
                           total tax to be payed, and locked income.
Function Output/Parameters: none
Function Output/Returned: none
Device Input/Keyboard: none
Device Output/Monitor: table as showed in example for PA05
Dependencies: printEndline, printString, printCharacter, printStringJustified,
              printDoubleJustified 
*/
void displayResultsTable( double taxArizona, double taxFederal,
                          double incomeAfterTaxes, double effectiveTax,
                          double taxTotal, double incomeLocked)
{

  // display results
       // print top line
          // function: printString, printEndline
    printEndline();
    printString( TOP_LINE );
    printEndline();

    // print title line
        // function: printCharacter, printStringJustified, printEndline
    printCharacter( PIPE );
    printStringJustified( "DUMMY TAX CALCULATIONS",
                                TABLE_WIDTH - TABLE_CORRECTION, "CENTER" );
    printCharacter( PIPE );
    printEndline();

    // print thick divider line
        // function: printString, printEndline
    printString( THICK_LINE_DIVIDER );
    printEndline();

    // print sub title line
       // function: printStringJustified, printString, printCharacter,
       //    printEndline
    printString( PIPE_SPACE );
    printStringJustified( "Data Name", DATA_NAME_WIDTH, "LEFT" );
    printCharacter( PIPE );
    printStringJustified( "Units", UNIT_WIDTH, "CENTER" );
    printString( PIPE_SPACE );
    printStringJustified( "Value", VALUE_WIDTH - TABLE_CORRECTION, "CENTER" );
    printCharacter( PIPE );
    printEndline();

    // print thin divider line
       // function: printString, printEndline
    printString( THICK_LINE_DIVIDER );
    printEndline();

        // print Effective AZ tax
       // function: printStringJustified, printString, printCharacter,
       //    printEndline
    printString( PIPE_SPACE );
     printStringJustified( "AZ Tax", DATA_NAME_WIDTH, "LEFT" );
    printCharacter( PIPE );
    printStringJustified( "$", UNIT_WIDTH, "CENTER" );
    printCharacter( PIPE );
    printDoubleJustified( taxArizona,
                                PRECISION, VALUE_WIDTH, "RIGHT" );
    printCharacter( PIPE );
    printEndline();

    // print thin divider line
       // function: printString, printEndline
    printString( THIN_LINE_DIVIDER );
    printEndline();


        // print Effective Federal tax
       // function: printStringJustified, printString, printCharacter,
       //    printEndline
    printString( PIPE_SPACE );
    printStringJustified( "Fed Tax", DATA_NAME_WIDTH, "LEFT" );
    printCharacter( PIPE );
    printStringJustified( "$", UNIT_WIDTH, "CENTER" );
    printCharacter( PIPE );
    printDoubleJustified( taxFederal,
                                PRECISION, VALUE_WIDTH, "RIGHT" );
    printCharacter( PIPE );
    printEndline();

    // print thin divider line
       // function: printString, printEndline
    printString( THIN_LINE_DIVIDER );
    printEndline();


    // print Effective tax rate
       // function: printStringJustified, printString, printCharacter,
       //    printEndline
    printString( PIPE_SPACE );
    printStringJustified( "Effective Tax Rate", DATA_NAME_WIDTH, "LEFT" );
    printCharacter( PIPE );
    printStringJustified( "%", UNIT_WIDTH, "CENTER" );
    printCharacter( PIPE );
    printDoubleJustified( effectiveTax * PERCENTAGE_CONVERSION,
                                PRECISION, VALUE_WIDTH, "RIGHT" );
    printCharacter( PIPE );
    printEndline();

    // print thin divider line
       // function: printString, printEndline
    printString( THIN_LINE_DIVIDER );
    printEndline();

    // Total tax payed
       // function: printStringJustified, printString, printCharacter,
       //    printEndline
    printString( PIPE_SPACE );
    printStringJustified( "Tax To Be Payed", DATA_NAME_WIDTH, "LEFT" );
    printCharacter( PIPE );
    printStringJustified( "$", UNIT_WIDTH, "CENTER" );
    printCharacter( PIPE );
    printDoubleJustified( taxTotal, PRECISION, VALUE_WIDTH, "RIGHT" );
    printCharacter( PIPE );
    printEndline();

    // print thin divider line
       // function: printString, printEndline
    printString( THIN_LINE_DIVIDER );
    printEndline();
	
	//Income after tax
		//function: printStringJustified, printString, printCharacter,
		//	 printEndline
    printString( PIPE_SPACE );
    printStringJustified( "Income After Tax", DATA_NAME_WIDTH, "LEFT" );
    printCharacter( PIPE );
    printStringJustified( "$", UNIT_WIDTH, "CENTER" );
    printCharacter( PIPE );
    printDoubleJustified( incomeAfterTaxes, 
								PRECISION, VALUE_WIDTH, "RIGHT" );
    printCharacter( PIPE );
    printEndline();

    // print thin divider line
       // function: printString, printEndline
    printString( THIN_LINE_DIVIDER );
    printEndline();

	//Locked in IRA
		//function: printStringJustified, printString, printCharacter,
		//	 printEndline
    printString( PIPE_SPACE );
    printStringJustified( "Locked in IRA", DATA_NAME_WIDTH, "LEFT" );
    printCharacter( PIPE );
    printStringJustified( "%", UNIT_WIDTH, "CENTER" );
    printCharacter( PIPE );
    printDoubleJustified( incomeLocked,
                                PRECISION, VALUE_WIDTH, "RIGHT" );
    printCharacter( PIPE );
    printEndline();


    // print thick divider line
       // function: printString, printEndline
    printString( THICK_LINE_DIVIDER );
    printEndlines(TWO_ENDLINES);
	//End of table
}
