#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
using namespace std::chrono;
using namespace std;




class BloomFilter {
private:
	
	vector<bool> usernames;

public:
	int hashFunction1(string name);
	int hashFunction2(string name);
	
	bool nameCheck(string name);
	void setSize(int users); 
	void addName(string name);
	bool validName(string name);
		

};


bool BloomFilter::validName(string name) {

	for (int i = 0; i < name.size(); i++)
		if (name[i] == ' ') {
			return true;
		}
		else if (!(name[i] >= '0' && name[i] <= '9') && !(name[i] >= 'A' && name[i] <= 'Z') && !(name[i] >= 'a' && name[i] <= 'z' )) {
			return true;

		}
	return false;

}
void BloomFilter::setSize(int users)
{
	 usernames.resize(users, false);
}


int BloomFilter::hashFunction1(string name) {
	int hash = 0;
	for (int i = 0; i < name.size(); i++)
	{
		hash = (hash * 31 + name[i]) % 1000;
	}
	return hash;
}

int BloomFilter::hashFunction2(string name) {
	int hash = 0;
	for (int i = 0; i < name.size(); i++)
	{
		hash = (hash * 37 + name[i]) % 1000;
	}
	return hash;
}

	void BloomFilter::addName(string name) {
		int x = hashFunction1(name);
		int y = hashFunction2(name);
		usernames[x] = true;
		usernames[y] = true;
	}

	bool BloomFilter::nameCheck(string name) {
		int x = hashFunction1(name);
		int y = hashFunction2(name);
		if (usernames[x] && usernames[y]) {
			cout << "Username "<< name << " may exist" << endl;
			return true;
		}
		else {
			cout << "Username " << name << " definitely does not exist" << endl;
			return false;
		}
		
	}


	int main() {

		BloomFilter bf;

		bf.setSize(1000);
		vector<string> list;


		ifstream inputFile("people-10000.csv");
		if (!inputFile.is_open()) {
			cerr << "Error: Unable to open file!" << endl;
			return 1;
		}
		string username;
		while (getline(inputFile, username)) {
			bf.addName(username);
			list.push_back(username);
		}

		inputFile.close();

		string name;

		bool validInput = true;
		do {
			validInput = true;
			cout << "What username would you like to enter? ";
			cin >> name;
			if (name.size() > 15 || name.size() < 2)
			{
				cout << "Username size is improper length. Try again: ";
				validInput = false;
			}

			else if (bf.validName(name))
			{
				cout << "Username contains an invalid character. Try again: ";
				validInput = false;

			}

			else if (bf.nameCheck(name))
			{
				cout << "Username is taken. Please try again: ";
				validInput = false;
			}
		} while (validInput == false);


		bf.addName(name);
		cout << "Name has been added successfully " << endl;

		//Random Search for 100 names using BloomFilter

		auto s1 = high_resolution_clock::now();

		bf.nameCheck("Steven");
		bf.nameCheck("Emily");
		bf.nameCheck("Michael");
		bf.nameCheck("Sarah");
		bf.nameCheck("Joshua");
		bf.nameCheck("Jessica");
		bf.nameCheck("David");
		bf.nameCheck("Ashley");
		bf.nameCheck("Daniel");
		bf.nameCheck("Amanda");
		bf.nameCheck("Matthew");
		bf.nameCheck("Megan");
		bf.nameCheck("Andrew");
		bf.nameCheck("Rachel");
		bf.nameCheck("Christopher");
		bf.nameCheck("Lauren");
		bf.nameCheck("Joseph");
		bf.nameCheck("Samantha");
		bf.nameCheck("Ryan");
		bf.nameCheck("Hannah");
		bf.nameCheck("Nicholas");
		bf.nameCheck("Olivia");
		bf.nameCheck("John");
		bf.nameCheck("Sophia");
		bf.nameCheck("James");
		bf.nameCheck("Ava");
		bf.nameCheck("Justin");
		bf.nameCheck("Isabella");
		bf.nameCheck("Brandon");
		bf.nameCheck("Mia");
		bf.nameCheck("Alexander");
		bf.nameCheck("Abigail");
		bf.nameCheck("Tyler");
		bf.nameCheck("Madison");
		bf.nameCheck("Jonathan");
		bf.nameCheck("Chloe");
		bf.nameCheck("Benjamin");
		bf.nameCheck("Ella");
		bf.nameCheck("Christian");
		bf.nameCheck("Grace");
		bf.nameCheck("Austin");
		bf.nameCheck("Lily");
		bf.nameCheck("Samuel");
		bf.nameCheck("Victoria");
		bf.nameCheck("Zachary");
		bf.nameCheck("Sofia");
		bf.nameCheck("Jacob");
		bf.nameCheck("Amelia");
		bf.nameCheck("Kyle");
		bf.nameCheck("Evelyn");
		bf.nameCheck("Aaron");
		bf.nameCheck("Aria");
		bf.nameCheck("Kevin");
		bf.nameCheck("Scarlett");
		bf.nameCheck("Thomas");
		bf.nameCheck("Elizabeth");
		bf.nameCheck("Brian");
		bf.nameCheck("Penelope");
		bf.nameCheck("Jason");
		bf.nameCheck("Aurora");
		bf.nameCheck("Nathan");
		bf.nameCheck("Lillian");
		bf.nameCheck("Eric");
		bf.nameCheck("Layla");
		bf.nameCheck("Adam");
		bf.nameCheck("Zoey");
		bf.nameCheck("Sean");
		bf.nameCheck("Nora");
		bf.nameCheck("Ethan");
		bf.nameCheck("Ellie");
		bf.nameCheck("Mark");
		bf.nameCheck("Hazel");
		bf.nameCheck("Cameron");
		bf.nameCheck("Paisley");
		bf.nameCheck("Patrick");
		bf.nameCheck("Audrey");
		bf.nameCheck("Logan");
		bf.nameCheck("Claire");
		bf.nameCheck("Jordan");
		bf.nameCheck("Skylar");
		bf.nameCheck("Anthony");
		bf.nameCheck("Violet");
		bf.nameCheck("Dylan");
		bf.nameCheck("Stella");
		bf.nameCheck("Gabriel");
		bf.nameCheck("Addison");
		bf.nameCheck("Isaac");
		bf.nameCheck("Lucy");
		bf.nameCheck("William");
		bf.nameCheck("Ruby");
		bf.nameCheck("Noah");
		bf.nameCheck("Savannah");bf.nameCheck("Luke");bf.nameCheck("Aubrey");bf.nameCheck("Henry");bf.nameCheck("Bella");bf.nameCheck("Jack");bf.nameCheck("Eva");bf.nameCheck("Lucas");bf.nameCheck("Natalie");bf.nameCheck("Owen");bf.nameCheck("Brooklyn");


		auto e1 = high_resolution_clock::now();
		auto d1 = duration_cast <milliseconds>(e1 - s1);
		cout << "Randomized name search using Bloom Filter: " << d1.count() << "ms" << endl;

		//Linear Search for 100 names
		auto s2 = high_resolution_clock::now();

		vector<string> nameList = { "Steven", "Alice", "John", "Emma", "Chris", "Jessica", "Daniel", "Sarah", "Matthew", "Sophia",
	"David", "Olivia", "Michael", "Ava", "James", "Isabella", "Robert", "Mia", "Joseph", "Amelia",
	"Thomas", "Charlotte", "William", "Harper", "Charles", "Evelyn", "George", "Abigail", "Henry", "Emily",
	"Edward", "Elizabeth", "Andrew", "Scarlett", "Peter", "Victoria", "Patrick", "Chloe", "Kevin", "Grace",
	"Samuel", "Lily", "Mark", "Hannah", "Paul", "Ella", "Donald", "Zoe", "Brian", "Natalie",
	"Jason", "Leah", "Anthony", "Penelope", "Scott", "Lillian", "Justin", "Aria", "Kyle", "Madison",
	"Brandon", "Eleanor", "Jeffrey", "Ellie", "Eric", "Stella", "Jacob", "Nora", "Nicholas", "Camila",
	"Gregory", "Layla", "Ryan", "Riley", "Benjamin", "Aubrey", "Nathan", "Zoey", "Jonathan", "Hazel",
	"Aaron", "Violet", "Adam", "Aurora", "Frank", "Savannah", "Patrick", "Bella", "Jack", "Lucy",
	"Arthur", "Paisley", "Sean", "Anna", "Jeremy", "Claire", "Christian", "Skylar", "Ethan", "Sadie" };
		for (int j = 0; j < nameList.size(); j++)
		{
			bool found = false;
			for (int i = 0; i < list.size(); i++)
			{
				if (list[i] == nameList[j]) {
					cout << nameList[j] << " has been found at position " << i << endl;
					found = true;

					break;
				}
			}
			if (!found) {
				cout << "Username " << nameList[j] << " does not exist" << endl;
			}
		}

		auto e2 = high_resolution_clock::now();
		auto d2 = duration_cast <milliseconds>(e2 - s2);
		cout << "Linear search programming time: " << d2.count() << "ms" << endl;




		return 0;
	}