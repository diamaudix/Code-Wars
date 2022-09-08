#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
class Elevator {
public:
    Elevator(std::vector<std::vector<int>> q, int c): queues(q), capacity(c) {
       
        currentFloor = 0;
        topFloor = (int)queues.size();
        goingUp = true;
        finished = false;  
    }
    std::vector<int> findSolution();
    
private: 
   
    void unloadPassengers();
    void loadPassengers();
    int nextWaitingUpUp();   // next up up person waiting(if room) OR next passenger
    int nextWaitingDownDown(); //next down down person waiting(if room) OR next passenger  
    int emptyScanUpDown();// return highest down person; -1 for naught
    int emptyScanDownUp(); //return lowest up passenger; -1 for naught
    int nextPassengerDown();
    int nextPassengerUp();
    int determineNextFloor();
    bool isFinished();
    void printQueues();  
    bool emptyAbove();
    bool emptyBelow();

    std::vector<std::vector<int>> queues;
    int capacity;
    int currentFloor;
    int topFloor;
    bool finished;
    bool goingUp;
    std::vector<int> passengers;
    std::vector<int> solutionPath;
    
    
};

int Elevator::emptyScanUpDown() { 
    int highestDownPassenger = -1;
    for (int i = currentFloor + 1; i < topFloor; i++) {
        for (int j = 0; j < (int)queues[i].size(); j++) {
            if (queues[i][j] < i) highestDownPassenger = i;
        }
    }
    return highestDownPassenger;
}
int Elevator::emptyScanDownUp() {
    int lowestUpPassenger = -1;
    for (int i = currentFloor - 1; i >= 0; i--) {
        for (int j = 0; j < (int)queues[i].size(); j++) {
            if (queues[i][j] > i) lowestUpPassenger = i;
        }
    }
    return lowestUpPassenger;
}
bool Elevator::emptyAbove() {
    for (int i = currentFloor + 1; i < topFloor; i++) {
        if (!queues[i].empty()) return false;
    }
    return true;
}
bool Elevator::emptyBelow() {
    for (int i = currentFloor - 1; i >= 0; i--) {
        if (!queues[i].empty()) return false;
    }
    return true;
}
int Elevator::nextWaitingDownDown() { 
    int result = currentFloor;
    for (int i = result - 1; i >=0; i--) {
        for (int j = 0; j < (int)queues[i].size(); j++) {
            if (queues[i][j] < i) {
                result = i;
                return result;
            }
        }
    }
    return -1;
}
int Elevator::nextPassengerDown() {
    if (passengers.empty()) return -1; //shouldn't have been called in the first place
    int result = currentFloor;    
    std::sort(passengers.begin(), passengers.end(), std::greater<int>()); 
    if (passengers[0] > currentFloor) return -1;
    result = passengers[0];
    return result;
}
int Elevator::nextPassengerUp() {
    int result = currentFloor;
    if (passengers.empty()) return -1; //shouldn't be called in the first place
    std::sort(passengers.begin(), passengers.end());
    if (passengers[0] < currentFloor) return -1;
    result = passengers[0];
    return result;
}
int Elevator::nextWaitingUpUp() {   
    int result = currentFloor;
    for (int i = currentFloor + 1; i < topFloor; i++) {
        for (int j = 0; j < (int)queues[i].size(); j++) {
            if (queues[i][j] > i) {
                result = i;
                return result;
            }
        }
    }
    return -1;
}
void Elevator::unloadPassengers() {
    if (currentFloor == topFloor - 1) goingUp = false;
    if (currentFloor == 0) goingUp = true;
    for (int i = 0; i < (int)passengers.size(); i++) {
        if (passengers[i] == currentFloor) {
            passengers.erase(passengers.begin() + i);
            i = -1;
        }
    }
   // printQueues();
}
void Elevator::loadPassengers() {
    if (goingUp) {
        for (int i = 0; i < (int)queues[currentFloor].size(); i++) {
            if (queues[currentFloor][i] > currentFloor && (int)passengers.size() < capacity) {
                passengers.push_back(queues[currentFloor][i]);
                queues[currentFloor].erase(queues[currentFloor].begin() + i);
                i = -1;
            }
        }
        if ((int)passengers.size() == 0 && emptyAbove()) {
            for (int i = 0; i < (int)queues[currentFloor].size(); i++) {
                if ((int)passengers.size() < capacity) {
                    passengers.push_back(queues[currentFloor][i]);
                    queues[currentFloor].erase(queues[currentFloor].begin() + i);
                    i = -1;
                }
            }
        }
    }
    else { //going down
        for (int i = 0; i < (int)queues[currentFloor].size(); i++) {
            if (queues[currentFloor][i] < currentFloor && (int)passengers.size() < capacity) {
                passengers.push_back(queues[currentFloor][i]);
                queues[currentFloor].erase(queues[currentFloor].begin() + i);
                i = -1;
            }
        }
        if ((int)passengers.size() == 0 && emptyBelow()) {
            for (int i = 0; i < (int)queues[currentFloor].size(); i++) {
                if ((int)passengers.size() < capacity) {
                    passengers.push_back(queues[currentFloor][i]);
                    queues[currentFloor].erase(queues[currentFloor].begin() + i);
                    i = -1;
                }
            }
        }
    }
  //  printQueues();
}
bool Elevator::isFinished() {
    if ((int)passengers.size() != 0) return false;

    for (int i = 0; i < topFloor; i++) {
        if (!queues[i].empty()) return false;
    }
    return true;
}
int Elevator::determineNextFloor() {
   
    if (goingUp) {
        std::sort(passengers.begin(), passengers.end()); //sort in ascending order
        if((int)passengers.size() == capacity){          
            int a = nextPassengerUp();
            if (a!= -1) {
                for (int i = currentFloor; i < a; i++) {
                    for (int j = 0; j < (int)queues[i].size(); j++) {
                        if (queues[i][j] > i) {
                            if(solutionPath.back() != i) solutionPath.push_back(i);
                            break;
                        }
                    }
                }
                currentFloor = a;
                return currentFloor;
            }
            else {
                goingUp = false;
                currentFloor = nextPassengerDown();
                return currentFloor;
            }
                    
        }
        else if ((int)passengers.size() == 0) { // empty           
            if (currentFloor != 0) {// look for highest floor passenger going down
                int a = emptyScanUpDown();
                if (a != -1) {
                    currentFloor = a;
                    return currentFloor;
                }
                a = nextWaitingUpUp();
                if (a != -1) {
                    currentFloor = a;
                    return currentFloor;
                }
                a = emptyScanDownUp();
                if (a != -1) {
                    currentFloor = a;
                    return currentFloor;
                }
                a = nextWaitingDownDown();
                currentFloor = a;
                goingUp = false;
                return currentFloor;
        }
            else { // just turned around at lobby - normal scan up              
                int a = emptyScanUpDown();
                int b = nextWaitingUpUp();

                if (a >= 0 || b >= 0) {
                    if (a == -1) {
                        currentFloor = b;
                        return currentFloor;
                    }
                    if (b == -1) {
                        currentFloor = a;
                        return currentFloor;
                    }
                    currentFloor = std::min(a, b);
                    return currentFloor;
                }
            }
        }
        else { //room for more on way up  //someone must be going up (?)
            int a = nextWaitingUpUp();
            int b = nextPassengerUp();
            if (a >=0 || b>= 0) {               
                if (a == -1) { // no one waiting above to go up
                    currentFloor = b; //go to floor of next passenger going up
                    return currentFloor;
                }
                if (b == -1) { //no passengers going up
                    currentFloor = a; //go to floor of next person waiting above, wanting to go up
                    return currentFloor;
                }
                // there are passengers going up, as well as people above waiting to go up - take min
                currentFloor = std::min(a, b);
                return currentFloor;
            }
            else { //nothing up to Do; i.e both a, b = -1
                goingUp = false;              
                std::sort(passengers.begin(), passengers.end(), std::greater<int>());
                int a = nextWaitingDownDown();
                int b = nextPassengerDown();
                if (a >= 0 || b >= 0) {
                    if (a == -1){
                        currentFloor = b;
                        return currentFloor;
                    }
                    if (b == -1) {
                        currentFloor = a;
                        return currentFloor;
                    }
                    currentFloor = std::max(a, b);
                    return currentFloor;
                }
                currentFloor = -1; //shouldn't happen - isFinished should have already eliminated this possibility
                return currentFloor;
            }
        }
    }
    else { //going down
        std::sort(passengers.begin(), passengers.end(), std::greater<int>());
        if ((int)passengers.size() == capacity) {

            int a = nextPassengerDown();
            
            if (a != -1) {

                for (int i = currentFloor; i > a; i--) {
                    for (int j = 0; j < (int)queues[i].size(); j++) {
                        if (queues[i][j] < i) {
                            if(solutionPath.back()!=i) solutionPath.push_back(i);
                            break;
                        }
                    }
                }

                currentFloor = a;
                return currentFloor;
            }
            else {
                std::sort(passengers.begin(), passengers.end());
                goingUp = true;
                currentFloor = nextPassengerUp();
                return currentFloor;
            }
        }

        else if ((int)passengers.size() == 0) { // empty

            if (currentFloor != topFloor-1) {// look for highest floor passenger going down
                int a = emptyScanDownUp();
                if (a != -1) {
                    currentFloor = a;
                    return currentFloor;
                }
                a = nextWaitingDownDown();
                if (a != -1) {
                    currentFloor = a;
                    return currentFloor;
                }
                // nothing to do downwards;
                goingUp = true;
                a = emptyScanUpDown();
                if (a != -1) {
                    currentFloor = a;
                    return currentFloor;
                }
                a = nextWaitingUpUp();
                currentFloor = a;
                
                return currentFloor;
            }
            else { // just turned around at top and empty - normal scan down

                int b = emptyScanDownUp();
                int a = nextWaitingDownDown();
                if (a >= 0 || b >= 0) {
                    if (b == -1) {
                        currentFloor = a;
                        return currentFloor;
                    }
                    if (a == -1) {
                        currentFloor = b;
                        return currentFloor;
                    }
                    currentFloor = std::max(a, b);
                    return currentFloor;
                }
            }
        }
        else { //room for more on way down //someone must be going down(?)
            int a = nextWaitingDownDown();
            int b = nextPassengerDown();
            if (a >= 0 || b >= 0) {

                if (a == -1) { // no one waiting below to go down
                    currentFloor = b; //go to floor of next passenger going down
                    return currentFloor;
                }
                if (b == -1) { //no passengers going down
                    currentFloor = a; //go to floor of next person waiting below, wanting to go down
                    return currentFloor;
                }
                // there are passengers going down, as well as people below waiting to go down - take max
                currentFloor = std::max(a, b);
                return currentFloor;
            }
            else { //nothing down to Do; i.e both a, b = -1
                goingUp = true;
                std::sort(passengers.begin(), passengers.end());
                int a = nextWaitingUpUp();
                int b = nextPassengerUp();
                if (a >= 0 || b >= 0) {
                    if (a == -1) {
                        currentFloor = b;
                        return currentFloor;
                    }
                    if (b == -1) {
                        currentFloor = a;
                        return currentFloor;
                    }
                    currentFloor = std::min(a, b);
                }
                currentFloor = -1; //shouldn't happen - isFinished should have already eliminated this possibility
                return currentFloor;

            }
        }
    }
    return -1;
}
std::vector<int> Elevator::findSolution() {
    printQueues();
    std::cout << "Capacity : " << capacity << std::endl;

    while (!isFinished()) {
        solutionPath.push_back(currentFloor);
        unloadPassengers();
        loadPassengers();
        currentFloor = determineNextFloor();
        std::cout << std::endl<<"Next Floor : " << currentFloor << std::endl;
    }
    if(solutionPath.back()!=0) solutionPath.push_back(0);
    return solutionPath;
}
void Elevator::printQueues() {
    std::cout << "Current Passengers: " << std::endl << std::endl;
    for (int i = 0; i < (int)passengers.size(); i++) {
        std::cout << passengers[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Current Queues: " << std::endl << std::endl;
    
    for (int i = topFloor - 1; i >= 0; i--) {
        std::cout << " Floor " << i << " : ";
        for (unsigned int j = 0; j < queues[i].size(); j++) {
            std::cout << queues[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    
}
std::vector<int> the_lift(const std::vector<std::vector<int>>& queues, int capacity) {
    
    bool empty = true;
    for (int i = 0; i < (int)queues.size(); i++) {
        if (!queues[i].empty()) empty = false;
    }
    if (empty) return { {0} };

    std::vector<std::vector<int>> mutableQueue = queues;
    Elevator lift(mutableQueue, capacity);
    std::vector<int> solution;
    solution = lift.findSolution();
    return solution;
}

int main(){
        std::vector<std::vector<int>> queues; std::vector<int> result;


       // queues = { {}, {}, {4,4,4,4,4,4,4,4,4,4}, {}, {2,2,2,2,2,2,2,2,2,2,2,2,2}, {}, {} , {} };
       // result = the_lift(queues, 3);

        queues = { {}, {0,0,0,0,0,0}, {0,0,0,0,0,0},{0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0} };
        result = the_lift(queues, 4);
        
        queues = { {}, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, {2,2,2,2,2,2,2,2,2,2,2,2}, {3,3,3,3,3,3,3,3,3}, {4,4,4,4,4,4} , {5,5,5} };
        result = the_lift(queues, 3);

        queues = { {}, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, {2,2,2,2,2,2,2,2,2,2,2,2}, {3,3,3,3,3,3,3,3,3}, {4,3,2,1,0,4} , {5,4,3} };
        result = the_lift(queues, 3);



        //queues = { {6,6,6,4,5,3}, {0}, {}, {4,5,2,5}, {2}, {3,3,0,1}, {} , {2,5,5,6,5,5,3} };
        //result = the_lift(queues, 3);
        //
        //queues = { {}, {}, {5,5,5}, {}, {}, {}, {} };
        ////result = { 0, 2, 5, 0 };
        //result = the_lift(queues, 5);// , Equals(result));

        //queues = { {}, {}, {1,1}, {}, {}, {}, {} };
        ////result = { 0, 2, 1, 0 };
        //result = the_lift(queues, 5);//;// , Equals(result));

        //queues = { {}, {3}, {4}, {}, {5}, {}, {} };
        ////result = { 0, 1, 2, 3, 4, 5, 0 };
        //result = the_lift(queues, 5);// , Equals(result));

        //queues = { {}, {0}, {}, {}, {2}, {3}, {} };
        ////result = { 0, 5, 4, 3, 2, 1, 0 };
        //result = the_lift(queues, 5);// , Equals(result));

        
        return 0;

}

//
//
//int Elevator::getNextFloor() {
//
//    if (goingUp) {
//        for (unsigned int i = currentFloor+1; i < topFloor; i++) {
//            if (queues[i].empty()) {
//                i++; continue;
//            }
//
//            
//            nextFloor = queues[i][0];
//
//            if (nextFloor < i) goingUp = false;
//            else goingUp = true;
//
//        }
//    }
//    else {
//        goingUp = false;
//
//        for (unsigned int i = currentFloor - 1; i >= 0; i--) {
//            if (queues[i].empty()) {
//                continue;
//            }
//
//            nextFloor = queues[i][0];
//            if (nextFloor < i) goingUp = false;
//            else goingUp = true;
//        }
//    }
//
//    return nextFloor;
//}
//
//int Elevator::proceedToNextFloor() {
//   
//    
//    if (passengers.empty()) {
//        nextFloor = getNextFloor();
//        return nextFloor;
//    }
//
//    nextFloor = *passengers.begin();
//
//    return nextFloor;
//}
//

//
//void Elevator::interactWithFloor() {
//    std::cout << "Before Unloading: " << std::endl;
//    printQueues();
//
//    std::vector<int>::iterator it = passengers.begin();
//
//    while (!passengers.empty() && it != passengers.end())  //unload tennants;
//    { 
//           if (*it == currentFloor)
//           {
//               passengers.erase(it);
//               if (*(solutionPath.end() - 1) != currentFloor)
//               {
//                   solutionPath.push_back(currentFloor);
//
//               }
//           }
//           else 
//           {
//                it++;
//           }
//
//    }
//    std::cout << "After Unloading, Before Loading: " << std::endl;
//    printQueues();
//
//    it = queues[currentFloor].begin(); //board new tennants
//
//    while (it != queues[currentFloor].end())
//    {
//            
//            if (goingUp) 
//            {
//                if (*it > currentFloor) 
//                {
//                    std::vector<int>::iterator itTemp = it;
//                    passengers.push_back(*it);
//                    queues[currentFloor].erase(itTemp, itTemp+1);
//                    printQueues();
//                }
//                else {
//                    
//                }
//                it++;
//            }
//            else 
//            {
//                if (*it < currentFloor) 
//                {
//                    passengers.push_back(*it);
//                    queues[currentFloor].erase(it, it+1);                    
//                }
//                else {
//                    
//                }
//                it++;
//            }
//            
//    }
//
//    std::cout << "After Loading: " << std::endl;
//    printQueues();
//
//}
//