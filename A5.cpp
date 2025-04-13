#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <filesystem>

using namespace std;
using namespace::chrono;



class Node {
public:
	long int data;
	Node* prev;
	Node(int n) {
		data = n;
		prev = NULL;
	}

};
void multiply(Node* tail, int n) {
	Node* temp = tail;
	Node* prevNode = tail;
	int carry = 0;

	while (temp != NULL) {
		long int data = temp->data * n + carry;
		if (data < 0) {
			cout << "Number is too big";
			exit(1);
		}
		temp->data = data % 10;
		carry = data / 10;
		prevNode = temp;
		temp = temp->prev;
	}
	while (carry != 0) {
		prevNode->prev = new Node((int)(carry % 10));
		carry /= 10;
		prevNode = prevNode->prev;
	}
}

void print(Node* tail, vector<int>&results) {
	if (tail == NULL)
	{
		return;
	}
	print(tail->prev, results);
	cout << tail->data;
	results.push_back(tail->data);
}

int main() {
	

	int n = 0;//default value
	int m = 0;//default value
	vector<int> results;//default vector
	cout << "What base would you like to use? ";
	cin >> n;

	//input validation
	while (n < 0 || n >10000) {
		cout << "Please input a valid base: " << endl;
		cin >> n;
	}

	cout << endl << "What exponent would you like to use? ";
	cin >> m;

	//input validation

	while (m < 0 || m > 999) {
		cout << "Please input a valid exponent: " << endl;
		cin >> m;
	}
	Node tail(1);



	auto s1 = high_resolution_clock::now();

	for (int i = 1; i <= m; i++) {
		multiply(&tail, n);
	}
	print(&tail, results);


	auto e1 = high_resolution_clock::now();
	auto d1 = duration_cast <milliseconds>(e1 - s1);
	
	cout << endl << "Exponentiation programming time: " << d1.count() << "ms" << endl;
	
	string filePath = "Results.txt";

	ofstream outfile(filePath);

	if (!outfile.is_open()) {
		exit(EXIT_FAILURE);
	}
	for (size_t i = 0; i < results.size(); i++) { 
		outfile << results[i]; 
	}
	outfile.close();

	return 0;
}


