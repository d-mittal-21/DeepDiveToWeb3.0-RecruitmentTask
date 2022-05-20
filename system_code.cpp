#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;

class loans 
{
    private:
    string name;
    string type;
    int income;
    int ammount;
    int interest;
    string company;
    string mobile;
    // int aadhar[12];

    public:
    void homescreen();
    void lenders();
    void borrowers();
    void Admin();
};

void loans :: homescreen() 
{
    t:
    int num;
    cout<<"\t\t\t-----------------------------------------------"<<endl;
    cout<<"\t\t\t      Welcome To Divyansh's Loaning Service    "<<endl;
    cout<<"\t\t\t-----------------------------------------------"<<endl;
    cout<<"\t\t\t click 1 if you are administrator              "<<endl;
    cout<<"\t\t\t click 2 if you want to lend your money        "<<endl;
    cout<<"\t\t\t click 3 if you want to borrow some money      "<<endl;
    cin>> num;
    string pass;
    switch(num) 
    {
        case 1:
        {
            cout<<"\t\t\t-----------------------------------------------"<<endl;
            cout<<"\t\t\t please enter the passcode                     "<<endl;
            cin>> pass;
            if(pass== "123456")
            Admin();
            else
            {
                cout<<"\t\t\t you are not administrator                     "<<endl;
                cout<<"\t\t\t Calling Police in 3...2....1....              "<<endl;
            }
            break;
        }
        case 2:
        {
            cout<<"\t\t\t-----------------------------------------------"<<endl;
            lenders();
            break;
        }
        case 3:
        {
            cout<<"\t\t\t-----------------------------------------------"<<endl;
            borrowers();
            break;
        }
        default :
        {
            cout<<"\t\t\t please click valid options(1/2/3)            "<<endl;
            break;
        }
    }
    goto t;
}

void loans :: Admin()
{
    fstream data;
    cout<<"\t\t\t Hello Admin !!!                               "<<endl;
    cout<<"\t\t\t Here is the List of Members of our Service    "<<endl;
    data.open("database.txt", ios::in);
    data>>type>>name>>company>>mobile>>income>>ammount>>interest;
    while(!data.eof())
    {
        cout<<" "<<type<<" "<<name<<" "<<company<<" "<<mobile<<" "<<income<<" "<<ammount<<" "<<interest<<endl;
        data>>type>>name>>company>>mobile>>income>>ammount>>interest;
    }
    data.close();
}
void loans :: lenders()
{
    fstream data;
    cout<<"\t\t\t Welcome Rich Dude                             "<<endl;
    cout<<"\t\t\t Please enter your Name                        "<<endl;
    cin>> name;
    type= "lender";
    cout<<"\t\t\t please enter your annual income               "<<endl;
    cin>> income;
    cout<<"\t\t\t please enter the amount you want to deposit   "<<endl;
    cin>> ammount;
    cout<<"\t\t\t please enter your company/office/firm name    "<<endl;
    cin>> company;
    cout<<"\t\t\t please enter your mobile number               "<<endl;
    cin>> mobile;
    if(ammount>1000000)
    interest= 9;
    else if(ammount>500000)
    interest= 7;
    else
    interest= 6;
    cout<<"\t\t\t Based on your data you will recieve "<<interest<<"% anually     "<<endl;
    cout<<"\t\t\t Thank You for using our Services              "<<endl;
    cout<<"\t\t\t Deposit the money at our office within 2 days "<<endl;
    data.open("database.txt", ios::app|ios::out);
    data<<" "<<type<<" "<<name<<" "<<company<<" "<<mobile<<" "<<income<<" +"<<ammount<<" +"<<interest<<endl;
    data.close();
}
void loans :: borrowers()
{
    fstream data;
    int appr;
    cout<<"\t\t\t Welcome Dude                                  "<<endl;
    cout<<"\t\t\t Please enter your Name                        "<<endl;
    cin>> name;
    type= "borrower";
    cout<<"\t\t\t please enter your annual income               "<<endl;
    cin>> income;
    cout<<"\t\t\t please enter the amount you want to borrow    "<<endl;
    cin>> ammount;
    cout<<"\t\t\t please enter your company/office/firm name    "<<endl;
    cin>> company;
    cout<<"\t\t\t please enter your mobile number               "<<endl;
    cin>> mobile;
    if(ammount>income)
    appr=0;
    else
    appr=1;
    interest = 12;
    if(appr==1)
    {
        cout<<"\t\t\t Your Loan is Approved at 12% per annum        "<<endl;
        cout<<"\t\t\t You can collect your money from our office tomorrow"<<endl;
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<type<<" "<<name<<" "<<company<<" "<<mobile<<" "<<income<<" -"<<ammount<<" -"<<interest<<endl;
        data.close();
    }
    else
    cout<<"\t\t\t Your Loan is not approved                     "<<endl;
    cout<<"\t\t\t Thank you for choosing us                     "<<endl;

}

int main()
{
    loans DLS;
    DLS.homescreen();
}