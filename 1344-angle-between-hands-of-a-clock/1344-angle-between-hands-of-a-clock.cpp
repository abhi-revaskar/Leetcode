class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourangle = (30*(hour%12))+0.5*((minutes));
        double minuteangle= 6*((minutes));
        double ans = abs(hourangle-minuteangle);
        return (ans>180)?360-ans:ans;
        
    }
};