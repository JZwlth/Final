#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;

// For Coffee Booth (Linked List)
struct ListNode {

};

// For Muffin, Friendship Bracelets, and Donuts booths
struct Customer {
};

// Function Prototypes
void appendCustomer();


int main() {
    srand((unsigned)time(nullptr)); 
    const string names[] = {};
    const int nameCount = sizeof(names)/sizeof(names[0]);

    const string coffeeOrders[] = {"l", "c", "a", "e", "m"};
    const int coffeeOrderCount = sizeof(coffeeOrders)/sizeof(coffeeOrders[0]);

    const string muffinOrders[] = {"b", "c", "b", "l"};
    const int muffinOrderCount = sizeof(muffinOrders)/sizeof(muffinOrders[0]);

    const string braceletOrders[] = {"bb", "ff", "c v", "ww"};
    const int braceletOrderCount = sizeof(braceletOrders)/sizeof(braceletOrders[0]);

    const string donutOrders[] = {"ga", "cs", "sd", "as"};
    const int donutOrderCount = sizeof(donutOrders)/sizeof(donutOrders[0]);

    // Coffee Booth: Linked List
    ListNode* coffeeHead = nullptr;
    // Muffin Booth: deque
    deque<Customer> muffinQueue;
    // Friendship Bracelet Booth: vector
    vector<Customer> braceletQueue;
    // Donut Booth: list
    list<Customer> donutQueue;

    
    return 0;
}

// Function

void appendCustomer(){

}

