#include <iostream>
#include <fstream>
#include <string>
using namespace std;







int main() {
    string search_sequence;
    ifstream file("Pi-10.txt"); 
    string pi;

    if (file.is_open()) {
        getline(file, pi, '\0');
        file.close();
    }
    else {
        std::cerr << "Unable to open file!" << std::endl;
        return 1;
    }

    cout << "What sequence do you want to search for? " << endl;
        cin >> search_sequence;

        //My birthday is 072403, found at 758052
       
  
    size_t position = pi.find(search_sequence);

    if (position != string::npos) {
         
        cout << "Sequence " << search_sequence << " found at position: " << position << endl;
    }
    else {
      
       cout << "Sequence " << search_sequence << " not found in π." << endl;
    }

   

    

    return 0;
}
