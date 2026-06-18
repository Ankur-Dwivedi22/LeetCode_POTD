class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        if (hour == 12)
            hour = 0;
        double h = 360 / 12;
        double m = 360 / 60;
        double hour_deg = (hour + (minutes / 60.0)) * h;
        double min_deg = minutes * m;
        double val = abs(hour_deg - min_deg);
        double ans = min(val, 360.0 - val);
        return ans;
    }
};