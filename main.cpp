#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// Order Struct
struct Order
{
    int id;
    string type; 
    int price;
    int quantity;
    Order(int _id, string _type, int _price, int _quantity)
        : id(_id), type(_type), price(_price), quantity(_quantity) {}
};

// Comparators for heaps
struct BuyCompare 
{
    bool operator()(const Order& a, const Order& b) 
{
        return a.price < b.price; // Max-heap for buy
    }
};
struct SellCompare 
{
    bool operator()(const Order& a, const Order& b) 
{
        return a.price > b.price; // Min-heap for sell
    }
};

// Trade Struct
struct Trade {
    int buyId, sellId, price, quantity;
    Trade(int b, int s, int p, int q) : buyId(b), sellId(s), price(p), quantity(q) {}
};

int main() 
{
    priority_queue<Order, vector<Order>, BuyCompare> buyOrders;
    priority_queue<Order, vector<Order>, SellCompare> sellOrders;
    vector<Trade> tradeHistory;
    int orderId = 1;

    cout << "Welcome to the Limit Order Book Simulator\n";
    cout << "------------------------------------------\n";
    cout << "This program simulates buy/sell order matching.\n";
    cout << "You will be asked to enter:\n";
    cout << "1. Order Type (buy or sell)\n";
    cout << "2. Quantity (e.g., 100)\n";
    cout << "3. Price (e.g., 55)\n";

    while (true) 
    {
        string type;
        int qty, price;

        cout << "\nEnter Order Type (buy/sell): ";
        cin >> type;

        if (type != "buy" && type != "sell") 
        {
            cout << "Invalid type. Please enter 'buy' or 'sell'.\n";
            continue;
        }

        cout << "Enter Quantity: ";
        cin >> qty;

        cout << "Enter Price: ";
        cin >> price;

        Order newOrder(orderId++, type, price, qty);
        if (type == "buy") buyOrders.push(newOrder);
        else sellOrders.push(newOrder);

        // Matching Logic
        while (!buyOrders.empty() && !sellOrders.empty()) 
        {
            Order buy = buyOrders.top();
            Order sell = sellOrders.top();

            if (buy.price >= sell.price) 
            {
                int tradedQty = min(buy.quantity, sell.quantity);
                int tradePrice = sell.price;

                cout << "Trade Executed: Rs" << tradePrice << " x " << tradedQty << endl;
                tradeHistory.push_back(Trade(buy.id, sell.id, tradePrice, tradedQty));

                buyOrders.pop();
                sellOrders.pop();

                if (buy.quantity > tradedQty) 
                {
                    buy.quantity -= tradedQty;
                    buyOrders.push(buy);
                }
                if (sell.quantity > tradedQty) 
                {
                    sell.quantity -= tradedQty;
                    sellOrders.push(sell);
                }
            } else break;
        }

        // Display Order Book
        auto tempBuy = buyOrders;
        auto tempSell = sellOrders;
        cout << "\nCurrent Buy Orders:\n";
        if (tempBuy.empty()) cout << "(none)\n";
        while (!tempBuy.empty()) 
        {
            auto o = tempBuy.top(); tempBuy.pop();
            cout << "[Rs" << o.price << " x " << o.quantity << "] (ID " << o.id << ")\n";
        }

        cout << "\nCurrent Sell Orders:\n";
        if (tempSell.empty()) cout << "(none)\n";
        while (!tempSell.empty())
        {
            auto o = tempSell.top(); tempSell.pop();
            cout << "[Rs" << o.price << " x " << o.quantity << "] (ID " << o.id << ")\n";
        }

        // Display Trade History
        cout << "\nTrade History:\n";
        if (tradeHistory.empty()) cout << "(none)\n";
        for (auto& t : tradeHistory) 
        {
            cout << "Buy ID " << t.buyId << " matched with Sell ID " << t.sellId
                 << " at Rs" << t.price << " x " << t.quantity << endl;
        }

        char cont;
        cout << "\nDo you want to enter another order? (y/n): ";
        cin >> cont;
        if (cont != 'y') break;
    }

    cout << "\nExiting Limit Order Book Simulator. Thank you!\n";
    return 0;
}

