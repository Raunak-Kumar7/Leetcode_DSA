vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> st;
    int n = asteroids.size();
    for (int i = 0; i < n; i++)
    {
        if (st.empty() || st.top() < 0)
            st.push(asteroids[i]);
        else // right at top --> only then conflict arrises
        {
            if (asteroids[i] > 0) // right
                st.push(asteroids[i]);
            else
            {
                bool flag = false;
                while (!st.empty())
                {
                    if (st.top() < 0) // left going found
                    {
                        flag = true;
                        st.push(asteroids[i]);
                        break;
                    }
                    if (st.top() > abs(asteroids[i]))
                    {
                        flag = true;
                        break;
                    }
                    else if (st.top() == abs(asteroids[i]))
                    {
                        flag = true;
                        st.pop();
                        break;
                    }
                    else
                    {
                        st.pop();
                    }
                }
                if (!flag)
                    st.push(asteroids[i]);
            }
        }
    }
    int l = st.size();
    vector<int> ans(l);
    for (int i = l - 1; i >= 0; i--)
    {
        ans[i] = st.top();
        st.pop();
    }
    return ans;
}