
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void NaiveSurvival(int n) {
	for (int i = 0; i < n; i++)
	{
		srand(std::time(0));
		int k;
		int n;
		int x;
		int y = 0;
		int z = 0;
		int r = 0;


		n = rand() % 951 + 50;
		k = rand() % 9 + 2;
		x = rand() % n + 1

			cout << "The number of your people is: " << n << endl;
		cout << "We are eliminating every " << k << "th person." << endl;


		//cout << "Please pick a position between 1 and " << n << endl;
		//cin >> x;
		//while (x < 1 || x > n) {
		//	cout << "Please enter a number in the range : " << endl;
		//	cin >> x;
		//}


		for (int i = 0; i < 25; i++)
		{
			for (int i = 1; i <= n / k; i++) {

				/*if (r == 0)
				{
					r = k;
				}*/
				y = r + k * i;
				if (x == y) {
					cout << "You have died!" << endl;
					return 0;
				}
				if (x > n)
				{
					x = x - n;
				}

			}
			if (r > 0)
			{

				x = x - (x + r) / k;

			}
			else
			{
				x = x - x / k;
			}
			/*if (x < n && x / k != (x + r) / k)
			{
				x++;
			}*/
			//cout << endl << y << endl;

			if (n % k == 0)
			{
				z = 0;
				r = 0;
			}
			else
			{
				z = n - y;
				r = k - z;
			}
			y = 0;
			n = n - n / k;

			cout << "The number of people remaining is: " << n << endl;
			cout << "Your position is: " << x << endl;
			cout << "We are eliminating every " << k << "th  person." << endl;
			cout << "We are starting at the " << r << "th person" << endl;
			cout << endl << endl;
			//cout << endl << z;
			//cout << endl << r << endl;
			if (x == r)
			{
				cout << "You are eliminated!";
				return 0;

			}
			if ((n / k) * k + r > n)
			{
				r = r - k;
			}
		}
		cout << "You survived!!" << endl;
	}
}







void OptimizedSurvival(int n) {
	for (int i = 0; i < n; i++)
	{
		int n, k, position;
		n = rand() % 951 + 50;
		k = rand() % 9 + 2;
		position = rand() % n + 1;



		int zero_based_position = position - 1;

		int survivor = josephus(n, k);

		if (zero_based_position == survivor) {
			std::cout << "Congratulations! You survive.\n";
		}
		else {
			std::cout << "Sorry, you do not survive.\n";
		}
	}
}



int josephus(int n, int k) {
	if (n == 1) {
		return 0;
	}
	return (josephus(n - 1, k) + k) % n;
}



int main() {


	int n = 5;
	auto s1 = high_resolution_clock::now();

	cout << NaiveSurvival(n) << endl;
	auto e1 = high_resolution_clock::now();
	auto d1 = duration_cast <microseconds>(e1 - s1);
	cout << "Naive Survival programming time: " << d1.count() << "us" << endl;



	auto s2 = high_resolution_clock::now();

	cout << OptimizedSurvival(n) << endl;
	auto e2 = high_resolution_clock::now();
	auto d2 = duration_cast <microseconds>(e2 - s2);
	cout << "Optimized Survival programming time: " << d2.count() << "us" << endl;




	return 0;
}
