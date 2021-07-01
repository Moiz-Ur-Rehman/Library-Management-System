#include<iostream>
#include<string>
#include<sstream>

using namespace std;

void fine();

struct booknode
{
	string bname;
	string bauthor;
	int bid;
	string status;
	booknode *next;
};

struct snode
{
	string sname;
	string regNo;
	int semester;
	int bid;
	string status;
	string magname;
	snode *next;
};

struct magazinenode
{
	string mname;
	string genre;
	string status;
	magazinenode *next;
};


class booklist
{
	booknode *head;
	booknode *tail;
public:
	booklist();
	~booklist();
	void createnode(string bname,string bauthor,int bid,string status);
	void issuebook(int bid);
	void returnbook(int bid);
	void displayspecific(int bid);
	void displayissued();
	void deleteSpecific(int bid);
	void display();
	int getid(booknode *node)
	{
		while (node != NULL)
			return node->bid;
	}
	booknode *gethead()
	{
		return head;
	}
};
booklist::booklist()
{
	head = tail = NULL;
}
booklist::~booklist()
{
	booknode *t = head;
	head = head->next;
	while (head != NULL)
	{
		delete t;
		t = head;
		head = head->next;
	}
}
void booklist::createnode(string bname, string bauthor, int bid, string status)
{
	booknode *temp = new booknode;
	temp->bname = bname;
	temp->bauthor = bauthor;
	temp->status = status;
	temp->bid = bid;
	temp->next = NULL;
	if (head == NULL)
	{
		head = tail = temp;
		temp = NULL;
	}
	else
	{
		tail->next = temp;
		tail = temp;
		temp = NULL;
	}
}
void booklist::issuebook(int bid)
{
	if (head != NULL)
	{
		booknode *current = head;
		bool found = false;
		while (current != NULL)
		{
			if (current->bid == bid)
			{
				found = true;
				if (current->status == "Available")
				{
					current->status = "Issued";
					cout << "Book Issued Succesfully\n";
					cout << "Book Name: " << current->bname << endl;
					cout << "Book Author: " << current->bauthor << endl;
					cout << "Book ID: " << current->bid << endl;
					break;
				}
				else cout << "Cannot Issue Book. Book is already Issued\n";
			}
			current = current->next;
		}
		if (!found)
			cout << "Book Not Found\n";
	}
	else cout << "Book List is empty\n";
}
void booklist::displayissued()
{
	if (head != NULL)
	{
		booknode *current = head;
		bool found = false;
		int i = 1;
		while (current != NULL)
		{
			if (current->status == "Issued")
			{
				found = true;
				cout << "Book " << i++ << endl;
				cout << "Book Name: " << current->bname << endl;
				cout << "Book Author: " << current->bauthor << endl;
				cout << "Book ID: " << current->bid << endl;
			}
			current = current->next;
		}
		if (!found)
			cout << "No Issued Books Found\n";
	}
	else cout << "Book List is Empty\n";
}
void booklist::returnbook(int bid)
{
	if (head != NULL)
	{
		booknode *current = head;
		bool found = false;
		while (current != NULL)
		{
			if (current->bid == bid)
			{
				found = true;
				if (current->status == "Issued")
				{
					fine();
					current->status = "Available";
					cout << "Book Returned Succesfully\n";
					cout << "Book Name: " << current->bname << endl;
					cout << "Book Author: " << current->bauthor << endl;
					cout << "Book ID: " << current->bid << endl;
					break;
				}
				else cout << "Cannot Return. There are no Issued Books\n";
			}
			current = current->next;
		}
		if (!found)
			cout << "Book Not Found\n";
	}
	else cout << "Book List is Empty\n";
}
void booklist::deleteSpecific(int bid)
{
	if (head != NULL)
	{
		booknode *current = head;
		booknode *previous = NULL;
		int count_node = 1;
		while (current != NULL)
		{
			if (current->bid == bid && current == head)
			{
				head = head->next;
				delete current;
				cout << "Book Deleted Succesfully\n";
				break;
			}
			else if (current->bid == bid && current == tail)
			{
				previous->next = NULL;
				tail = previous;
				delete current;
				cout << "Book Deleted succesfully\n";
				break;
			}
			else
				if (current->bid == bid)
				{
					previous->next = current->next;
					current->next = NULL;
					delete current;
					cout << "Book Deleted succesfully\n";
					break;
				}
			count_node++;
			previous = current;
			current = current->next;
		}
	}
	else cout << "Book List is Empty\n";
}

void booklist::display()
{
	if (!head)
	{
		cout << "List is empty\n";
	}
	else
	{
		int NODE = 1;
		booknode *current = head;
		while (current != NULL)
		{
			cout << "BOOK: " << NODE++ << endl;
			cout << current->bname << endl;
			cout << current->bauthor << endl;
			cout << current->bid << endl;
			cout << "----------------" << endl << endl;
			current = current->next;
		}
	}
}
void booklist::displayspecific(int bid)
{
	if (head != NULL)
	{
		booknode *current = head;
		bool found = false;
		while (current != NULL)
		{
			if (current->bid == bid)
			{
				found = true;
				cout << "Book Name: " << current->bname << endl;
				cout << "Book Author: " << current->bauthor << endl;
				cout << "Book ID: " << current->bid << endl;
				break;
			}
			current = current->next;
		}
		if (!found)
			cout << "Book Not Found\n";
	}
	else cout << "Book list Empty\n";
}




class magazinelist
{
	magazinenode *head;
	magazinenode *tail;
public:
	magazinelist();
	//~magazinelist();
	void createnode(string mname, string genre, string status);
	void issuemagazine(string mname);
	void returnmagazine(string mname);
	void displayspecific(string mname);
	void displayissued();
	void deleteSpecific(string mname);
	void display();
	string getmname(magazinenode *node)
	{
		if (node != NULL)
			return node->mname;
	}
	magazinenode *gethead()
	{
		return head;
	}
};
 magazinelist::magazinelist()
{
	head = tail = NULL;
}
void magazinelist::createnode(string mname, string genre, string status)
{
	magazinenode *temp = new magazinenode;
	temp->mname = mname;
	temp->genre = genre;
	temp->status = status;
	temp->next = NULL;
	if (head == NULL)
	{
		head = tail = temp;
		temp = NULL;
	}
	else
	{
		tail->next = temp;
		tail = temp;
		temp = NULL;
	}
}
void magazinelist::issuemagazine(string mname)
{
	if (head != NULL)
	{
		magazinenode *current = head;
		bool found = false;
		while (current != NULL)
		{
			if (current->mname == mname)
			{
				found = true;
				if (current->status == "Available")
				{
					current->status = "Issued";
					cout << "Magazine Issued Succesfully\n";
					cout << "Magazine Name: " << current->mname << endl;
					cout << "Magazine Genre: " << current->genre << endl;
					break;
				}
				else cout << "Cannot Issue Magazine. Magazine is already Issued\n";
			}
			current = current->next;
		}
		if (!found)
			cout << "Magazine Not Found\n";
	}
	else cout << "Magazine List is empty\n";
}
void magazinelist::displayissued()
{
	if (head != NULL)
	{
		magazinenode *current = head;
		bool found = false;
		int i = 1;
		while (current != NULL)
		{
			if (current->status == "Issued")
			{
				found = true;
				cout << "Magazine " << i++ << endl;
				cout << "Magazine Name: " << current->mname << endl;
				cout << "Magazine Genre: " << current->genre << endl;
			}
			current = current->next;
		}
		if (!found)
			cout << "No Issued Magazines Found\n";
	}
	else cout << "Magazines List is Empty\n";
}
void magazinelist::returnmagazine(string mname)
{
	if (head != NULL)
	{
		magazinenode *current = head;
		bool found = false;
		while (current != NULL)
		{
			if (current->mname == mname)
			{
				found = true;
				if (current->status == "Issued")
				{
					fine();
					current->status = "Available";
					cout << "Magazine Returned Succesfully\n";
					cout << "Magazine Name: " << current->mname << endl;
					cout << "Magazine Genre: " << current->genre << endl;
					break;
				}
				else cout << "Cannot Return. There are no Issued Magazines\n";
			}
			current = current->next;
		}
		if (!found)
			cout << "Magazine Not Found\n";
	}
	else cout << "Magazine List is Empty\n";
}
void magazinelist::deleteSpecific(string mname)
{
	if (head != NULL)
	{
		magazinenode *current = head;
		magazinenode *previous = NULL;
		int count_node = 1;
		while (current != NULL)
		{
			if (current->mname == mname && current == head)
			{
				head = head->next;
				delete current;
				cout << "Magazine Deleted Succesfully\n";
				break;
			}
			if (current->mname == mname && current == tail)
			{
				previous->next = NULL;
				tail = previous;
				delete current;
				cout << "Magazine Deleted succesfully\n";
				break;
			}
			else
				if (current->mname == mname)
				{
					previous->next = current->next;
					current->next = NULL;
					delete current;
					cout << "Magazine Deleted succesfully\n";
					break;
				}
			count_node++;
			previous = current;
			current = current->next;
		}
	}
	else cout << "Magazine List is Empty\n";
}

void magazinelist::display()
{
	if (!head)
	{
		cout << "List is empty\n";
	}
	else
	{
		int NODE = 1;
		magazinenode *current = head;
		while (current != NULL)
		{
			cout << "Magazine: " << NODE++ << endl;
			cout << "Magazine Name: " << current->mname << endl;
			cout << "Magazine Genre: " << current->genre << endl;
			cout << "----------------" << endl << endl;
			current = current->next;
		}
	}
}
void magazinelist::displayspecific(string mname)
{
	if (head != NULL)
	{
		magazinenode *current = head;
		bool found = false;
		while (current != NULL)
		{
			if (current->mname == mname)
			{
				found = true;
				cout << "Magazine Name: " << current->mname << endl;
				cout << "Magazine Genre: " << current->genre << endl;
				break;
			}
			current = current->next;
		}
		if (!found)
			cout << "Magazine Not Found\n";
	}
	else cout << "Magazine list Empty\n";
}
 

void fine()
{
	string issueDate, returnDate;
	string sub1, sub2, sub3, sub4, sub5, sub6;
	int k = 0;
	int l = 0;
	int m = 0;
	int n = 0;
	int p = 0;
	int q = 0;
	do
	{
		cout << "Enter Issuing Date(DD/MM/YYYY): " << endl;
		cin >> issueDate;
		cout << "Enter Returning Date(DD/MM/YYYY): " << endl;
		cin >> returnDate;
		sub1 = issueDate.substr(0, 2);             //getting date
		sub2 = returnDate.substr(0, 2);
		sub3 = issueDate.substr(3, 2);             //getting month  
		sub4 = returnDate.substr(3, 2);
		sub5 = issueDate.substr(6, 4);             //getting year
		sub6 = returnDate.substr(6, 4);

		stringstream geek(sub1);                  //converting strings into integer
		//int k = 0;
		geek >> k;
		stringstream ss(sub2);
		//int l = 0;
		ss >> l;
		stringstream ss1(sub3);
		//int m = 0;
		ss1 >> m;
		stringstream ss2(sub4);
		//int n = 0;
		ss2 >> n;
		stringstream ss3(sub5);
		//int p = 0;
		ss3 >> p;
		stringstream ss4(sub6);
		//int q = 0;
		ss4 >> q;
	} while (m > 12 || n > 12 || k > 31 || l > 31 || q < p);



	int dateSubtract, subtract1, days, subtract2;
	dateSubtract = l - k;
	subtract1 = n - m;
	int fine = 0;
	if (q == p)
	{
		if (n == m)
		{
			if (dateSubtract > 7)
			{
				fine = 10 * (dateSubtract-7);
				cout << "Fine per Day = " << 10 << endl;
				cout << "Total Fine = " << fine << endl;
			}
			else
				cout << "Total Fine = " << fine << endl;
		}
		else
		{
			days = subtract1 * 30 + dateSubtract;
			fine = (days-7) * 10;
			cout << "Fine per Day = " << 10 << endl;
			cout << "Total Fine = " << fine << endl;
		}
	}
	else
	{
		subtract2 = q - p;
		days = subtract2 * 360 + subtract1 * 30 + dateSubtract;
		fine = (days-7) * 10;
		cout << "Fine per Day = " << 10 << endl;
		cout << "Total Fine = " << fine << endl;
	}
}

class studentlist
{
	snode *head;
	snode *tail;
public:
	studentlist()
	{
		head = tail = NULL;
	}
	string getregNo(snode *node)
	{
		while (node != NULL)
			return node->regNo;
	}
	snode *gethead()
	{
		return head;
	}
	void createstudent(string sname, string regNo, int semester, int bid, string magname)
	{
		snode *temp = new snode;
		temp->sname = sname;
		temp->regNo = regNo;
		temp->semester = semester;
		temp->bid = bid;
		temp->magname = magname;
		temp->next = NULL;
		if (head == NULL)
		{
			head = tail = temp;
			temp = NULL;
		}
		else
		{
			tail->next = temp;
			tail = temp;
			temp = NULL;
		}
	}
	void displayStudent(booklist bk)
	{
		if (!head)
		{
			cout << "List is empty\n";
		}
		else
		{
			int NODE = 1;
			snode *current = head;
			while (current != NULL)
			{
				booknode *node = bk.gethead();
				while (node != NULL)
				{
					if (bk.getid(node) == current->bid)
					{
						if (node->status == "Issued")
						{
							cout << "STUDENT: " << NODE++ << endl;
							cout << "Student Name: " << current->sname << endl;
							cout << "Student Registration: " << current->regNo << endl;
							cout << "Student Semester: " << current->semester << endl;
							cout << "Book Name: " << node->bname << endl;
							cout << "Book Author: " << node->bauthor << endl;
							cout << "Book ID: " << node->bid << endl;
							cout << "----------------" << endl;
							break;
						}
					}
					node = node->next;
				}
				current = current->next;
			}
		}
	}


	void displayStudentMagazine(magazinelist m)
	{
		if (!head)
		{
			cout << "List is empty\n";
		}
		else
		{
			int NODE = 1;
			snode *current = head;
			while (current != NULL)
			{
				magazinenode *node = m.gethead();
				while (node != NULL)
				{
					if (m.getmname(node) == current->magname)
					{
						if (node->status == "Issued")
						{
							cout << "STUDENT: " << NODE++ << endl;
							cout << "Student Name: " << current->sname << endl;
							cout << "Student Registration: " << current->regNo << endl;
							cout << "Student Semester: " << current->semester << endl;
							cout << "Magazine Name: " << node->mname << endl;
							cout << "Magazine Genre: " << node->genre << endl;
							cout << "----------------" << endl;
							break;
						}
					}
					node = node->next;
				}
				current = current->next;
			}
		}
	}

	void displayspecific(string regNo, booklist bk)
	{
		if (head != NULL)
		{
			snode *current = head;
			while (current != NULL)
			{
				if (current->regNo == regNo)
				{
					booknode *node = bk.gethead();
					while (node != NULL)
					{
						if (bk.getid(node) == current->bid)
						{
							if (node->status == "Issued")
							{
								cout << "Student Name: " << current->sname << endl;
								cout << "Student Registration: " << current->regNo << endl;
								cout << "Student Semester: " << current->semester << endl;
								cout << "Book Name: " << node->bname << endl;
								cout << "Book Author: " << node->bauthor << endl;
								cout << "Book ID: " << node->bid << endl;
								cout << "----------------" << endl;
								break;
							}
						}
						node = node->next;
					}
				}
				else cout << "Student Not Found\n";
				current = current->next;
			}
		}
		else cout << "Student list Empty\n";
	}
	void deleteSpecific(string regNo)
	{
		if (head != NULL)
		{
			snode *current = head;
			snode *previous = NULL;
			int count_node = 1;
			while (current != NULL)
			{
				if (current->regNo == regNo && current == head)
				{
					head = head->next;
					delete current;
					cout << "Student Deleted Succesfully\n";
					break;
				}
				if (current->regNo == regNo && current == tail)
				{
					previous->next = NULL;
					tail = previous;
					delete current;
					cout << "Student Deleted succesfully\n";
					break;
				}
				else
					if (current->regNo == regNo)
					{
						previous->next = current->next;
						current->next = NULL;
						delete current;
						cout << "Student Deleted succesfully\n";
						break;
					}
				count_node++;
				previous = current;
				current = current->next;
			}
		}
		else cout << "Studnet List is Empty\n";
	}

};



int main()
{
	booklist book;
	magazinelist magazine;
	studentlist student;
	string a, b, nam;
	int x, y;
	char n;
	bool found = true;
	snode *node;
	do
	{
		int choice;
		cout << "\t1.  Add a Book\n";
		cout << "\t2.  Add a Magazine\n";
		cout << "\t3.  Display Students Who Issued Books\n";
		cout << "\t4.  Display Students Who Issued Magazine\n";
		cout << "\t5.  Display a Specific Student\n";
		cout << "\t6.  Display all Books\n";
		cout << "\t7.  Display a Specific Book\n";
		cout << "\t8.  Display all Magazines\n";
		cout << "\t9.  Display Specific Magazine\n";
		cout << "\t10. Issue Book\n";
		cout << "\t11. Issue Magazine\n";
		cout << "\t12. Display Issued Books\n";
		cout << "\t13. Display Issued Magazines\n";
		cout << "\t14. Return book\n";
		cout << "\t15. Return Magazine\n";
		cout << "\t16. Delete book\n";
		cout << "\t17. Delete Magazine\n";
		cout << "\t18. Delete Student\n";
		cout << "\t19. Calculate Fine\n";
		cout << "\t20. Exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Enter Book Name\n";
			cin >> a;
			cout << "Enter Author Name\n";
			cin >> b;
			cout << "Enter Book ID\n";
			cin >> x;
			book.createnode(a, b, x, "Available");
			break;
		case 2: cout << "Enter Magazine Name\n";
			cin >> a;
			cout << "Enter Genre\n";
			cin >> b;
			magazine.createnode(a, b, "Available");
			break;
		case 3: student.displayStudent(book);
			break;
		case 4: student.displayStudentMagazine(magazine);
			break;
		case 5: cout << "Enter Registration Number to Search\n";
			cin >> b;
			student.displayspecific(b,book);
			break;
		case 6: book.display();
			break;
		case 7: 
			cout << "Enter Book ID to Search\n";
			cin >> y;
			book.displayspecific(y);
			break;
		case 8: magazine.display();
			break;
		case 9: cout << "Enter Magazine Name to search\n";
			cin >> a;
			magazine.displayspecific(a);
			break;
		case 10: cout << "Enter Student Name \n";
			cin >> a;
			cout << "Enter Student Registration Number\n";
			cin >> b;
			cout << "Enter Semester\n";
			cin >> x;
			cout << "Enter Book ID to Issue\n";
			cin >> y;
			node = student.gethead();
			while (node != NULL)
			{
				if (student.getregNo(node) == b)
				{
					found = false;
					cout << "Cannot Issue. You have already issued a Magazine\n";
				}
				node = node->next;
			}
			if (found)
			{
				student.createstudent(a, b, x, y, "NULL");
				book.issuebook(y);
			} 
			break;
		case 11: cout << "Enter Student Name \n";
			cin >> a;
			cout << "Enter Student Registration Number\n";
			cin >> b;
			cout << "Enter Semester\n";
			cin >> x;
			cout << "Enter Magazine Name to Issue\n";
			cin >> nam;
			node = student.gethead();
			while (node != NULL)
			{
				if (student.getregNo(node) == b)
				{
					found = false;
					cout << "Cannot Issue. You have already issued a Book\n";
				}
				node = node->next;
			}
			if (found)
			{
				student.createstudent(a, b, x, 0,nam);
				magazine.issuemagazine(nam);
			}
			break;
		case 12: book.displayissued();
			break;
		case 13: magazine.displayissued();
			break;
		case 14: cout << "Enter Book ID to Return\n";
			cin >> y;
			book.returnbook(y);
			break;
		case 15: cout << "Enter Magazine Name to Return\n";
			cin >> a;
			magazine.returnmagazine(a);
			break;
		case 16:cout << "Enter Book ID to Delete\n";
			cin >> y;
			book.deleteSpecific(y);
			break;
		case 17: cout << "Enter Magazine Name to Delete\n";
			cin >> a;
			magazine.deleteSpecific(a);
			break;
		case 18:
			cout << "Enter Student Registration Number to Delete\n";
			cin >> b;
			student.deleteSpecific(b);
			break;
		case 19: fine();
			break;
		case 20: return 0; break;
		default: cout << "Wrong Input\n";
		}

		cout << "Do you want to continue? Press Y to continue " << endl;
		cin >> n;
		system("CLS");

	} while (n == 'y' || n == 'Y');
	return 0;
}
