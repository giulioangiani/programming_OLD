#include <iostream>
#include <string>

using namespace std;

string subseq(string a, string b) {
	if (a.length() == 0 || b.length() == 0) return "";
	else {
		if (a[0] == b[0])
			// la sottosequenza più lunga è il carattere in comune più quello che rimane dalle restanti stringhe
			return a[0] + subseq(a.substr(1, a.length()), b.substr(1, b.length()));
		else {
			 // calcolo la sottosequenza più lunga fra 'a' e il rimanente di b
			 string tmp1 = subseq(a, b.substr(1, b.length()));
			 // calcolo la sottosequenza più lunga fra 'b' e il rimanente di a
			 string tmp2 = subseq(a.substr(1, a.length()), b);
			 // prendo la più lunga fra le due
			 if (tmp1.length() > tmp2.length()) return tmp1;
			 else return tmp2;
		 }
	}
	return "";	// default
}

int main() {

	string a = "UNGATTOGRASSO";
	string b = "UNARTOROTTO";
	// result = UNATORO
	cout << subseq (a, b);
	return 0;
}
