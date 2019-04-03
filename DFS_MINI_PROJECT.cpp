#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
#define A 2000
using namespace std;
class attend{
	public:
	string adate;
	string lunch;
	string dinner;
	string both;
	attend *link;
};

class node {
	public:
	string name ;
	string phoneno;
	string date;
	int t;
	int amount;
	int pamount;
	string time;
	int tamount;
	int lcount=0;
	int dcount=0;
	node *next;
	attend *a=NULL;

};
class mess{
	node *head;
	attend *ahead;
public:
	mess();
    void save();
	void insert();
	void display();
	void del();
	void attendence();
	void dspattend(node *);
	void dsp(node *m);
	void getamount(node *temp);
	node* update();
	attend* timing(node *);
	void total();
	void receipt();


};
mess::mess(){

	head=NULL;
	ahead=NULL;



}
void mess::insert(){
	int a=0,b=0;
	node *temp;
	temp=new node;
	cout<<endl;
	cout<<"                            Enter Customer Details \n"<<endl;
	cout<<"Enter name of Customer->";
	cin.ignore();
	getline(cin,temp->name);
	//cin>>temp->name;
	cout<<"Enter phone number->";
	cin>>temp->phoneno;

	do
	{
		if(a>0)
		{
			cout<<"Please re-enter your choice \n";
		}
	cout<<"Enter the timing (1.lunch 2.dinner 3.both)";
	cin>>temp->t;
	a++;
	}while(temp->t>3);

	cout<<"Enter Date of joining mess->";
	cin>>temp->date;


	do
	{
		if(b>0)
		{
			cout<<"Please pay the minimum amount"<<endl;
		}
		getamount(temp);
		b++;
	}while(temp->amount<500);

	temp->next=NULL;
	if(head==NULL){
		head=temp;
	}
	else{
		node *p;
		p=head;

		while(p->next!=NULL){
			p=p->next;
		}
		p->next=temp;
	}
}
void mess :: getamount(node *temp)
{

	cout<<"Enter Amount paid->";
		cin>>temp->amount;

}

void mess::save()
{

    ofstream data;
    data.open("Report.txt",ios::app);
    node* temp=head;
   
	
    data<<"                 Customer Details \n"<<endl;
    data<<"______________________________________________________________________________________________________________"<<endl;
    data<<left<<setw(15)<<"Customer name";
    data<<right<<setw(15)<<"Phone no";
    data<<right<<setw(15)<<"Date";
    data<<right<<setw(15)<<"Amount";
    data<<right<<setw(15)<<"Total lunch";
    data<<right<<setw(15)<<"Total dinner";
    data<<right<<setw(15)<<"Pending amount"<<endl;
    data<<"_______________________________________________________________________________________________________________"<<endl;
	
	
	
    while(temp!=NULL){
        data<<left<<setw(15)<<temp->name;
        data<<right<<setw(15)<<temp->phoneno;
        data<<right<<setw(15)<<temp->date;
        data<<right<<setw(15)<<temp->amount;
        data<<right<<setw(15)<<temp->lcount;
        data<<right<<setw(15)<<temp->dcount;
        switch(temp->t)
        {
        	case 1:
        		data<<right<<setw(15)<<((A/2)-temp->amount)<<endl;
        		break;
        	case 2:
				data<<right<<setw(15)<<((A/2)-temp->amount)<<endl;
				break;
			case 3:
			    data<<right<<setw(15)<<((A)-temp->amount)<<endl;	
        		break;
		}
        
        temp=temp->next;
    }
}




void mess::display(){
	node *p;
	char N;
	string mname;
	if(head==NULL)
	{
			cout<<"Customer list is Empty "<<endl;
			return;
	}

	else{

		cout<<"1:To display All customers details "<<endl;
		cout<<"2:To Display Particular customer Details "<<endl;
		cin>>N;
		switch(N){
			case '1':
			{
				p=head;
				cout<<endl;
				cout<<"                       Customer Details \n"<<endl;
				cout<<"______________________________________________________________________________"<<endl;
				cout<<left<<setw(15)<<"Customer name";
				cout<<right<<setw(15)<<"Phone no";
				cout<<right<<setw(15)<<"Joining Date";
				cout<<right<<setw(15)<<"Amount"<<endl;
				cout<<"______________________________________________________________________________"<<endl;

				while (p!=NULL)
				{

				dsp(p);
				//data << p->name << "  " << p->amount;
				cout<<endl<<"------------------------------------------------------------------------------"<<endl;
				p=p->next;

				}
				break;
			}
			case '2':
				{
				cout<<"Enter name to find Details ->";
				cin>>mname;
				p=head;
				while(p!=NULL)
				{
					if(p->name==mname)
					{
						cout<<endl;
						cout<<"                 Customer Details \n"<<endl;
						cout<<"______________________________________________________________________________"<<endl;
						cout<<left<<setw(15)<<"Customer name";
						cout<<right<<setw(15)<<"Phone no";
						cout<<right<<setw(15)<<"Date";
						cout<<right<<setw(15)<<"Amount"<<endl;
						cout<<"______________________________________________________________________________"<<endl;

						dsp(p);
						break;
					}
					p=p->next;
				}
				if(p==NULL)
				cout<<"Customer not found "<<endl;
				break;
				}
	}}
}
void mess::dsp(node *m){
	//cout<<endl;
	cout<<left<<setw(15)<<m->name;
	cout<<right<<setw(15)<<m->phoneno;
	cout<<right<<setw(15)<<m->date;
	cout<<right<<setw(15)<<m->amount+m->pamount;
	cout<<endl<<endl;
	//data << m->name << "  " << m->phoneno;
	//cout<<"______________________________________________________________________________"<<endl;
	cout<<left<<setw(15)<<"Date  ";
	switch(m->t)
	{
		case 1:
			cout<<right<<setw(15)<<"Lunch "<<endl;
			break;
		case 2:
			cout<<right<<setw(15)<<"Dinner "<<endl;
			break;
		case 3:
		cout<<right<<setw(15)<<"Lunch";
		cout<<right<<setw(15)<<"Dinner "<<endl;
		break;
		default :
			cout<<"Entered wrong choice"<<endl;
			break;



	}


	//cout<<"______________________________________________________________________________"<<endl;
	dspattend(m);

}
void mess::attendence(){
	node *p;
	p=head;
	attend *s;
	if(head==NULL)
	{
		cout<<"Customer List is empty"<<endl;
		return;
	}
		string name;
	cout<<"Enter name for attendence->";
	cin>>name;
		while(p!=NULL)
		{
			//cout<<"while";
				if(p->name==name)
				{
					//cout<<"if";
					timing(p);
					break;
				}
				p=p->next;
		}
			if(p==NULL)
		{
			cout<<"Customer Not Found"<<endl;
			return;

		}


	//string name;
	//cout<<"Enter name for attendence->";
	//cin>>name;





int num;
	switch(p->t)
	{
		case 1:
			s=timing(p);
			cout<<"Enter Date->";
				cin>>s->adate;

			cout<<"Lunch (PRESS-> 1:Present , 2:Absent)";
			cin>>num;
			if(num==1)
			{

			s->lunch="Present";
				p->lcount++;
		}
			else
			s->lunch="Absent";
			break;
		case 2:
		s=timing(p);
		cout<<"Enter Date->";
				cin>>s->adate;

			cout<<"dinner (PRESS-> 1:Present , 2:Absent)";
			cin>>num;
			if(num==1)
			{

			s->dinner="Present";
				p->dcount++;
			}
			else
			s->dinner="Absent";

		break;
		case 3:
			s=timing(p);
			cout<<"Enter Date->";
			cin>>s->adate;
			cout<<"lunch (PRESS-> 1:Present , 2:Absent)";
			cin>>num;
				if(num==1)
			{

			s->lunch="Present";
				p->lcount++;
		}
			else
			s->lunch="Absent";
			cout<<"dinner (PRESS-> 1:Present , 2:Absent)";
			cin>>num;
				if(num==1)
			{

			s->dinner="Present";
				p->dcount++;
			}
			else
			s->dinner="Absent";





			break;
		default :
		cout<<"Entered wrong choice,Please re-enter your choice "<<endl;
		break;

	}


}
attend* mess :: timing(node *p)
{



				attend *s,*r;
				s=new attend;


				s->link=NULL;

				if(p->a==NULL)
				{
					p->a=s;
					return s;

				}
				else
				{

					r=p->a;
					while(r->link!=NULL)
					{
						r=r->link;
					}
					r->link=s;
					return s;
				}


			}

void mess::dspattend(node *m)
{
	node *p;

	p=m;
	if(p->a==NULL){
		return;
	}
	attend *s;
	s=p->a;
	cout<<endl;
	while(s!=NULL){
		cout<<left<<setw(15)<<s->adate;
		switch(p->t)
		{
		case 1:
		cout<<right<<setw(15)<<s->lunch<<endl;
		break;

		case 2:
	 	cout<<right<<setw(15)<<s->dinner<<endl;

	break;
	case 3:
		cout<<right<<setw(15)<<s->lunch;
		cout<<right<<setw(15)<<s->dinner<<endl;
		break;
	}

	s=s->link;}



}
void mess::del(){
	string name;
	node *p,*d,*s;
	p=head;
	if (head==NULL)
	{
			cout<<"Customer List is Empty"<<endl;
			return;
	}

	cout<<"Enter Name to delete customer info->";
	cin>>name;

	s=p;
	while(p!=NULL)
	{
		if(p->name==name)
		{
			if(p==head)
			{
				head=NULL;
				d=p;
				delete p;
				cout<<"Successfully Deleted Info of Customer "<<name<<endl;
				
				return;

			}
			s->next=p->next;
			d=p;
			delete d;
			cout<<"Successfully Deleted Info of Customer "<<name<<endl;
			return;
		}
		s=p;
		p=p->next;
	}
	if(p==NULL)
	cout<<"Customer Not found \n";

}
node*  mess :: update()
{
	string mname;
	int num;
	node *tempo;
	tempo=head;
	if(head==NULL)
	{
		cout<<"No registered customer\n";
		return NULL;
	}


	cout<<"Enter the name to update->";
	cin>>mname;
	while(tempo!=NULL)
	{
		if(tempo->name==mname)
		{
			cout<<"Enter new contact";
			cin>>tempo->phoneno;
			cout<<"Do you want to change the date (Y=1/N=0)->";
			cin>>num;
			if(num==1)
			{
			cout<<"Enter date->";
			cin>>tempo->date;
			}
			else
			{
				cout<<"Date change is not required"<<endl;
			}
			cout<<"Enter the amount->";
			cin>>tempo->pamount;
			cout<<"The information of "<<mname<<" updated successfully";
			return tempo;	
		}
		tempo=tempo->next;
	}
		if(tempo==NULL)
		{
			cout<<"Customer not found\n";
			return NULL;
		}

	
	
	}


void mess :: total()
{
	
	int amount;
	string name;
	if(head==NULL)
	{
		cout<<"No registered customer"<<endl;
		return;
	}
	node *p;
	p=head;
	cout<<"Enter name to search ";
	cin>>name;
	
	while(p!=NULL)
	{
		if(p->name==name)
		{
			amount=p->amount;
			switch(p->t)
			{
			case 1:
			cout<<"lunch :"<<p->lcount<<endl;
			cout<<"pending amount :"<<(A/2-amount);
			break;
			case 2:
			cout<<"dinner:"<<p->dcount<<endl;
			cout<<"Pending amount :"<<(A/2-amount);
			break;
			case 3:
			cout<<"lunch :"<<p->lcount<<endl;
			cout<<"dinner:"<<p->dcount<<endl;
			cout<<"Pending amount :"<<(A-amount);
			break;
			default :
				cout<<"Wrong choice";
			
		}

		}
		p=p->next;
	}

}
void mess::receipt()
{
		if(head==NULL)
	{
		cout<<"No registered customer\n";
		return;
	}
	ofstream file;
	file.open("Receipt.txt");
	string contact;
	string mname;
	contact="9561208966";
	node *temp;
	cout<<"Enter the name ->";
	cin>>mname;
	temp=head;

	while(temp!=NULL)
	{
		if(temp->name==mname)
		{
			file<<"                                                   ||SHREE||                                 "<<endl;
			file<<endl;
			file<<"                                                   GOKUL MESS                                   "<<endl;
			file<<"                                                                                              contact : "<<contact<<endl;
			file<<endl<<endl;
			file<<"                                             * Receipt of Payment *                       "<<endl;
			file<<endl<<endl;
			file<<" Name of the customer : "<<temp->name<<endl;
			file<<endl;
			file<<" Date of joining : "<<temp->date<<endl;
			file<<endl;
			//cout<<" Time of a mess : "<<temp->time;
			file<<" Payment done : "<<temp->amount<<endl;
			file<<endl;
			switch(temp->t)
			{
				case 1 :
					file<<" Remaining payment : "<<A/2-temp->amount<<endl;
					break;
				case 2:
					file<<" Remaining payment : "<<A/2-temp->amount<<endl;	
					break;
				case 3:
					file<<" Remaining payment : "<<A-temp->amount<<endl;
					break;
				
			}
			
			file<<endl;
			file<<endl<<endl;
			file<<" Signature of  customer"<<"                                     Signature of Manager"<<endl;
			cout<<"Receipt created successfully";
			
			return ;
			
		}
		else
		{
			cout<<"Name not found";
		}
		temp=temp->next;
	}
	
	
}
int main (){
	mess mk;
	char N;
    string aid,apassword;
	string id,password;
	int count=1;
	
	id="aniket";
	password="123456";
	cout<<"                                          * MESS MANAGEMENT SYSTEM *     \n\n ";
		
	cout<<"Enter the login ID : ";
	cin>>aid;
	cout<<"Enter the password : ";
	cin>>apassword;
	if(aid==id && apassword==password)
		{
	while(count==1)
	{
		cout<<endl<<endl;
		cout<<"Enter your choice :\n";
		cout<<"1:To Add new Customer\n"<<"2:To display customer info"<<endl<<"3:To add attendence\n"<<"4:Receipt of Payment "<<endl;
		cout<<"5:To delete customer"<<endl<<"6:Update information"<<endl<<"7:Total"<<endl<<"8:To stop\n";
		cin>>N;
		switch(N){
			case '1':
				{
					mk.insert();
					break;
				}
			case '2':
				{
					mk.display();
					break;
				}
			case '3':
				{
					mk.attendence();
					break;
				}
			case '4':	
			 	{
					mk.receipt();
			    	break;
			    }
			
			case '5':
				{
					mk.del();
					break;

				}
			case '6':
				mk.update();
				break;
				
			case '7':
				mk.total();
				break;
			
			case '8':
			{
				count++;
				break;
			}
			default:
			{
				cout<<"You entered wrong choice "<<endl;
				break;

			}
		}
	}
	}
	else 
  	{
		if(aid!=id)
		{
			cout<<"Invalid login credentials ";	
		
		}
			
	}	
	mk.save();
	return 0;
}
/*
**INPUT** :
                                         * MESS MANAGEMENT SYSTEM *

Enter the login ID : aniket
Enter the password : 123456


Enter your choice :
1:To Add new Customer
2:To display customer info
3:To add attendence
4:Receipt of Payment
5:To delete customer
6:Update information
7:Total
8:To stop
1

                            Enter Customer Details

Enter name of Customer->aniket
Enter phone number->7020855302
Enter the timing (1.lunch 2.dinner 3.both)1
Enter Date of joining mess->12/3/18
Enter Amount paid->800




Enter your choice :
1:To Add new Customer
2:To display customer info
3:To add attendence
4:Receipt of Payment
5:To delete customer
6:Update information
7:Total
8:To stop
3


Enter name for attendence->manoj
Enter Date->13/7/18
dinner (PRESS-> 1:Present , 2:Absent)2




 OUTPUT :
                       Customer Details

______________________________________________________________________________
Customer name         Phone no   Joining Date         Amount
______________________________________________________________________________
aniket              7020855302        12/3/18            800

Date                    Lunch


12/4/18                Present

------------------------------------------------------------------------------
manoj               7583648367        23/4/18            900

Date                   Dinner


13/7/18                 Absent

------------------------------------------------------------------------------
yash                4556674867        24/5/18            500

Date                     Lunch        Dinner


15/6/18                Present         Absent

------------------------------------------------------------------------------
rahul              90857383748        21/3/18           1000

Date                     Lunch        Dinner


12/4/18                Present        Present

------------------------------------------------------------------------------

              Customer Details 

______________________________________________________________________________________________________________
Customer name         Phone no           Date         Amount    Total lunch   Total dinner Pending amount
_______________________________________________________________________________________________________________
aniket              7020855302        12/3/18            800              1              0            200
manoj               7583648367        23/4/18            900              0              0            100
yash                4556674867        24/5/18            500              1              0           1500
rahul              90857383748        21/3/18           1000              1              1           1000
*/


