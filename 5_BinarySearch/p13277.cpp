#include <iostream>
#include <vector>

using namespace std;

void print(string prefix, const vector<int>& v, const vector<int>& v2) {
	cout << prefix;
	for(vector<int>::const_reverse_iterator riter(v.rbegin()); riter != v.rend(); ++riter)
		cout << *riter;
	cout << " ";
	for(vector<int>::const_reverse_iterator riter(v2.rbegin()); riter != v2.rend(); ++riter)
		cout << *riter;
	cout << endl;
}

vector<int> sub(const vector<int>& a, const vector<int>& b) {

	int i;
	int sum;
	int tenth;
	vector<int> ret;

	if (a.size() < b.size())
		return (sub(b, a));
	i = 0;
	tenth = 0;
	while (i < b.size()) {
		sum = a[i] - b[i] - tenth;
		tenth = sum < 0;
		ret.push_back(sum + tenth * 10);
		i++;
	}
	while (i < a.size()) {
		sum = a[i] - tenth;
		tenth = sum < 0;
		ret.push_back(sum + tenth * 10);
		i++;
	}
	return (ret);
}

vector<int> add(const vector<int>& a, const vector<int>& b) {
	int i;
	int sum;
	int tenth;
	vector<int> ret;

	i = 0;
	tenth = 0;
	while (i < a.size() && i < b.size()) {
		sum = a[i] + b[i] + tenth;
		tenth = sum / 10;
		ret.push_back(sum % 10);
		i++;
	}
	bool flag = i < a.size();
	while (i < a.size() || i < b.size()) {
		sum = (flag ? a[i] : b[i]) + tenth;;
		tenth = 0;
		ret.push_back(sum % 10);
		i++;
	}
	if (tenth) ret.push_back(tenth);
	return (ret);
}

vector<int> power(const vector<int>& a, int len) {
    vector<int> ret;

    while (len--)
		ret.push_back(0);
    for (int i = 0; i < a.size(); i++)
        ret.push_back(a[i]);
	return (ret);
}

vector<int> multipy_one(const vector<int>& a, int num) {
    int i;
    int sum;
    int tenth;
    vector<int> ret;

    i = 0;
    tenth = 0;
    while (i < a.size()) {
        sum = a[i] * num + tenth;
        tenth = sum / 10;
        ret.push_back(sum % 10);
        i++;
    }
	if (tenth) ret.push_back(tenth);
    return (ret);
}

void divide(const vector<int>& a, int len, vector<int>& a0, vector<int>& a1) {
    int a_len;

	a_len = a.size();
    for (int i = 0; i < len; i++) {
        a0.push_back(a[i]);
        a1.push_back(a[i + len]);
    }
    if (a_len % 2 == 1) a1.push_back(a[a_len - 1]);
}

vector<int> rec(const vector<int>& a, const vector<int>& b) {
	int len;
    vector<int> a1, a0;
    vector<int> b1, b0;
    vector<int> z0, z1, z2;
    vector<int> ret;

	if (a.size() == 1 || b.size() == 1) {
		if (a.size() == 1)
			return (multipy_one(b, a[0]));
		else
			return (multipy_one(a, b[0]));
	}

	len = min(a.size(), b.size()) / 2;
	divide(a, len, a0, a1);
	divide(b, len, b0, b1);


    z2 = rec(a1, b1);
	z0 = rec(a0, b0);
    z1 = sub(sub(rec(add(a0, a1), add(b0, b1)), z0), z2);
	ret = add(add(z0, power(z1, len)), power(z2, len * 2));
	//print("input : ", a, b);
	//print("a : ", a1, a0);
	//print("b : ", b1, b0);
	//print("ret : ", z2, z1);
	//print("ret : ", z0, ret);
	//cout << endl;
	return (ret);
}

void solve(const vector<int>& a, const vector<int>& b) {
	vector<int> ret;

	ret = rec(a, b);
	for(vector<int>::reverse_iterator riter(ret.rbegin()); riter != ret.rend(); ++riter)
		cout << *riter;
}

int main() {
    vector<int> a;
    vector<int> b;
    string a_input;
    string b_input;

    cin >> a_input >> b_input;
	for(int i = a_input.length() - 1; i >= 0 ; --i)
		a.push_back(a_input[i] - '0');
	for(int i = b_input.length() - 1; i >= 0 ; --i)
		b.push_back(b_input[i] - '0');
	solve(a, b);
    return (0);
}
