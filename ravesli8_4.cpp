// ravesli6_6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <array>

using namespace std;



class Card
{
public:
    enum SUIT
    {
        SUIT_clubs,
        SUIT_diamonds,
        SUIT_hearts,
        SUIT_spades,
        SUIT_num
    };

    enum VALUE
    {
        VALUE_2 = 0,
        VALUE_3,
        VALUE_4,
        VALUE_5,
        VALUE_6,
        VALUE_7,
        VALUE_8,
        VALUE_9,
        VALUE_10,
        VALUE_Jack,
        VALUE_Queen,
        VALUE_King,
        VALUE_Ace,
        VALUE_num
    };
private:
    SUIT m_suit;
    VALUE m_val;

public:
    Card(SUIT suit = SUIT_num, VALUE val = VALUE_num) :m_suit(suit), m_val(val)
    {}
    void printCard() const
    {
        switch (m_suit)
        {
        case SUIT_clubs:
            cout << "C";
            break;
        case SUIT_diamonds:
            cout << "D";
            break;
        case SUIT_hearts:
            cout << "H";
            break;
        case SUIT_spades:
            cout << "S";
            break;
        default:
            cout << "error!";
            break;
        }

        switch (m_val)
        {
        case VALUE_2:
            cout << "2";
            break;
        case VALUE_3:
            cout << "3";
            break;
        case VALUE_4:
            cout << "4";
            break;
        case VALUE_5:
            cout << "5";
            break;
        case VALUE_6:
            cout << "6";
            break;
        case VALUE_7:
            cout << "7";
            break;
        case VALUE_8:
            cout << "8";
            break;
        case VALUE_9:
            cout << "9";
            break;
        case VALUE_10:
            cout << "T";
            break;
        case VALUE_Jack:
            cout << "J";
            break;
        case VALUE_Queen:
            cout << "Q";
            break;
        case VALUE_King:
            cout << "K";
            break;
        case VALUE_Ace:
            cout << "A";
            break;
        default:
            cout << "Error!";
            break;
        }
        cout << endl;
    }

    int getCardValue() const
    {
        int num = static_cast<int>(m_val);
        if (num <= 8)
            return num + 2;
        if (m_val == VALUE_Ace)
            return 11;
        return 10;
    }
};


class Deck
{
private:
    array<Card, 52> m_deck;
    int m_cardIndex = 0;
    void swapCard(Card& a, Card& b)
    {
        Card tmp = a;
        a = b;
        b = tmp;
    }
    
public:
    Deck()
    {
        for (int i = 0; i < Card::VALUE_num; i++)
        {
            for (int j = 0; j < Card::SUIT_num; j++)
            {
                m_deck[i * Card::SUIT_num + j] = Card(static_cast<Card::SUIT>(j), static_cast<Card::VALUE>(i));
            }
        }
    }
    void printDeck() const
    {
        for (const auto& tmp : m_deck)
        {
            tmp.printCard();
        }
    }
    void shuffleDeck()
    {
        int rand_num;
        m_cardIndex = 0;
        for (int i = 0; i < 52; i++)
        {
            rand_num = static_cast<int>(rand()) % 52;
            swapCard(m_deck[i], m_deck[rand_num]);
        }
    }
    const Card& dealCard()
    {
        return m_deck[m_cardIndex++];
    }


};


bool playBlackjack(Deck deck)
{
    int num_player = 0;
    int num_diller = 0;
    char choice;
    deck.shuffleDeck();
    num_diller += deck.dealCard().getCardValue();
    num_player += deck.dealCard().getCardValue();
    num_player += deck.dealCard().getCardValue();
    while (true)
    {
        if (num_player <= 21)
        {
            cout << "Make choice! t - to take, any - to skip" << endl;
            cin >> choice;
            if (choice == 't')
            {
                num_player += deck.dealCard().getCardValue();
            }
            else
            {
                break;
            }
        }
        else
        {
            return false;
        }
    }

    while (num_diller < 17)
    {
        num_diller += deck.dealCard().getCardValue();
    }
    if (num_diller > 21)
        return true;
    if (num_diller > num_player)
        return false;
    return true;
}
int main()
{
    srand(static_cast<unsigned int>(time(0))); // используем системные часы в качестве стартового значения
    rand(); // пользователям Visual Studio: делаем сброс первого случайного числа

    Deck deck;
    if (playBlackjack(deck))
        cout << "u win" << endl;
    else
        cout << "u lose" << endl;
   
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
