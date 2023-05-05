#include <iostream>
using namespace std ;
class NumDays{
private:
    float hour_work ;
public :
    NumDays(float hour_work){
        this -> hour_work = hour_work ;
    }
    float operator+(NumDays &object){
        return hour_work + (object.hour_work);
    }

    float operator-(NumDays &object){
        return hour_work - (object.hour_work);
    }

    float operator++(int){
        hour_work++ ;
        return hour_work ;
    }

    float operator++(){
        ++hour_work ;
        return hour_work ;
    }

    float operator--(int) {
        hour_work-- ;
        return hour_work ;
    }

    float operator--() {
        -- hour_work ;
        return hour_work ;
    }
    void calc() {
        cout << "You had work for : " << hour_work / 8 << " Days" << endl;
    }
};

int main () {
    NumDays day1(8) ;
    day1.calc();
    cout << "---------------------------------------------"<< endl;
    day1++;
    day1.calc();
    cout << "---------------------------------------------"<< endl;
    day1--;
    day1.calc();
    cout << "---------------------------------------------"<< endl;
    NumDays day2(8);
    cout << "The sum of the hours is = " << day1 + day2 << endl;

}