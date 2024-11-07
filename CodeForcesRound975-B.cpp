#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
    int t;
    cin >> t;  // number of test cases
    
    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> points(n);
        for (int i = 0; i < n; ++i) {
            cin >> points[i];
        }

        vector<long long> queries(q);
        for (int i = 0; i < q; ++i) {
            cin >> queries[i];
        }

        // Sort points (although they are already sorted by problem description)
        sort(points.begin(), points.end());

        // Vector to store the coverage of each point
        map<int, long long> segment_count;
        
        // For each segment between xi and xj, increment coverage in the range [xi, xj-1]
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // All points in the range [points[i], points[j] - 1] are covered by this segment
                segment_count[points[i]]++;
                segment_count[points[j]]--;
            }
        }
        
        // Convert segment_count to prefix sums to get exact coverage per point
        vector<pair<int, long long>> coverage;
        long long current_coverage = 0;
        for (auto &entry : segment_count) {
            current_coverage += entry.second;
            coverage.push_back({entry.first, current_coverage});
        }

        // Answer each query
        for (int i = 0; i < q; ++i) {
            long long k = queries[i];
            long long count = 0;

            // Count how many points have exactly `k` coverage
            for (auto &entry : coverage) {
                if (entry.second == k) {
                    count++;
                }
            }
            
            cout << count << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
