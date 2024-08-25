#include<iostream>
#include<io.h>
#include<fcntl.h>
#include"ConsoleFunctions.h"


class PlayingCard
{
	int rank;
	int suit;
	char color;
	wstring symbol;
	bool faceUp;
	bool top;

public :

	static const int Diamond = 0;
	static const int Heart = 1;
	static const int Spade = 2;
	static const int Club = 3;

	PlayingCard(int r = 1, int s = 0)
	{
		faceUp = true;
		top = true;

		
		if (s < 0 || s > 3)
		{
			while (true)
			{
				cout << "Wrong Suit!!" << endl;
				cout << "Enter 0 for Diamond" << endl;
				cout << "Enter 1 Heart" << endl;
				cout << "Enter 2 Spade" << endl;
				cout << "Enter 3 Club" << endl;
				cout << "Enter suit : ";
				cin >> s;
				if (s >= 0 && s <= 3)
				{
					break;
				}
			}
		}
		if (r < 1 || r > 13)
		{
			while (true)
			{
				cout << "Wrong Rank!!" << endl;
				cout << "Enter 1-13 for Apropriate Rank : " << endl;
				cout << "Enter rank : ";
				cin >> r;
				if (r > 0 && r < 14)
				{
					break;
				}
			}
		}
		if (s == 0 || s == 1)
		{
			rank = r;
			suit = s;
			color = 'r';
			if (s == 0)
			{
				symbol = L"\u2666";//diamond 
			}
			else
			{
				symbol = L"\u2665";//heart
			}
		}
		else
		{
			rank = r;
			suit = s;
			color = 'b';
			if (s == 2)
			{
				symbol = L"\u2660"; //spade
			}
			else
			{
				symbol = L"\u2663";//club 
			}
		}
		
	}

	void display(int x, int y)
	{

		if (faceUp && top)
		{
			ConsoleFunctions c;
			c.SetCursorAt(x, y);
			if (color == 'r')
			{
				c.SetColor(12, 15);
			}
			else
			{
				c.SetColor(0, 15);
			}

			int m = 7;
			if (rank == 10)
			{
				m = 6;
			}
			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (j == 0 && i == 1)
					{
						if (rank == 1)
						{
							cout << "A";
						}
						else if (rank == 11)
						{
							cout << "J";
						}
						else if (rank == 12)
						{
							cout << "Q";
						}
						else if (rank == 13)
						{
							cout << "K";
						}
						else
						{
							if (rank == 10)
							{
								j++;
							}
							cout << rank;
						}
					}
					else if (j == 2 && i == 1)
					{
						_setmode(_fileno(stdout), _O_U8TEXT);
						wcout << symbol;
						_setmode(_fileno(stdout), _O_TEXT);
					}
					else if (j == 5 && i == 6)
					{
						_setmode(_fileno(stdout), _O_U8TEXT);
						wcout << symbol;
						_setmode(_fileno(stdout), _O_TEXT);
					}
					else if (j == m && i == 6)
					{
						if (rank == 1)
						{
							cout << "A";
						}
						else if (rank == 11)
						{
							cout << "J";
						}
						else if (rank == 12)
						{
							cout << "Q";
						}
						else if (rank == 13)
						{
							cout << "K";
						}
						else
						{
							cout << rank;
							if (rank == 10)
							{
								j++;
							}
						}
					}
					else
					{
						c.writeCharOnConsole(' ');
					}


				}
				c.SetCursorAt(x, y + i);
			}
		}
		else if (faceUp && !top)
		{
			ConsoleFunctions c;
			c.SetCursorAt(x, y);
			if (color == 'r')
			{
				c.SetColor(12, 15);
			}
			else
			{
				c.SetColor(0, 15);
			}

			int m = 7;
			if (rank == 10)
			{
				m = 6;
			}
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (j == 0 && i == 1)
					{
						if (rank == 1)
						{
							cout << "A";
						}
						else if (rank == 11)
						{
							cout << "J";
						}
						else if (rank == 12)
						{
							cout << "Q";
						}
						else if (rank == 13)
						{
							cout << "K";
						}
						else
						{
							if (rank == 10)
							{
								j++;
							}
							cout << rank;
						}
					}
					else if (j == 2 && i == 1)
					{
						_setmode(_fileno(stdout), _O_U8TEXT);
						wcout << symbol;
						_setmode(_fileno(stdout), _O_TEXT);
					}
					else
					{
						if (i == 2)
						{
							cout << "_";
						}
						else
						{
							c.writeCharOnConsole(' ');
						}
						
					}


				}
				c.SetCursorAt(x, y + i);
			}
		}
		else if (!faceUp && top)
		{
			ConsoleFunctions c;
			c.SetCursorAt(x, y);

			c.SetColor(12, 12);

			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					c.writeCharOnConsole(' ');
				}
				c.SetCursorAt(x, y + i);
			}
		}
		else if (!faceUp && !top)
		{
			ConsoleFunctions c;
			c.SetCursorAt(x, y);

			c.SetColor(0, 12);

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (i == 2)
					{
						cout << "_";
					}
					else
					{
						c.writeCharOnConsole(' ');
					}
				}
				
				c.SetCursorAt(x, y + i);
			}

		}
		

	}

	bool isFaceUp()
	{
		return faceUp;
	}

	void setFaceUp(bool a)
	{
		faceUp = a;
	}

	bool isTop()
	{
		return top;
	}

	void setTop(bool a)
	{
		top = a;
	}

	int getRank()
	{
		return rank;
	}

	int getSuit()
	{
		return suit;
	}

	char getColor()
	{
		return color;
	}
};

class PileofCards
{
	PlayingCard* pile;
	int top;
	int size;
	point startPt;
	point endPt;
public:
	PileofCards(int size = 0)
	{
		pile = new PlayingCard[size];
		this->size = size;
		top = -1;
		startPt.x = 0;
		endPt.x = 0;
		startPt.y = 0;
		endPt.y = 0;
	}

	~PileofCards()
	{
		delete[] pile;
	}

	int getTop()
	{
		return top;
	}

	point getStartPt()
	{
		return startPt;
	}

	void setStartPt(int x, int y)
	{
		startPt.x = x;
		startPt.y = y;
	}

	point getEndPt()
	{
		return endPt;
	}

	void setEndPt(int x, int y)
	{
		endPt.x = x;
		endPt.y = y;
	}

	PileofCards& operator = (const PileofCards& poc)
	{
		if (this != &poc)
		{
			top = poc.top;
			size = poc.size;
			startPt = poc.startPt;
			endPt = poc.endPt;
			for (int i = 0; i <= top; i++)
			{
				pile[i] = poc.pile[i];
			}
		}
		return *this;
	}

	PlayingCard viewCard(int i)
	{
		return pile[i];
	}

	void simpleDisplay()
	{
		if (top != -1)
		{
			pile[top].display(startPt.x, startPt.y);
		}
		else
		{
			ConsoleFunctions c;
			c.SetCursorAt(startPt.x, startPt.y);

			c.SetColor(10, 10);

			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					c.writeCharOnConsole(' ');
				}
				c.SetCursorAt(startPt.x, startPt.y + i);
			}
		}
		
	}

	void cascadingDisplay()
	{
		if (top != -1)
		{
			int y = startPt.y;
			for (int i = 0; i <= top; i++)
			{
				pile[i].display(startPt.x, y);
				y += 2;
			}
		}
		else
		{
			ConsoleFunctions c;
			c.SetCursorAt(startPt.x, startPt.y);

			c.SetColor(10, 10);

			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					c.writeCharOnConsole(' ');
				}
				c.SetCursorAt(startPt.x, startPt.y + i);
			}
		}
	}

	PlayingCard Peek()
	{
		return pile[top];
	}

	PlayingCard Remove()
	{
		if (top == -1)
		{
			cout << "Pile is Empty!" << endl;
			return NULL;
		}
		else
		{
			top--;
			if (top != -1)
			{
				pile[top].setTop(true);
				
			}
			return pile[top + 1];
		}
	}

	void Add(PlayingCard& obj)
	{
		if (top < size - 1)
		{
			top++;
			pile[top] = obj;
			pile[top].setTop(true);
			if (top != 0)
			{
				pile[top - 1].setTop(false);
			}
			
		}
		else
		{
			cout << "Pile is Full!!" << endl;
		}
	}

	bool IsEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool IsFull()
	{
		if (top == size-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class Deck
{
	PlayingCard* deck[52];
	int size;
public:
	Deck()
	{
		
		size = 52;
		int i = 0;
			for (int j = 1; j < 14; j++,i++)
			{
				deck[i] = new PlayingCard(j, PlayingCard::Diamond);
			}
			for (int j = 1; j < 14; j++, i++)
			{
				deck[i] = new PlayingCard(j, PlayingCard::Heart);
			}
			for (int j = 1; j < 14; j++, i++)
			{
				deck[i] = new PlayingCard(j, PlayingCard::Spade);
			}
			for (int j = 1; j < 14; j++, i++)
			{
				deck[i] = new PlayingCard(j, PlayingCard::Club);
			}
	}
	int getSize()
	{
		return size;
	}
	bool IsEmpty()
	{
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	PlayingCard Remove(int j)
	{
		if (size == 0)
		{
			cout << "Deck is Empty!" << endl;
			return NULL;
		}
		else
		{
			PlayingCard temp = *deck[j];
			delete deck[j];
			for (int i = j; i < size; i++)
			{
				deck[i] = deck[i + 1];
			}
			size--;
			return temp;
		}
	}
	~Deck()
	{
		for (int i = 0; i < size; i++)
		{
			delete deck[i];
		}
	}
};

class Solitaire
{
	Deck deckofCards;
	PileofCards stock;
	PileofCards waste;
	PileofCards home[4];
	PileofCards playingPile[7];
	ConsoleFunctions cf;
public:

	Solitaire() : stock(52), waste(52),home{13,13,13,13}, playingPile{ 14,15,16,17,18,19,20}
	{
		
		stock.setStartPt(3,2);
		stock.setEndPt(3+8,2+6);
		waste.setStartPt(14, 2);
		waste.setEndPt(14 + 8, 2 + 6);

		home[0].setStartPt(30, 2);
		home[0].setEndPt(30 + 8, 2 + 6);
		home[1].setStartPt(42, 2);
		home[1].setEndPt(42 + 8, 2 + 6);
		home[2].setStartPt(54, 2);
		home[2].setEndPt(54 + 8, 2 + 6);
		home[3].setStartPt(66, 2);
		home[3].setEndPt(66 + 8, 2 + 6);

		playingPile[0].setStartPt(2, 12);
		playingPile[0].setEndPt(2 + 8, 12 + 6);
		playingPile[1].setStartPt(14, 12);
		playingPile[1].setEndPt(14 + 8, 12 + 6);
		playingPile[2].setStartPt(26, 12);
		playingPile[2].setEndPt(26 + 8, 12 + 6);
		playingPile[3].setStartPt(38, 12);
		playingPile[3].setEndPt(38 + 8, 12 + 6);
		playingPile[4].setStartPt(50, 12);
		playingPile[4].setEndPt(50 + 8, 12 + 6);
		playingPile[5].setStartPt(62, 12);
		playingPile[5].setEndPt(62 + 8, 12 + 6);
		playingPile[6].setStartPt(74, 12);
		playingPile[6].setEndPt(74 + 8, 12 + 6);
	}

	void shuffle()
	{		
		int i;
		
		while (!deckofCards.IsEmpty())
		{
			i = rand() % deckofCards.getSize();
			PlayingCard c = deckofCards.Remove(i);
			c.setFaceUp(false);
			stock.Add(c);
		}
	}

	void dealToPlayingPiles()
	{
		PlayingCard p;
		for (int i = 0; i < 7; i++)
		{
			for (int  j = 0; j <= i; j++)
			{
				p = stock.Remove();
				if (j==i)
				{
					p.setFaceUp(true);
				}
				playingPile[i].Add(p);
			}
			
					
		}
	}

	void displayGame()
	{
		stock.simpleDisplay();
		waste.simpleDisplay();

		for (int i = 0; i < 4; i++)
		{
			home[i].simpleDisplay();
		}
		
		for (int i = 0; i < 7; i++)
		{
			playingPile[i].cascadingDisplay();
		}
	}

	~Solitaire()
	{

	}

};


int main()
{

	Solitaire s;
	s.shuffle();
	s.dealToPlayingPiles();
	s.displayGame();
	/*PlayingCard c1(2,3);
	c1.display(0,0);
	PlayingCard c2(1,2);
	PlayingCard c3(10,0);
	PlayingCard c4(10,1);
	PlayingCard c5(13,0);
	PileofCards p(5);
	p.simpleDisplay();
	system("pause");
	p.Add(c1);
	p.Add(c2);
	p.Add(c3);
	p.Add(c4);
	p.Add(c5);
	p.cascadingDisplay();*/
	//system("pause");
	//Deck D1;
	//PlayingCard A(0, 0);
	//int y = 0;
	//A = D1.Remove(0);
	//A.display(0, y);
	//y = y + 10;
	//A = D1.Remove(0);
	//A.display(0, 10);
	//y = y + 10;
	//A = D1.Remove(0);
	//A.display(0, 20); // three cards removed
	//y = y + 10;
	//system("pause");
	//while (!D1.IsEmpty())
	//{
	//	A = D1.Remove(0);
	//	A.display(0, y);
	//	y = y + 2;
	//}
	return 0;
}