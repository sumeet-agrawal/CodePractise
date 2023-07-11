#include<iostream>

struct Advertising {
    int count{};
    double clickPercentage{};
    double earnPerClick{};
};

void getAdvertising(Advertising& ad)
{
    std::cout << "How many ads were shown today? ";
    std::cin >> ad.count;
    std::cout << "What percentage of ads were clicked on by users? ";
    std::cin >> ad.clickPercentage;
    std::cout << "What was the average earnings per click? ";
    std::cin >> ad.earnPerClick;
}

void printAdvertising(const Advertising& ad)
{
    std::cout << "Number of ads shown: " << ad.count << '\n';
    std::cout << "Click through rate: " << ad.clickPercentage << '\n';
    std::cout << "Average earnings per click: $" << ad.earnPerClick << '\n';

     std::cout << "Total Earnings: $" <<
        (ad.count * ad.clickPercentage / 100 * ad.earnPerClick) << '\n';
}
int main()
{
    Advertising ad{};
    getAdvertising(ad);
    printAdvertising(ad);

    return 0;
}