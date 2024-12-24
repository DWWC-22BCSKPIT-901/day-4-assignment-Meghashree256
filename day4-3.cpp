#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
vector<int> gcdQuery(vector<int>& nums, vector<int>& queries) {
vector<int> gcdPairs;
int n = nums.size();
// Generate all GCD pairs
for (int i = 0; i < n; ++i) {
for (int j = i + 1; j < n; ++j) {
gcdPairs.push_back(gcd(nums[i], nums[j]));
}
}
// Sort the GCD pairs
sort(gcdPairs.begin(), gcdPairs.end());
// Answer the queries
vector<int> answer;
for (int q : queries) {
if (q < gcdPairs.size()) {
answer.push_back(gcdPairs[q]);
} else {
answer.push_back(-1); // Handle out-of-range queries
}
}
return answer;
}
int main() {
vector<int> nums = {10, 15, 20};
vector<int> queries = {0, 2, 5};
vector<int> result = gcdQuery(nums, queries);
cout << "Results: ";
for (int val : result) {
cout << val << " ";
}
cout << endl;
return 0;
}