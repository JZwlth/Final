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

    auto randomName = [&](const string arr[], int size) {
        return arr[rand() % size];
    };

    auto randomCoffeeOrder = [&]() {
        return coffeeOrders[rand() % coffeeOrderCount];
    };
    auto randomMuffinOrder = [&]() {
        return muffinOrders[rand() % muffinOrderCount];
    };
    auto randomBraceletOrder = [&]() {
        return braceletOrders[rand() % braceletOrderCount];
    };
    auto randomDonutOrder = [&]() {
        return donutOrders[rand() % donutOrderCount];
    };

    for (int i = 0; i < 3; ++i) {
        appendCustomer(coffeeHead, randomName(names, nameCount), randomCoffeeOrder());
        muffinQueue.push_back({randomName(names, nameCount), randomMuffinOrder()});
        braceletQueue.push_back({randomName(names, nameCount), randomBraceletOrder()});
        donutQueue.push_back({randomName(names, nameCount), randomDonutOrder()});
    }

    const int rounds = 10;

    int coffeeSize = 0;
    cout << "End of Round " << round << " Queues:\n";
    cout << " Coffee Booth Queue Size: " << coffeeSize << "\n";
    cout << " Muffin Booth Queue Size: " << muffinQueue.size() << "\n";
    cout << " Bracelet Booth Queue Size: " << braceletQueue.size() << "\n";
    cout << " Donut Booth Queue Size: " << donutQueue.size() << "\n";
    return 0;
}

// Function

void appendCustomer(ListNode*& head, const string& name, const string& order) {

}

bool serveCustomer(ListNode*& head, string& servedName, string& servedOrder) {

}
