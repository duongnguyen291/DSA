#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

vector<int> getNetProfit(vector<string>& events) {
    unordered_map<string, int> portfolio; // Map to store stock quantities
    unordered_map<string, int> stockPrices; // Map to store stock prices
    vector<int> result; // Vector to store profit from QUERY events
    int profit = 0;

    for (string event : events) {
        istringstream iss(event);
        vector<string> parts;
        string part;
        while (iss >> part) {
            parts.push_back(part);
        }

        if (parts[0] == "BUY") {
            string stock = parts[1];
            int quantity = stoi(parts[2]);
            portfolio[stock] += quantity;
        } else if (parts[0] == "SELL") {
            string stock = parts[1];
            int quantity = stoi(parts[2]);
            portfolio[stock] -= quantity;
            profit += stockPrices[stock] * quantity;
        } else if (parts[0] == "CHANGE") {
            string stock = parts[1];
            int priceChange = stoi(parts[2]);
            stockPrices[stock] += priceChange;
            profit += portfolio[stock] * priceChange;
        } else if (parts[0] == "QUERY") {
            result.push_back(profit);
        }
    }

    return result;
}

int main() {
    vector<string> events = {"BUY hackr 2", "QUERY"};
    vector<int> result = getNetProfit(events);

    for (int profit : result) {
        cout << profit << endl;
    }

    return 0;
}
