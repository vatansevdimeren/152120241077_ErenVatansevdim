#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
int customer_counter = 0;
//in this Project I am gonna design a program which is calculate credit note and the bank will user Credit volume.
using namespace std;
class Human {
private :
	string Name;
	long long int Tc;
	int age;
	bool gender;//true men ---->false women //I dont wanna judge by the people who judge me for by naming bool variable....
	string profession;
	double salary;
	double credit_note;
	bool Active;
public :
	Human(string Name, long long int Tc, int age, bool gender, string profession, double salary, double credit_note, bool active) {
		this->Name = Name;
		this->Tc = Tc;
		this->age = age;
		this->gender = gender;
		this->profession = profession;
		this->profession = profession;
		this->salary = salary;
		this->credit_note = credit_note;
		this->Active = active;
	}
	//get functions
	string getName() {
		return Name;
	}
	long long int getTc() {
		return Tc;
	}
	int getAge() {
		return age;
	}
	bool getGender() {
		return gender;
	}
	string getProfession() {
		return profession;
	}
	double getSalary() {
		return salary;
	}
	double getCredit_note() {
		return credit_note;
	}
	bool getActive() {
		return Active;
	}
	
	//set functions.
	void setName(string Name) {
		this->Name = Name;
	}
	void setTc(long long int Tc) {
		this->Tc = Tc;
	}
	void setAge(int age) {
		this->age = age;
	}
	void setGender(bool gender) {
		this->gender = gender;
	}
	void setProfession(string profession) {
		this->profession = profession;
	}
	void setSalary(double salary) {
		this->salary = salary;
	}
	void setCredit_note(double credit_note) {
		this->credit_note = credit_note;
	}
	void setActive(bool active) {
		this->Active = active;
	}
};
//Functions

int Fmenü();
void Customercreater(vector<Human>& customer);
double CreditNoteCalculator(vector<Human>& customer);
void LoadData(vector<Human>&customer);
void InformationDesigner(vector<Human>& customer);
void Leaderboard(vector<Human>& customer);
void CustomerRemover(vector<Human>& customer);
void TestBotCustomers(vector<Human>& customer);

int main() {
	vector<Human> customer;
	LoadData(customer);
	//I dont recommend you to use this function before you use please check your rams :D
	//TestBotCustomers(customer);
	while (1) {
		int user_choice_in_main = Fmenü();
		
		switch (user_choice_in_main) {
			case 0:
				cout << "Thank you for chosing us " << endl;
				return 0;
			case 1:
				Customercreater(customer);
				break;
			case 2:
				CreditNoteCalculator(customer);
				break;
			case 3:
				InformationDesigner(customer);
				break;
			case 4:
				Leaderboard(customer);
				break;
			case 5:
				CustomerRemover(customer);
				break;
		}
	}

	return 0;
}
void LoadData(vector<Human>& customer) {
	//I am loading all values from ssd to ram
	ifstream read("data.txt");
	if (bool(read) == 0) {
		cout << "The data file did NOT riddden!" << endl;
		return;
	}
	else {
		string temp_name;
		long long int temp_tc;
		int temp_age;
		bool temp_gender;
		string temp_profession;
		double temp_salary;
		double temp_credit_note;
		bool Activite;
		char virgülReader;
		bool temp_person;
		
		while (getline(read, temp_name, ',')) {
			read >> temp_tc >> virgülReader;
			read >> temp_age >> virgülReader;
			read >> temp_gender >> virgülReader;
			
			getline(read, temp_profession, ',');

			read >> temp_salary >> virgülReader;
			read >> temp_credit_note >> virgülReader;
			read >> temp_person;
			
			read.ignore();
			
			Human temp(temp_name, temp_tc, temp_age, temp_gender, temp_profession,temp_salary,temp_credit_note,temp_person);
			
			customer.push_back(temp);
		}
		read.close();
	}
}
int Fmenü() {
	int user_choice = 0;
	cout << "<-----Welcome to Bank of Eren----->" << endl;
	cout << "<---To add new user press 1--->" << endl;
	cout << "<---To learn credit note press 2--->" << endl;
	cout << "<---To design user information press 3--->" << endl;
	cout << "<---To see leaderboard of the credit notes of Eren's bank press 4--->" << endl;
	cout << "<---To remove any person press 5--->" << endl;
	cout << "<---To quit press 0--->" << endl;
	cout << "Please choose one of them :";
	cin >> user_choice;
	
	if (user_choice < 0 || user_choice > 5) {
		cout << "Please enter available number!!!" << endl;
		return Fmenü();
	}
	else {
		cin.ignore();
		return user_choice;
	}
}
void Customercreater(vector<Human>& customer) {
	if (customer_counter != 0) {
		customer_counter = customer.size();
	}
	cout << "*****WELCOME TO BANK OF EREN*****" << endl;
	int gender_temp;
	string n, p;//these chars is named by its orginal string's letter.
	int a;
	long long int t;
	bool g;
	double s, c;
	
	cout << "Please enter your FULL name :";
	getline(cin, n);

	cout << "Please enter Tc :";
	cin >> t;
	// we need to search all members who have if they input same tc

	for (int i = 0; customer.size() > i; i++) {
		if (customer[i].getTc() == t) {
			cout << "The acount has been applied in our system." << endl;
			cout << "Please enter with original acount !" << endl;
			return Customercreater(customer);
		}
	}

	cout << "Please enter your age :";
	cin >> a;
	if (a < 0 || a > 170) {
		cout << "you're a son of a bitch...." << endl;
		return Customercreater(customer);
	}

	cout << "Please enter your gender (woman 0),man(1)";
	cin >> gender_temp;
	if (gender_temp == 0 || gender_temp == 1) {
		if (gender_temp == 0) g = false;
		else g = true;
	}
	else {
		cout << "Please enter available gender !!!" << endl;
		return Customercreater(customer);
	}
	
	cout << "Please enter your profession :";
	cin >> p;

	cout << "Please enter How much money do you earn in a month :";
	cin >> s;
	
	cout << "It is a protocol that you need to calculate your credit score when you currently create a new acount." << endl;
	
	c = CreditNoteCalculator(customer);
	//Here I did something that the part of codes is a little bit complex but you can understand
	//because the person who is creted right now can't have credit note if has any referance 
	//in that I dont think I dont know what to do....

	Human Newcustomer(n, t, a, g, p, s, c,true);
	customer.push_back(Newcustomer);
	
	//by putting CreditNoteCalculater here I Calculated its credit note while S/he create a new acount.
	
	//Here I used real time to add the person who has just entered our system 
	//and you can analzye acounts by using log system because it keeps all variables in just one file with time when the acount is created.

	time_t current_time = time(0);
	char time_buffer[30];
	ctime_s(time_buffer, sizeof(time_buffer), &current_time);
	bool activiteState =true;

	ofstream log("log.txt",ios ::app);
	if (bool(log) == false) {
		cout << "The log file can't be oppened! something has gone wrong." << endl;
		return;
		//I dont know What to do in case the file do not open....
	}
	else {
		log << "<-------------------------------------------------------------->" << endl; 
		log << customer_counter << ". USER " << time_buffer << " IS CRETED THAT TIME" << endl;
		log << "Name :" << n<< endl;
		log << "TC :" <<t << endl;
		log << "Age :" << a << endl;
		log << "Gender :" << g<< endl;
		log << "Profession :" << p << endl;
		log << "Salary :" << s<< endl;
		log << "Credit note :" << c << endl;
		log << "Activate state :" << activiteState << endl;
		log.close();
	}
	ofstream data("data.txt",ios ::app);
	if (bool(data) == false) {
		cout << "The data file did NOT oppened!" << endl;
		return;
	}
	else {
		//name /Tc /salary /Credit note
		data << n << "," << t << "," << a << "," << g << "," << p << "," << s << "," << c << "," << activiteState << endl;
		data.close();
	}
}
double CreditNoteCalculator(vector<Human>& customer) {
	long long int Tc_temp;
	int index=-1;
	double CreditScore=0;
	
	
	cout << "Please enter  the number of TC whoose credit note you want to learn :";
	cin >> Tc_temp;
	
	for (int i = 0; customer.size() > i; i++) {
		if (Tc_temp == customer[i].getTc()) {
			index = i;
			break;
		}
	}
	
	if (index == -1) {
		cout << "The acount can't be found please firstly create an acount!" << endl;
		return 0;
	}
	if (customer[index].getActive() == false) {
		cout << "The user has already deleted in our datas" << endl;
		return 0;
	}

	if (customer[index].getAge() > 18 && customer[index].getAge() < 25) {
		CreditScore += 50;
	}
	else if (customer[index].getAge() > 25 && customer[index].getAge() < 50) {
		CreditScore += 200;
	}
	else if (customer[index].getAge() < 18 || customer[index].getAge() > 50) {
		CreditScore += 50;
	}
	
	if (customer[index].getProfession() == "Lawyer" || customer[index].getProfession() == "Doctor" || customer[index].getProfession() == "Dentist" ||
		customer[index].getProfession() == "Engineer" || customer[index].getProfession() == "Pilot" || customer[index].getProfession() == "Writer"){
		CreditScore += 300;
	}
	else {
		CreditScore += 100;
	}

	if (customer[index].getGender() == false) {
		CreditScore += 50;
	}
	else if (customer[index].getGender() == true) {
		CreditScore += 100;
	}
	CreditScore += customer[index].getSalary() * 0.4;
	
	cout << "Your total credit score is :" << CreditScore << endl;

	if (CreditScore < 5000) {
		cout << "We cannot give you any credit!" << endl;
		customer[index].setCredit_note(0);
	}
	else if (CreditScore > 5000 && CreditScore < 15000) {
		cout << "We can give you Credit about 100.000$-250.000$" << endl;
		double money=0;
		cout << "Please enter How much money you want :";
		cin >> money;
		if (money < 0 || money > 250000) {
			cout << "orospu cocougu" << endl;
			return 0;
		}
		customer[index].setCredit_note(money);
		return money;
	}
	else if (CreditScore > 15000 && CreditScore < 30000){
		cout << "We can give you 500.000$-2.500.000$" << endl;
		cout << "Please enter How much money you want :";
		double money = 0;
		cin >> money;
		if (money < 0 || money > 25000000) {
			cout << "Orospu cocopgu" << endl;
			return 0;
		}
		customer[index].setCredit_note(money);
		return money;
	}
	else if (CreditScore > 30000) {
		cout << "You are the speacial one in our bank so you can get whatever you want :D" << endl;
		cout << "Please enter How much money you want you can enter maximum the total volume of the bank dude! ";
		double money;
		cin >> money;
		//if e gerek mi var amınakoyim
		customer[index].setCredit_note(money);
		return money;
	}
}
void InformationDesigner(vector<Human>& customer) {
	int user_choice = -1;
	int temp_index_keeper = -1;
	long long int temp_tc;
	cout << "Please enter user's Tc :";
	cin >> temp_tc;
	for (int i = 0; customer.size() > i; i++) {
		if (customer[i].getTc() == temp_tc) {
			temp_index_keeper = i;
			break;
		}
	}
	if (temp_index_keeper == -1) {
		cout << "That user cannot be found Please firstly create an acount!" << endl;
		return;
	}
	
	cout << "---------------------------------------" << endl;
	cout << "TO DESIGN NAME PRESS 1" << endl;
	cout << "TO DESIGN NUMBER OF TC PRESS 2" << endl;
	cout << "TO DESIGN AGE PRESS 3" << endl;
	cout << "TO DESIGN GENDER PRESS 4" << endl;
	cout << "TO DESIGN PROFESSION PRESS 5" << endl;
	cout << "TO DESIGN SALARY PRESS 6" << endl;
	cout << "TO QUIT PRESS 0" << endl;
	cout << "YOU CAN'T DESIGN YOUR CREDIT NOTE!" << endl;
	cout << "Please choose one of them :";
	cin >> user_choice;

	if (user_choice < 0 || user_choice > 6) {
		cout << "Please enter available number!" << endl;
		return InformationDesigner(customer);
	}
	
	while (true) {
		switch (user_choice) {
			case 0: 
				return;
				break;//it doesnt work
			case 1:
				{
				cout << "Please enter new name :";
				string name;
				cin.ignore();
				getline(cin, name);
				customer[temp_index_keeper].setName(name);
				}
				return;
				break;
			case 2:
				{
				cout << "Please enter New Tc :";//how can it possiblle I dont understand but I put a command here :)
				long long int tc;
				cin >> tc;
				customer[temp_index_keeper].setTc(tc);
				}
				return;
				break;
			case 3:
				cout << "Please enter New age :";
				int age;
				cin >> age;
				if (age < 0 || age > 170) {
					return;
				}
				user_choice = -1;
				customer[temp_index_keeper].setAge(age);
				return;
				break;
			case 4:
				{
				cout << "Please enter New gender man (1) ,woman(0):" << endl;
				int number = 0;
				cin >> number;
				if (number != 0 && number != 1) {
					cout << " ben sana ne diyeyim ki...." << endl;
					return;
				}
				bool temp;
				if (number == 0) {
					temp = false;
				}
				else if (number == 1) {
					temp = true;
				}
				customer[temp_index_keeper].setGender(temp);
				}
				return;
				break;
			case 5:
				{
				cout << "Please enter your New Profession :";
				string New_profession;
				cin.ignore();
				getline(cin, New_profession);
				customer[temp_index_keeper].setProfession(New_profession);
				}
				return;
				break;
			case 6:
				{
				cout << "Please enter your New Salary :";
				double new_salary;
				cin >> new_salary;
				if (new_salary < 0) {
					return;
				}
				customer[temp_index_keeper].setSalary(new_salary);
				}
				return;
				break;
		}
	}
}
void Leaderboard(vector<Human>& customer) {
	//I am gonna enlist all customers by using buble sort algorithm
	vector<Human> temp_customer;
	for (int i = 0; customer.size() > i; i++) {
		temp_customer.push_back(customer[i]);
	}
	for (int i = 0; temp_customer.size()-1 > i; i++) {
		for (int j = 0; temp_customer.size() - i - 1>j;j++) {
			if (temp_customer[j].getCredit_note() < temp_customer[j + 1].getCredit_note()) {
				Human temp=temp_customer[j];
				temp_customer[j] = temp_customer[j + 1];
				temp_customer[j + 1] = temp;
			}
		}
	}
	cout << "******************************************" << endl;
	for (int i = 0; temp_customer.size()-1 > i; i++) {
		cout << i + 1 << " | " << temp_customer[i].getName() << " Credit Score :" << temp_customer[i].getCredit_note() << endl;
	}
	cout << "The highest person's name is " << temp_customer[0].getName() << " and we are thank Him/her for chosing us." << endl;
	cout << "******************************************" << endl;
}
void CustomerRemover(vector<Human>& customer) {
	long long int Tc;
	int index_keeper=-1;
	cout << "Please enter Tc of person whoose you want to remove :";
	cin >> Tc;
	int deneme_counter = 0;
	if (deneme_counter > 3) {
		return;
	}
	bool flag = false;
	for (int i = 0; customer.size() > i; i++) {
		if (customer[i].getTc() == Tc) {
			flag = true;
			index_keeper = i;
			break;
		}
	}
	if (index_keeper < 0) {
		return;
	}
	if (flag == false) {
		cout << "Probably You entered Wrong Tc adress Please try again!" << endl;
		deneme_counter++;
		return CustomerRemover(customer);
	}
	
	cout << "Are you sure to delete that acount? if you decided to delete Please enter (yes)";
	string controller_temp;
	bool controller_temp_boolen=false;
	cin >> controller_temp;
	if (controller_temp == "Yes" || controller_temp == "YES" || controller_temp == "yes") {
		controller_temp_boolen = true;
	}
	if (controller_temp_boolen == true) {
		customer[index_keeper].setActive(false);
	}
	else if (controller_temp_boolen == false) {
		cout << "The Tc adress did not match any person in our bank!" << endl;
		return;
	}
}
void TestBotCustomers(vector<Human>& customer) {
	for (int i = 0; 5000000 > i; i++) {
		string temp_name = "Tester_"+to_string(i);
		long long int tempTc = 100000000;
		Human Temp(temp_name,tempTc,20,true,"Tester",3000,double ((3/7)*i),true);
		customer.push_back(Temp);
	}
}