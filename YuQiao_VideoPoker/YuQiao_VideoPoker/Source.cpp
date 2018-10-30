
#define _CRTDBG_MAP_ALLOC
#define _CRTDBG_MAP_ALLOC_NEW
#include <cstdlib>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif



#include<iostream>
#include<string>
#include<ctime>


using namespace std;
 

// Linked List -----------------------------------------------------------------------------------------------------------
char convert(int i)
{
	return (i % 26) + 'A';
}

struct node
{
	string type;
	string face;
	int data;
	node* next;
};



struct linked_list
{
	int count ;
	node*head;
};

linked_list* create_linked_list()
{
	linked_list* list = new linked_list;
	list->head = nullptr;
	list->count = 0;
	return list;
}

void add_first(linked_list*list, string type, string face, int data)
{
	node* n = new node;
	n->type = type;
	n->face = face;
	n->data = data;
	n->next = list->head;
	list->head = n;
	list->count++;
}

void add_last(linked_list*list, string type, string face, int data)
{
	if (list->head == nullptr)
	{
		add_first(list, type, face, data);
		return;
	}

	node*tail = list->head;
	while (tail->next != nullptr)
		tail = tail->next;

	node*n = new node;
	n->type = type;
	n->face = face;
	n->data = data;
	n->next = nullptr;
	tail->next = n;
	list->count++;
}


void remove_first(linked_list* list)
{
	if (list->head == nullptr)
	{
		cout << "error!" << endl;
		return;
	}

	node*n = list->head;
	list->head = n->next;
	delete n;
	list->count--;
}

void remove_item(linked_list*list, int index) {
	if (index == 0)
	{
		remove_first(list);
		return;
	}

	node*prev = list->head;
	while (index - 1 > 0)
	{
		prev = prev->next;
		--index;
	}

	node*n = prev->next;
	prev->next = n->next;
	delete n;
	list->count--;
}


string get_itemFace(linked_list*list, int index)
{
	node*n = list->head;
	while (index > 0)
	{
		n = n->next;
		--index;
	}
	return n->face;
}

string get_itemType(linked_list*list, int index)
{
	node*n = list->head;
	while (index > 0)
	{
		n = n->next;
		--index;
	}
	return n->type;
}

int get_itemData(linked_list*list, int index)
{
	node*n = list->head;
	while (index > 0)
	{
		n = n->next;
		--index;
	}
	return n->data;
}

void print_items(linked_list* list)
{
	node*n = list->head;
	int letter = 0;
	while (n != nullptr)
	{
		cout << convert(letter)<< ": "<<n->face << " of "<< n->type << endl ;
		n = n->next;
		letter++;
	}
}

void clear(linked_list*list)
{
	node*n = list->head;
	while (n != nullptr)
	{
		node* temp = n;
		n = n->next;
		delete temp;
	}
	delete list;
}

int getSize(linked_list*list) {
	
	return list->count;
}




// Linked list above ----------------------------------------------------------------------------
void print_menu() {
	cout << "Here are your options: " << endl
		<< "keep    ---- To choose which card you wish to keep" << endl
		<< "all     ---- To keep all the cards" << endl
		<< "none    ---- To discard all the cards and replace them" << endl
		<< "deck    ---- View the cards left in the deck" << endl
	    << "swap    ---- swap a card in your hand with the card you want" << endl;	 

}



void initial_deck(linked_list* deck,linked_list*hand) {
	

		add_last(deck, "Heart", "2", 2); add_last(deck, "Heart", "3", 3); add_last(deck, "Heart", "4", 4); add_last(deck, "Heart", "5", 5); add_last(deck, "Heart", "6", 6); add_last(deck, "Heart", "7", 7); add_last(deck, "Heart", "8", 8); add_last(deck, "Heart", "9", 9);
		add_last(deck, "Heart", "10", 10); add_last(deck, "Heart", "Jack", 11); add_last(deck, "Heart", "Queen", 12); add_last(deck, "Heart", "King", 13); add_last(deck, "Heart", "Ace", 14);

		add_last(deck, "Club", "2", 2); add_last(deck, "Club", "3", 3); add_last(deck, "Club", "4", 4); add_last(deck, "Club", "5", 5); add_last(deck, "Club", "6", 6); add_last(deck, "Club", "7", 7); add_last(deck, "Club", "8", 8); add_last(deck, "Club", "9", 9);
		add_last(deck, "Club", "10", 10); add_last(deck, "Club", "Jack", 11); add_last(deck, "Club", "Queen", 12); add_last(deck, "Club", "King", 13); add_last(deck, "Club", "Ace", 14);

		add_last(deck, "Spade", "2", 2); add_last(deck, "Spade", "3", 3); add_last(deck, "Spade", "4", 4); add_last(deck, "Spade", "5", 5); add_last(deck, "Spade", "6", 6); add_last(deck, "Spade", "7", 7); add_last(deck, "Spade", "8", 8); add_last(deck, "Spade", "9", 9);
		add_last(deck, "Spade", "10", 10); add_last(deck, "Spade", "Jack", 11); add_last(deck, "Spade", "Queen", 12); add_last(deck, "Spade", "King", 13); add_last(deck, "Spade", "Ace", 14);

		add_last(deck, "Diamond", "2", 2); add_last(deck, "Diamond", "3", 3); add_last(deck, "Diamond", "4", 4); add_last(deck, "Diamond", "5", 5); add_last(deck, "Diamond", "6", 6); add_last(deck, "Diamond", "7", 7); add_last(deck, "Diamond", "8", 8);
		add_last(deck, "Diamond", "9", 9); add_last(deck, "Diamond", "10", 10); add_last(deck, "Diamond", "Jack", 11); add_last(deck, "Diamond", "Queen", 12); add_last(deck, "Diamond", "King", 13); add_last(deck, "Diamond", "Ace", 14);
	
};

void view_deck(linked_list*deck) {
	node*n = deck->head;
	
	while (n != nullptr)
	{
		cout  << n->face << " of " << n->type << ", "<<endl;
		n = n->next;
		
	}
}

void print_hand(linked_list*hand,linked_list*keep_hand) {
	node*n = hand->head;
	int letter = 0;
	while (n != nullptr)
	{
		cout << convert (letter+ getSize(keep_hand))<<  ": " << n->face << " of " << n->type  << endl;
		n = n->next;
		letter++;
	}

}

void print_keep_hand(linked_list* keep_hand, linked_list*hand) {
	node*n = keep_hand->head;
	int i;
	int letter = 0;
	
	while (n != nullptr)
	{
		cout <<convert (letter) << ": " << n->face << " of " << n->type << "-----(kept)"<< endl;
		n = n->next;
		letter++;
	}
}

// Universal var of money
int money = 5;

struct player {
	

	void print_money() {
		cout << endl << "Money: $" << money << endl;
	};

	void clear_hand() {
	}

};

//Random number
int random_index(int max) {

	return rand() % max;
}

//Random??
void get_Card(linked_list* deck, linked_list*hand)
{
	if (getSize(deck) == 0) {
		initial_deck(deck,hand);
		for (int i = 0; i < getSize(hand); i++) {

			for (int j = 0; j < getSize(deck); j++) {
				if (get_itemType(deck, j) == get_itemType(hand, i) && get_itemFace(deck, j) == get_itemFace(hand, i) && get_itemData(deck, j) == get_itemData(hand, i))
				{
					remove_item(deck, j);
				}
			}
		}
	}

		int index = random_index(getSize(deck));
	node playerCard = { get_itemType(deck, index), get_itemFace(deck, index), get_itemData(deck,index) };
	add_last(hand, get_itemType(deck, index), get_itemFace(deck, index), get_itemData(deck, index));
	remove_item(deck, index);

}

void fill_hand(linked_list*deck, linked_list*hand)
{
	for (int i = getSize(hand); i < 5; i++)
	{
		get_Card(deck, hand);
	}
}

//how many cards left in the deck
void check_cardsLeft(linked_list* deck) {
	cout << endl << "Cards left on deck: " << getSize(deck) << endl;
}

//player to choose which cards to keep
bool keep_Cards(linked_list* deck, linked_list* hand, linked_list*keep_hand)
{
	

	string input;
	cout << endl << "Enter the letter of the card you wish to keep: " << endl;
	cin >> input;
	if (input.length() > 5)
	{
		cout << endl << "Invalid Input, try again."<< endl;
		return false;
	}

	for (int i = 0; i < input.length(); i++) {
		if (input[i] < 'A' || input[i] > 'E') {
			cout << endl << "Invalid Input, try again." << endl;
			return false;
		}
	}

	
	if (input.find("A") != string::npos) {
		node kept_card = { get_itemType(hand, 0), get_itemFace(hand, 0), get_itemData(hand, 0) };
		add_last(keep_hand, get_itemType(hand, 0), get_itemFace(hand, 0), get_itemData(hand, 0));
	}

	if (input.find("B") != string::npos) {
		node kept_card = { get_itemType(hand, 1), get_itemFace(hand, 1), get_itemData(hand, 1) };
		add_last(keep_hand, get_itemType(hand, 1), get_itemFace(hand, 1), get_itemData(hand, 1));
	}

	if (input.find("C") != string::npos) {
		node kept_card = { get_itemType(hand, 2), get_itemFace(hand, 2), get_itemData(hand, 2) };
		add_last(keep_hand, get_itemType(hand, 2), get_itemFace(hand, 2), get_itemData(hand, 2));
	}

	if (input.find("D") != string::npos) {
		node kept_card = { get_itemType(hand, 3), get_itemFace(hand, 3), get_itemData(hand, 3) };
		add_last(keep_hand, get_itemType(hand, 3), get_itemFace(hand, 3), get_itemData(hand, 3));
	}

	if (input.find("E") != string::npos) {
		node kept_card = { get_itemType(hand, 4), get_itemFace(hand, 4), get_itemData(hand, 4) };
		add_last(keep_hand, get_itemType(hand, 4), get_itemFace(hand, 4), get_itemData(hand, 4));
	}

	// remove the same card from hand list
	for (int i = 0; i < getSize(keep_hand); i++) {
		
		for (int j = 0; j < getSize(hand); j++) {
			if (get_itemType(hand, j) == get_itemType(keep_hand, i) && get_itemFace(hand, j) == get_itemFace(keep_hand, i)&& get_itemData(hand,j)== get_itemData(keep_hand, i))
			{
				remove_item(hand, j);
			
			}
			
		}

	}

	//print_items(keep_hand);
	//print_items(hand);
	
	// replace them with new card

	for (int i = 0; i <getSize(hand); i++)
	{
		get_Card(deck, hand);
		remove_first(hand);
		
	}
 
  print_keep_hand(keep_hand, hand);
   print_hand(hand, keep_hand);
	
	if (getSize(hand) < 5) {
		for (int i = getSize(keep_hand)-1; i >= 0; i--)
		{
			add_first(hand, get_itemType(keep_hand, i), get_itemFace(keep_hand, i), get_itemData(keep_hand, i));
			remove_item(keep_hand, i);
		}
	}

	//cout << getSize(keep_hand);
	
	return money--;

}

//------------------------------------------------------------------------------------------------------
//swap card 
bool swap_card(linked_list*deck, linked_list*hand, linked_list*keep_hand) {
	cout << "Enter the letter of the card you want to swap: " << endl;
	string input; 
	cin >> input;
	while (!(input.length() == 1 && input[0] >= 'A' && input[0] <= 'E')) {
		cout << endl << "Invalid input, try again:";
		input.clear();
		cin >> input;
	}

	int index_to_delete = input[0] - 65;
	input.clear();
	cout << endl << "Now enter the face of the card you want (2,3,Jack,Queen, ect):";
	cin >> input;
	while (input != "2" && input != "3" && input != "4" && input != "5" && input != "6" && input != "7" && input != "8"
		&& input != "9" && input != "10" && input != "Jack" && input != "Queen" && input != "King" && input != "Ace") {
		cout << endl << "Invalid input, try again (2,3,Jack, ect):";
		input.clear();
		cin >> input;
	}
	string desired_face = input;
	input.clear();
	cout << endl << "Now enter the type of the card you want (Heart, Diamond, ect):";
	cin >> input;
	while (input != "Heart" && input != "Club" && input != "Diamond" && input != "Spade") {
		cout << endl << "Invalid input, try again (Heart, Diamond ect):";
		input.clear();
		cin >> input;
	}
	string desired_type = input;

	for (int i = 0; i < getSize(deck); i++) {
		node card = { get_itemType(deck, i), get_itemFace(deck, i), get_itemData(deck,i) };

		if (card.face == desired_face && card.type == desired_type) 
		{
			remove_item(hand, index_to_delete);
			add_last(hand, get_itemType(deck, i), get_itemFace(deck, i), get_itemData(deck, i));
			remove_item(deck, i);
			cout << endl << "Card swapped!" << endl;
			
		
			return true;
		}
	}


	cout << endl << "The card you want isn't in the deck" << endl;
	return false;

}

// check card conditions
bool check_flush(linked_list*hand)
{
	node card = {
		get_itemType(hand, 0), get_itemFace(hand, 0), get_itemData(hand, 0)

	};
	string target_type = card.type;
	for (int i = 1; i < 5; i++) {
		card = { get_itemType(hand, i), get_itemFace(hand, i), get_itemData(hand, i) };
		if (card.type != target_type) {
			return false;
		}
	}
	return true;
}



bool check_straight(linked_list*hand)
{
	int check_arr[15] = {};
	node card = {
		get_itemType(hand, 0), get_itemFace(hand, 0), get_itemData(hand, 0)
	};
	for (int i = 0; i < 5; i++) {
		node card = { get_itemType(hand, i), get_itemFace(hand, i), get_itemData(hand, i) };
		check_arr[card.data]++;
	}
	 
	for (int i = 0;  i < 15; i++) {
		if (check_arr[i] == 1 && check_arr[i + 1] == 1 && check_arr[i + 2] == 1 && check_arr[i + 3] == 1 && check_arr[i + 4] == 1) {
			
			return  true;
			break;
			
		}
		
	 }
	return false;
	
}

bool check_royal_straight(linked_list*hand)
{
	int check_arr[15] = {};
	node card = {
		get_itemType(hand, 0), get_itemFace(hand, 0), get_itemData(hand, 0)
	};
	for (int i = 0; i < 5; i++) {
		node card = { get_itemType(hand, i), get_itemFace(hand, i), get_itemData(hand, i) };
		check_arr[card.data]++;
	}

	for (int i = 10; i < 15; i++) {
		if (check_arr[i] == 1 && check_arr[i + 1] == 1 && check_arr[i + 2] == 1 && check_arr[i + 3] == 1 && check_arr[i + 4] == 1) {
			return true;
		}
	
	}
	return false;

}

bool check_four(linked_list*hand) {
	int check_arr[15] = {};
	for (int i = 0; i < 5; i++) {
		node card = { get_itemType(hand, i), get_itemFace(hand, i), get_itemData(hand, i) };
		check_arr[card.data]++;
	}
	for (int i = 0; i < 15; i++) {
		if (check_arr[i] >= 4) {
			return true;
		}
	}
	return false;

}

bool check_three(linked_list*hand) {
	int check_arr[15] = {};
	for (int i = 0; i < 5; i++) {
		node card = { get_itemType(hand, i), get_itemFace(hand, i), get_itemData(hand, i) };
		check_arr[card.data]++;
	}
	for (int i = 0; i < 15; i++) {
		if (check_arr[i] >= 3) {
			return true;
		}
	}
	return false;
}


bool check_twopair(linked_list*hand) {
	int check_arr[15] = {};
	int count = 0;
	for (int i = 0; i < 5; i++) {
		node card = { get_itemType(hand, i), get_itemFace(hand, i), get_itemData(hand, i) };
		check_arr[card.data]++;
	}
	for (int i = 0; i < 15; i++) {
		if (check_arr[i] >= 2) {
			count++;
		}
	}
	if (count >= 2) {
		return true;
	 }
	return false;
}

// Jack or higher
bool check_pair(linked_list*hand) {
	int check_arr[15] = {};
	for (int i = 0; i < 5; i++) {
		node card = { get_itemType(hand, i), get_itemFace(hand, i), get_itemData(hand, i) };
		check_arr[card.data]++;
	}
	for (int i = 11; i < 15; i++) {
		if (check_arr[i] >= 2) {
			return true;
		}
	}
	return false;
}

bool check_full(linked_list*hand) {
	int check_arr_full[15] = {};
	for (int i = 0; i < 5; i++) {
		node card = { get_itemType(hand, i), get_itemFace(hand, i), get_itemData(hand, i) };
		
		check_arr_full[card.data]++;
	
	}
	for (int i = 0; i < 15; i++) {

		if (check_arr_full[i] >= 3) {
			check_arr_full[i] = 0;
			
		}
	}

	for (int j = 0; j < 15; j++) {
		if (check_arr_full[j] >= 2 && check_arr_full[j]<3) {
			return true;
		}
		else {
			return false;
		}
	}

	
}

// Bonus: straight flush, royal flush and Full House
int check_hand(linked_list*hand) {
	if (check_flush(hand)) {
		if (check_straight(hand)) {
			for (int i = 0; i < 5; i++) {
				if (get_itemData(hand, i) == 14) {
					cout << "------You have a Royal flush!------" << endl;
					return money = money + 800;
				}
			} 
			cout << "------You have a straight flush!------" << endl;
			return money = money + 50;
		}
	
		cout << "------You have a flush!------" << endl;
		return money = money+6;
	}



	if (check_four(hand)) {
		cout << "------You have four of a kind!------" << endl;
		
		return money = money+25;
	}

	if (check_three(hand)) {
		if (check_full(hand)) {
			cout << "------You have a full house!------" << endl;
			return money = money + 9;

		}
		else {

			cout << "------You have three of a kind!------" << endl;

			return money = money + 3;
		}
		
	}

	

	if (check_pair(hand)) {
		if (check_twopair(hand)) {
			cout << "------You have two pairs!------" << endl;

			return money = money + 2;
		}
		cout << "------You have a pair of Jack or Higher!-------" << endl;
		
		return money = money+1;
	}

	if (check_twopair(hand)) {
		cout << "------You have two pairs!------" << endl;
		
		return money = money+2;
	}
	else {
		
		cout << "------Bad luck, you have nothing!-------" << endl;
	}

}



bool check_player_input(linked_list*deck, linked_list*hand, linked_list*keep_hand) {
	string input;

	cin >> input;
	if (input == "exit") { return false; }
	else if (input == "deck") {
		view_deck(deck);
		
	}
	else if (input == "swap") {
		if (swap_card(deck, hand, keep_hand)) {
			//keep_hand = hand;
			print_items(hand);
		}
		else {
			print_items(hand);
		}
		//check_hand(hand);
	    // hand = keep_hand;
		return true;
		
	}
	else if (input == "all") {
		print_items(hand);
		money--;
		check_hand(hand);
	/*	for (int i = 0; i < 5; i++) {
			remove_first(hand);
		}

		fill_hand(deck, hand);
		print_items(hand);*/
		return true;
	}
	else if (input == "none") {
		for (int i = 0; i < getSize(hand); i++) {
			get_Card(deck, hand);
			remove_first(hand);
		};
		
		print_items(hand);
		check_hand(hand);
		money--;
		return true;
		
	}
	else if (input == "keep") {
		if (keep_Cards(deck, hand, keep_hand)) {
			check_hand(hand);
		}
		
	/*	for (int i = 0; i < 5; i++) {
			remove_first(hand);
		}

		fill_hand(deck, hand);
		print_items(hand);*/
	//	hand = keep_hand;
		
	
		return true;
	}
	
	else {
		cout << endl << "Invalid input, try again: " << endl;
		return false;
	}

}


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF |
		_CRTDBG_LEAK_CHECK_DF);




	srand(time(NULL));
	linked_list* deck = create_linked_list();
	
	//print_deck(deck);
	//check_cardsLeft(deck);

	linked_list* hand = create_linked_list();
	initial_deck(deck, hand);
	linked_list* keep_hand = create_linked_list();
	fill_hand(deck, hand);
	print_hand(hand, keep_hand);
	//print_items(deck);

	//keep_Cards(deck, hand, keep_hand);
	cout << "----------------------------------------------------------------Now you have: $ " << money << endl;

	char input;
	bool gameplay = true;


	while (true) {
			print_menu();
			cout << "----Cards left in deck:" << getSize(deck) << endl;

			if (check_player_input(deck, hand, keep_hand)) {

				cout << "----------------------------------------------------------------Now you have: $ " << money << endl;
			}


			else {	
					break;
			}
			for (int i = 0; i < 5; i++) {
				remove_first(hand);
			}

			fill_hand(deck, hand);
			print_items(hand);

			cout << endl << "Hit ENTER to continue" << endl;
			cin.ignore(1000, '\n');
			cin.get();


			/*for (int i = 0; i < 5; i++) {
				remove_first(hand);
			}

			fill_hand(deck, hand);
			print_items(hand);*/

			if (money <= 0)
			{
				cout << endl << "Out of money. GAME OVER" << endl; system("PAUSE");
				clear(keep_hand);
				clear(deck);
				clear(hand);
				break;
			}

		};
	
	


	clear(keep_hand);
	clear(deck);
	clear(hand);

	//system("pause");
		
};

