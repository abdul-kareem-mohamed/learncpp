#include <iostream>
#include "random.h"
#include <vector>
#include <string>

namespace WordList 
{
    
    const std::vector<std::string> wordlist = {
        "mystery",
        "broccoli",
        "account",
        "almost",
        "spaghetti",
        "opinion",
        "beautiful",
        "distance",
        "luggage",
    };
}

class Session
{
    private:
        std::string m_randomWord {};
        std::vector<char> m_guesses{};
        std::vector<bool> m_lookup{std::vector<bool>(256, false)};
        std::string wrongGuesses {"------"};
    public:
        Session()
        {
            m_randomWord = WordList::wordlist[Random::get(0, WordList::wordlist.size()-1)];
        }
        std::string_view getWord() const { return m_randomWord; }
        const std::vector<char>& getGuesses() const { return m_guesses; }
        const std::vector<bool> getLookUp() const { return m_lookup; }
        void setLetterGuessed(char letter) 
        { 
            m_guesses.push_back(letter);
            m_lookup[static_cast<unsigned char>(letter)] = true; 
        }
        bool isLetterGuessed(char letter) 
        { 
            return m_lookup[static_cast<unsigned char>(letter)];
        }
        void setWrongGuesses(char letter, int incorrectGuess)
        {
            wrongGuesses[6-incorrectGuess] = letter;
        }
        std::string_view getWrongGuesses() const
        {
            return wrongGuesses;
        }
};

void display(const Session& sess)
{
    
    std::cout << "The word: ";

    std::string_view randw = sess.getWord();
    const std::vector<char>& guesses = sess.getGuesses();
    std::vector<bool> lookup = sess.getLookUp();
    for(int i {0}; i < randw.size(); ++i)
    {
        if (lookup[static_cast<unsigned char>(randw[i])])
        {
            std::cout << randw[i];
        }
        else
        {
            std::cout << '_';
        }
        
    }

    std::cout << "\tWrong guesses: " << sess.getWrongGuesses();

    std::cout << "\n";

}

char getGuess(const std::vector<bool>& lookup) 
{
    char letter{};
    std::cout << "Enter your next letter: ";
    std::cin >> letter;

    while ((!std::cin) || letter < 'a' || letter > 'z') {
        // 1. Clear the error flag
        std::cin.clear();

        // 2. Discard invalid input from the buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "That was not a valid input.\tTry again.\n";

        std::cout << "Enter your next letter: ";
        std::cin >> letter;
    }

    while (lookup[static_cast<unsigned char>(letter)]) 
    {
        std::cout << "You already guessed that.  Try again.\n";
        std::cout << "Enter your next letter: ";
        std::cin >> letter;
    }

    // Clear out any extraneous input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return letter;
}

int main()
{
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word";
    std::cout << "\tTo lose: run out of pluses\n\n";
    
    Session session{};
    std::string_view randomWord = session.getWord();
    

    char guess{};
    int count {static_cast<int>(randomWord.size())+6};
    int incorrectGuess {};
    while (--count) { 
        display(session);
        guess = getGuess(session.getLookUp());
        if (randomWord.find(guess) != std::string_view::npos)
        {
            session.setLetterGuessed(guess);
            std::cout << "Yes, '" << guess << "' is in the word.\n\n";

        }
        else
        {
            std::cout << "No, '" << guess << "' is not in the word.\n\n";
            ++incorrectGuess;
            session.setWrongGuesses(guess, incorrectGuess);
        }
    }

}
