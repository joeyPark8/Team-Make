#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	vector<string> teams;
	map<string, string> members;
	map<string, vector<string>> members2;

	members2["banana"].push_back("joey");
	members2["banana"].push_back("mint");

	while (true) {
		cout << teams.size() << endl;
		for (auto i : teams) {
			cout << i << endl;
		}

		cout << members.size() << endl;
		for (auto [team, member] : members) {
			cout << team << "   " << member << endl;
		}

		cout << endl;

		for (auto [team, memberList] : members2) {
			for (auto member : memberList) {
				cout << team << "   " << member << endl;
			}
		}

		cout << endl;

		cout << "a. add team" << endl << 
				"b. add member" << endl <<
				"c. show teams" << endl <<
				"d. show members" << endl << endl << "> ";
		
		char choice;
		cin >> choice;

		if (choice == 'a') {
			cout << endl << "team name: ";
			string teamName;
			cin >> teamName;

			for (auto i : teams) {
				if (teamName == i) {
					cout << "team [" << teamName << "] is already existed" << endl;
					continue;
				}
			}

			teams.push_back(teamName);
			cout << "team [" << teamName << "] is added" << endl << endl;
		}
		else if (choice == 'b') {
			cout << "team name: ";
			string teamName;
			cin >> teamName;

			bool found = false;
			for (auto i : teams) {
				if (teamName == i) {
					found = true;
					break;
				}
			}

			if (found != true) {
				cout << "Can't find team [" << teamName << "]" << endl;
				continue;
			}

			cout << "member name: ";
			string memberName;
			cin >> memberName;

			members.insert(pair<string, string>(teamName, memberName));
			cout << "member [" << memberName << "] is added in team [" << teamName << "]" << endl;
		}
		else if (choice == 'c') {
			for (auto i : teams) {
				cout << i << endl;
			}
		}
		else if (choice == 'd') {
			cout << "team name: ";
			string teamName;
			cin >> teamName;

			bool found = false;
			for (auto i : teams) {
				if (teamName == i) {
					found = true;
					break;
				}
			}

			if (found != true) {
				cout << "Can't find team [" << teamName << "]" << endl;
				continue;
			}

			for (auto [team, member] : members) {
				if (teamName == team) {
					cout << member << endl;
				}
			}
		}
	}
	
	return 0;
}