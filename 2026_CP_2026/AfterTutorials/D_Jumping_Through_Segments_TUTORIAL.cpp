// CORE logic: if works for k=n, then also works for k > n;
// increasing seq. of k binary search to get least ONE for which it works
// SMART

#include <bits/stdc++.h>

using namespace std;

int segmentStart[200000], segmentEnd[200000];

bool isReachableWithJump(int segmentCount, int maxJump)
{
	int currentMinPosition = 0;  // After i moves: minimal coordinate we can be at
	int currentMaxPosition = 0;  // After i moves: maximal coordinate we can be at

	for (int i = 0; i < segmentCount; i++)
	{
		// From any position in [currentMinPosition, currentMaxPosition],
		// we can move at most maxJump left/right
		currentMaxPosition += maxJump;
		currentMinPosition -= maxJump;

		// Intersect reachable range with the i-th segment [l_i, r_i]
		int reachableStart = max(currentMinPosition, segmentStart[i]);
		int reachableEnd = min(currentMaxPosition, segmentEnd[i]);

		// If intersection is empty, we cannot land in segment i
		if (reachableStart > reachableEnd)
		{
			return false;
		}

		// Narrow our reachable range to the intersection for the next step
		currentMinPosition = reachableStart;
		currentMaxPosition = reachableEnd;
	}

	// We successfully found a landing point for every segment
	return true;
}

void solveTestCase()
{
	int segmentCount;
	cin >> segmentCount;

	for (int i = 0; i < segmentCount; i++)
	{
		cin >> segmentStart[i] >> segmentEnd[i];  // Segments must be visited in given order
	}

	int low = 0, high = 1e9;  // Binary search on the minimal feasible jump length k

	while (low < high)
	{
		int mid = (low + high) / 2;  // Candidate k
		if (isReachableWithJump(segmentCount, mid))
		{
			// k = mid works; try to find smaller
			high = mid;
		}
		else
		{
			// k = mid doesn't work; need larger k
			low = mid + 1;
		}
	}

	cout << low << '\n';  // Minimal k making the path possible
}

int main()
{
	int testCases;
	cin >> testCases;

	for (int testCase = 0; testCase < testCases; testCase++)
	{
		solveTestCase();
	}
}
