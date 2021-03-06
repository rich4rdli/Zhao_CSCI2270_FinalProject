#ifndef HANGMAN_H
#define HANGMAN_H
#include <iostream>

struct guessedLetters{
    std::string letter;
    guessedLetters *next;

    guessedLetters(){};

    guessedLetters(std::string initletter, guessedLetters *initNext)
    {
        letter = initletter;
        next = initNext;
    }
};

struct Word{
    char letterSpot;
    bool guessed;
    Word *next;
    Word *previous;

    Word(){}; // default constructor

    Word(char initSpot, Word *initNext, Word *initPrevious, bool initguess)
    {
        letterSpot = initSpot;
        next = initNext;
        previous = initPrevious;
        guessed = initguess;
    }

};

class Hangman
{
    public:
        Hangman();
        ~Hangman();
        int a = 0;
        int subject = 1;
        int guessedletterindex = 0;
        int wordLength = 0;
        int wrongGuesses = 0;
        void addWord(std::string inword);
        void generateWord();
        std::string checkLetter(std::string);
        std::string checkWord(std::string);
        std::string displayGuesses();
        std::string displayProgress();
        std::string displayAnswer();
        void resetGame();
        std::string displayMan();
        void giveHint();
        void changeSubject();
    protected:
    private:
        std::string wordArray[75];
        Word *Wordhead;
        Word *Wordtail;
        guessedLetters *Letterhead;
        guessedLetters *Lettertail;
};

#endif // HANGMAN_H
