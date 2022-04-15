#pragma once

class StorageService
{
public:
    void SaveScore(int score, int player);

    int LoadScore(int player);

    int *LoadScores();
};
