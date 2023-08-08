#ifndef PRNG_MT_RD_SEED_SEQ
#define PRNG_MT_RD_SEED_SEQ

#include <random>
#include <chrono>

namespace Random
{
    inline std::mt19937_64 generate()
    {
        std::random_device rd{};
        std::seed_seq sq{
            static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()), 
            rd(), rd(), rd(), rd(), rd(), rd(), rd() };
        std::mt19937_64 mt{sq};
        return mt;
    }
    
    inline std::mt19937_64 mt{generate()};

    template <typename T>
    inline T get(T min, T max)
    {
        return std::uniform_int_distribution<T>{min, max}(mt);
    }

    template <typename R, typename S, typename T>
    inline R get(S min, T max)
    {
        return static_cast<R>(get(static_cast<R>(min), static_cast<R>(max)));
    }

}

#endif