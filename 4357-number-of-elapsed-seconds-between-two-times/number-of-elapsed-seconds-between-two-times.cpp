class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
       int hi= stoi(startTime.substr(0,2))*3600;
       int he= stoi(endTime.substr(0,2))*3600;
       int mi= stoi(startTime.substr(3,5))*60;
       int me= stoi(endTime.substr(3,5))*60;
       int si= stoi(startTime.substr(6,8));
       int se= stoi(endTime.substr(6,8));

       return abs((hi+mi+si)-(he+me+se));
    }
};