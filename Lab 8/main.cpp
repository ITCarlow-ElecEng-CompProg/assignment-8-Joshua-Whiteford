 /**
 *Joshua Whiteford
 *20/11/2017
 *main.c
 *OpAmp Circuits
 */



/**< preprocessor directives */
#include <iostream>
#include <stdio.h>
#include <tgmath.h>
#include <math.h>

using namespace std;
/**< Starting all of the functions */
void inverting();
void notinverting();
void invert ( double Vin, double Rin, double Rf, double *Vout_ptr, double *Av_ptr);
void notinvert ( double Vin, double R1, double R2, double *Vout_ptr, double *Av_ptr);
/**< Starting the main function */
int main()
{
    /**< Variable Decliration */
    char input;

    /**< Introducing the User to the program */
    cout << "\t\tCoordinate Conversion!" << endl << "This application will convert from polar to Cartesian and back!" << endl;


    /**< Sending the program into a loop until the user enters some value */
     do
    {
        /**< Displaying the Different tasks this program can do */
        cout << "Please Select one of the following Keys depending upon which conversion you wish to do!"<< endl;
        cout << " Press 'a' to select:\t Vout & Av for Inverting Op Amp " << endl;
        cout << " Press 'b' to select:\t Vout & Av for NotInverting Op Amp" << endl;
        cout << "\tPress 'q' to Quit ";

        fflush(stdin);
        /**< Getting the User to input a character */
        cin >> input;

        /**< Checxking if the Inputted character is equal to any of the following cases */
        switch (input)
        {
             case 'a' :
                        /**< Seding the program to the Another function */
                        inverting();



                        /**< Ending this part of the switch Case */
                        break;

            case 'b' :
                        /**< Sending the program to Another Function */
                        notinverting();



                        /**< Ending this part of the Switch Case */
                        break;

            case 'q' :
                        /**< Thanking & saying goodbye to the User */
                        cout << "Tank you and GoodBye..." << endl;

                        /**< Ending this part of the Switch case */
                        break;

            default :
                        /**< Asking the User to try to select the case they want again */
                        cout << "\t\tPlease Try that again!" << endl;

                        /**< Ending this part of the Switch Case */
                        break;
        }
    }
    /**< Causing the Program to loop with the input is not equal to 'q' */
    while (input != 'q');

    /**< Ending the pregram */
    return 0;
}

void inverting()
{
    double Vcc, Vee, Vin, Rin = 0, Rf = 0;
    double  Vout = 0, Av = 0 ;
    double *Vout_ptr, *Av_ptr;

    /**< Setting out pointers to the address of Vout & Av */
    Vout_ptr = &Vout;
    Av_ptr = &Av;

     /**< Asking the User to enter in Values for Vcc, Vee & Vin  */
    cout << "Please enter values for the Following Variables \nNeeded to Calculate Vout & Av for a Inverting Opp Amp" << endl;

    cout << "Enter a Value for Vcc:" << endl;
    cin >> Vcc;

    cout << "Enter a Value for Vee:"<< endl;
    cin >> Vee;

    /**< Asking the User to enter in positive values for Rin & Rf and looping until positive values are entered */
    if (Rin == 0)
    {
        cout << "Enter a Value for Rin:"<< endl;
        cin >> Rin;
    }
    if (Rf == 0)
    {
        cout << "Enter a Value for Rf:"<< endl;
        cin >> Rf;
    }

    /**< Calling the Invert Function! */
    invert ( Vin, Rin, Rf , Vout_ptr, Av_ptr);

    /**< If the Value Vout is too High (Over the Pos & Neg Supply of the Op Amp) then setting Vout to be Equal to Vcc if its (+) or Vee if its a Neg (-) */
    if ( Vout > Vcc )
    {
        Vout = Vcc;
    }
    if (Vout < Vee)
    {
        Vout = Vee;
    }
    /**< Displaying the Result to the user */
    cout << "Vout = " << Vout << endl;
    cout << "Voltage Gain =" << Av << endl;
}

/**< The Invert Function */
void invert ( double Vin, double Rin, double Rf, double *Vout_ptr, double *Av_ptr)
{
    /**< Declaring a variable gv (Gain Voltage ) to use in The Vout Calculation */
    double gv;

    /**< Calculations and setting the Value at the address the pointers are pointing to the result of the Calculations */
    gv = - 1*(Rf/Rin);
    *Av_ptr = (- 1*(Rf/Rin));
    *Vout_ptr = gv * Vin;
}

/**< The NotInverting Function */
void notinverting()
{
    double Vcc, Vee, Vin, R1 = 0, R2 = 0;
    double  Vout = 0, Av = 0 ;
    double *Vout_ptr, *Av_ptr;

    /**< Setting out pointers to the address of Vout & Av */
    Vout_ptr = &Vout;
    Av_ptr = &Av;

     /**< Asking the User to input values for Vcc, Vee, Vin */
    cout << "Please enter values for the Following Variables \nNeeded to Calculate Vout & Av for a Inverting Opp Amp" << endl;

    cout << "Enter a Value for Vcc:"<< endl;
    cin >> Vcc;

    cout << "Enter a Value for Vee:"<< endl;
    cin >> Vee;

    cout << "Enter a Value for Vin:"<< endl;
    cin >> Vin;

    /**< Sending the user into a loop at least once since R1 is set to one to get the user to input a value */
    if (R1 == 0)
    {
        cout << "Enter a positive Value for R1:"<< endl;
        cin >> R1;
    }
    /**< Sending the user into a loop at least once since R2 is set to one to get the user to input a value */
    if (R2 == 0)
    {
        cout << "Enter a Value for R2:"<< endl;
        cin >> R2;
    }

    /**< Calls the NotInvert Function Sending the (Variables inside the Brackets) too it */
    notinvert ( Vin, R1, R2, Vout_ptr, Av_ptr);

    /**< If the Value Vout is too High (Over the Pos & Neg Supply of the Op Amp) then setting Vout to be Equal to Vcc if its (+) or Vee if its a Neg (-)*/
    if ( Vout > Vcc )
    {
        Vout = Vcc;
    }
    else if (Vout < Vee)
    {
        Vout = Vee;
    }
    /**< Displaying the User the Result */
    cout << "Vout = " << Vout << endl;
    cout << "Voltage Gain =" << Av << endl;
}

/**< The NotInvert Function */
void notinvert ( double Vin, double R1, double R2, double *Vout_ptr, double *Av_ptr)
{
    /**< Declaring a variable gv (Gain Voltage ) to use in The Vout Calculation */
    double gv;

    /**< Calculations and setting the Value at the address the pointers are pointing to the result of the Calculations */
    gv = 1+(R2/R1);
    *Av_ptr = 1+(R2/R1);
    *Vout_ptr = gv * Vin;
}
