#include <iostream>
#include <iomanip>
#include <locale>
#include <string>
#include <boost/locale.hpp>

int main() {
    //install locale
    std::locale::global(std::locale("ka_GE.UTF-8")); //georgia
    std::locale::global(std::locale("ru_RU.UTF-8"));//russian
    std::locale::global(std::locale("pl_PL.UTF-8"));//polish
    //Input ijn georgian lari
    long double moneyGE = 0;
    std::cout << "Enter amount of money in georgian lari: ";
    std::cin >> std::get_money(moneyGE);
    //convert lari to rubles
    long double moneyRU = moneyGE * 25.0; //for example
    //output in rubles
    std::cout << "Converted to rubles(Russia): " << std::put_money(moneyRU) << std::endl;
    //convert rubles to polish zloty
    long double moneyPL = moneyRU * 0.05; 
    //output in zloty
    std::cout << "Converted to zloty(Poland): " << std::put_money(moneyPL) << std::endl;
    //convert zloty to lari
    long double moneyGE_PLN = moneyPL * 5.0;
    //Output in lari
    std::cout << "Converted to lari(Georgian, from Poland): " << std::put_money(moneyGE_PLN) << std::endl;

    return 0;
}
