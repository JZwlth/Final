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
    string name;
    string order;
    ListNode* next;
};

// For Muffin, Friendship Bracelets, and Donuts booths
struct Customer {
    string name;
    string order;
};

// Function Prototypes
void appendCustomer(ListNode*& head, const string& name, const string& order);
bool serveCustomer(ListNode*& head, string& servedName, string& servedOrder);


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
        for (int round = 1; round <= rounds; ++round) {
        cout << "\n=== ROUND " << round << " =\n";
        {
            string servedName, servedOrder;
            bool served = serveCustomer(coffeeHead, servedName, servedOrder);
            if (served) {
                cout << "[Coffee Booth] Served: " << servedName << " (" << servedOrder << ")\n";
            } else {
                cout << "[Coffee Booth] No one served (queue empty)\n";
            }

            if (rand() % 2 == 0) {
                appendCustomer(coffeeHead, randomName(names, nameCount), randomCoffeeOrder());
                cout << "[Coffee Booth] New Customer Arrived!\n";
            }
        }


        {
            if (!muffinQueue.empty()) {
                Customer c = muffinQueue.front();
                muffinQueue.pop_front();
                cout << "[Muffin Booth] Served: " << c.name << " (" << c.order << ")\n";
            } else {
                cout << "[Muffin Booth] No one served (queue empty)\n";
            }

            if (rand() % 2 == 0) {
                muffinQueue.push_back({randomName(names, nameCount), randomMuffinOrder()});
                cout << "[Muffin Booth] New Customer Arrived!\n";
            }
        }

         if (!braceletQueue.empty()) {
                Customer c = braceletQueue.front();
                braceletQueue.erase(braceletQueue.begin());
                cout << "[Bracelet Booth] Served: " << c.name << " (" << c.order << ")\n";
            } else {
                cout << "[Bracelet Booth] No one served (queue empty)\n";
            }

            if (rand() % 2 == 0) {
                braceletQueue.push_back({randomName(names, nameCount), randomBraceletOrder()});
                cout << "[Bracelet Booth] New Customer Arrived!\n";
            }
        }

        {
            if (!donutQueue.empty()) {
                Customer c = donutQueue.front();
                donutQueue.pop_front();
                cout << "[Donut Booth] Served: " << c.name << " (" << c.order << ")\n";
            } else {
                cout << "[Donut Booth] No one served (queue empty)\n";
            }

        }




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
    ListNode* newNode = new ListNode{name, order, nullptr};
    if (!head) {
        head = newNode;
    } else {
        ListNode* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

bool serveCustomer(ListNode*& head, string& servedName, string& servedOrder) {
    if (!head) return false;
    ListNode* temp = head;
    head = head->next;
    servedName = temp->name;
    servedOrder = temp->order;
    delete temp;
    return true;
}

