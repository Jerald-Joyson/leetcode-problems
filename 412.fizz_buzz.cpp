/* Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz",
"Buzz","11","Fizz","13","14","FizzBuzz"] */

#include <iostream>
using namespace std;

char** FizzBuzz(int n){}

int main(){
	int n;
	cin >> n;	

	char** arr = FizzBuzz(n);
	
	for(int i = 0; i < n; i++){
		cout << arr[i] << endl;
	}
	
	return 0;
}
