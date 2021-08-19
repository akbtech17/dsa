class ParkingSystem {
    int b;
    int m;
    int s;
public:
    ParkingSystem(int big, int medium, int small) {
        b = big;
        m = medium;
        s = small;
    }
    
    bool addCar(int x) {
        switch(x) {
            case 3: 
                if(s>0) {
                    s--;
                    return true;
                } 
                else return false;
                break;
            case 2:
                if(m>0) {
                    m--;
                    return true;
                } 
                else return false;
                break;
            case 1:
                if(b>0) {
                    b--;
                    return true;
                } 
                else return false;
                break;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */