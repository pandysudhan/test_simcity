#include "Zone.h"

#pragma once

class RZone : public Zone<RZone>
{
public:
	RZone(int y, int x, bool adjtoPL)
		:Zone(y, x, adjtoPL) {
		newPopulation = 0;
	}

	vector<Worker*> getWorkersAvailable()
	{
		vector<Worker*> w;
		vector<Worker*>::iterator it;

		for (it = workers.begin(); it != workers.end(); it++)
		{
			if ((*it)->isAvailable())
				w.push_back(*(it));
		}

		return w;
	}
	void STEP()
	{
		if (population == 0 && adjtoPowerLine) {
			newPopulation = population + 1;
			t_workers.push_back(new Worker());
		}
		else if (population == 0 && isadjwithPopulation(1, 1)) {
			newPopulation = population + 1;
			t_workers.push_back(new Worker());
		}
		else if (population == 1 && isadjwithPopulation(2, 1)) {
			newPopulation = population + 1;
			t_workers.push_back(new Worker());
		}
		else if (population == 2 && isadjwithPopulation(4, 2)) {
			newPopulation = population + 1;
			t_workers.push_back(new Worker());
		}
		else if (population == 3 && isadjwithPopulation(6, 3)) {
			newPopulation = population + 1;
			t_workers.push_back(new Worker());
		}
		else if (population == 4 && isadjwithPopulation(8, 4)) {
			newPopulation = population + 1;
			t_workers.push_back(new Worker());
		}
	}

	void implement() { 
		population = newPopulation; 
		workers.insert(workers.end(), t_workers.begin(), t_workers.end());
		t_workers.clear();
	}

private:
	int newPopulation;
	vector<Worker*> workers, t_workers;
};