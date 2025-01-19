#ifndef TEHT2_H
#define TEHT2_H

class Game
{
public:
    Game(int maxNum);

    void Play();
    void printGameResult();

private:
    int maxNumber;
    int targetNumber;
    int attempts;
};

#endif // TEHT2_H
