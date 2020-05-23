//
//  Word.hpp
//  w1
//
//  Created by Mikhail Frolov on 2020-01-14.
//  Copyright © 2020 Mikhail Frolov. All rights reserved.
//

#ifndef Word_h
#define Word_h


namespace sdds{

const int MAX_NO_OF_WORDS = 500;
const int MAX_WORD_LEN = 21;

struct Word {
   char letters[MAX_WORD_LEN];
   int count;
};

void toLowerCaseAndAlphabeticCopy(char des[], const char source[]);
int searchWords(const Word words[], int num, const char word[]);
void addWord(Word words[], int* index, const char newWord[]);
void totalWordsStat(int totNoWrds,int totalOverAll, int longestWord );
void report(const Word words[],int noOfWords, int longestWord);
void wordStats(bool logOn);
void print(const Word* w, bool gotoNextLine);
void sort(Word words[], int cnt);
void swap(Word* p1, Word* p2);
void programTitle();
}


#endif /* Word_h */
