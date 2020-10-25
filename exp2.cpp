#include<iostream>
#include<algorithm>
#include<cstring>
#include<limits.h>

int main (){
	int total_length, num, left, right, mid;
	std::cin>> total_length >> num;
        // the absolute distance of each point from 0 to last.
	int  abs_distance[num + 2];

	//initialize the absolute distance of each point.
	abs_distance[0] = 0;
	for (int i = 1; i < num + 1; i++) std::cin >> abs_distance[i];
	abs_distance[num + 1] = total_length;
	std::sort(abs_distance, abs_distance + num + 1);
	
	//min distance from point i to point j.
	int ans[num + 2][num + 2];
	std::memset(ans, 0, (num + 2)*(num + 2)*sizeof(int));
	
	//min_cost[i][j] = min(min_cost[i][mid] + min_cost[mid][j]) + leng_of_(i,j).
	for(left = num - 1; left >= 0; left--){
	    for (right = left + 2; right <= num + 1; right++){
	    	ans[left][right] = INT_MAX;
	    	for (mid = left + 1; mid < right; mid++)
	    	     ans[left][right] = std::min(ans[left][right], ans[left][mid] + ans[mid][right]);
	    	ans[left][right] += (abs_distance[right] - abs_distance[left]);
		}
	}
	std::cout<< ans[0][num +1] << std::endl;
}
