#include <bits/stdc++.h>
using namespace std;

class NewspaperSubscription {
public:
    NewspaperSubscription(string name, vector<double> prices) {
        this->name = name;
        this->prices = prices;
        this->total_cost = calculate_total_cost();
    }
    double calculate_total_cost() {
    double total = 0;
    for (double price : prices) {
        total += price;
    }
    return total;
    }
    string name;
    vector<double> prices;
    double total_cost;
};

vector<vector<NewspaperSubscription>> find_combinations(double budget, vector<NewspaperSubscription> current_combination, vector<NewspaperSubscription> newspapers) {
vector<vector<NewspaperSubscription>> combinations;

if (budget <= 0) {
    return combinations;
}

for (NewspaperSubscription newspaper : newspapers) {
    current_combination.push_back(newspaper);
    double total_cost = newspaper.calculate_total_cost();

    if (total_cost <= budget) {
        combinations.push_back(current_combination);
    }

    vector<vector<NewspaperSubscription>> sub_combinations = find_combinations(budget - total_cost, current_combination, newspapers);
    combinations.insert(combinations.end(), sub_combinations.begin(), sub_combinations.end());
    current_combination.pop_back();
}

    return combinations;
}

int main() {
    vector<NewspaperSubscription> newspapers = {
    NewspaperSubscription("TOI", {3, 3, 3, 3, 3, 5, 6}),
    NewspaperSubscription("Hindu", {2.5, 2.5, 2.5, 2.5, 2.5, 4, 4}),
    NewspaperSubscription("ET", {4, 4, 4, 4, 4, 4, 10}),
    NewspaperSubscription("BM", {1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5}),
    NewspaperSubscription("HT", {2, 2, 2, 2, 2, 4, 4})
    };
  double budget;
  cin>>budget;
  vector<NewspaperSubscription> current_combination;
  vector<vector<NewspaperSubscription>> ans=find_combinations(budget, current_combination, newspapers);
    for(auto x: ans){
        for(auto y: x){
            cout<<y.name<<" ";
        }
        cout<<"\n";
    }
    return 0;
}