
vector<int> manacher(string s)
{
    string t;
    int i;
    for (auto ch : s)
    {
        t += string("#") + ch;
    }
    t += "#";
    int l = 1, r = 1;
    vector<int> p(t.size());
    p.assign(t.size(), 1);
    for (i = 1; i < t.size(); i++)
    {
        p[i] = max((int)0, min(r - i, p[l + r - i]));
        while (i + p[i] < t.size() && i - p[i] >= 0 && t[i - p[i]] == t[i + p[i]])
        {
            p[i]++;
        }
        if (i + p[i] > r)
        {
            l = i - p[i];
            r = i + p[i];
        }
    }
    // p[i] is longest pallindrom length center at i
    return p;
}

