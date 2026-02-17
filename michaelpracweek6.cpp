#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    srand(time(0));
    

    int numbers[20];
    int oddArray[20];
    int evenArray[20];
    int oddCount = 0;
    int evenCount = 0;
    

    cout << "Original Array (20 integers between 1 and 100):" << endl;
    for (int i = 0; i < 20; i++) {
        numbers[i] = (rand() % 100) + 1; 
        cout << numbers[i] << " ";
    }
    cout << endl << endl;
    

    for (int i = 0; i < 20; i++) {
        if (numbers[i] % 2 == 0) {
            evenArray[evenCount] = numbers[i];
            evenCount++;
        }
        else {
            oddArray[oddCount] = numbers[i];
            oddCount++;
        }
    }
    
    
    cout << "Odd Numbers (" << oddCount << " elements):" << endl;
    for (int i = 0; i < oddCount; i++) {
        cout << oddArray[i] << " ";
    }
    cout << endl << endl;
    
    
    cout << "Even Numbers (" << evenCount << " elements):" << endl;
    for (int i = 0; i < evenCount; i++) {
        cout << evenArray[i] << " ";
    }
    cout << endl;
    
    return 0;
}