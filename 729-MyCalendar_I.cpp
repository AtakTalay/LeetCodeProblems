//https://leetcode.com/problems/my-calendar-i/
class MyCalendar {
public:
    vector<pair<int,int>> a;
    MyCalendar() {

    }

    bool book(int start, int end) {
        for(int i = 0; i < a.size(); i++){
            if((a[i].first <= start && a[i].second > start) || (a[i].first < end && a[i].second > end) || (start <= a[i].first && end >= a[i].second)){
                return false;
            }
        }
        a.push_back({start, end});
        return true;
    }
};
