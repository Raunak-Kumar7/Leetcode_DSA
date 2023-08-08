// Based on Sort an Array using Recursion
void insert(stack<int> &st, int val)
{
	if (st.empty() || st.top() <= val) // Base case and no conflict case --> easily insert at top/last and return
	{
		st.push(val);
		return;
	}
	// else we need to find the correct location to insert
	int v = st.top();
	st.pop();
	insert(st, val); // keep reomving the elements until original val is inserted
	st.push(v);		 // once location found and inserted, insert back the removed elements
}
void sortStack(stack<int> &st)
{
	if (st.size() == 1)
		return;
	int val = st.top(); // remvoing the top/last element and sorting the remianing stack/array
	st.pop();
	sortStack(st); // Recursion call
	insert(st, val);
}