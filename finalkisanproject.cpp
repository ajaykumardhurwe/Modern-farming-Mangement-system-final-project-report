/*
1 farmer class
a storeCropData
b showCropData
c signin
d signup
e cropsale
f byeingmanure
g CheckUserId
i CheckUserName



*/


#include<bits/stdc++.h>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<string>
#include<string.h>
#include<ctype.h>
#include<math.h>

using namespace std;

void WRITE_LABOURS_FOUND();
void SEARCH_LABOURSNAME();
void SEARCH_VILLAGE();
void LABOURS_SEARCH();
void LABOURSFOUNDPORTAL();
void WRITECROP();
void READCROP();
void WRITEMANURE();
void READMANURE();
void SEARCH_KisanId();
void SEARCH_USERNAME();
void SHOPPING_SEARCH();
void DELETION1();
void DELETION2();
void DELETION();
void marketplace();
void TOTAL_REC();
void mfdetail();
void sfdetail();
void smfdetail();
void mediumfdetail();
void lfdetail();
void FARMER_DETAIL();
void ADMIN_PANEL();
void login();
void registr();
void forgot();




class farmer
{
public:
	int password;
	int qty;
	char date[50];
	char UserName[50];
	char cropname[50];
	char manurename[50];
	int  KisanId;
	char firstname[50];
	char secondname[50];
    char unit[50];
	char gmail[50];
	char laboursname[50];
	char village[50];
	char post[50];
	char block[50];
	char district[50];
	char mono[15];


	public:

		farmer()
		{
			// Default constructor
			password=0;
			 qty=0;
			 
			 date[0]='\0';
			 laboursname[0]='\0';
	         village[0]='\0';
             post[0]='\0';
             block[0]='\0';
	         district[0]='\0';
	          mono[0]='\0';
			 UserName[0]='\0';
	        cropname[0]='\0';
	        manurename[0]='\0';
			KisanId=0;
			firstname[0]='\0';
			secondname[0]='\0';
			gmail[0]='\0';
			unit[0]='\0';

		}
		farmer(char UserName, int KisanId, char firstname, char secondname, int password, int qty, char cropname, char manurename, char date, char unit, char laboursname, char village, char post, char block, char district, char mono)
		{
			// parametrized constructor
		KisanId=KisanId;
		UserName=UserName;
		firstname=firstname;
		secondname=secondname;
		password=password;
		qty=qty;
		date=date;
	    cropname=cropname;
	    manurename=manurename;
	   unit=unit;
       laboursname=laboursname;
	   village=village;
	    post=post;
	    block=block;
	   district=district;
	    mono=mono;
		}

		farmer(farmer &f)
		{
			// copy constructor
		    KisanId=f.KisanId;
		    strcpy(UserName, f.UserName);
			strcpy(firstname, f.firstname);
			strcpy(secondname, f.secondname);
			strcpy(cropname, f.cropname);
			strcpy(manurename, f.manurename);
			strcpy(date, f.date);
			qty=f.qty;
			password=f.password;
		   strcpy(unit, f.unit);
		   strcpy(laboursname, f.laboursname);
		   strcpy(village, f.village);
		   strcpy(post, f.post);
		   strcpy(block, f.block);
		   strcpy(district, f.district);
		   strcpy(mono, f.mono);


		}
// prototype or signature

     void storeCropData();
     void showCropData();
     void storeManureData();
     void showManureData();
     void LaboursFound();
     void LaboursFoundSD();

   // friend void signin(farmer &f1);// friend function
    int CheckKisanId();
//	void signup();
	void cropsale();
    void buyeingmanure();
    char*CheckUserName();
    char*Checklaboursname();
    char*Checkvillage();

};

// try to store records
void farmer::LaboursFound()
{
	cout<<"Welcome to Labours found portal"<<endl;
	cout<<"Labours Name :"<<endl;
	cin>>laboursname;
	cin.ignore();

	cin.getline(mono, 15);
	cout<<"Address :"<<endl;
	cout<<"Village or city Name :"<<endl;
	cin>>village;
	cout<<"post :"<<endl;
	cin>>post;
	cout<<"Block :"<<endl;
	cin>>block;
	cout<<"District :"<<endl;
	cin>>district;
		cout<<"mobile Number :"<<endl;
	cin>>mono;




}

void farmer::LaboursFoundSD()
{

//	cout<<"Welcome to Labours found portal"<<endl;
	cout<<"Labuours Name :"<<laboursname<<endl;
	cout<<"mobile Number :"<<mono<<endl;
	cout<<"Address :"<<endl;
	cout<<"Village or city :"<<village<<"      "<<"post :"<<post<<endl;
	cout<<"Block :"<<block<<"          "<<"District :"<<district<<endl;


}


	void WRITE_LABOURS_FOUND()
{
    ofstream r("record.txt",ios::binary | ios::app);
    farmer f;
    char reply;
    do
    {
        f.LaboursFound();
        r.write((char*)&f,sizeof(f));
        cout<<"Want to enter more records";
        cin>>reply;
    }while(toupper(reply)=='Y');
    r.close();
}

char*farmer::Checklaboursname()
{
	return(laboursname);
}

char*farmer::Checkvillage()
{
	return(village);
}

void SEARCH_LABOURSNAME()
{
    ifstream r("record.txt",ios::in | ios::binary);
    char found='N';
     farmer f;
    if(!r)
    {
        cout<<endl<<"FILE DOESN'T EXIST!!!!!";
        return;
    }
    char ln[50];
     cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"Enter name whose record is to be searched: ";
    gets(ln);
    while(r.read((char*)&f,sizeof(f)))
    {
        if(strcmp(f.Checklaboursname(),ln)==0)
        {
            cout<<"Detail to sale / purches of crop / manure  :";
            f.LaboursFoundSD();
            found='Y';
            break;
        }
    }
    if(found=='N')
    {
        cout<<"NO SUCH RECORD FOUND"<<endl;
    }
    r.close();
}


void SEARCH_VILLAGE()
{
    ifstream r("record.txt",ios::in | ios::binary);
    char found='N';
     farmer f;
    if(!r)
    {
        cout<<endl<<"FILE DOESN'T EXIST!!!!!";
        return;
    }
    char v[50];
     cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"Enter name whose record is to be searched: ";
    gets(v);
    while(r.read((char*)&f,sizeof(f)))
    {
        if(strcmp(f.Checkvillage(),v)==0)
        {
            cout<<"Detail to sale / purches of crop / manure  :";
            f.LaboursFoundSD();
            found='Y';
            break;
        }
    }
    if(found=='N')
    {
        cout<<"NO SUCH RECORD FOUND"<<endl;
    }
    r.close();
}


void LABOURS_SEARCH()
{
    int s;
    cout<<"\n Search on the basis of :- ";
    cout<<"\n 1.Labours Name ";
    cout<<"\n 2.City / Village ";

    cin>>s;
    switch(s)
    {
    case 1:
        SEARCH_LABOURSNAME();
        break;
    case 2:
        SEARCH_VILLAGE();
        break;

    }
}

void LABOURSFOUNDPORTAL()
{
	int c;
	cout<<"****************************************************************************************\n\n";
	
	cout<<"                         Welcome to Labours found portal                            "<<endl;
	
	cout<<"********************                                           ***********************\n\n";
	cout<<"1. Register for wages "<<endl;
	cout<<"2. Find Labours "<<endl;
	cout<<"choose the option as per your choice ---";
	cin>>c;
	switch(c)
	{
		case 1: WRITE_LABOURS_FOUND();
		break;
		case 2: LABOURS_SEARCH();
		break;
		default:
			cout<<"option not valid "<<endl;
	}
}


void farmer::storeCropData()
{
//cout<<"Welcome to Market Place "<<endl;
cout<<"Suitable time for crop sale : ";
     cout<<"\n Enter Your KisanId : ";
     cin>>KisanId;
     cout<<"Enter your user name :";
     cin>>UserName;
     cout<<"\n Enter your crop name :";
     cin>>cropname;
     cout<<"\n Enter crop Qty : ";
     cin>>qty;cin>>unit;

     cout<<"\n Enter suitable date :";
     cin>>date;
    

}

void farmer::showCropData()
{
        cout<<endl<<"KisanId: "<<KisanId;
        cout<<endl<<"User Name :"<<UserName;
        cout<<endl<<"Crop name : "<<cropname;
        cout<<endl<<"Crop quantity : "<<qty<<unit;
        cout<<endl<<"Suitable date : "<<date;

}

void farmer::storeManureData()
{
//cout<<"Welcome to Market Place "<<endl;
cout<<"Suitable time for crop sale : ";
     cout<<"\n Enter Your KisanId : ";
     cin>>KisanId;
     cout<<"Enter your user name :"<<endl;
     cin>>UserName;
     cout<<"\n Enter  Manure name :";
     cin>>cropname;
     cout<<"\n Enter Manure Qty :";
     cin>>qty;cin>>unit;
     //cin.ignore(numeric_limits<streamsize>::max(),'\n');
     cout<<"\n Enter suitable date :"<<endl;;
     cin>>date;

}

void farmer::showManureData()
{
        cout<<endl<<"KisanId: "<<KisanId;
         cout<<endl<<"User Name :"<<UserName;
        cout<<endl<<"Crop name : "<<cropname;
        cout<<endl<<"Crop quantity : "<<qty<<unit;
        cout<<endl<<"Suitable date : "<<date;

}




int farmer::CheckKisanId()
{
    return(KisanId);
}

char*farmer::CheckUserName()
{
	return(UserName);
}

	void WRITECROP()
{
    ofstream r("record.txt",ios::binary | ios::app);
    farmer f;
    char reply;
    do
    {
        f.storeCropData();
        r.write((char*)&f,sizeof(f));
        cout<<"Your orderd is successful !! Are you want to more purchase !";
        cin>>reply;
    }while(toupper(reply)=='Y');
    r.close();
}



	void READCROP()
{
    ifstream r("record.txt",ios::binary | ios::in);
    farmer f;

    if(!r)
    {
        cout<<endl<<"FILE DOESN'T EXIST!!!!!";
        return;
    }
    int ctr=0;

    while(r.read((char*)&f,sizeof(f)))
    {
        cout<<endl<<"Record: "<<++ctr;
        f.showCropData();
    }
    r.close();
}



	void WRITEMANURE()
{
    ofstream r("record.txt",ios::binary | ios::app);
    farmer f;
    char reply;
    do
    {
        f.storeManureData();
        r.write((char*)&f,sizeof(f));
        cout<<"Your orderd is successful !! Are you want to more purchase !";
        cin>>reply;
    }while(toupper(reply)=='Y');
    r.close();
}



	void READMANURE()
{
    ifstream r("record.txt",ios::binary | ios::in);
    farmer f;

    if(!r)
    {
        cout<<endl<<"FILE DOESN'T EXIST!!!!!";
        return;
    }
    int ctr=0;

    while(r.read((char*)&f,sizeof(f)))
    {
        cout<<endl<<"Record: "<<++ctr;
        f.showManureData();
    }
    r.close();
}


void SEARCH_KisanId()
{
    ifstream r("record.txt",ios::in | ios::binary);
    char found='N';
     farmer f;
    if(!r)
    {
        cout<<endl<<"FILE DOESN'T EXIST!!!!!";
        return;
    }
    int KisanId1;
    cout<<"Enter ID whose record is to be searched: ";
    cin>>KisanId1;
    while(r.read((char*)&f,sizeof(f)))
    {
        if(f.CheckKisanId()==KisanId1)
        {
            cout<<"INFORMATION OF THE SHOPPING DETAILS :";
            f.showCropData();
            found='Y';
            break;
        }
    }
    if(found=='N')
    {
        cout<<"NO SUCH RECORD FOUND"<<endl;
    }
    r.close();
}


void SEARCH_USERNAME()
{
    ifstream r("record.txt",ios::in | ios::binary);
    char found='N';
     farmer f;
    if(!r)
    {
        cout<<endl<<"FILE DOESN'T EXIST ! ";
        return;
    }
    char un[50];
     cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"Enter name whose record is to be searched: ";
    gets(un);
    while(r.read((char*)&f,sizeof(f)))
    {
        if(strcmp(f.CheckUserName(),un)==0)
        {
            cout<<"Detail to sale / purches of crop / manure  :";
            f.showCropData();
            found='Y';
            break;
        }
    }
    if(found=='N')
    {
        cout<<"NO SUCH RECORD FOUND"<<endl;
    }
    r.close();
}




void SHOPPING_SEARCH()
{
    int s;
    cout<<"\n                Search on the basis of :-                 \n\n ";
    cout<<"****************                               ********************\n\n";
    cout<<"\n 1.KisanId";
    cout<<"\n 2.UserName";

    cin>>s;
    switch(s)
    {
    case 1:
        SEARCH_KisanId();
        break;
    case 2:
        SEARCH_USERNAME();
        break;

    }
}




void DELETION1()
{
    ifstream fmain("record.txt", ios::binary | ios::in);
    ofstream ftemp("temp.txt", ios::binary | ios::out);
    farmer f;
    int KisanId1;
    cout<<"Enter ID whose record is to be deleted:";
    cin>>KisanId1;
    char found='N';
    while(fmain.read((char*)&f,sizeof(f)))
    {
        if(f.CheckKisanId()!=KisanId1)
        {
            ftemp.write((char*)&f,sizeof(f));
        }
        else
        {
            found='Y';
        }
    }
    if(found=='N')
    {
        cout<<"\n RECORD NOT FOUND!!";
    }
    else
    {
        cout<<"\n RECORD DELETED";
    }
    fmain.close();
    ftemp.close();
    remove("record.txt");
    rename("temp.txt","record.txt");
}



void DELETION2()
{
    ifstream fmain("record.txt", ios::binary | ios::in);
    ofstream ftemp("temp.txt", ios::binary | ios::out);
    farmer f;
    char un[50];
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"Enter Name whose record is to be deleted: ";
    gets(un);
    char found='N';
    while(fmain.read((char*)&f,sizeof(f)))
    {
        if(strcmp(f.CheckUserName(),un)!=0)
        {
            ftemp.write((char*)&f,sizeof(f));
        }
        else
        {
            found='Y';
        }
    }
    if(found=='N')
    {
        cout<<"\n RECORD NOT FOUND!!";
    }
    else
    {
        cout<<"\n RECORD DELETED";
    }
    fmain.close();
    ftemp.close();
    remove("record.txt");
    rename("temp.txt","record.txt");
}


void DELETION()
{
    int s;
    cout<<"           \n Delete on the basis of :-      \n\n  ";
    
    cout<<"\n 1.User ID";
    cout<<"\n 2.User Name";
    cin>>s;
    switch(s)
    {
    case 1:
        DELETION1();
        break;
    case 2:
        DELETION2();
        break;


    }
}





void marketplace()
{
	int c;
	    cout<<"***********************************************************************\n\n\n";
	    cout<<endl;
		cout<<"                    Welcome to Market Place                          \n\n\n "<<endl;
		
		cout<<"****************                               *************************\n\n\n"<<endl;
		cout<<"1. Crop Sale "<<endl;
		cout<<"2. Manure Byeing "<<endl;
	    cout<<"3. Check your shopping Details "<<endl;
		cin>>c;
		switch(c)
		{
			case 1: WRITECROP();
			break;

			case 2: WRITEMANURE();
			break;
			case 3: SHOPPING_SEARCH();
			break;
			
			default :
				cout<<"Plese Choosen option proper way"<<endl;
		}


	}




	void TOTAL_REC()
{
    farmer f;
    ifstream Rt("record.txt",ios::in|ios::binary);
     if(!Rt)
    {
        cout<<"File Reading Error"<<endl;
        return;
    }
    int num=0;
    while(Rt.read((char*)&f,sizeof(f)))
    {
        num++;
    }
    cout<<"Records in the file are-- "<<num;
    Rt.close();
}


void mfdetail()//  mf means marginal farmer agriculture land up to 1 hectare
{

ifstream file;
file.open("farmer1.txt");

if(!file.is_open())
{
	cout<<"File Doesn't exiest"<<endl;
}
else
{
	cout<<"Details of Marginal Farmer "<<endl;
	string line;
	while(file.good())
{


	getline(file,line);
	cout<<line<<endl;
}

}


}

void sfdetail()// sf means small farmer agricultural land of more than 1 hectare and <2 hectare
{
   ifstream file;
file.open("smallfarmer.txt");

if(!file.is_open())
{
	cout<<"File Doesn't exiest"<<endl;
}
else
{
	cout<<"Details of Small Farmer "<<endl;
	string line;
	while(file.good())
{


	getline(file,line);
	cout<<line<<endl;
}

}
}

void smfdetail() // smf means semi medium farmer Agricultural land 2-4 hectare
{

ifstream file;
file.open("semimediumfarmer.txt");

if(!file.is_open())
{
	cout<<"File Doesn't exiest"<<endl;
}
else
{
	cout<<"Details of Marginal Farmer "<<endl;
	string line;
	while(file.good())
{


	getline(file,line);
	cout<<line<<endl;
}

}
}

void mediumfdetail()// mediumf means medium farmer agricultural land of 4-10 hectare
{
ifstream file;
file.open("mediumfarmer.txt");

if(!file.is_open())
{
	cout<<"File Doesn't exiest"<<endl;
}
else
{
	cout<<"Details of Marginal Farmer "<<endl;
	string line;
	while(file.good())
{


	getline(file,line);
	cout<<line<<endl;
}

}
}


void lfdetail()// lf meams large farmer agricultural land of more than 10 hectare
{

ifstream file;
file.open("largfarmer.txt");

if(!file.is_open())
{
	cout<<"File Doesn't exiest"<<endl;
}
else
{
	cout<<"Details of Marginal Farmer "<<endl;
	string line;
	while(file.good())
{


	getline(file,line);
	cout<<line<<endl;
}

}
}

void FARMER_DETAIL()
{
	int c;
	cout<<"*********************************************************************"<<endl;
	cout<<endl;
	cout<<"*************  Welcome to Details of farmer Portal   ****************\n\n"<<endl;
	cout<<"1. Details of Marginal farmer "<<endl;
	cout<<"2. Details of Small farmer "<<endl;
	cout<<"3. Details of Semi Medium farmer "<<endl;
	cout<<"4. Details of Medium farmer "<<endl;
	cout<<"5. Details of Large farmer "<<endl;
	cout<<"which option do you belong to---";
	cin>>c;
	switch(c)
	{
		case 1:mfdetail();
		break;
		case 2:sfdetail();
		break;
		case 3:smfdetail();
		break;
		case 4:mediumfdetail();
		break;
		case 5:lfdetail();
		break;
		default:
			cout<<"Option not found";

	}


}

 class scheme
{
private:


public:

void cis()//cis means crop insurance scheme
{
ifstream file;
file.open("cropinsurance.txt");

if(!file.is_open())
{
	cout<<"File Doesn't exiest"<<endl;
}
else
{
	cout<<" Details of Crop Insurance Scheme "<<endl;
	string line;
	while(file.good())
{


	getline(file,line);
	cout<<line<<endl;
}

}
}

void nfms()//nfms means National farming market scheme
{
ifstream file;
file.open("nationalfarmingmarket.txt");

if(!file.is_open())
{
	cout<<"File Doesn't exiest"<<endl;
}
else
{
	cout<<"Details of Marginal Farmer "<<endl;
	string line;
	while(file.good())
{


	getline(file,line);
	cout<<line<<endl;
}

}

}
void shc()//shc means soil health card
{
ifstream file;
file.open("soilhealthcard.txt");

if(!file.is_open())
{
	cout<<"File Doesn't exiest"<<endl;
}
else
{
	cout<<"Details of soil health card "<<endl;
	string line;
	while(file.good())
{


	getline(file,line);
	cout<<line<<endl;
}

}

}
void of()//of means organic farming
{
ifstream file;
file.open("organicfarming.txt");

if(!file.is_open())
{
	cout<<"File Doesn't exiest"<<endl;
}
else
{
	cout<<"Details of organic farming "<<endl;
	string line;
	while(file.good())
{


	getline(file,line);
	cout<<line<<endl;
}

}

}
void ps()//ps means pension scheme
	{


ifstream file;
file.open("pensionscheme.txt");

if(!file.is_open())
{
	cout<<"File Doesn't exiest"<<endl;
}
else
{
	cout<<"Details of Pension Scheme : "<<endl;
	string line;
	while(file.good())
{


	getline(file,line);
	cout<<line<<endl;
}

}
       cout<<" Apply for pension scheme :"<<endl;
	    int age;
	    string name;
	    cout<<" Eligieblity for pension yojna :"<<endl;
	    cout<<"Enter your name :";
	    cin>>name;
	    cout<<"Enter your age : ";
	    cin>>age;
	    if(age>=60)
        {
            cout<<"you are eligieble for pension yojana "<<endl;
        }
        else
        {
            cout<<"You are not eligieble for pension yojna"<<endl;
        }
	}

void schemeset()//collection of all above scheme
{
	int ch;
    cout<<"***********************************************************************\n\n\n";
    cout<<endl;
	cout<<"                  welcome to Scheme sectiom                               \n\n "<<endl;
	cout<<endl;
	cout<<"****************                              **************************"<<endl;
	cout<<"1. crop insurance scheme"<<endl;
	cout<<"2. National farming market scheme"<<endl;
	cout<<"3. organic farming"<<endl;
	cout<<"4. Pension Scheme "<<endl;
	cout<<"5. soil health card"<<endl;
    cout<<"Which Plan do you want to know about---";
    cin>>ch;
    switch(ch)
    {
    	case 1:cis();
    	break;
    	case 2:nfms();
    	break;
    	case 3:of();
    	break;
    	case 4:ps();
    	break;
    	case 5:shc();
    	break;
    	default:
    		cout<<"Option not found"<<endl;
	}
}


};
void ADMIN_PANEL()
{
	
	int c;
	        cout<<"***********************************************************************\n\n\n";
	        cout<<endl;
	cout<< "******************  HELLO THIS IS ADMIN PANEL  ******************"<<endl;
	cout<<endl;
	cout<<"1. Delete Farmer Shopping Details "<<endl;
	cout<<"2. Total Number of Farmer Shopping "<<endl;
	cout<<"Enter Your choice---- ";
	cin>>c;
	switch(c)
	{
		case 1:
			DELETION();
			break;
			case 2:
	        TOTAL_REC();
	        break;
	        default:
	        	cout<<"option is not valid"<<endl;
	}

	
	
}


int main()
{
        int choice;
        cout<<"*******************************************************************************************************\n\n\n";
        cout<<"         WELCOME TO MODERN FARMING MANAGEMENT SYSTEM PROJECT                               \n\n";
       
	    cout<<"*******************        MENU        *****************************************************************\n\n";
        cout<<"1.LOGIN"<<endl;
        cout<<"2.REGISTER"<<endl;
        cout<<"3.FORGOT PASSWORD (or) USERNAME"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"\nEnter your choice :";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case 1:
                        login();
                        break;
                case 2:
                        registr();
                        break;
                case 3:
                        forgot();
                        break;
                case 4:

                        cout<<"Thanks for using this program\nThis program is created by ---- Ajaykumardhurwe\n\n";
                        break;
                default:
                        system("cls");
                        cout<<"You've made a mistake , give it a try again\n"<<endl; 
                        main();
        }
        
}

void login()
{
        int count;
        string user,pass,u,p;
        system("cls");
        cout<<"please enter the following details"<<endl;
        cout<<"USERNAME :";
        cin>>user;
        cout<<"PASSWORD :";
        cin>>pass;
        
        ifstream input("database.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)
        
                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nHello"<<user<<"\nLOGIN SUCESSFULL !!!\n";
                
                
                
                
                int option;
  
    scheme s;


	do
	{

	    //cout<<"manue"<<endl;
	    cout<<"*******************************************************************************************"<<endl;
	    cout<<endl;
	    cout<<"***************  WELCOME TO MODERN FARMING MANAGEMENT SYSTEM PROJECT   ********************"<<endl;
	    cout<<endl;
	
        cout<<"1. Details of farmer"<<endl;
        cout<<"2. Government Scheme"<<endl;
        cout<<"3. Market Place  "<<endl;
        cout<<"4. Labours Found portal "<<endl;
        cout<<"5. Admin Panel "<<endl;
        cout<<"6. Clear the Screen "<<endl;
        cout<<"7. Logout "<<endl;
                cout<<endl;
                cout<<"Enter Your choice ----"<<endl;

		cin>>option;
		switch(option)
		{
			
                case 1:FARMER_DETAIL();
                break;
                case 2:s.schemeset();
                break;
                case 3:marketplace();
                break;
                case 4:LABOURSFOUNDPORTAL();
                break;
                case 5:ADMIN_PANEL();
                break;
                case 6:system("cls");
                 break;
                case 7: cin.get();
                        main();
				default:

                cout<<"The option is not valid "<<endl;

		}
		 cout<<endl;
	}while(option!=0);
                
                
                
                cin.get();
                cin.get();
                main();
               
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                main();
        }
}

void registr()
{
        
        string reguser,regpass,ru,rp;
	
        system("cls");
        cout<<"Create the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;
        
        ofstream reg("database.txt",ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"\nRegistration Sucessful\n";
        main();
        
        
}

void forgot()
{
        int ch;
        system("cls");
        cout<<"Forgotten ? We're here for help\n";
        cout<<"1.Search your id by username"<<endl;
        cout<<"2.Search your id by password"<<endl;
        cout<<"3.Main menu"<<endl;
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp;
                        cout<<"\nEnter your remembered username :";
                        cin>>searchuser;
                        
                        ifstream searchu("database.txt");
                        while(searchu>>su>>sp)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\nHurray, account found\n";
                                cout<<"\nYour password is "<<sp;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"\nSorry, Your KisanId is not found in our database\n";
                                cout<<"\nPlease kindly contact your system administrator for more details \n";
                                cin.get();
                                cin.get();
                                main();
                        }
                        break;
                }
                case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\nEnter the remembered password :";
                        cin>>searchpass;
                        
                        ifstream searchp("database.txt");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                }       
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\nYour password is found in the database \n";
                                cout<<"\nYour Id is : "<<su2;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"Sorry, We cannot found your password in our database \n";
                                cout<<"\nkindly contact your administrator for more information\n";
                                cin.get();
                                cin.get();
                                main();
                        }
                
                        break;
                }
                
                case 3:
                {
                        cin.get();
                        main();
                }
                default:
                        cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
                        forgot();
        }
}
