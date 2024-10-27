#include "Zone.h"
#pragma once

class CZone : public Zone<CZone>
{
public:
	CZone(int y, int x, bool adjtoPL, Common* c)
		:Zone(y, x, adjtoPL) {
		this->common = c;
		isImplementable = false;
		good = NULL;
		worker = NULL;
	}

	void STEP()
	{
		isImplementable = false;
		vector<Good*> g = common->getSoldableGoods();
		vector<Worker*> w = common->getAvailWorkers();
		if (population == 0 && adjtoPowerLine && w.size() >= 1 && g.size() >= 1) {
			isImplementable = true;
			good = g.at(0);
			worker = w.at(0);
		}
		else if (population == 0 && isadjwithPopulation(1, 1) && w.size() >= 1 && g.size() >= 1) {
			isImplementable = true;
			good = g.at(0);
			worker = w.at(0);
		}
		else if (population == 1 && isadjwithPopulation(2, 1) && w.size() >= 1 && g.size() >= 1) {
			isImplementable = true;
			good = g.at(0);
			worker = w.at(0);
		}
	}

	void Implement() {
		if (isImplementable) {
			STEP();
			if (isImplementable) {
				isImplementable = false;
				++population;
				worker->assign();
				good->sell();
			}
		}
	}

private:
	bool isImplementable;
	Common* common;
	Good* good;
	Worker* worker;
};
