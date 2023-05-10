#include <iostream>
#include <string.h>
#include<conio.h>
using namespace std;
struct node
{
int num{1};
    int fill = 0;
    char name[3][10];
    node *next;
    node *prev;
};
struct login
{
    char name[30],pass[30];
};
int n;
class hostel
{
    node *header[10];
    node *cn;


public:
    hostel()
    {
        for (int i = 0; i < 10; i++)
            header[i] = NULL;
    }
    void create()
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                node *nn = new node;
                nn->next = NULL;
                nn->prev = NULL;
                if (header[i] == NULL)
                {
                    header[i] = nn;
                    nn->num = 1;
                }
                else
                {
                    node *cn = header[i];
                    while (cn->next != NULL)
                    {
                        cn = cn->next;
                    }
                    if (j == 2 || j == 3 || j == 4)
                    {
                        cn->num = 4;
                    }
                    if (j == 5 || j == 6 || j == 7)
                    {
                        cn->num = 2;
                    }
                    if (j == 8 || j == 9 )
                    {
                        cn->num = 3;
                    }
                    cn->next = nn;
                    nn->prev = cn;
                }
            }
        }
    }
    void display()
    {
        int j = 0, k = 0, l = 0,a=0,b=0,c=0,d=0,e=0,f=0;
        for (int i = 0; i < 100; i++)
        {
            cout << "--";
        }
        cout << "\n "
        ;
        for (int i = 1; i < 10; i++)
        {
            cout << "| FLOOR NUMBER : "<< i << " \t\t ";
        }
        cout << "|\n" ;
        for (int i = 0; i < 100; i++)
        {
            cout << "--";
        }
        cn = header[j];
        node *sn = header[j + 1];//Floors
        node *tn = header[j + 2];
         node *an = header[j + 3];
          node *en = header[j + 4];
           node *bn = header[j + 5];
            node *yn = header[j + 6];
             node *xn = header[j + 7];
              node *nn = header[j + 8];
             
        cout << "\n ";
        while (cn != NULL)
        {
            if (cn->fill != cn->num && cn->num != 0)
            {
                j++;
                cout << "| ROOM NO : "<< j;
                cout << "->VACANT COTS->"<< cn->num;
            }
            else
            {
                j++;
                cout << "| ROOM NO : "<< j;
                cout << "->PRESENT ";
            }
            if (sn->fill != sn->num && sn->num != 0)
            {
                k++;
                cout << "\t| room no : "<< j;
                cout << "->Vacant cots->"<< sn->num;
            }
            else
            {
                k++;
                cout << " \t| room no : "<< j;
                cout << "->Present ";
            }
            if (tn->fill != tn->num && tn->num != 0)
            {
                l++;
                cout << "\t| room no : "<< j;
                cout << "->Vacant cots->"<< tn->num << "| ";
            }
            else
            {
                l++;
                cout << "\t| room no : "<< j;
                cout << "->Present "<< " | ";
            }
            if (an->fill != an->num && an->num != 0)
            {
                a++;
                cout << "\t| room no : "<< j;
                cout << "->Vacant cots->"<< an->num << "| ";
            }
            else
            {
                a++;
                cout << "\t| room no : "<< j;
                cout << "->Present "<< " | ";
            }
            if (en->fill != en->num && en->num != 0)
            {
                b++;
                cout << "\t| room no : "<< j;
                cout << "->Vacant cots->"<< en->num << "| ";
            }
            else
            {
                b++;
                cout << "\t| room no : "<< j;
                cout << "->Present "<< " | ";
            }
            if (bn->fill != bn->num && bn->num != 0)
            {
                c++;
                cout << "\t| room no : "<< j;
                cout << "->Vacant cots->"<< bn->num << "| ";
            }
            else
            {
                c++;
                cout << "\t| room no : "<< j;
                cout << "->Present "<< " | ";
            }
            if (yn->fill != yn->num && yn->num != 0)
            {
                d++;
                cout << "\t| room no : "<< j;
                cout << "->Vacant cots->"<< yn->num << "| ";
            }
            else
            {
                d++;
                cout << "\t| room no : "<< j;
                cout << "->Present "<< " | ";
            }
            if (xn->fill != xn->num && xn->num != 0 )
            {
                e++;
                cout << "\t| room no : "<< j;
                cout << "->Vacant cots->"<< xn->num << "| ";
            }
            else
            {
                e++;
                cout << "\t| room no : "<< j;
                cout << "->Present "<< " | ";
            }
            if (nn->fill != nn->num && nn->num != 0)
            {
                f++;
                cout << "\t| room no : "<< j;
                cout << "->Vacant cots->"<< nn->num << "| ";
            }
            else
            {
                f++;
                cout << "\t| room no : "<< j;
                cout << "->Present "<< " | ";
            }
            cout << " \n ";
            for (int i = 0; i < 100; i++)
            {
                cout << "--" ;
            }
            cout << "\n ";
            cn = cn->next;
            sn = sn->next;
            tn = tn->next;
            an = an->next;
            en = en->next;
            bn = bn->next;
            yn = yn->next;
            xn = xn->next;
            nn = nn->next;
           
        }
    }
    void book(int people)//BOOKING MILAN
    {
        int floor, room;
        cout << "\nENTER THE FLOOR NUMBER : ";
        cin >> floor;
        try
        {
            if (floor < 0 || floor > 10)


            {
                throw(floor);
            }
            cn = header[floor - 1];


            cout << "\nENTER THE ROOM NUMBER: ";
            cin >> room;
            try
            {


                if (room < 0 || room > 10)
                {
                    throw(room);
                }
                else
                {
                    int i = 1;
                    while (i < room)
                    {
                        cn = cn->next;
                        i++;
                    }
                    if (cn->num >= people)
                    {
                        cout << "\nROOM IS VACANT \n YOU CAN APPLY FOR ROOM" ;


                        int count = 0;
                        while (cn->fill - 1 <= cn->num)
                        {


                            cout << "\nENTER NAME: "<< cn -> fill + 1 << " : ";


                            cin >> cn->name[cn->fill];
                            count++;
                            cn->fill++;
                            if (count >= people)
                            {
                                break;
                            }
                        }
                        cn->num = cn->num - people;
                    }


                    else
                    {
                        cout << "\nROOM IS NOT VACANT... SORRY !!!";
                    }
                }
            }
            catch (int r)
            {
                cout << "\nINVALID ROOM NUMBER : "<< r;
            }
        }
        catch (int r)
        {
            cout << " \nINVALID FLOOR NUMBER : " << r;
        }
    }
    void cancel(int check)//CANCELLING
    {
        char namecheck[10];
        int flag = 0;
        int room, i = 1;
        try
        {
            if (check < 0 || check > 10)


            {
                throw(check);
            }
            else
            {
                cout << " ENTER THE ROOM NO : ";
                cin >> room;
                try
                {
                    if (room < 0 || room > 10)
                    {
                        throw(room);
                    }
                    else
                    {
                        cout << " ENTER THE NAME TO BE DELETE:";


                        cin >> namecheck;
                        cn = header[check - 1];
                        while (i < room)
                        {
                            cn = cn->next;
                            i++;
                        }
                        i = 0;
                        while (i < 10)
                        {


                            if (!strcmp(namecheck, cn -> name[i]))


                            {
                                flag = 1;
                                break;
                                i = 0;
                            }
                            else
                                i++;
                        }
                        if (flag == 1 && cn->fill != 0)
                        {
                            cout << "\nRECORD DELETED : "<< cn -> name[i];


                            cn->name[i][0] ='A';
                            cn->name[i][1] ='\0';
                            cn->fill--;
                            cn->num++;
                        }
                        else


                            cout << "\nRECORD NOT PRESENT ";
                    }
                }
                catch (int r)
                {
                    cout << "\nINVALID ROOM NUMBER : " << r;
                }
            }
        }


        catch (int r)


        {
            cout << " \n FLOOR DOES NOT EXIST : " << r;
        }
    }
    void upgrade(int check)//UPGRADING DIVYANSH
    {
        char namecheck[10];
        int room, i = 1;
        try
        {
            if (check < 0 || check > 10)


            {
                throw(check);
            }
            else
            {
                cout << " Enter the room no : ";
                cin >> room;
                try
                {
                    if (room < 0 || room > 10)


                    {
                        throw(room);
                    }
                    else
                    {
                        cout << "Enter the name to be updated :";


                        cin >> namecheck;
                        cn = header[check - 1];
                        while (i < room)
                        {
                            cn = cn->next;
                            i++;
                        }
                        i = 0;
                        while (i < 10)
                        {
                            if (!strcmp(namecheck, cn -> name[i]))


                            {
                                cout << "\nenter updated name : " ;


                                cin >> cn->name[i];
                                break;
                            }
                            else
                                i++;
                        }
                        if (i >= 10)
                            cout << "record not found ";
                        else
                        {
                            cout << "\nrecord updated\nprevious name : "<< namecheck << "\nupdated name : "<< cn->name[i];
                        }
                    }
                }
                catch (int r)
                {
                    cout << "\ninvalid room number : "<< r;
                }
            }
        }


        catch (int r)


        {
            cout << "\n floor dosn't exist : "<< r;
        }
    }
    void admin()//ADMIN Ruchitha
    {
        cout<<"\n=====================================";
        cout<<"\n WELCOME TO HOSTEL MANAGEMENT SYSTEM";
        cout<<"\n=====================================";
        cout<<"\n\n1.LOGIN\t\t2.REGISTER";
        cout<<"\n\n\nENTER YOUR CHOICE: ";
        cin>>n;
        switch(n)
        {
            case 1: 
            cout<<"\n\n";
            login();
            break;
            case 2: 
            cout<<"\n\n";
            reg();
            default:
            cout<<"\n\n";
            cout<<"\nWRONG CHOICE";
            admin();
            break;
        }
    }
    void reg()//REGISTRATION RUhcitha
    {
        FILE *fp;
        struct login l;
        fp=fopen("login.txt","w");
        cout<<"\n========================";
        cout<<"\n      REGISTRATION";
        cout<<"\n========================";
        cout<<"\n\nUSER ID:  ";
        cin>>l.name;
        fflush(stdin);
        cout<<"\nPASSWORD:  ";
        cin>>l.pass;
        cout<<"\n\n<<ENTER TO PROCEED>>";
        getch();
        fwrite(&l,sizeof(l),1,fp);
        fclose(fp);   
        cout<<"\n\nACCOUNT SUCCESSFULLY CREATED";
        cout<<"\n\nGO TO LOGIN PAGE\n\n";
        cout<<">PRESS 1 FOR YES\n\n> PRESS 2 FOR NO\n\n";
        cin>>n;
        switch(n)
        {
            case 1: 
            login();
            break;
            case 2:  
            cout<<"\nTHANK YOU FOR REGISTERING";
            exit(0);
            break;
        }  
    }  
    void login()//LOGIN
    {
        FILE *fp;
        char c,name[30],pass[30];
        fp=fopen("login.txt","r");
        cout<<"\n================";
        cout<<"\n     LOGIN";
        cout<<"\n================";
        struct login l;
        cout<<"\n\nUSER ID:  ";
        cin>>name;
        fflush(stdin);
        cout<<"\nPASSWORD: ";
        cin>>pass;
        while(fread(&l,sizeof(l),1,fp))
        {
            if(strcmp(name,l.name)==0 && strcmp(pass,l.pass)==0)
            {   
                mainmenu();
            }
            else if(strcmp(name,l.name)==0&&strcmp(pass,l.pass)!=0)
            {
                cout<<"\n\nWRONG PASSWORD!!";
                cout<<"\n\n<<PRESS 'Y' TO RE_LOGIN)";
                if(getch()=='y'||getch()=='Y')
                login();
            }
            else if(strcmp(name,l.name)!=0)
            {
                cout<<"\n\nNOT AN EXISTING USER\nPRESS ENTER TO REGISTER\n";
                if(getch()==10)
                cout<<"\n\n";
                reg();
            }
        }
        fclose(fp);
        getch();
    }
    void mainmenu()//MAIN MENU
    {
        int key;
        char ch;
        int floorcheck;
        do
        {
        cout<<"\n\n\n=========================";
        cout<<"\n        MAINMENU";
        cout<<"\n========================\n";
        cout << "1.BOOK A ROOM FOR 1 PERSON\n2.DISPLAY THE CURRENT STATUS OF THE ROOMS\n3.CANCEL BOOK\n4.UPDATE CURRENT ROOM"<< endl;
        cout<<"\n\nENTER YOUR CHOICE:";
        cout << " "   ;
        cin >> key;
        switch (key)
        {
        case 1:
        {
            this->book(1);
            break;
        }
       
        case 2:
        {
            this->display();
            break;
        }
        case 3:
        {
            cout << "ENTER FLOOR NUMBER : ";
            cin >> floorcheck;
            this->cancel(floorcheck);
            break;
        }
        case 4:
        {
            cout << "ENTER FLOOR NUMBER : ";
            cin >> floorcheck;
            this->upgrade(floorcheck);
            break;
        }


        default:
            cout << "\nInvalid choice ";
        }
        cout << "\nDo you want to continue(Y / N) ";
        cin >> ch;
        } while (ch =='Y'|| ch =='y');
    }   
};
int main()//MAIN FUCNTION
{


    hostel obj;
    obj.create();
    obj.admin();
    obj.mainmenu();   
}