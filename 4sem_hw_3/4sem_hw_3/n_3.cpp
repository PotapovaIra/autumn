#include <iostream>
#include <string>
#include <unordered_set>
#include <fstream>

//hash-functions
unsigned int RSHash(const char* str, unsigned int length)
{
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hash = 0;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash = hash * a + (*str);
        a = a * b;
    }

    return hash;
}
unsigned int JSHash(const char* str, unsigned int length)
{
    unsigned int hash = 1315423911;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash ^= ((hash << 5) + (*str) + (hash >> 2));
    }

    return hash;
}
unsigned int PJWHash(const char* str, unsigned int length)
{
    const unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
    const unsigned int ThreeQuarters = (unsigned int)((BitsInUnsignedInt * 3) / 4);
    const unsigned int OneEighth = (unsigned int)(BitsInUnsignedInt / 8);
    const unsigned int HighBits =
        (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
    unsigned int hash = 0;
    unsigned int test = 0;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash = (hash << OneEighth) + (*str);

        if ((test = hash & HighBits) != 0)
        {
            hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));
        }
    }

    return hash;
}
unsigned int ELFHash(const char* str, unsigned int length)
{
    unsigned int hash = 0;
    unsigned int x = 0;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash = (hash << 4) + (*str);

        if ((x = hash & 0xF0000000L) != 0)
        {
            hash ^= (x >> 24);
        }

        hash &= ~x;
    }

    return hash;
}
unsigned int BKDRHash(const char* str, unsigned int length)
{
    unsigned int seed = 131; /* 31 131 1313 13131 131313 etc.. */
    unsigned int hash = 0;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash = (hash * seed) + (*str);
    }

    return hash;
}
unsigned int SDBMHash(const char* str, unsigned int length)
{
    unsigned int hash = 0;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash = (*str) + (hash << 6) + (hash << 16) - hash;
    }

    return hash;
}
unsigned int DJBHash(const char* str, unsigned int length)
{
    unsigned int hash = 5381;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash = ((hash << 5) + hash) + (*str);
    }

    return hash;
}
unsigned int DEKHash(const char* str, unsigned int length)
{
    unsigned int hash = length;///? len?
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash = ((hash << 5) ^ (hash >> 27)) ^ (*str);
    }

    return hash;
}
unsigned int APHash(const char* str, unsigned int length)
{
    unsigned int hash = 0xAAAAAAAA;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash ^= ((i & 1) == 0) ? ((hash << 7) ^ (*str) * (hash >> 3)) :
            (~((hash << 11) + ((*str) ^ (hash >> 5))));
    }

    return hash;
}
//generate uniq strings from eng alphabet
std::string gen(int length)
{
    static const char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    std::string randString;

    for (auto i = 0; i < length; i++)
    {
        randString += alpha[rand() % (sizeof(alpha) - 1)];
    }
    return randString;
}
int main()
{
    const auto numStrings = 308915776;//amount
    const auto stringlen = 6;
    
    for (int i = 0; i < numStrings; ++i)
    {
        std::string randString = gen(stringlen);

        //count hash-code
        unsigned int rsHash = RSHash(randString.c_str(), stringlen);
        unsigned int jsHash = JSHash(randString.c_str(), stringlen);
        unsigned int pjwHash = PJWHash(randString.c_str(), stringlen);
        unsigned int elfHash = ELFHash(randString.c_str(), stringlen);
        unsigned int bkdrHash = BKDRHash(randString.c_str(), stringlen);
        unsigned int sdbmHash = SDBMHash(randString.c_str(), stringlen);
        unsigned int djbHash = DJBHash(randString.c_str(), stringlen);
        unsigned int dekHash = DEKHash(randString.c_str(), stringlen);
        unsigned int apHash = APHash(randString.c_str(), stringlen);

        //output
        std::ofstream out;
        out.open("RSHash.txt", std::ios_base::app);
        out << rsHash << std::endl;
        out.close();

        out.open("JSHash.txt", std::ios_base::app);
        out << jsHash << std::endl;
        out.close();

        out.open("PJWHash.txt", std::ios_base::app);
        out << pjwHash << std::endl;
        out.close();

        out.open("ELFHash.txt", std::ios_base::app);
        out << elfHash << std::endl;
        out.close();

        out.open("BKDRHash.txt", std::ios_base::app);
        out << bkdrHash << std::endl;
        out.close();

        out.open("SDBMHash.txt", std::ios_base::app);
        out << sdbmHash << std::endl;
        out.close();

        out.open("DJBHash.txt", std::ios_base::app);
        out << djbHash << std::endl;
        out.close();

        out.open("DEKHash.txt", std::ios_base::app);
        out << dekHash << std::endl;
        out.close();

        out.open("APHash.txt", std::ios_base::app);
        out << apHash << std::endl;
        out.close();
    }
    
    return 0;

}