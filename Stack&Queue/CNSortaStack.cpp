//Recursive Approach

void insert(stack<int>& s, int temp)
{
	if(s.size()==0 || s.top()<=temp)
	{
		s.push(temp);
		return;
	}
	int val = s.top();
	s.pop();
	insert(s,temp);
	s.push(val);
}
void sortStack(stack<int> &s)
{
	// Write your code here
	if(s.size()==1)
	{
		return;
	}
	int temp = s.top();
	s.pop();
	sortStack(s);
	insert(s,temp);
}
