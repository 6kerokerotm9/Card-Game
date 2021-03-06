#include <iostream>
#include <iomanip>
#include <fstream>
#include <thread>
#include <chrono>
struct node {
  char suit;
  int number;
  node * next;
};

//checks to see if empty
bool isEmpty(int counter) {
  if(counter == 0) { 
    return true;
  }
  return false;
}

//push function
void push_deck(node array[], int & counter, char input, int value) {
  if(counter == 30) { //if the queue reaches the max size
    counter = 0; //reset the counter
    array[counter].suit = input;
    array[counter].number = value;
    array[counter].next = NULL; //set the next pointer back to the beginning of the queue
    counter++;
  }
  else {
    array[counter].suit = input;
    array[counter].number = value;
    array[counter].next = new node;
    counter++;
  }
}

void push(node* &tail, node* &first, int &counter, int size, char input, int value)
{  
    if(counter == size-1) { //checks to see if the tail reaches hand size
      tail->next = first;
      tail->suit = input; 
      tail->number = value;
      tail = tail->next; //sets tail back to the first spot in the hand
      counter++;
    }
    else{
      if(counter == size) {
          counter = 0;
      }
      tail->suit = input; 
      tail->number = value;
      tail->next = new node; 
      tail = tail->next;
      counter++;
    }
}

void push_stack(node* &tail, node* &first, int &counter, char input, int value)
{  
    if(counter == 0) { //checks to see if the tail reaches hand size
      tail->suit = input; 
      tail->number = value;    
      tail->next = new node;
      //tail = tail->next; //sets tail back to the first spot in the hand
      counter++;
    }
    else{
      tail = tail->next;
      tail->suit = input; 
      tail->number = value;
      tail->next = new node; 
      //tail = tail->next;
      counter++;
    }
}

node pop_deck(node array[], int & head) {
  node temp = array[head];
  head++;
  return temp; //return the node that was the head
}

void pop_hand(node * &head, node * &first) {
  /*if(head->next == NULL) {
    head = first;
  }
  else {*/
    head = head->next;
  //}
}

void pop_stack(node* &tail,node* &head,int sort_counter){
     if (isEmpty(sort_counter)) //check if empty list
    {
        std::cout << "Empty" << std::endl;
        return;

    }
    else if(head == tail) //identical case to queue, if there is 1 node left
    {
        delete head;
        head = tail = NULL;
    }
    node* temp = tail; //now we have a temporary node set equal to the current tail
    tail = head; //because temp is now at tail, we can change tail to equal head (back to beginning of list)
    while (tail->next != temp) //this will iterate through the linked list until just before the current temp
    { //which temp is now in previous tail's pos, or at last of list
        tail = tail->next; // set tail equal to the node before the last of the list for future pop
    }
    tail->next = NULL; // unlink the very last node because temp is already that node
    delete temp; // now delete temp since we had stored in the data char
}


//opens file and fills up the deck
void parse(node array[], int &tail) { 
  std::ifstream in;
  char s; //placeholders for values
  int n; 
  in.open("deck2"); //opens the file
  std::string garbageline; //holds the first line so it can be ignored
  if(in.fail()) {
    std::cout << "Cannot open the file." << std::endl;
    return; 
  }
  else {
    std::getline(in, garbageline); //ignores the first line
    for(int i=0;i<30;i++) { //reads the file line by line and fills up the array with the data
      in >> s;
      in >> n;
      push_deck(array, tail, s, n); //uses push to fill up the deck
    }
  }
}

//prints out the array 
void print(node deck[], int counter, int size) {
  for(int i=0;i<size;i++) { 
    if(counter == size) {
      counter = 0;
    }
    std::cout << deck[counter].suit << " " << deck[counter].number;
    counter++;
    std::cout << std::endl;
    //head = head->next;
  }
}

//print for hands or anything using linked lists
void print(node * head, int size, node * first) {
	std::cout << "| "; 
  for(int i=0;i<size;i++) { 
    std::cout << head->suit << head->number << " | ";
    head = head->next;
  }
  std::cout << std::endl;
}

void load(std::string a) //Loading animation
{
	std::string dot[] = {".", ". .", ". . ."};
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			std::cout << a << dot[i] << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
			system("clear");
		}
	}
}


int main() {
  int choice;
  int choice2; 
  int size_deck = 30; //max deck size 
  int left = 30; //used for the game later to count how many cards are in the deck
  int size_hand = 5;
  int actions = 5; //amount of cards left in hand basically
  int turn = 1; // number of turns 
  
  //initializes decks
  node deck[size_deck]; //ring buffer array for deck 
  int head_deck = 0; //effective head pointer for the deck
  int tail_deck = 0; //next availible place to put values in the deck
  parse(deck, tail_deck); //fills up the deck
  
  //initialize hand
  node * first_hand = new node; //already have new node as temp in function
  node * head_hand = first_hand; //head of the queue used to pop values
  node * tail_hand = first_hand; //tail of the queue used to store values
  int counter_hand = 0; 
  
  //3 sorting stack nodes initialize
	//node* head = new node;
	node* headA = NULL;
	node* tailA = new node;
    //    node* topA = new node;	

	node* headB = NULL;
	node* tailB = new node;
    //    node* topB = new node;	

	node* headC = NULL;
	node* tailC = new node;
    //    node* topC = new node;        

        //initialize these for later use
        tailA->number = 0;
        tailB->number = 0;
        tailC->number = 0;

	// 5 sorting stack nodes initialize
	node* headO1 = NULL;
	node* tailO1 = new node;
    //    node* topO1 = new node;
	node* headO2 = NULL;
	node* tailO2 = new node;
    //    node* topO2 = new node;
	node* headO3 = NULL;
	node* tailO3 = new node;
    //    node* topO3 = new node;
	node* headO4 = NULL;
	node* tailO4 = new node;
    //    node* topO4 = new node;	
	node* headO5 = NULL;
	node* tailO5 = new node;
    //    node* topO5 = new node;
	int counter_sort = 0;
	int iA,iB,iC; //suit A,B,C counters for sort full

  //sort algorithm - determines which stack user wants to put card in and will only allow user to put in card numbers
  //1 less than current value at top of respective sorting stacks
 
  load("Drawing");
  for(int i=0; i<5; i++) {
    push(tail_hand, first_hand, counter_hand, size_hand, deck[head_deck].suit, deck[head_deck].number);
    pop_deck(deck, head_deck);
    left--;
  }
  bool game_end = false;
	while(game_end == false)
	{ 
                
                std::cout << "Hand: " << std::endl;
                print(head_hand, actions, first_hand); //pass actions so prints just the right amount of cards
                std::cout << "1: To enter your card into sorted pile (final product)" << std::endl;
                std::cout << "2: To enter your card into a sorting space" << std::endl;
                std::cout << "3: To place first card in hand back into bottom of deck." << std::endl;
                std::cout << "4: To place first card in sorting space to sorted pile." << std::endl;
                std::cout << "5: To quit (but not on the first turn)." << std::endl;
                std::cin >> choice; //menu options
		std::cout << "TURN " << turn << std::endl;
                switch(choice) {
		case 1:
                  system ("clear");
                  print(head_hand, actions, first_hand);
                  while(true) {
                    std::cout << "Choose either pile 1: A, 2: B, 3: C, or 4 to quit (pick the number that corresponds to suit)." << std::endl;
                    std::cin >> choice2; 
                    if(choice2 == 1) {
                      if(iA == 10) // 10 values per suit
		      {
			std::cout << "Stack A is full!" << std::endl;
			//return; redo the push
		      }
		      else if(tail_hand->suit == 'B' || tail_hand->suit == 'C')
		      {
			std::cout << "Wrong card type" << std::endl;
			//return; redo the push
		      }
		      else if(tail_hand->number != (tailA->number)+1)
		      {
			std::cout << "Not sorted correctly!" << std::endl;
			//return; redo push
		      }
              else {
		  	  iA++;
              push_stack(tailA,headA,counter_sort, head_hand->suit, head_hand->number); //make the stack huge
              pop_hand(head_hand, first_hand);//pop hand 
                        actions--;
                        break;
                      }
                    }
		    else if (choice2 == 2)
		    {
			if(iB == 10) // 10 values per suit
			{
				std::cout << "Stack B is full!" << std::endl;
				//return; redo the push
			}
			else if(tail_hand->suit == 'A' || tail_hand->suit == 'C')
			{
				std::cout << "Wrong card type" << std::endl;
				//return; redo the push
			}
			else if(tail_hand->number != (tailB->number)+1)
			{
				std::cout << "Not sorted correctly!" << std::endl;
				//return; redo push
			}
                        else{
			  iB++;
			  push_stack(tailB,headB,counter_sort, tail_hand->suit, tail_hand->number);
			  pop_hand(head_hand, first_hand);//pop
                          actions--;
                          break;
                        }
		    }
		    else if (choice2 == 3)
		    {
			if(iC == 10) //10 values per suit
			{
				std::cout << "Stack A is full!" << std::endl;
				//return; redo the push
			}
			else if(tail_hand->suit == 'B' || tail_hand->suit == 'A')
			{
				std::cout << "Wrong card type" << std::endl;
				//return; redo the push
			}
			else if(tail_hand->number != (tailC->number)+1)
			{
				std::cout << "Not sorted correctly!" << std::endl;
				//return; redo push
			}
                        else{ //exception handling
			  iC++;
              push_stack(tailC,headC,counter_sort, tail_hand->suit,tail_hand->number);
			  pop_hand(head_hand, first_hand);//pop
                          actions--;
                          break;
		        }
                      }
                      else if(choice2 == 4) {
                        break;
                      }
                      else{ //exception handling
                        std::cin.clear(); //clears the stream
                        std::cin.ignore(); //ignores the rest of the values in the stream
                        std::cout << "Invalid input, please try again." << std::endl;
                        choice2 = 0;
                      }
                    }
                    break; 
                case 2: 
                	system ("clear");
                	print(head_hand, actions, first_hand);
                	std::cout << "Choose a sorting pile from 1-5" << std::endl;
                        int sort_choice;
                        std::cin >> sort_choice;
                        if(sort_choice == 1) // push hand into sorting stack 1
                        {
	                  if(tailO1->number == 0) // if nothing in stack, set number to 1 higher than input
	                  {
		            tailO1->number = (tail_hand->number)+1;
	                  }
	                  if(tail_hand->number = (tailO1->number)+1) // must be lower value than card currently in stack
	                  {  
	                    push_stack(tailO1,headO1,counter_sort,head_hand->suit,head_hand->number);
                            pop_hand(head_hand, first_hand);
                            actions--;
		          }
		          else
		          {
			      std::cout << "Not a valid value to be placed" << std::endl;
			      break; // return back to sort menu
		          }	  
                        }
			else if(sort_choice == 2)
                        {
	                  if(tailO2->number == 0) // if nothing in stack, set number to 1 higher than input
	                  {
		            tailO2->number = (tail_hand->number)+1;
	                  }
	                  if(tail_hand->number = (tailO2->number)+1) // must be lower value than card currently in stack
	                  {  
	                    push_stack(tailO2,headO2,counter_sort,head_hand->suit,head_hand->number);
                            pop_hand(head_hand, first_hand);
                            actions--;
		          }
		          else
		          {
			    std::cout << "Not a valid value to be placed" << std::endl;
			    break; // return back to sort menu
		          }	  
                        }
                        else if(sort_choice == 3)
                        {
	                  if(tailO3->number == 0) // if nothing in stack, set number to 1 higher than input
	                  {
		            tailO3->number = (tail_hand->number)+1;
	                  }
	                  if(tail_hand->number = (tailO3->number)+1) // must be lower value than card currently in stack
	                  {  
	                    push_stack(tailO3,headO3,size_hand,head_hand->suit,head_hand->number);
                            pop_hand(head_hand, first_hand);
                            actions--;
		          }
		          else
		          {
			      std::cout << "Not a valid value to be placed" << std::endl;
			      break; // return back to sort menu
		          }	  
                        }
                        else if(sort_choice == 4)
                          {
	                    if(tailO4->number == 0) // if nothing in stack, set number to 1 higher than input
	                    {
		              tailO4->number = (tail_hand->number)+1;
	                    }
	                    if(tail_hand->number = (tailO4->number)+1) // must be lower value than card currently in stack
	                    {  
	                      push_stack(tailO4,headO4,counter_sort,head_hand->suit,head_hand->number);
                              pop_hand(head_hand, first_hand);
                              actions--;
		            }
		            else
		            {
			      std::cout << "Not a valid value to be placed" << std::endl;
			      break; // return back to sort menu?
		            }	  
                           }
                           else if(sort_choice == 5)
                           {
	                     if(tailO5->number == 0) // if nothing in stack, set number to 1 higher than input
	                     {
		               tailO5->number = (tail_hand->number)+1;
	                     }
	                     if(tail_hand->number = (tailO5->number)+1) // must be lower value than card currently in stack
	                     {  
	                       push_stack(tailO5,headO5,counter_sort,head_hand->suit,head_hand->number);
                               pop_hand(head_hand, first_hand);
                               actions--;
		             }
		             else
		             {
			       std::cout << "Not a valid value to be placed" << std::endl;
			       break; // return back to sort menu?
		             }	  
                           }
                           break;
		case 3: 
			system ("clear");
			print(head_hand, actions, first_hand);
			std::cout << "Putting the card in the bottom of the deck." << std::endl;
			push_deck(deck, tail_deck, head_hand->suit, head_hand->number); // suit and number comes from hand on all of these
			pop_hand(head_hand, first_hand);//pop hand that was sent to deck
                        actions--;
                        left++; //adds to the cards in the deck
		        break;
                
		case 4: 
			   system ("clear");
			   print(head_hand, actions, first_hand);
			   std::cout << "Which stack would you like to take from(1-5): " << std::endl;
			   std::cin >> choice2;
			   
		case 5:
				system ("clear");
				if(turn == 1) {
				  std::cout << "Can't quit on turn 1!" << std::endl;
				  break;
				}
			game_end = true; 
				break;
		default: 
				system ("clear");
				std::cin.clear();
				std::cin.ignore();
			std::cout << "Invalid input, please try again." << std::endl;
			choice = 0;
				break;
	 }
             if(actions == 0) { 
  	       std::cout << "Sorted Stacks: ";
  	       std::cout << "| " << tailA->suit << tailA->number << " | " << tailB->suit << tailB->number << " | " << tailC->suit << tailC->number << " | ";
  	       std::cout << "                Temporary Stacks: " << tailO1->suit << tailO1->number << " | " << tailO2->suit << tailO2->number << " | " << tailO3->suit << tailO3->number << " | ";
  	       std:: cout << tailO4->suit << tailO4->number << " | " << tailO5->suit << tailO5->number << " | " << std::endl;
 
                turn++;
                load("Drawing");
                for(int i=0; i<5; i++) {
                  push(tail_hand, first_hand, counter_hand, size_hand, deck[head_deck].suit, deck[head_deck].number);
                  pop_deck(deck, head_deck);
                  left--;
                  actions = 5;
                }
             }
	      if(left == 0) //if the deck is empty and the hand is empty
              {
		game_end = true;
              }//end game	
	}
}
