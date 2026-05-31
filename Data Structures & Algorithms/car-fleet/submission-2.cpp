class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
                std::map<int, int> posSpeedMap;
        std::vector<double> timeArr;
        timeArr.reserve(posSpeedMap.size());

        // t: O (n log n), s: O (n)
        for (int i = 0; i < position.size(); ++i)
        {
            posSpeedMap[position[i]] = speed[i];
        }

        // t: O (n)
        for (const auto &[pos, speed] : posSpeedMap)
        {
            double arrivalTime = (double) (target - pos) / speed;
            timeArr.push_back(arrivalTime);
        }

        int fleet = position.size(); // maximum number of fleet

        std::stack<double> fleetStack;

        fleetStack.push(timeArr[position.size() - 1]); // earliest the first fleet will arrive

        for (int i = position.size() - 2; i >= 0; --i)
        {

            if (timeArr[i] <= fleetStack.top())
            {
                fleet--;
            }
            else
            {
                fleetStack.push(timeArr[i]);
            }
        }
        return fleet;
    }
};
