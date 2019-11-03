// Thang (Alan) Bui
// poker.cpp

#include <iostream>
#include <ctime>
using namespace std;

void inputHand(char R[], char S[], int n);
bool straightFlush(char R[], char S[], int n);
bool fourKind(char R[], char S[], int n);
bool fullHouse(char R[], char S[], int n);
bool flush(char R[], char S[], int n);
bool straight(char R[], char S[], int n);
bool threeKind(char R[], char S[], int n);
bool twoPair(char R[], char S[], int n);
bool onePair(char R[], char S[], int n); 


int main() {
	const int N = 5;
	char Rank[N], Suit[N];
	int i;

	cout << "User inputs a hand:" << endl;
	inputHand(Rank, Suit, N);

	if (straightFlush(Rank, Suit, N))
		cout << "The rank of the hand is: Straight Flush" << endl;
	else if (fourKind(Rank, Suit, N))
		cout << "The rank of the hand is: Four of a Kind" << endl;
	else if (fullHouse(Rank, Suit, N))
		cout << "The rank of the hand is: Full House" << endl;
	else if (flush(Rank, Suit, N))
		cout << "The rank of the hand is: Flush" << endl;
	else if (straight(Rank, Suit, N))
		cout << "The rank of the hand is: Straight" << endl;
	else if (threeKind(Rank, Suit, N))
		cout << "The rank of the hand is: Three of a Kind" << endl;
	else if (twoPair(Rank, Suit, N))
		cout << "The rank of the hand is: Two Pair" << endl;
	else if (onePair(Rank, Suit, N))
		cout << "The rank of the hand is: One Pair" << endl;
	else {
		cout << "The rank of the hand is: Nothing" << endl;
	}
	return 0;
}



void inputHand(char R[], char S[], int n) {
	int i;
	cout << "Input a hand of " << n << " cards in rank order" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "input rank[" << i << "] ";
		cin >> R[i];  R[i] = toupper(R[i]);
		cout << "input suit[" << i << "] ";
		cin >> S[i];  S[i] = toupper(S[i]);
	}
}

bool straightFlush(char R[], char S[], int n) {
	bool result = false;
	string ranks = "23456789TJQKA";
	if (S[0] == S[1] && S[1] == S[2] && S[2] == S[3] && S[3] == S[4]) 
		for (int i = 4; i < 13; i++) {
			if (R[0] == ranks[i])
				if (R[1] == ranks[i - 1] && R[2] == ranks[i - 2] && R[3] == ranks[i - 3] && R[4] == ranks[i - 4]) 
					result = true;
			}
		return result;
			}
	
bool fourKind(char R[], char S[], int n) {
	bool result = false;
	if (R[0] == R[3] || R[1] == R[4])
		result = true;
	return result;
}

bool fullHouse(char R[], char S[], int n) {
	bool result = false;
	if (R[0] == R[1] && R[2] == R[4] || R[0] == R[2] && R[3] == R[4])
		result = true;
	return result;
}

bool flush(char R[], char S[], int n) {
	bool result = false;
	if (S[0] == S[1] && S[1] == S[2] && S[2] == S[3] && S[3] == S[4])
		result = true;
	return result;
}

bool straight(char R[], char S[], int n) {
	bool result = false;
	string ranks = "23456789TJQKA";
	for (int i = 4; i < 13; i++) {
		if (R[0] == ranks[i])
			if (R[1] == ranks[i - 1] && R[2] == ranks[i - 2] && R[3] == ranks[i - 3] && R[4] == ranks[i - 4])
				result = true;
	}
	return result;
}
bool threeKind(char R[], char S[], int n) {
	bool result = false;
	if (R[0] == R[2] || R[1] == R[3] || R[2] == R[4])
		result = true;
	return result;
}

bool twoPair(char R[], char S[], int n) {
	bool result = false;
	if (R[0] == R[1] && R[2] == R[3] || R[0] == R[1] && R[3] == R[4] || R[1] == R[2] && R[3] == R[4])
		result = true;
	return result;
}

bool onePair(char R[], char S[], int n) {
	bool result = false;
	int count = 0;
	for (int i = 0; i < 3; i++) {
		if (R[i] == R[i + 1])
			count++;
	}
	if (count == 1)
		result = true;
	return result;
}

