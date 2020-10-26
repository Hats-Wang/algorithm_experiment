#include<iostream>
#include<algorithm>
#include<queue>
#include<functional>
#include<stdio.h>


int main(){
    freopen("exp3_1_in.txt", "r", stdin);
    int loop_times = 50;
    
    while(loop_times-- > 0){
    int num_jobs, num_machines, ans = 0, time = 0;
    std::cin >> num_jobs >> num_machines;
    int machines[num_machines];
    int jobs[num_jobs];
    for (int i = 0; i < num_jobs; i++) {
	std::cin >> jobs[i];
	//jobs[i].id = i;
	}
 
    if (num_jobs <= num_machines){
	std::cout << 0 << std::endl;
        continue;
    }
    
	// jobs > machines
    
    // remained_time of jobs arranged from large to small.
	std::sort(jobs, jobs + num_jobs);

    // min_heap of end_time_of_machine
	std::priority_queue<int, std::vector<int>, std::greater<int> > end_time_of_machine;

	for (int i = 0; i < num_machines; i++){
	//	machines[i] = jobs[i];
		end_time_of_machine.push(jobs[i]);
	}
	
		for (int i = num_machines; i < num_jobs; i++){
         	time = end_time_of_machine.top();
         	end_time_of_machine.pop();
         	ans += time;
			time += jobs[i];
         	end_time_of_machine.push(time);
		}
	std::cout << ans << std::endl;
      }
	return 0;
}
