#pragma once
class snake // snake class
{
public:
	int x; // Variable declaration
	int y; // Variable declaration
	char direction; // Variable declaration
	snake* next; // Pointer Variable declaration

	snake(); // constructor
	~snake(); // destructor
};

class food // food class
{
public:
	int fx; // Variable declaration
	int fy; // Variable declaration

	food(); // constructor
	~food(); // destructor
};

// Snake header file functions
void CreateSnake(snake** SnakeHead); // Function to create starting snake
void MoveSnake(UINT SetMove, snake *SnakeHead); // Function that move snake
BOOL CrashBody(const snake *SnakeHead); // Function when snake crash to body
BOOL EatFood(snake** SnakeHead, food* Food); // Function that changes when a snake eats its food
BOOL CrashWall(snake* SnakeHead); // Function when snake crash to wall
void CreateFood(food** Food); // Function to create first food

snake::snake() // constructor
{
	x = 0; // Initialize value
	y = 0; // Initialize value
	direction = '0'; // Initialize value
	next = NULL; // Initialize value
}

snake::~snake() {} // destructor
 
food::food() // constructor
{
	fx = 0; // Initialize value
	fy = 0; // Initialize value
}

food::~food() {} // destructor

void CreateSnake(snake **SnakeHead)
{
	snake* curr; // Declaring Pointer Variables
	snake* NewNode; // Declaring Pointer Variables
	
	curr = (*SnakeHead); // Save variable

	for (int i = 0; i <= 3; i++)
	{
		if (curr == NULL) //This function Saves information to Head
		{
			NewNode = new snake;
			NewNode->direction = 'A'; //Starting direction is left
			NewNode->x = 25 / 2 + i; //The information of position
			NewNode->y = 25 / 2; //The information of position
			(*SnakeHead) = NewNode; //Save newNode to Head
			curr = (*SnakeHead);
		}

		else if (curr != NULL)
		{
			NewNode = new snake;
			NewNode->direction = 'A'; //Starting direction is left
			NewNode->x = 25 / 2 + i; //The information of position
			NewNode->y = 25 / 2 ; //The information of position
			curr->next = NewNode;
			curr = curr->next; // Load the next node
			curr->next = NULL; 
		}
	}
}

void CreateFood(food** Food) // The function to create first food
{
	srand((unsigned)time(NULL)); // Random number generation condition
	(*Food) = new food; // Memory dynamic allocation

	(*Food)->fx = rand() % 25 ; // x coordinate of food
	(*Food)->fy = rand() % 25 ; // y coordinate of food
}

void MoveSnake(UINT nChar, snake *SnakeHead) // The function that move snake
{
	snake *curr = SnakeHead; // Declaring Pointer Variables
	UINT Front; // Declaring UNIT Variables
	int Back; // Declaring Variables

	Front = SnakeHead->direction; 

	if (nChar != NULL) // Snake move condition statement
	{
		SnakeHead->direction = nChar; // Save direction
	}

	while (curr->next != NULL) // Loops for direction
	{
		curr = curr->next; // Load the next node
		Back = curr->direction; // Save current node orientation
		curr->direction = Front; // Switch to the direction of all nodes
		Front = Back; // Store the direction of the current node in a variable
	}

	curr = SnakeHead; // store head node
	while (curr != NULL) // A loop that changes direction from head to tail
	{
		switch (curr->direction) // information transfer
		{
		case 'S':
		case 's': //down
			curr->y += 1; // Save variable
			break; // escaping condition
		case 'W':
		case 'w': //up
			curr->y -= 1; // Save variable
			break; // escaping condition
		case 'A':
		case 'a': //left
			curr->x -= 1; // Save variable
			break; // escaping condition
		case 'D':
		case 'd' : //right
			curr->x += 1; // Save variable
			break; // escaping condition
		}
		curr = curr->next; // load next node
	}
}

BOOL EatFood(snake** SnakeHead, food* pFood) // The function that changes when the snake eats food
{
	snake* NewHead; // Declaring Pointer Variables
	snake* SnakeCurr = *SnakeHead; // Declaring Pointer Variables
	int flag = 0; // Declaring Variables

	if ((*SnakeHead)->y != pFood->fy || (*SnakeHead)->x != pFood->fx) // when the snake have not eaten
		return FALSE; // return FALSE
	
	NewHead = new snake; // Memory dynamic allocation
	NewHead->direction = (*SnakeHead)->direction; // Save orientation of existing head

	NewHead->x = pFood->fx ; //Save information of food position to New Node
	NewHead->y = pFood->fy ; //Save information of food position to New Node

	switch (NewHead->direction) //Switch function for position of newly created head
	{
	case 'S': // down
	case 's': 
		NewHead->y += 1; // Save variable
		break; // escaping condition
	case 'W': //  up
	case 'w': 
		NewHead->y -= 1; // Save variable
		break; // escaping condition
	case 'A':  // left
	case 'a':
		NewHead->x -= 1; // Save variable
		break; // escaping condition
	case 'D': // right
	case 'd': 
		NewHead->x += 1; // Save variable
		break; // escaping condition
	}

	NewHead->next = *SnakeHead; // Increase head side when eating food
	*SnakeHead = NewHead; // Save new head
	while(1)
	{
		pFood->fx = (rand() % 25)  ; // x Coordinates of new food when feeding 
		pFood->fy = (rand() % 25) ; // y Coordinates of new food when feeding 
		
		flag = 0; // Save variable
		SnakeCurr = *SnakeHead;
		while(SnakeCurr !=NULL)
		{
			if (SnakeCurr->x == pFood->fx && SnakeCurr->y == pFood->fy) // When the food overlaps the snake's body
			{
				flag = 1; // Save variable
				break; // escape loop
			}
			SnakeCurr = SnakeCurr->next; // load next node
		}

		if (flag == 0)
			break;
	} 
	return TRUE; // return TRUE
}

BOOL CrashWall(snake* SnakeHead) // Functions when snakes crash to wall
{
	if (!(SnakeHead->x >= 0 && SnakeHead->x < 25) || !(SnakeHead->y >= 0 && SnakeHead->y < 25)) // condition for crashing wall
	{
		return TRUE; // return TRUE
	}
	return  FALSE; // return FALSE
}

BOOL CrashBody(const snake *SnakeHead) // Functions when snakes crash to body
{
	snake* curr = SnakeHead->next; // Declaring Pointer Variables

	while (curr != NULL) // escape loop when curr is NULL
	{
		if (curr->x == SnakeHead->x && curr->y == SnakeHead->y) // When the coordinates are same
		{
			return TRUE; // return TRUE
		}
		curr = curr->next; // load next node
	}
	return FALSE; // return FALSE
}