#include <iostream>
#include <fstream>
#include <unordered_map>
#include <map>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_TOKENS 10000 // Maximum number of tokens to handle

// Structure to store token and frequency
struct TokenFrequency {
    string token; // The token (word) itself
    int frequency; // Frequency of the token in the text
};

// Custom comparator for sorting the TokenFrequency array
// Sort by frequency in descending order, and alphebetically in ascending order for ties
bool compareTokenFrequency(const TokenFrequency &a, const TokenFrequency &b) {
    if (a.frequency != b.frequency) {
        return a.frequency > b.frequency; // Sort by frequency descending
    }
    return a.token < b.token; // Sort alphabetically ascending
}

int main() {
    // Read input text
    string inputText; // To store each word from input
    string text[MAX_TOKENS]; // Array to store the tokens in input order
    unordered_map<string, int> token; // Unordered map to count the frequency of each token
    int textSize = 0; // Counter for the number of tokens

    // Read tokens from standard input until the end of file
    do
    {
        cin >> inputText; // Read a single token (word)
        token[inputText]++; // Increment its frequency in the unordered_map
        text[textSize] = inputText; // Store the token in the 'text' array
        textSize++; // Increment the token count
    } while (!cin.eof()); // Countinue until the endof input is reached

    // Transfer data from unordered_map to an array for sorting
    TokenFrequency sortedTokenArray[MAX_TOKENS]; // Array to store tokens and their frequencies
    int uniqueCount = 0; // Counter for unique tokens

    for (const auto &pair : token) { // Iterate over the map
        sortedTokenArray[uniqueCount] = {pair.first, pair.second}; // Store token and its frequency
        uniqueCount++; // Increment unique token count
    }

    // Sort the array by frequency (descending) and alphabetically (ascending)
    sort(sortedTokenArray, sortedTokenArray + uniqueCount, compareTokenFrequency);

    // Output the sorted tokens in order
    for (int i = 0; i < uniqueCount; ++i) {
        cout << sortedTokenArray[i].token << " ";
    }

    cout << endl;

    cout << "**********" << endl;

    // Output the encoded text using sorted token indices
    string textToIndex; // Current token from the original text
    string sortedText; // Current token from the sorted array
    for (int i = 0; i < textSize; i++){ // Iterate through original text tokens
        textToIndex = text[i]; // Get the token at position 'i'
        
        for (int j = 0; j < uniqueCount; j++){ // Iterate through sorted tokens
            sortedText = sortedTokenArray[j].token; // Get the sorted token
            
            if(sortedText == textToIndex){ // If tokens match
                cout << j + 1 << " "; // Print the sorted index (1-based)
                break; // Stop searching after finding a match
            }
        }
    }
    cout << endl;

    return 0;
}


/*
LLM Documentation
    The first main prompt I asked ChatGPT about was how I could implement an unordered_map 
    in C++. This was in the early stages of this project's development and I had no idea what 
    an unordered_map or a multimap was. I had asked Chat to explain what they were and how I 
    could use them. Chat explained unordered_maps as a container that stores key-value pairs. 
    Each key in an unordered_map are unique and when inserteing elements into an unordered_map, 
    as the name suggests, the order of how the elements are stored in an unordered_map is not 
    ordered or sorted in any way. We implemented this into the project as a way to store the words 
    of the text into it and steadily increment the frequency of the word every time it appeared in 
    the text. 
    The multimap is a container that stores key-value pairs too, but this data structure allows us 
    to sort elements. In our case, we want to sort the elements in descending order by the key. We 
    implemented this into the project to help us sort the unordered text into descending order for us 
    output the ordered text and eventually output the indeces of the sorted elements in correlation to 
    the original text. 

    Another prompt I have asked Chat was how to iterate over unordered_maps and multimaps. At first, 
    I assumed that iterating over these maps would be similar to iterating over arrays and vectors. I 
    was quickly proven wrong after implementing it as such and eventually turned to Chat to help me. Chat 
    had sugested me to use a special for loop called a range-based for loop to iterate over the maps to 
    not only output the elements in the maps, but also iterating through them to transfer the data from 
    the unordered_map to the multimap. These concepts were implemented into this project and used to help 
    input and sort the input texts. 

Debugging and Testing
    To test the code, I would output the key-value pairs to check if I had inputed all of the texts correctly 
    and check their frequencies too. After confirming that all of the inputs are dealt with correctly, I would 
    output all of the key-value pairs in the multimap to confirm if they were sorted properly. This is where I 
    found our main issue. After that, I would output the indeces of the sorted elements and this is where I 
    found the second issue, which ultimately revolved around the first issue. 

    There were problems with the indeces of the sorted elements with outputing the indeces. In some cases the 
    indeces were off by one, but there were the occasional off by two which confused me. If the multimap was 
    sorted and all the elements were in order, then there shouldn't be cases of indeces being off by two and only 
    should have been off by one. This is when I found out that the multimap was not fully sorted. After sorting 
    the elements by their keys', the keys with the same frequency were then needed to be further sorted 
    alphabetically and that was not the case causing off by two indeces when debugging. After implementing a custom 
    comparison for sorting, the indeces then were only off by one and a simple add one to the index before outputting 
    would fix the problem. 

    To verify all of the outputs of the program were correct, I compared it to the outputs given on canvas and used 
    the comparison tool on VS Code to compare outputs. The comparison tool on VS Code proved to be useful in this 
    project as it helped point out the index errors and helped me figure out what was wrong with the sorting 
    implementation. I tested with all three inputs and outputs on canvas to be sure that it worked for all inputs and 
    showed correct outputs with the correspnding inputs.


*/