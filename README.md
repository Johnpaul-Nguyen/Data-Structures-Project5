Encoding is a process of converting data from one form to another. Encoding in
many cases reduces the number of bits required to store the original file, in which case it is called
compression. In this project, the goal is to encode a text file and replace
each word with a number. 

The goal of this project is to get all tokens from an input file and then count the number of times each
token occurs. For example, in the above text, the token “the” occurs 4 times. Once I have the
tokens and their frequencies, I then need to sort the tokens in the decreasing order of their frequencies.
I then output, all the unique tokens, separated by a space, followed by a number of integers again
separated by a space that represents the position of each token in the text in the sorted set. For
example, if the word “the” is the second token (in the index position 1) in the sorted set of tokens,
I will replace the token “the” in the text with the number 1, and so on.
