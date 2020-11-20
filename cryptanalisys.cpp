//In cryptanalysis, words patterns can be a useful tool in cracking simple ciphers.
//
//A word pattern is a description of the patterns of letters occurring in a word, where each letter is given an integer code in order of appearance.
//So the first letter is given the code 0, and second is then assigned 1 if it is different to the first letter or 0 otherwise, and so on.
//
//As an example, the word "hello" would become "0.1.2.2.3".For this task case-sensitivity is ignored, so "hello", "helLo" and "heLlo" 
//will all return the same word pattern.
//
//Your task is to return the word pattern for a given word.All words provided will be non - empty strings of alphabetic characters only,
//i.e.matching the regex "[a-zA-Z]+".
#include<string>
#include<vector>

std::string wordPattern(const std::string& word) {
	std::string outString;
	std::vector<std::string> outVector;
	int charMap[26] = { 0 };
	int nextLetterCode = 0;
	char currentLetter;
	for (auto n : word)
	{
		currentLetter = tolower(n);
		if (charMap[currentLetter - 'a'] > 0)
		{
			std::string a = std::to_string(1);
			outVector.push_back(std::to_string(charMap[currentLetter - 'a']));
			outVector.push_back(".");
		}
		else
		{
			charMap[currentLetter - 'a'] = nextLetterCode;
			outVector.push_back(std::to_string(nextLetterCode));
			outVector.push_back(".");
			nextLetterCode++;
		}
	}
	for (auto n : outVector) outString += n;
	outString.pop_back();
	return outString;
}