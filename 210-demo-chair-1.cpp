// COMSC-210 | Lab 20 | Huiluan Yie

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
const int SIZE = 3;
const int MIN = 10000, MAX = 99999;

class Chair {
    private: 
        int legs;
        double * prices;
    public:
        // constructors
        Chair() {
            prices = new double[SIZE];

            // randomly select 3 or 4 legs
            int n = rand() % 2;
            legs = (n == 0) ? 3 : 4;

            for (int i = 0; i < SIZE; i++) {
                // randomly select price
                double price = (rand() % (MAX - MIN + 1) + MIN) / (double) 100;
                prices[i] = price;
            }
        }

    Chair(int l, double p[]) {
        prices = p;
        legs = l;
    }

    ~Chair() {
        delete[] prices;
    }

    // setters and getters
    void setLegs(int l) {
        legs = l;
    }
    int getLegs() {
        return legs;
    }

    void setPrices(double p1, double p2, double p3) {
        prices[0] = p1;
        prices[1] = p2;
        prices[2] = p3;
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: ";
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    cout << fixed << setprecision(2);
    srand(time(0)); // seed for random number

    cout << "=======DEFAULT-CONSTRUCTED CHAIR=======\n";
    //creating pointer to first chair object
    Chair * chairPtr = new Chair;
    chairPtr -> print();
    delete chairPtr;
    chairPtr = nullptr;

    cout << "\n======PARAMETER-CONSTRUCTED CHAIR======\n";
    //creating dynamic chair object with constructor
    // makr an double array to pass into the constructor
    double prices[] = {
        525.25,
        434.34,
        252.52
    };
    Chair * livingChair = new Chair(3, prices);
    livingChair -> print();
    delete livingChair;
    livingChair = nullptr;

    cout << "\n==ARRAY OF DEFAULT-CONSTRUCTED CHAIRS==\n";
    //creating dynamic array of chair objects
    Chair * collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++)
        collection[i].print();

    delete collection;
    collection = nullptr;

    return 0;
}