#include <iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<windows.h>
using namespace std;

//CONSTANTS USED THROUGHOUT THE PROGRAM
const int row = 12;
const int col=4;
const double econPrice=50000.0;
const double bizPrice=90000.0;

//ARRAY SEATS SIZE FIXED FOR ALL FLIGHTS
int seat4AM [12][4];
int seat3PM [12][4];
int seat11PM [12][4];

//PASSENGER DATA STRUCTURE CONTAING ALL THE DATA IN PROGRAM
struct passenger
{
    string name;
    string phone;
    string cnic;
    string email;

    string depCity;
    string arrCity;
    string depDate;
    string arrDate;

    char seatClass;
    int timeSlot;
    double totalPrice;

    int sRow, sCol;

    int adult, children;
};

/*Starting Of the user defined functions
  applied in this program*/

//ASSIGNING VALUES TO ARRAYS AND RANDOMIZING OCCUPIED SEATS.
void seatStart()
{
    for(int r=0 ; r<12; r++)
        for(int c=0; c<4; c++){
            seat4AM[r][c] =0;
            seat3PM[r][c] =0;
            seat11PM[r][c]=0;
        }

    //hardcoding occupied seats
    seat4AM[0][1] = 1;
    seat4AM[1][3] = 1;
    seat4AM[2][0] = 1;
    seat4AM[3][0] = 1;
    seat4AM[5][1] = 1;
    seat4AM[6][2] = 1;
    seat4AM[7][2] = 1;
    seat4AM[7][1] = 1;
    seat4AM[8][3] = 1;
    seat4AM[9][0] = 1;
    seat4AM[10][2] = 1;
    seat4AM[11][1] = 1;

    seat3PM[0][2] = 1;
    seat3PM[1][0] = 1;
    seat3PM[2][3] = 1;
    seat3PM[3][1] = 1;
    seat3PM[4][3] = 1;
    seat3PM[5][0] = 1;
    seat3PM[6][1] = 1;
    seat3PM[7][3] = 1;
    seat3PM[8][0] = 1;
    seat3PM[9][2] = 1;
    seat3PM[10][1] = 1;
    seat3PM[11][3] = 1;

    seat11PM[0][0] = 1;
    seat11PM[1][2] = 1;
    seat11PM[2][1] = 1;
    seat11PM[3][3] = 1;
    seat11PM[4][0] = 1;
    seat11PM[5][2] = 1;
    seat11PM[6][3] = 1;
    seat11PM[7][0] = 1;
    seat11PM[8][1] = 1;
    seat11PM[9][3] = 1;
    seat11PM[10][0] = 1;
    seat11PM[11][2] = 1;

    //NOT PART OF THE PROGRAM(USED TO DISPLAY ARRAY)
    /*for(int r=0 ; r<12; r++){
        cout<<endl;
        for(int c=0; c<2; c++)
            cout<<seat3PM[r][c];
        cout<<"  ";
        for(int c=2; c<4; c++)
                cout<<""<<seat3PM[r][c];*/
}

//SIMPLE FUNCTION TO GET PERSONAL DATA FROM USER
void passengerINFO(passenger &p)
{
    system("cls");
    cout << " ------------------------------------------ " << endl;
    cout << "|         PASSENGER INFORMATION            |" << endl;
    cout << " ------------------------------------------ " << endl;

    //name
    cout<<"\nEnter Full Name: ";
    cin.ignore();
    getline(cin, p.name);

    //phone
    do{
        cout<<"Enter Your Phone: ";
        cin>>p.phone;
        if(p.phone.length() != 11)
            cout<<"\nInvalid! Phone number must be 11 digits.\n";
    }while(p.phone.length() != 11);

    //email
    cout<<"Enter Your Email: ";
    cin>>p.email;

    //cnic
    do{
        cout<<"Enter Your CNIC (without dashes) : ";
        cin>>p.cnic;
        if(p.cnic.length() != 13)
            cout<<"\nInvalid! CNIC number must be 13 digits.\n";
    }while(p.cnic.length() != 13);


    //adults
    do{
        cout<<"\nEnter the Number of Adults: ";
        cin>>p.adult;
        if(p.adult<1)
            cout<<"\nPlease select at least one adult!\n";
    }while(p.adult<1);

    //children
    do{
        cout<<"Enter the number of CHildren :";
        cin>>p.children;
        if(p.children<0)
            cout<<"\nInvalid input.";
    }while(p.children<0);

    //class
    do{
        cout<<"\nPlease Choose your Desired Class."<<endl;
        cout<<"Economy  (50,000 pkr) --> E"<<endl;
        cout<<"Business (90,000 pkr) --> B"<<endl;
        cout<<"Enter :";
        cin>>p.seatClass;
        p.seatClass=toupper(p.seatClass);
        if(p.seatClass != 'E' && p.seatClass != 'B')
            cout<<"\nPlease Enter 'E' or 'B'\n";
    }while(p.seatClass != 'E' && p.seatClass != 'B');

    cout<<"\n\n PASSENGER INFORMATION SAVED!";
}

//COLLECTING FLIGHT DATA FROM USER
void selectFlight(passenger &p)
{
    system("cls");
    cout<<" ------------------------------------------ "<<endl;
    cout<<"|           FLIGHT SELECTION               |"<<endl;
    cout<<" ------------------------------------------ "<<endl;

    cout<<"\n         SKYROUTE DESTINATIONS"<<endl;
    cout<<"\n-> LAHORE    (LHR)";
    cout<<"\n-> ISLAMABAD (ISB)";
    cout<<"\n-> KARACHI   (KHI)";
    cout<<"\n-> SIALKOT   (SIAL)";
    cout<<"\n-> SKARDU    (SKD)"<<endl;

    //validation loop for taking departure city and capitalizing each letter and testing the string using logic
    do{
        cout<<"\nEnter city of departure (IATA CODE): ";
        cin>>p.depCity;
        for (int i = 0; i < p.depCity.length(); i++)
            p.depCity[i] = toupper(p.depCity[i]);
        if(p.depCity != "LHR" && p.depCity != "KHI" && p.depCity != "ISB" && p.depCity != "SIAL" && p.depCity != "SKD")
            cout<<"\nPlease Enter the provided IATA coded cities as mentioned above!";
    }while(p.depCity != "LHR" && p.depCity != "KHI" && p.depCity != "ISB" && p.depCity != "SIAL" && p.depCity != "SKD");

    //same validation loop for arrival city
    do{
        do{
        cout<<"\nEnter city of arrival (IATA CODE): ";
        cin>>p.arrCity;
        for (int i = 0; i < p.arrCity.length(); i++)
            p.arrCity[i] = toupper(p.arrCity[i]);
        if(p.arrCity != "LHR" && p.arrCity != "KHI" && p.arrCity != "ISB" && p.arrCity != "SIAL" && p.arrCity != "SKD")
            cout<<"\nPlease Enter the provided IATA coded cities as mentioned above!";
        }while(p.arrCity != "LHR" && p.arrCity != "KHI" && p.arrCity != "ISB" && p.arrCity != "SIAL" && p.arrCity != "SKD");
        if(p.arrCity == p.depCity)
            cout<<"Error! The Departure city cant be the same as arrival city.\n";
    }while(p.arrCity == p.depCity);

    //date selection
    char ticketType;
    cout<<"Enter Date of Departure (DD/MM/YYYY): ";
    cin>>p.depDate;
    do{
        cout<<"\nDo you want a return ticket? (Y/N): ";
        cin>>ticketType;
        ticketType=toupper(ticketType);
        if(ticketType!='Y'&&ticketType!='N')
            cout<<"Please Select Y or N!"<<endl;
    }while(ticketType!='Y'&&ticketType!='N');

    if (ticketType == 'Y' || ticketType =='y'){
        cout<<"\nEnter the Return Date (DD/MM/YYYY): ";
        cin>>p.arrDate;
    }
    else
        p.arrDate="ONE WAY";

    //time selection
    do{
    cout<<"\nSelect the required time slot for departure: "<<endl;
    cout<<"1.  04:00 am"<<endl;
    cout<<"2.  03:00 pm"<<endl;
    cout<<"3.  11:00 pm"<<endl;
    cout<<"\nSelect from 1-3: ";
    cin>>p.timeSlot;
    if(p.timeSlot != 1 && p.timeSlot != 2 && p.timeSlot != 3 )
        cout<<"\nPlease Select the correct option!\n";
    }while(p.timeSlot != 1 && p.timeSlot != 2 && p.timeSlot != 3 );

}

//FUNCTION WHICH DISPLAYS THE SEAT MAP LAYOUT
void displaySeat(int seats[][4])
{
    system("cls");
    cout<<" ------------------------------------------ "<<endl;
    cout<<"|               SEAT MAP                   |"<<endl;
    cout<<" ------------------------------------------ "<<endl;

    cout<<"\n COL:    1   2  |  3   4"<<endl;
    cout<<"     _______________________"<<endl;

    //printing 12 rows
    for(int r=0; r<12; r++){
        cout<<" R "<<(r<9?"0":"")<<(r+1)<<":  ";//printing ro label

        for(int c=0; c<2; c++){//printing first 2 cols
            cout<<"";
            if(seats[r][c] == 1)
                cout<<"[X] ";
            else
                cout<<"[O] ";

        }

        cout<< "  ";

        for(int c=2; c<4; c++){//printing second 2 cols
            if(seats[r][c] == 1)
                cout<<"[X] ";
            else
                cout<<"[O] ";

        }

         // row class
        if(r<3)
            cout<<"   Business"  ;
        else
            cout<<"    Economy"   ;

        cout<<endl;
    }

    cout<<"\n [O]= Available       [X]= Occupied"<<endl;
}

//FUNCTION TO DISPLAY THE SEATS AND BOOK THEM BY ASKING THE USER AND TELLING IF IT IS OCCUPIED OR NOT
void bookSeat(passenger &p, int seats[][4])
{
    system("cls");
    int totalPassengers=p.adult+p.children;

    for(int i = 1; i <= totalPassengers; i++){
        displaySeat(seats);
        cout << "\nSelecting seat for passenger " << i << " of " << totalPassengers << endl;

        //validation incase selecting occupied seat
        bool taken;
        taken = true;
        do{
            //ask for row, validate based on class
            do
            {
                cout << "\nEnter Row Number: ";
                cin >> p.sRow;

                if(p.seatClass == 'B' && (p.sRow < 1 || p.sRow > 3))
                    cout << "Business class is rows 1 to 3 only!\n";


                if(p.seatClass == 'E' && (p.sRow < 4 || p.sRow > 12))
                    cout << "Economy class is rows 4 to 12 only!\n";

            }while(p.seatClass == 'B' && (p.sRow < 1 || p.sRow > 3) || p.seatClass == 'E' && (p.sRow < 4 || p.sRow > 12));

            //ask for coulmn, validate based on 4 couln aisles
            do
            {
                cout<<"\nEnter the Col number: ";
                cin>>p.sCol;
                if(p.sCol<1 || p.sCol>4)
                    cout<<"\nThere are only 4 coulmns!";
            }while(p.sCol<1 || p.sCol>4);

            //index starts from 0 in array but user entered 1
            int r = p.sRow-1;
            int c = p.sCol-1;

            //setting the seat reserve , making it occupied
            if(seats[r][c] == 1)
            {
                cout << "Seat taken! Try another.\n";
                taken = false;
            }
            else
            {
                    seats[r][c] = 1;
                    displaySeat(seats);
                    cout << "\n       SEAT CONFIRMED!\n";
                    break;
            }


        }while(taken == false);

    }
}

//function to calculate final price
void calculatePrice(passenger&p)
{
    double basePrice;
    if (p.seatClass=='B')
        basePrice=bizPrice;

    if(p.seatClass=='E')
        basePrice=econPrice;

    double adultPrice = p.adult * basePrice;
    double childPrice = p.children * (basePrice/2);
    p.totalPrice= adultPrice + childPrice;

    if(p.arrDate!="ONE WAY")
        p.totalPrice=p.totalPrice*2;

    cout<<"\n       PRICE SUMMARY"<<endl;
    cout<<"\n----------------------------"<<endl;
    if(p.seatClass=='B'){
        cout<<"BASE PRICE : "<<bizPrice<<endl;
        cout<<"ADULTS     : "<<p.adult<<" x " <<bizPrice<<" = "<<p.adult*bizPrice<<endl;
        cout<<"CHILDREN   : "<<p.children<<" x " <<(bizPrice/2)<<" = "<<p.children*(bizPrice/2)<<endl;
        if(p.arrDate != "ONE WAY")
        {
            p.totalPrice = p.totalPrice * 2;
            cout << "RETURN TICKET: Price doubled" << endl;
            cout<<"TOTAL   : "<<p.totalPrice<<endl;
        }
        else
        cout << "ONE WAY TICKET" << endl;
    }
    else if(p.seatClass=='E'){
        cout<<"\nBASE PRICE : "<<econPrice<<endl;
        cout<<"ADULTS     : "<<p.adult<<" x " <<econPrice<<" = "<<p.adult*econPrice<<endl;
        cout<<"CHILDREN   : "<<p.children<<" x " <<(econPrice/2)<<" = "<<p.children*(econPrice/2)<<endl;
        if(p.arrDate != "ONE WAY")
        {
            p.totalPrice = p.totalPrice * 2;
            cout << "RETURN TICKET: Price doubled" << endl;
            cout<<"TOTAL   : "<<p.totalPrice<<endl;
        }
        else
        cout << "ONE WAY TICKET" << endl;
    }

}

//payment verification loading animation and
void processPayment(passenger &p)
{
    cout << "\nPress Enter to proceed to payment...";
    cin.ignore();
    cin.get();

    system("cls");
    cout << " ------------------------------------------ " << endl;
    cout << "|          PAYMENT VERIFICATION            |" << endl;
    cout << " ------------------------------------------ " << endl;

    string cardNum;
    string cvc;//used string bcuz int crashes if character are typed
    string otp ="123";

    cout<<"        TOTAL INVOICE PRICE: "<<p.totalPrice<<endl;

    //simple validation to check cc number lenght and get cc number from user
    do{
        cout<<"\nEnter Credit/Debit Card number :  ";
        cin>>cardNum;
        if(cardNum.length() != 16)
            cout<<"\nCard number has only lenght 16!"<<endl;
    }while(cardNum.length() != 16);

    //simple validation to check cvc number lenght and get cvc number from user
    do{
        cout<<"Enter CVC Security Code on back:  ";
        cin>>cvc;
        if(cvc.length() != 3)
            cout<<"\nCVC number has only lenght 3!"<<endl;
    }while(cvc.length() != 3);

    //otp verification
    string enterOTP;
    do{
        cout << "\nPlease enter the OTP on your phone: ";
        cin >> enterOTP;
        if(enterOTP != otp)
            cout << "OTP VERIFICATION FAILED! Please try again.\n";
    }while(enterOTP != otp);

    //loading animation
    cout<<"\n         PROCESSING PAYMENT";
    for(int i = 0; i < 3; i++)
    {
        Sleep(1500);        // waits 1 second
        cout << ".";
    }
    cout << "\n";

    //PRINTING PAYMENT VERIFICATION
    cout << "\n +------------------------------------------+ " << endl;
    cout << " |                                          | " << endl;
    cout << " |         *** PAYMENT SUCCESSFUL ***       | " << endl;
    cout << " |                                          | " << endl;
    cout << " |   Amount Paid : Rs. " << p.totalPrice         << endl;
    cout << " |   Status      : Confirmed                | " << endl;
    cout << " |                                          | " << endl;
    cout << " +------------------------------------------+ " << endl;

}

//TICKET GENERATOR FILE HANDLER FUNCTION
void generateBoardingPass(passenger &p)
{
    // create filename using name
    string filename = "boardingpass_" + p.name + ".txt";

    // open the file
    ofstream ticket(filename);

    ticket << " +------------------------------------------+ " << endl;
    ticket << " |          SKYROUTE BOARDING PASS          | " << endl;
    ticket << " +------------------------------------------+ " << endl;
    ticket << " | Name       : " << p.name                    << endl;
    ticket << " | CNIC       : " << p.cnic                    << endl;
    ticket << " | Phone      : " << p.phone                   << endl;
    ticket << " | Email      : " << p.email                   << endl;
    ticket << " +------------------------------------------+ " << endl;
    ticket << " | From       : " << p.depCity                 << endl;
    ticket << " | To         : " << p.arrCity                 << endl;
    ticket << " | Dep Date   : " << p.depDate                 << endl;
    ticket << " | Ret Date   : " << p.arrDate                 << endl;
    ticket << " | Time Slot  : ";
    if(p.timeSlot == 1)ticket << "04:00 AM"                  << endl;
    if(p.timeSlot == 2) ticket << "03:00 PM"                  << endl;
    if(p.timeSlot == 3) ticket << "11:00 PM"                  << endl;
    ticket << " | Seat Row   : " << p.sRow                    << endl;
    ticket << " | Seat Col   : " << p.sCol                    << endl;
    ticket << " | Class      : ";
    if(p.seatClass == 'B') ticket << "Business"               << endl;
    if(p.seatClass == 'E') ticket << "Economy"                << endl;
    ticket << " | Total Paid : Rs. " << p.totalPrice          << endl;
    ticket << " +------------------------------------------+ " << endl;

    ticket.close();

    cout << "\nBoarding pass saved as: " << filename << endl;
    cout << "Please collect your boarding pass!" << endl;
}

/*END OF THE USER
DEFINED FUNCTIONS.*/

//MAIN
int main()
{
    seatStart();
    passenger p;

    // intro screen
    system("cls");
    INTRO:
    cout << " +------------------------------------------+ " << endl;
    cout << " |                                          | " << endl;
    cout << " |     WELCOME TO SKYROUTE AIRLINES         | " << endl;
    cout << " |      Domestic Flight Reservations        | " << endl;
    cout << " |                                          | " << endl;
    cout << " +------------------------------------------+ " << endl;
    cout << "\n  1. About US"                            << endl;
    cout << "  2. Book A Flight!"                                   << endl;
    cout << "  3. Exit"                                       << endl;

    int choice;
    do{
        cout << "\nEnter your choice: ";
        cin >> choice;
        if(choice < 1 || choice > 3)
            cout << "Invalid! Enter 1, 2 or 3.\n";
    }while(choice < 1 || choice > 3);

    switch(choice)
    {
        case 1:
            system("cls");
            cout << " +------------------------------------------+ " << endl;
            cout << " |                                          | " << endl;
            cout << " |      WELCOME TO SKYROUTE AIRLINES        | " << endl;
            cout << " |      Domestic Flight Reservations        | " << endl;
            cout << " |                                          | " << endl;
            cout << " +------------------------------------------+ " << endl;
            cout << " |                                          | " << endl;
            cout << " |  Created by:                             | " << endl;
            cout << " |   -> Muhammad Hassan Sharif              | " << endl;
            cout << " |   -> Muhammad Daniyal                    | " << endl;
            cout << " |   -> Talha Zafar                         | " << endl;
            cout << " |                                          | " << endl;
            cout << " |  Course    : Programming Fundamentals    | " << endl;
            cout << " |  Instructor: Dr. Arsla KHAN              | " << endl;
            cout << " |                                          | " << endl;
            cout << " +------------------------------------------+ " << endl;
            cout << " |                                          | " << endl;
            cout << " |    From Johar Town, With Love :)         | " << endl;
            cout << " |                                          | " << endl;
            cout << " +------------------------------------------+ " << endl;
            cin.ignore();
            cin.get();
            system("cls");
            goto INTRO;

        case 2:
            passengerINFO(p);
            selectFlight(p);
            switch(p.timeSlot)
            {
                case 1: bookSeat(p, seat4AM);  break;
                case 2: bookSeat(p, seat3PM);  break;
                case 3: bookSeat(p, seat11PM); break;
            }
            calculatePrice(p);
            processPayment(p);
            generateBoardingPass(p);
            break;

        case 3:
            cout << "\nThank you for choosing SkyRoute. Goodbye!\n";
            break;
    }

    return 0;
}

//THIS PROGRAM CONSISTS OF 8 FUNCTIONS EACH PERFORMING DIFFERENT TASKS.A SINGLE STRUCT CONTAINING ALL USER DATA
//seatStart--Initialize arrays and hardcoding random values
//passengerINFO--takes all the data from user and stores in struct passenger
//selectFlight--Allows user to choose required destination and time and stores in struct passenger
//displaySeat--It shows all the seated layout and updates seats acc to users , if they are 3 so enter 3
//bookSeat--allows to book the seat and tells user if it is already booked, and validates if input wrong
//calculatePrice--it sums up all the total price of the number of adults and children and the travel class
//processpayment--simple verification system asking users cc details and payment info
//generateBoardingPass--Simply generates a boarding pass and saves it in a file.
//generateBoardingPass--Simply generates a boarding pass and saves it in a file.
