//Formatted file for AZ tax purposes, function implementations

// Header files
#include "Arizona_Tax_Utility.h"

//Global constants:
//	Some...
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

/*
    Name: calculateArizonaTax
    process: determines user tax bracket, tax rate, and calculates tax amount.
    Function input/parameters: adjustedIncome (double)
    Function output/parameters: none
    Function output/returned: AZtax (double)
    Device input/file: none
    Device output/monitor: none
    Dependencies: none
    */
	
	double calculateArizonaTax ( double adjustedIncome )
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


//End of utility file