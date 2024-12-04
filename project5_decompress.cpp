#include <iostream>
#include <fstream>
#include <unordered_map>
#include <map>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

// Here is the code that accepts the output files as the input
// #define MAX_TOKENS 10000 // Maximum number of tokens to handle
// #define MAX_INDICES 10000 // Maximum number of tokens to handle

// int main() {
//     // cout << "Start Main" << endl;

//     string inputText;
//     string token[MAX_TOKENS];
//     int indexes[MAX_INDICES];
//     int textSize = 0;
//     int indexSize = 0;

//     // Read tokens from standard input until the end of file
//     do
//     {
//         cin >> inputText; // Read a single token (word)
//         // cout << "input " << inputText << endl;

//         if (inputText == "**********"){
//             //cout << "If entered if **********" << endl;
//             do
//             {
//                 cin >> inputText;
//                 // cout << "Input num " << inputText;

//                 int num = std::stoi(inputText);
//                 indexes[indexSize] = num;
//                 indexSize++;
//             } while (!cin.eof());

//             break;
//         }

//         if (inputText != "\""){
//             token[textSize] = inputText; // Store the token in the array
//             textSize++; // Increment the token count
//         }
        
//     } while (!cin.eof()); // Countinue until the endof input is reached

//     // Output the original text
//     for (int i = 0; i < indexSize; i++){
//         if (i < indexSize - 1){
//             cout << token[indexes[i] - 1] << " ";
//         }
//         else{
//             cout << token[indexes[i] - 1];
//         }
        
//     }
//     cout << endl;

//     return 0;
// }


// Here is the code that reads in the input and outputs the text
int main(){
    string input;
    
    do
    {
        cin >> input;
        cout << input << " ";
    } while (!cin.eof());
    
    return 0;
}