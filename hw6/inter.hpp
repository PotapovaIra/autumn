#include <vector>

class Class {
public:
    Class();
    Class(const Class& other);
    Class(Class&& other);
    ~Class();
    Class& operator=(const Class& other);
    Class& operator=(Class&& other);
private:
    int* mas;
    int sizemas;
    std::vector<int> v;
};