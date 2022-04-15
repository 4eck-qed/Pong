#include "../include/IStorageRepository.h"

class StorageRepository : public IStorageRepository
{

    void Create(std::string table) override
    {
        std::string sql = "CREATE " + table + " (" +
                          "P1Score INTEGER" +
                          "P2Score INTEGER" +
                          ");";
    }
};