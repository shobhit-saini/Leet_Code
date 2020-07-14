/*
Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.

 

Example 1:



Input: hour = 12, minutes = 30
Output: 165
Example 2:



Input: hour = 3, minutes = 30
Output: 75
Example 3:



Input: hour = 3, minutes = 15
Output: 7.5
Example 4:

Input: hour = 4, minutes = 50
Output: 155
Example 5:

Input: hour = 12, minutes = 0
Output: 0
 

Constraints:

1 <= hour <= 12
0 <= minutes <= 59
Answers within 10^-5 of the actual value will be accepted as correct.
*/
class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double min_hand_angle, hour_hand_angle, result;
        //min_hand: 1min. = 6degree
        //hour_hand: 1min. = .5degree
        //hour_hand: 1hr = 30degree
        min_hand_angle = (minutes)*6;
        hour_hand_angle = ((hour*30) + (double)(minutes)*.5);
        result = (abs(min_hand_angle-hour_hand_angle));
        if( result > 180 )
        {
            return 360-result;
        }
        return result;
    }
};
