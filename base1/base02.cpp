#include <iostream>
#include <string.h>
#include "base1.h"

// copy from '现代c++语言核心特性解析'
class BigMemoryPool
{
public:
    static const int PoolSize = 4096;
    BigMemoryPool() : pool_(new char[PoolSize]) {}
    ~BigMemoryPool()
    {
        if (pool_ != nullptr)
        {
            delete[] pool_;
            pool_ = nullptr;
        }
    }
    BigMemoryPool(const BigMemoryPool& other) : pool_(new char[PoolSize])
    {
        std::cout << "copy big memory pool." << std::endl;
        memcpy(pool_, other.pool_, PoolSize);
    }

private:
    char* pool_;
};
BigMemoryPool get_pool(const BigMemoryPool& pool) { return pool; }
BigMemoryPool make_pool()
{
    BigMemoryPool pool;
    return get_pool(pool);
}

void base02()
{
    std::cout << "Base knowladge base_2 ---- lvalue and rvalue" << std::endl;
    BigMemoryPool my_pool = make_pool();
}