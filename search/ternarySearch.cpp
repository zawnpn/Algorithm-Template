double ternarySearch(double low, double high)
{
    double mid, midmid;
    while (low + EPS < high)
    {
        mid = (low + high) / 2;
        midmid = (mid + high) / 2;
        double mid_value = calc(mid);
        double midmid_value = calc(midmid);
        if (mid_value > midmid_value)
            high = midmid;
        else
            low = mid;
    }
    return low;
}