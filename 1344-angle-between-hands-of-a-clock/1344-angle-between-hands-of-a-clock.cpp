class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourangle = double(30*(hour%12))+0.5*(double(minutes));
        double minuteangle= 6*(double(minutes));
        double ans = abs(hourangle-minuteangle);
        return (ans>180.0)?360.0-ans:ans;
        
    }
};