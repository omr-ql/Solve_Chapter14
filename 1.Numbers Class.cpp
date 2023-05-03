#include <iostream>
#include <string>
using namespace std;

class Numbers
{
private:
    int number;
    static string lessThan20[];
    static string lessThan100[];
    static string hundred;
    static string thousand;

public:
    Numbers(int);
    void print();
};

// Static Members Definition
string Numbers::lessThan20[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                                "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                                "eighteen", "nineteen"};
string Numbers::lessThan100[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";

Numbers::Numbers(int num)
{
    if (num < 0 || num > 9999)
    {
        cout << "Enter a valid input" << endl;
    }
    else
    {
        number = num;
    }
}
void Numbers::print()
{
    if (number < 20) // Numbers that are less than 20
    {
        cout << "The number is: " << lessThan20[number] << endl;
    }
    else if (number >= 20 && number < 100) // Condition for numbers that are greater than 20 but less than 100
    {
        int tenth[] = {20, 30, 40, 50, 60, 70, 80, 90, 100};

        bool found;
        int index = 0;
        int high, low;

        do // Finds the tens value
        {
            found = false;

            if (number >= tenth[index])
            {
                high = tenth[index];
                found = true;
                index++;
            }
        } while (found);

        low = number - high; // Finds the single digit value

        cout << "The number is: " << lessThan100[index - 1] << " " << (low > 0 ? lessThan20[low] : "") << endl;
    }
    else if (number >= 100 && number < 1000) // Condition for numbers that are greater than 100 but less than 1000
    {
        int hundreth[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
        int tenth[] = {20, 30, 40, 50, 60, 70, 80, 90, 100};

        bool found;
        int index, index2;
        index = index2 = 0;
        int high, mid, low;

        do // Finds the hundreds value
        {
            found = false;

            if (number >= hundreth[index])
            {
                high = hundreth[index];
                found = true;
                index++;
            }
        } while (found);

        mid = number - high;

        if (mid != 0)
        {
            do // Finds the tens value
            {
                found = false;

                if (mid >= tenth[index2])
                {
                    low = tenth[index2];
                    found = true;
                    index2++;
                }
            } while (found);

            low = number - high - low; // Finds the single digit value
        }

        cout << "The number is: " << lessThan20[index] << " " << hundred << " " << (mid > 0 ? lessThan100[index2 - 1] : "") << " " << (low > 0 ? lessThan20[low] : "") << endl;
    }
    else if (number >= 1000 && number <= 9999) // Condition for numbers that are greater than 1000 but less than 9999
    {
        int thousandths[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
        int hundreth[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
        int tenth[] = {20, 30, 40, 50, 60, 70, 80, 90, 100};

        bool found;
        int index, index2, index3;
        index = index2 = index3 = 0;
        int high, mid, low, last;

        do // Finds the thousands value
        {
            found = false;

            if (number >= thousandths[index])
            {
                high = thousandths[index];
                found = true;
                index++;
            }
        } while (found);

        mid = number - high;

        if (mid != 0)
        {
            do // Finds the hundreds value
            {
                found = false;

                if (mid >= hundreth[index2])
                {
                    low = hundreth[index2];
                    found = true;
                    index2++;
                }

            } while (found);

            mid = low;
            low = number - (high + low);

            if (low != 0)
            {
                do // Finds the tens value
                {
                    found = false;

                    if (low >= tenth[index3])
                    {
                        last = tenth[index3];
                        found = true;
                        index3++;
                    }

                } while (found);
                last = number - (high + mid + last); // Finds the single digit value
            }
        }

        cout << "The number is: " << lessThan20[index] << " " << thousand << " " << (mid > 0 ? lessThan20[index2] : "") << " " << (mid > 0 ? hundred : "") << " " << (low > 0 ? lessThan100[index3 - 1] : "") << " " << (last > 0 ? lessThan20[last] : "") << endl;
    }
}

int main()
{
    int number;

    do
    {
        cout << "Enter a number from 0 to 9999: (-1 to exit) ";
        cin >> number;

        Numbers test(number);

        if (number >= 0 && number <= 9999)
        {
            test.print();
        }

        cout << endl;
    } while (number != -1);

    return 0;
}