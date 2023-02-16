class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        int pTruck = 0, gTruck = 0, mTruck = 0;
        int j = travel.size() - 1;
        bool pFlag = false, gFlag = false, mFlag = false;

        for(int i = garbage.size() - 1; i >= 0; i--) {  
            // COUNT FREQUENCY OF EACH TRUCK
            int p = count(garbage[i].begin(), garbage[i].end(), 'P');
            int g = count(garbage[i].begin(), garbage[i].end(), 'G');
            int m = count(garbage[i].begin(), garbage[i].end(), 'M');
            
            if(p != 0) {
                pTruck += p;
                pFlag = true;
            }
            if(g != 0) {
                gTruck += g;
                gFlag = true;
            }
            if(m != 0){
                mTruck += m;
                mFlag = true;
            }
        
            if(j > -1) {
                if(pFlag) 
                    pTruck += travel[j];
                if(gFlag)
                    gTruck += travel[j];
                if(mFlag)
                    mTruck += travel[j];
            }
            j--;
        }
        // max({pTruck, gTruck, mTruck});
        cout << pTruck << " " << gTruck << " " << mTruck << endl;
        return pTruck + gTruck + mTruck;
    }
};