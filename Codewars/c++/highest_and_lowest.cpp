#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
void Split(std::vector<int> &array, std::string numbers);
std::string FindMaxAndLow(std::vector<int> &array);
std::string highAndLow(const std::string &numbers)
{
    std::vector<int> array;
    Split(array, numbers);
    return FindMaxAndLow(array);
}
std::string FindMaxAndLow(std::vector<int> &array)
{
    if (array.empty())
        return "";
    int max = array[0];
    int min = array[0];
    for (auto x : array)
    {
        if (x > max)
            max = x;
        if (x < min)
            min = x;
    }
    std::string maxmin;
    if (max < 0)
        maxmin.push_back('-');
    maxmin.append(std::to_string(abs(max)));
    maxmin.push_back(' ');
    if (min < 0)
        maxmin.push_back('-');
    maxmin.append(std::to_string(abs(min)));
    return maxmin;
}
void Split(std::vector<int> &array, std::string numbers)
{
    char temp;
    std::string number;
    numbers += " ";
    int len = numbers.length();
    for (int i = 0; i < len; i++)
    {
        temp = numbers[i];
        if (temp == ' ')
        {
            int length = number.length();
            int num = 0;
            if (number[0] == '-')
            {

                for (int i = 1; i <=length-1; i++)
                {
                    num *= 10;
                    num += (int)(number[i] - '0');
                }
                num = -num;
            }
            else
            {
                for (int i = 0; i <=length-1; i++)
                {
                    num *= 10;
                    num += (int)(number[i] - '0');
                }
            }
            array.push_back(num);
            number = "";
            continue;
        }
        number.push_back(temp);
    }
    return;
}

int main()
{
    string numbers = "1 42 3 4 5 6 -7";
    cout<<highAndLow(numbers);
}