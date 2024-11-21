#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
using namespace std;

enum Banks {MONOBANK,PRYVATBANK,SENSEBANK};

class Customer {
    char* firstName;
    char* secondName;
    char* patronymic;
    Banks bank;
    int creditCardNumber;
    int limit;
    int bankState;
public:
    Customer() {
        firstName = nullptr;
        secondName = nullptr;
        patronymic = nullptr;
        bank = MONOBANK;
        creditCardNumber = 0;
        limit = 0;
        bankState = 0;
    }

    int getBankState() const {
        return this->bankState;
    }

    void setBankState(int bankstate) {
        this->bankState = bankstate;
    }

    int getLimit() const {
        return this->limit;
    }

    void setLimit(int limit) {
        this->limit = limit;
    }
    
    Customer(const char firstname[], const char secondname[], const char patronymic[], Banks bank, int creditcardnumber, int limit, int bankstate) {
        this->firstName = new char[strlen(firstname) + 1];
        strcpy(this->firstName, firstname);
        this->secondName = new char[strlen(secondname) + 1];
        strcpy(this->secondName, secondname);
        this->patronymic = new char[strlen(patronymic) + 1];
        strcpy(this->patronymic, patronymic);
        this->bank = bank;
        this->creditCardNumber = creditcardnumber;
        this->limit = limit;
        this->bankState = bankstate;
    }
    Customer(const Customer& other) {
        this->firstName = new char[strlen(other.firstName) + 1];
        strcpy(firstName, other.firstName);
        this->secondName = new char[strlen(other.secondName) + 1];
        strcpy(secondName, other.secondName);
        this->patronymic = new char[strlen(other.patronymic) + 1];
        strcpy(patronymic, other.patronymic);
        this->bank = other.bank;
        this->creditCardNumber = other.creditCardNumber;
        this->limit = other.limit;
        this->bankState = other.bankState;
    }

    Customer(int bankState)
    {
        this->firstName = nullptr;
        this->secondName = nullptr;
        this->patronymic = nullptr;
        this->bank = MONOBANK;
        this->creditCardNumber = 0;
        this->limit = 0;
        this->bankState = bankState;
    }

    void deleteMemory() {
        if (firstName != nullptr)
        {
            delete[] firstName;
        }

        if (secondName != nullptr)
        {
            delete[] secondName;
        }

        if (patronymic != nullptr)
        {
            delete[] patronymic;
        }
    }

    Customer operator = (const Customer other) {
        if (this == &other)
        {
            return *this;
        }

        deleteMemory();
        if (other.firstName || other.secondName || other.patronymic)
        {
            this->firstName = new char[strlen(other.firstName) + 1];
            strcpy(firstName, other.firstName);
            this->secondName = new char[strlen(other.secondName) + 1];
            strcpy(secondName, other.secondName);
            this->patronymic = new char[strlen(other.patronymic) + 1];
            strcpy(patronymic, other.patronymic);
            this->bank = other.bank;
            this->creditCardNumber = other.creditCardNumber;
            this->limit = other.limit;
            this->bankState = other.bankState;
        }
        else
        {
            this->firstName = nullptr;
            this->secondName = nullptr;
            this->patronymic = nullptr;
        }
        return *this;
    }

    bool operator == (const Customer& other) {
        return this->bankState == other.bankState;
    }

    bool operator < (const Customer& other) {
        return this->bankState < other.bankState;
    }

    Customer operator + (const Customer& other) {
         Customer res(this->bankState + other.bankState);
         return res;
    }

    /*int& operator [] (int value) {
        this->bankState = value;
    }*/

    friend ostream& operator << (ostream& out, const Customer& other);
    friend istream& operator >> (istream& in, Customer& other);
    ~Customer()
    {
        deleteMemory();
    }

    
};

ostream& operator << (ostream& out, const Customer& other) {
    out << "Name: " << other.firstName << endl;
    out << "Second name: " << other.secondName << endl;
    out << "patronymic: " << other.patronymic << endl;
    out << "Bank: " << other.bank << endl;
    out << "Credit card number: " << other.creditCardNumber << endl;
    out << "Limit: " << other.limit << endl;
    out << "Bank state: " << other.bankState << endl;
    out << "---------------------------------------------" << endl;
    return out;
}

istream& operator >> (istream& in, Customer& other) {
    int bank;
    char buffer[256];
    cout << "Enter name: " << endl;
    in >> buffer;
    other.firstName = new char[strlen(buffer) + 1];
    strcpy(other.firstName, buffer);
    cout << "Enter secondname: " << endl;
    in >> buffer;
    other.secondName = new char[strlen(buffer) + 1];
    strcpy(other.secondName, buffer);
    cout << "Enter patronymic: " << endl;
    in >> buffer;
    other.patronymic = new char[strlen(buffer) + 1];
    strcpy(other.patronymic, buffer);
    cout << "Select bank (0 - monobank, 1 - pryvatbank, 2 - sensebank): " << endl;
    cin >> bank;
    switch (bank)
    {
    case 0: other.bank = MONOBANK; break;
    case 1:  other.bank = PRYVATBANK; break;
    case 2: other.bank = SENSEBANK; break; 
    default: cout << "invalid choice " << endl;
        break;
    }
    cout << "Enter creditCardNumber: " << endl;
    in >> other.creditCardNumber;
    cout << "Enter limit: " << endl;
    in >> other.limit;
    cout << "Enter bankState: " << endl;
    in >> other.bankState;
    return in;
}

void showCustomer(vector<Customer> other) {
    for (size_t i = 0; i < other.size(); i++)
    {
        cout << other[i];
    }
}


void for_each(vector<Customer> other) {
    for (size_t i = 0; i < other.size(); i++)
    {
        cout << "the sum on your bank account is: " << other[i].getBankState() + 5000 << endl;
    }
    //other.for_each
}

void fill(vector<Customer> &other) {
    for (size_t i = 0; i < other.size(); i++)
    {
        other[i].setLimit(0);
    }
}

void remove(vector<Customer>& other, int value) {
    for (int i = other.size() - 1; i >= 0; i--) {
        if (other[i].getBankState() > value) {
            other.erase(other.begin() + i);
        }
    }
}

void permutation(vector<Customer> &other) {
    do {
        for (auto elem: other) {
            cout << elem;
        }
        cout << endl;
    } while (next_permutation(other.begin(), other.end()));
}

void sortFunction(vector<Customer>& other) {
    sort(other.begin(), other.end());
}

//bool found(const Customer& other, int value) { return other.getBankState() == value; }
//
//bool binarySearch(vector<Customer>& other, int value) {
//    sortFunction(other);
//    bool exist = binary_search(other.begin(), other.end(), value, found);
//    return exist;
//}

//void accumulateFunction(vector<Customer>& other) {
//    auto sum = accumulate(other.begin(), other.end(), [](Customer a, Customer b) {
//        return a + b; });
//    cout << (Customer) sum << endl;
//}


int main()
{
    Customer r1("Lymorenko", "Oleksandr", "Yuriyovych", MONOBANK, 128193839, 15000, 3829);
    Customer r2("Pupkin", "Vasyl", "Sergiyovych", PRYVATBANK, 289246803, 20000, 4831);
    Customer r3("Sereda", "Angelina", "Viktorivna", SENSEBANK, 462917478, 22000, 17042);
    Customer r4("Korolchuk", "Kostyantyn", "Sergiyovych", PRYVATBANK, 294748281, 17000, 14394);
    vector <Customer> customersArray;
    customersArray.push_back(r1);
    customersArray.push_back(r2);
    customersArray.push_back(r3);
    customersArray.push_back(r4);
   /* for_each(customersArray);
    showCustomer(customersArray);
    fill(customersArray);
    showCustomer(customersArray);
    remove(customersArray,10000);
    cout << "*****************************" << endl;
    showCustomer(customersArray);*/

    //vector<int> nums = { 1, 2, 3 };

    //// Генерація всіх перестановок
    //do {
    //    for (int num : nums) {
    //        cout << num << " ";
    //    }
    //    cout << std::endl;
    //} while (next_permutation(nums.begin(), nums.end()));

    //return 0;
    //showCustomer(customersArray);
    //permutation(customersArray);
    //showCustomer(customersArray);
    //showCustomer(customersArray);
    //sortFunction(customersArray);
    //showCustomer(customersArray);
    //cout << binarySearch(customersArray, 4831) << endl;
    //accumulateFunction(customersArray);
    Customer a1;
    cin >> a1;
    cout << a1;
}


